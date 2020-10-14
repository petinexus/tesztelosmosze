/*!
 * \class Unit
 * 
 * \brief Unit class
 * 
 * A karakterekért felelős osztály.
 * 
 * 
 * \author  Borbély Roland, Vitéz Marcell, Voznek Péter
 * 
 * \version 3.1
 * 
 * \date 2020/10/08 20:41
 * 
 * Created on 2020/10/08 20:41
 */
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class Unit
{
public:
	/// A fight függvény levezényli a csatát és a végén kiírja a győztest.
	Unit* fight(Unit *other /** [in] ellenfél karakter Unit */);
	/*! \brief Unit konstruktor.
 	*         
 	*  
 	*  Beállítja a karakterek adatait a paraméterek alapján.
 	*  
 	*  \param name [in] karakter neve
	*  \param hp [in] karakter életereje
	*  \param dmg [in] karakter támadási ereje
	*  \param acd [in] karakter támadási ideje
 	*/
	Unit(const std::string& name, int hP, int dmg, double acd) : b_name(name), b_hP(hP), b_dmg(dmg), b_acd(acd), b_maxHp(hP), b_xp(0), b_level(1) {}
	/// Ez a függvény a .json file parse-olja.
	static Unit* parseUnit(const std::string& fname/** [in] elérési út */);
private:
	const std::string b_name;  ///< A karakter neve. 
	int b_hP; ///< A karakter életereje.
	int b_dmg; ///< A karakter támadási ereje.
	double b_acd; ///< Karakter támadási ideje.
	int b_maxHp;
	int b_xp; 
	int b_level;
	/// Ez a függvény sebzést oszt ki a karakterre.
	void getHitBy(Unit *other /** [in] ellenfél karakter Unit */ );
	/// Ez a függvény visszaadja a karakter támadási erejét.
	int getDmg() const { return b_dmg; }
	/// Ez a függvény visszaadja a karakter támadási idejét.
	double getAcd() const { return b_acd; } 
	/// Ez a függvény visszaadja a karakter életerejét.
	int getHP() const { return b_hP; }
	/// Ez a függvény visszaadja a karakter nevét.
	std::string getName() const { return b_name; }
	/// Ez a függvény visszaadja a karakter meghalt-e.
	bool isDead() const;
	void levelup();
	int getXp() const { return b_xp; }
	int getLevel() const {return b_level; }
};
