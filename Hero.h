#ifndef HERO_H
#define HERO_H

#include "Unit.h"
#include "Monster.h"

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
 * \version 5.0
 * 
 * \date 2020/11/02 13:22
 * 
 * Created on 2020/11/02 13:22
 */

class Monster;

class Hero : public Unit{
private:
	int b_maxHp; ///< Hős maximális életereje.
	int b_xp; ///< Hős fejlődési pont.
	int b_level; ///< Hős szintje.
    int b_experience_per_level; ///< Hős szint növekedéséhez szükséges XP mértéke.
    int b_health_point_bonus_per_level; ///< Hős MAX életpontjának növekedése szintenként.
    int b_damage_bonus_per_level; ///< Hős fizikai sebzésének növekedése szintenként.
	int b_magical_damage_bonus_per_level; ///< Hős mágikus sebzésének növekedése szintenként.
    double b_cooldown_multiplier_per_level; ///< Hős támadási idő csökkenés mértéke szintenként.
	int b_defense_bonus_per_level; ///< Hős védelmi növekedése szintenként.
	int b_light_radius; ///< Hős látótávolsága.
	int b_light_radius_bonus_per_level; ///< Hős látótávolsága növekedése szintenként.

public:
     /*! \brief Hero konstruktor
 	*         
 	*  
 	*  Beállítja a Hősök adatait a paraméterek alapján.
 	*  
 	*  \param name [in] Hős neve
	*  \param hp [in] Hős életereje
	*  \param dmg [in] Hős támadási ereje
	*  \param acd [in] Hős támadási ideje
	*  \param defense [in] Hős védelme
	*  \param texture [in] Hős textúrája
  	*  \param experience_per_level [in] Hős szint növekedéséhez szükséges XP mértéke
  	*  \param health_point_bonus_per_level [in] Hős MAX életpontjának növekedése szintenként
  	*  \param damage_bonus_per_level [in] Hős fizikális sebzésének növekedése szintenként
	*  \param magical_damage_bonus_per_level [in] Hős mágikus sebézésének növekedése szintenként
  	*  \param cooldown_multiplier_per_level [in] Hős támadási idő csökkenés mértéke szintenként
	*  \param defense_bonus_per_level [in] Hős védelmi növekedése szintenként
	*  \param light_radius [in] Hős látótávolsága
	*  \param light_radius_bonus_per_level [in] Hős látótávolsága növekedése szintenként
 	*/
	Hero(const std::string& name, int hP, Damage dmg, double acd, int defense, const std::string& texture, 
    	int experience_per_level,
    	int health_point_bonus_per_level,
    	int damage_bonus_per_level,
		int magical_damage_bonus_per_level,
    	double cooldown_multiplier_per_level,
		int defense_bonus_per_level,
		int light_radius, 
		int light_radius_bonus_per_level) : Unit(name, hP, dmg, acd, defense, texture),
    	b_maxHp(hP), b_xp(0), b_level(1), 
    	b_experience_per_level(experience_per_level),
    	b_health_point_bonus_per_level(health_point_bonus_per_level),
    	b_damage_bonus_per_level(damage_bonus_per_level),
		b_magical_damage_bonus_per_level(magical_damage_bonus_per_level),
    	b_cooldown_multiplier_per_level(cooldown_multiplier_per_level), 
		b_defense_bonus_per_level(defense_bonus_per_level),
		b_light_radius(light_radius),
		b_light_radius_bonus_per_level(light_radius_bonus_per_level){} 

    /// Ez a függvény parse-olja a megadott fájlt. 
    static Hero parse(const std::string& fname/** [in] elérési út */); 
	/// A fightTilDeath függvény levezényli a csatát. 
	void fightTilDeath(Monster& other /** [in] ellenfél karakter */);  
    /// Ez a függvény visszaadja a Hős szintjét.
	int getLevel() const { return b_level; }
    /// Ez a függvény visszaadja a Hős maximális életerejét.
	int getMaxHealthPoints() const { return b_maxHp; }
    /// Ez a függvény végzi a Hős XP növekedését.
    void addXp(int amount/** [in] a növekedés mértéke */ ) { b_xp += amount; }
    /// Ez a függvény ellenőrzi/végzi a szintlépést.
	void levelup();
    /// Ez a függvény megüti a Hőst.
    void getHitBy(Unit* other/** [in] ellenfél karakter*/);
	/// Ez a függvény visszaadja a Hős látótávolságát.
	int getLightRadius() const { return b_light_radius; }
};

#endif
