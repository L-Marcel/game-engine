#include <Engine.hpp>
#include <Menus.hpp>

namespace Game {
  void GameProcess::close() {
    GameProcess::gp->window.close();
  };

  void GameProcess::pause(bool shop) {
    if(GameProcess::gp->restarted) return;
    GameProcess::gp->paused = true;
    if(shop) GameProcess::navigate(ShopMenu::create());
    else GameProcess::navigate(PauseMenu::create());
  };

  void GameProcess::defeat() {
    if(GameProcess::gp->restarted) return;
    GameProcess::gp->paused = true;
    GameProcess::navigate(DefeatMenu::create());
  };

  void GameProcess::victory() {
    if(GameProcess::gp->restarted) return;
    GameProcess::gp->paused = true;
    GameProcess::navigate(VictoryMenu::create());
  };

  void GameProcess::resume() {
    if(GameProcess::gp->restarted) return;
    GameProcess::gp->paused = false;
    GameProcess::navigate();
  };
  
  void GameProcess::navigate(Menu* menu) {
    if(GameProcess::gp->restarted) return;
    Input::update();
    Mouse::update();
    if(GameProcess::gp->menu != nullptr) GameProcess::gp->menu->close();
    if(GameProcess::gp->menu == nullptr && menu != nullptr) GameProcess::open_sound.play();
    GameProcess::gp->menu = menu;
  };

  bool GameProcess::in(string menu) {
    if(GameProcess::gp == nullptr || GameProcess::gp->menu == nullptr) return false;
    return GameProcess::gp->menu->type() == menu;
  };
};