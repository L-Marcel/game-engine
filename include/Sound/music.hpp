#include <Engine.hpp>

namespace Game {
  class Music : public sf::Music {
    public:
      /// @brief Cria uma instância de uma música
      /// @param filename o arquivo da música 
      Music(string filename);
      ~Music();
  };
}