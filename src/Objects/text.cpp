#include <Objects/text.hpp>

namespace Game {
  string Text::type() {
    return "Text";
  };
  
  void Text::draw() {
    this->gp->window.draw(this->text);
  };

  Text::~Text() {};
  
  Text::Text() {
    this->loadFontFromFile("assets/fonts/PixeloidMono.ttf");
    this->setFont(this->font);
  };

  Text* Text::create(GameProcess* gp, Vector<float> position, string content, unsigned int size) {
    Text* text = new Text();
    text->setPosition(position);
    text->setText(content);
    text->setSize(size);
    FloatRect textBounds = text->text.getLocalBounds();
    text->text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    text->gp = gp;
    gp->objects.add(text);
    return text;
  };

  void Text::setPosition(Vector<float> position) {
    this->text.setPosition(position);
  };

  void Text::setFont(sf::Font& font) {
    this->text.setFont(font);
  };

  void Text::setText(string content) {
    this->text.setString(content);
  };

  void Text::setSize(unsigned int size) {
    this->text.setCharacterSize(size);
  };

  void Text::setColor(sf::Color color) {
    this->text.setFillColor(color);
  };

  void Text::loadFontFromFile(string filename) {
    this->font.loadFromFile(filename);
  };
};