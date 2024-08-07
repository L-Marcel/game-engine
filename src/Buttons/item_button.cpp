#include <Buttons.hpp>
#include <Menus/shop_menu.hpp>
#include <Objects/player.hpp>
#include <Objects/base.hpp>
#include <Misc/shop.hpp>

namespace Game {
  string ItemButton::type() {
    return "ItemButton";
  };

  void ItemButton::step() {
    if(this->item->price() > GameProcess::money) {
      Color color = Color::White;
      color.a = 125;
      this->sprite->setColor(color);
      this->text->setColor(Color::Red);
    } else {
      this->sprite->setColor(Color::White);
      this->text->setColor(Color::White);
    };

    if(this->isHovered()) {
      this->animate(1, 1, 1, false);
      ShopMenu::description = this->item->description(this->item);

      if(Mouse::isLeftReleased()) {
        bool bought = Shop::purchase(this->item);
        if(bought) this->buy_sound.play();
        if(bought && this->item->rarity > 0) {
          this->visible = false;
          this->text->visible = false;
        };
      };
    } else this->animate(1, 1, 0, false);

    if(!this->visible && this->buy_sound.getStatus() == Sound::Stopped) {
      this->destroy();
      this->text->destroy();
      for(unsigned int i = 0; i < this->menu->objects.length(); i++) {
        Object2D* object = this->menu->objects.get(i);
        if(object == this) {
          this->menu->objects.remove(i);
          this->menu->texts.remove(i);
          break;
        };
      };
    };
  };

  ItemButton::~ItemButton() {};

  ItemButton* ItemButton::create(ShopMenu* menu, unsigned short int rarity) {
    Item* item = Shop::get_offer(rarity);

    Text* text = Text::create(CENTER, to_string(item->price()));
    text->depth = 510;
    menu->texts.add(text);

    ItemButton* itemButton = new ItemButton(item->name + "_upgrade.png", Box(28, 28, 56, 56));
    itemButton->menu = menu;
    itemButton->item = item;
    itemButton->animate(1, 1, 0, false);
    itemButton->pausable = false;
    itemButton->depth = 500;
    itemButton->position = CENTER;
    itemButton->scale(3);
    itemButton->text = text;
    menu->objects.add(itemButton);

    GameProcess::add(itemButton);
    return itemButton;
  };
};