#pragma once
#include <Objects.hpp>

namespace Game{
  class GameProcess;
  class Collision {
    protected:
      Object2D* object;
      string collider = "none";

      /// @brief Cria uma instância do registro de uma colisão
      Collision();
    public:
      /// @brief Registra a colisão entre um objeto e um tipo de objeto
      /// @param object o objeto que registrará a colisão
      /// @param collider o tipo de objeto que pode colidir com ele
      static Collision* create(Object2D* object, string collider);

      /// @brief Remove a instância do jogo e libera ela da memória
      void destroy();

      /// @brief Função step para verificar as colisões
      void step();

      /// @brief Checa a colisão entre dois círculos
      /// @param first primeiro objeto
      /// @param second segundo objeto
      /// @return `true` se houver uma colisão, `false` caso contrário
      static bool has_circles_collision(Object2D* first, Object2D* second);

      /// @brief Checa a colisão entre um círculo e um retângulo
      /// @param first primeiro objeto
      /// @param second segundo objeto
      /// @return `true` se houver uma colisão, `false` caso contrário
      static bool has_circle_and_rectangle_collision(Object2D* first, Object2D* second);

      /// @brief Checa a colisão entre dois retângulos
      /// @param first primeiro objeto
      /// @param second segundo objeto
      /// @return `true` se houver uma colisão, `false` caso contrário
      static bool has_rectangles_collision(Object2D* first, Object2D* second);
  };
};