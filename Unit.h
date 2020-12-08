#ifndef UNIT_H
#define UNIT_H

#include "JSON.h"
#include "Damage.h"
#include <string>

/*!
 * \class Unit
 * 
 * \brief Unit class
 * 
 * A Unit karakterért felelős osztály.
 * 
 * 
 * \author  Borbély Roland, Vitéz Marcell, Voznek Péter
 * 
 * \version 5.0
 * 
 * \date 2020/11/02 13:22
 * 
 * Created on 2020/11/02 13:22
 */

class Unit
{
public:

	/*! \brief Unit konstruktor
 	*         
 	*  
 	*  Beállítja a karakterek adatait a paraméterek alapján.
 	*  
 	*  \param name [in] karakter neve
	*  \param hp [in] karakter életereje
	*  \param dmg [in] karakter támadási ereje
	*  \param acd [in] karakter támadási ideje
	*  \param defense [in] karakter védelme
	*  \param texture [in] a karakter textúrája
 	*/
	Unit(const std::string& name, int hP, Damage damage, double acd, int defense, const std::string& texture) 
		: b_name(name), b_hP(hP), b_damage(damage), b_acd(acd), b_defense(defense), b_texture(texture) {}
	/// Ez a függvény visszaadja a karakter életerejét.
	int getHealthPoints() const { return b_hP; }
	/// Ez a függvény visszaadja a karakter nevét.
	std::string getName() const { return b_name; }
	/// Ez a függvény visszaadja a karakter meghalt-e.
	bool isAlive() const { return b_hP > 0; }
	/// Ez a függvény visszaadja a karakter támadási erejét.
	Damage getDamage() const { return b_damage; }
	/// Ez a függvény visszaadja a karakter támadási idejét.
	double getAttackCoolDown() const { return b_acd; } 
	/// Ez a függvény visszaadja a karakter védelmi pontját.
	int getDefense() const{ return b_defense; }
	/// Ez a függvény visszaadja a karakter textúráját.
	std::string getTexture() const {return b_texture; }
protected:
	const std::string b_name;  ///< A karakter neve. 
	int b_hP; ///< A karakter életereje.
	Damage b_damage; ///< A karakter támadása.
	double b_acd; ///< Karakter támadási ideje.
	int b_defense; ///< A karakter védelme.
	std::string b_texture; ///< A karakter textúrája.
};

#endif
