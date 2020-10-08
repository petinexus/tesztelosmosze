/*!
 * \class Unit
 * 
 * \brief Unit class
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


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Unit
{
private:
	const std::string b_name;  //!< A karakter neve 
	int b_hP; //!< A karakter életereje
	const int b_dmg; //!< A karakter támadási ereje
	const double b_acd; //!< A karakter támadási ideje
	//! getHitBy() függvény sebzést oszt ki a karakterre
	void getHitBy(const Unit *other /*! [in] ellenfél karakter Unit */ );
	int getDmg() const { return b_dmg; }
	double getAcd() const { return b_acd; } 
	int getHP() const { return b_hP; }
	std::string getName() const { return b_name; }
	bool isDead() const;
	friend class Game;
protected:
	void fight(Unit *other);
	Unit(const std::string& name, int hP, int dmg, double acd) : b_name(name), b_hP(hP), b_dmg(dmg), b_acd(acd) {}
	static Unit* parseUnit(const std::string& fname);
};