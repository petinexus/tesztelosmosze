#ifndef MONSTER_H
#define MONSTER_H

/*!
 * \class Monster
 * 
 * \brief Monster class
 * 
 * A Szörnyekért felelős osztály.
 * 
 * 
 * \author  Borbély Roland, Vitéz Marcell, Voznek Péter
 * 
 * \version 4.0
 * 
 * \date 2020/11/02 13:22
 * 
 * Created on 2020/11/02 13:22
 */

#include "Unit.h"
#include "Hero.h"

class Hero;

class Monster : public Unit{
public:

    /*! \brief Monster konstruktor
 	*         
 	*  
 	*  Beállítja a Szörny adatait a paraméterek alapján.
 	*  
 	*  \param name [in] Szörny neve
	*  \param hp [in] Szörny életereje
	*  \param dmg [in] Szörny támadási ereje
	*  \param acd [in] Szörny támadási ideje
 	*/
    Monster(std::string name, int hp, int dmg, double acd) : Unit(name, hp, dmg, acd){}
    /// Ez a függvény a .json file parse-olja. 
	static Monster parse(const std::string& fname/** [in] elérési út */);
    /// Ez a függvény megüti a Szörnyet.
    void getHitBy(Hero* other);
};

#endif