#pragma once
#include <Objects.hpp>

namespace Game {
  class Base;
  class Tower : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~Tower();

      /// @brief Cria uma instância da torre
      /// @param base a base a qual a torre pertence
      static Tower* create(Base* base);

      Base* base = nullptr;
      bool energized = true;
    protected:
      /// @brief Cria uma instância da torre
      /// @param spriteSheet página de textura do sprite da torre
      /// @param box uma caixa que informa a origem do sprite e as dimesões dele
      Tower(string spriteSheet, Box box);
  };
};