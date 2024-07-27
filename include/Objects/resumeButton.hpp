#include <Objects.hpp>
#include <Input.hpp>

namespace Game{
  class ResumeButton : public Button{
    public:
      void step();
      virtual ~ResumeButton();

      static ResumeButton* create(GameProcess* gp, string sprite, Box box, bool pauseBt);

    protected:
      using Button::Button;
  };

};