#include "Monster.h"

Monster Monster::parse(const std::string& fname) {
	std::vector <std::string> keysNeeded {"name", "health_points", "damage", "attack_cooldown"};
	JSON returnedJSON = JSON::parseFromFile(fname);
	bool okay = true;
	for (auto key : keysNeeded)
        if(!returnedJSON.count(key))
			okay = false;

	if (okay) 
	    return Monster(returnedJSON.get<std::string>("name"), 
			stoi(returnedJSON.get<std::string>("health_points")),
			stoi(returnedJSON.get<std::string>("damage")),
			stod(returnedJSON.get<std::string>("attack_cooldown")));
	else throw JSON::ParseException("Incorrect attributes in " + fname + "!");
}


void Monster::getHitBy(Hero* other) {
	if (b_hP - other->getDamage() > 0) {
		other->addXp(other->getDamage());
		b_hP -= other->getDamage();
	}
	else { 
		other->addXp(b_hP);
		b_hP = 0;
	}
	other->levelup();
}