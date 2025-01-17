#pragma once
#include <Objects.hpp>

namespace Game {
  class Base;
  class Wall : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Wall();

      /// @brief Cria uma instância da parede
      /// @param size diz qual é a parede
      static Wall* create(unsigned short int size);
    
      bool energized = true;
      bool enabled = true;

      Sound off_sound = Sound("wall_off.wav");
      Sound on_sound = Sound("wall_on.wav");
    protected:
      unsigned short int side = 0;
      
      /// @brief Cria uma instância da parede
      /// @param sprite_sheet página de textura do sprite da parede
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Wall(string sprite_sheet, Box box);
  };
};