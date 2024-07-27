#include <Objects/resumeButton.hpp>

namespace Game{
  void ResumeButton::step(){
    Vector<float> mousePos = Mouse::position(&this->gp->window);
    if(this->gp->checkPaused()){
      this->visible = true;
      if(mousePos.x <= (this->position.x + this->buttonWidth) &&
        mousePos.x >= (this->position.x - this->buttonWidth) &&
        mousePos.y <= (this->position.y + this->buttonHeight) &&
        mousePos.y >= (this->position.y - this->buttonHeight))
        {
          if(Mouse::left()){
            this->gp->setPaused(false);
          }
      }
    } else{
      this->visible = false;
    }
  };

  ResumeButton::~ResumeButton(){};

  ResumeButton* ResumeButton::create(GameProcess* gp, string sprite, Box box, bool pauseBt){
    ResumeButton* resumeButton = new ResumeButton(sprite, box);
    resumeButton->pausable = !pauseBt;
    resumeButton->buttonWidth = box.getSize().x;
    resumeButton->buttonHeight = box.getSize().y;
    resumeButton->gp = gp;
    gp->objects.add(resumeButton);
    return resumeButton;
  };
}