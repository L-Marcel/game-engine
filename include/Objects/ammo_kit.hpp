#pragma once
#include <Objects/object_2d.hpp>
#include <Misc/timer.hpp>
#include <Engine.hpp>

namespace Game {
  class AmmoKit : public Object2D {
    public:
      virtual string type();
      virtual void step();
      using Object2D::collision;
      using Object2D::draw;
      using Object2D::free;
      ~AmmoKit();
      
      /// @brief Cria uma instancia do AmmoKit
      /// @param enemyPosition a posição do kit
      static AmmoKit* create(Point enemyPosition);

      static const unsigned int charge;
    protected:
      using Object2D::Object2D;
      Timer timer;
  };
};