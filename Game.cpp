#include "Game.h"

void Game::runGame() {
    u1 = u1->fight(u2);
    std::cout << u1->getName() << " wins." << " Remaining hp: "<< u1->getHP()<<".";
}

Game::~Game(){
    delete u1;
    delete u2;
}