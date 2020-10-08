/*!
 * \class Game
 * 
 * \brief Game class
 * 
 * Ez az osztály a Csata lefutását vezényeli le.
 * 
 * \author  rooooooooooooooooooooland aka GUSZTÁV, vozo, marci
 * 
 * \version 1.0
 * 
 * \date 2020/10/08 18:56
 * 
 * Created on 2020/10/08 18:56
 */

#include "Unit.h"

class Game
{
private:
    Unit *u1, *u2;
public:
/*! \brief Game() konstruktor
 *         
 *  
 *  Beállítja a karakterek adatait a paraméterek alapján.
 *  
 *  \param argv [in] karaktertípusú tömb az argumentumokkal  
 */
    Game(char** argv) : u1(Unit::parseUnit(argv[1])), u2(Unit::parseUnit(argv[2])) { }
    ~Game();
/*! \brief runGame() függvény
 *      
 *  Lefutatja a játékot.
 */
    void runGame();
};