#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Unit
{
public:
	void getHitBy(Unit *other);
	int getHP() const { return b_hP; }
	int getXp() const { return b_xp; }
	int getLevel() const {return b_level; }
	std::string getName() const { return b_name; }
	int getDmg() const { return b_dmg; }
	bool isDead() const;
	Unit(const std::string& name, int hP, int dmg) : b_name(name), b_hP(hP), b_dmg(dmg), b_maxHp(hP), b_xp(0), b_level(1) {}
	static Unit* parseUnit(const std::string& fname);

private:
	const std::string b_name;
	int b_hP;
	int b_dmg;
	int b_maxHp;
	int b_xp; 
	int b_level;
	void levelup();
};