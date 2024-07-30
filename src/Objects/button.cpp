#include <Objects.hpp>

namespace Game{
  void Button::step(){};

  string Button::type(){
    return "Button";
  }

  string Button::subType(){
    return subTypeVar;
  }

  void Button::setSubType(string newSubType){
    this->subTypeVar = newSubType;
  }

  Button::~Button(){};

  Button* Button::create(string sprite, Box box, bool pauseBt){
    Button* button = new Button(sprite, box);
    button->pausable = !pauseBt;
    button->buttonWidth = box.getSize().x;
    button->buttonHeight = box.getSize().y;
    button->subTypeVar = "Main";
    GameProcess::add(button);
    return button;
  };

  void Button::draw(){
    this->sprite->setPosition(this->position.x, this->position.y);
    GameProcess::draw(*this->sprite);
  }

  Button::Button(){};
  Button::Button(string spriteSheet, Box box) {
    Texture* texture = new Texture();
    this->sprite = new Sprite();

    if(texture->loadFromFile("assets/sprites/" + spriteSheet)){
      this->sprite->setTexture(*texture);
      Vector<int> pos = box.getPosition();
      box.top = 0;
      box.left = 0;

      this->fps = 0;
      this->sprite->setTextureRect(box);
      this->sprite->setOrigin(pos.x, pos.y);
      this->sprite->setScale(1, 1);
    } else {
      throw new TextureNotFound(spriteSheet);
    };
  };

  bool Button::getClicked(){
    return this->isClicked;
  }

  void Button::setClicked(bool clicked){
    this->isClicked = clicked;
  }

  bool Button::wasBridged(){
    return this->bridged;
  }

  void Button::setBridged(bool bridged){
    this->bridged = bridged;
  }

  void Button::setText(string content, unsigned int size){
    // Text* tempText = Text::create(this->gp, Vector<float>(this->position.x, this->position.y), content, size);
    // tempText->depth = 30;
    // if(!this->pausable == true) tempText->setVisible(false);
    // this->buttonText = tempText;
  }

  Text* Button::getText(){
    return this->buttonText;
  }

  bool Button::mouseEnter(Vector<float> mousePosition){
    return (mousePosition.x <= (this->position.x + this->buttonWidth) &&
            mousePosition.x >= (this->position.x - this->buttonWidth) &&
            mousePosition.y <= (this->position.y + this->buttonHeight) &&
            mousePosition.y >= (this->position.y - this->buttonHeight));
  }
}