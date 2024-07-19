#include <Engine/objects.hpp>
#include <Objects.hpp>

namespace Game {
  class GameProcess {
      private:
        unsigned short int width = 800;
        unsigned short int height = 600;
        string title = "Base Defense";
        unsigned short int frame = 0;
        Clock clock;
        bool redraw = false;
        void (*events)(Event::EventType);

      public:
        Window window = Window(VideoMode(800, 600), "Base Defense");
        List<Object> objects;
        List<Collision> collisions;

        /// @brief Cria uma instância de processo do jogo
        GameProcess();

        /// @brief Cria uma instância de processo do jogo
        /// @param width a largura da janela
        /// @param height a altura da janela
        /// @param title o título da janela
        GameProcess(
          unsigned short int width, 
          unsigned short int height,
          string title
        );
        
        /// @brief Inicia o loop do jogo
        void execute();

        /// @brief Retorna um objeto de acordo com seu index
        /// @param index index do objeto
        /// @return um objeto
        Object* getObject(unsigned int index);

        /// @brief Retorna o tamanho da lista de objetos
        /// @return o tamanho da lista de objetos
        unsigned int getOListSize();

        /// @brief Adiciona uma colisão na lista de colisões
        /// @param collision a colisão que irá ser adicionada
        void addCol(Collision* collision);

        /// @brief Retorna uma colisão de acordo com os tipos dos objetos que colidem
        /// @param object objeto que está chamando a função no step
        /// @param collider objeto na qual vai colidir com object (ou que será colidido)
        /// @return a colisão com os dois tipos dos parâmetros
        Collision* getCollisionByType(string object, string collider);

        /// @brief Realiza a atualização do sprite do objeto, entre outras coisas
        /// @param object o objeto
        void animate(Object2D* object);

        /// @brief Retorna o frame atual do jogo
        /// @return o frame
        unsigned short int getFrame();

        /// @brief Avança o jogo para o próximo frame
        void nextFrame();

        /// @brief Diz se o jogo ainda está rodando
        /// @return verdadeiro, se estiver, falso caso contrário
        bool isRunning();

        /// @brief Recebe uma função que será chamada para todo e qualquer evento do jogo
        /// (não confundir com evento de um objeto)
        /// @param func a função a ser chamada
        void on(void (*func)(Event::EventType));

        /// @brief Pega a largura da janela
        /// @return A largura da window
        unsigned short int getWindowWidth();

        /// @brief Pega a altura da janela
        /// @return A altura da janela
        unsigned short int getWindowHeight();
  };
};