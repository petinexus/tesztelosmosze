#ifndef HERO_H
#define HERO_H

/*!
 * \class Hero
 * 
 * \brief Hero class
 * 
 * A hősökért felelős osztály.
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
#include "Monster.h"

class Monster;

class Hero : public Unit{
private:
    int b_maxHp; ///< Hős maximális életereje.
	int b_xp; ///< Hős fejlődési pont.
	int b_level; ///< Hős szintje.
    int b_experience_per_level; ///< Hős szint növekedéséhez szükséges XP mértéke.
    int b_health_point_bonus_per_level; ///< Hős MAX életpontjának növekedése szintekként.
    int b_damage_bonus_per_level; ///< Hős sebzésének növekedése szintekként.
    double b_cooldown_multiplier_per_level; ///< Hős támadási idő csökkenés mértéke szintekként.

public:
    /// A fightTilDeath függvény levezényli a csatát. 
	void fightTilDeath(Monster& other /** [in] ellenfél karakter */); 

    /*! \brief Hero konstruktor
 	*         
 	*  
 	*  Beállítja a karakterek adatait a paraméterek alapján.
 	*  
 	*  \param name [in] Hős neve.
	*  \param hp [in] Hős életereje.
	*  \param dmg [in] Hős támadási ereje.
	*  \param acd [in] Hős támadási ideje.
  	*  \param experience_per_level [in] Hős szint növekedéséhez szükséges XP mértéke.
  	*  \param health_point_bonus_per_level [in] Hős MAX életpontjának növekedése szintekként.
  	*  \param damage_bonus_per_level [in] Hős sebzésének növekedése szintekként.
  	*  \param cooldown_multiplier_per_level [in] Hős támadási idő csökkenés mértéke szintekként.
 	*/
    Hero(const std::string& name, int hP, int dmg, double acd,
    int experience_per_level,
    int health_point_bonus_per_level,
    int damage_bonus_per_level,
    double cooldown_multiplier_per_level) : Unit(name, hP, dmg, acd),
    b_maxHp(hP), b_xp(0), b_level(1), 
    b_experience_per_level(experience_per_level),
    b_health_point_bonus_per_level(health_point_bonus_per_level),
    b_damage_bonus_per_level(damage_bonus_per_level),
    b_cooldown_multiplier_per_level(cooldown_multiplier_per_level) {} 
    /// Ez a függvény a .json file parse-olja. 
    static Hero parse(const std::string& fname/** [in] elérési út */);   
    /// Ez a függvény visszaadja a Hős szintjét.
	int getLevel() const { return b_level; }
    /// Ez a függvény visszaadja a Hős maximális életerejét.
	int getMaxHealthPoints() const {return b_maxHp; }
    /// Ez a függvény visszaadja a Hős maximális életerejét.
    void addXp(int amount) { b_xp += amount; }
    /// Ez a függvény ellenőrzi/végzi a szintlépést.
	void levelup();
    /// Ez a függvény megüti a Hőst.
    void getHitBy(Unit* other);
};

/*!
 * \class MarkedMap
 * 
 * \brief MarkedMap class
 * 
 * A MarkedMap konstruktura beolvas egy térképet egy adott fájból amiben előre megtalálhatóak a Hős és a szörnyek pozíciói
 * 
 * 
 * \author  Borbély Roland, Vitéz Marcell, Voznek Péter
 * 
 * \version 4.0
 * 
 * \date 2020/11/17 18:39
 * 
 * Created on 2020/11/17 18:39
 */

class MarkedMap : public Hero
{
    public:
    
    /// MarkedMap konstruktor 
    MarkedMap(const std::string& filename /** [in] a fájl elérési útvonala*/);

    /// MarkedMap default konstruktor 
    MarkedMap(){}
   
    std::pair<int,int> getHeroPosition() const; ///< Visszaadja a Hős pozícióját
    std::vector<std::pair<int,int>> getMonsterPositions(char c) const; ///< Visszaadja a kért Monster pozícióját
};

#endif