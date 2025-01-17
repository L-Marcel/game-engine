#pragma once
#include <Character.hpp>
#include <Misc/playerfinder.hpp>
#include <Objects/base.hpp>
#include <Objects/bullet.hpp>
#include <Objects/medical_kit.hpp>
#include <Objects/ammo_kit.hpp>
#include <Sound.hpp>

namespace Game {
  class Enemy : public Character {
    public:
      virtual string type();
      virtual void step();
      using Character::collision;
      using Character::draw;
      using Character::free;
      ~Enemy();

      /// @brief Cria uma instância do Enemy
      /// @param x Posição de início na horizontal
      /// @param y Posição de início na vertical
      static Enemy* create(float x, float y);

      /// @brief Realiza um disparo
      void shoot();

      /// @brief Dropa os kits quando o Enemy é eliminado
      void dropKits();

      Sound shoot_sound = Sound("shoot.mp3");
      bool focusingBase = true;
      Playerfinder path;
      Object2D* legs = nullptr;

      static Wall* wab;
      static Wall* wbc;
      static Wall* wcd;
      static Wall* wda;
      static unsigned int amount;
    protected:
      using Character::Character;
      double range = 200.0;
  };
};