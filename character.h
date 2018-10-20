#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

#define NO_INITIATIVE -100	//Unable to receive -100 value in initiative rolls

struct effect{
	string desc;
	int duration;
};

class Character{
public:
	Character(const string name, int hp, int initiativeRoll=NO_INITIATIVE, int dexMod=0);
	void addEffect(string desc, int rounds);
	void removeDoneEffects();
	void display();
	void takeDamage(int dmg);
	void heal(int dmg);
private:
	string m_name;
	list<effect> m_effects;
	int m_initiativeRoll;
	int m_hp;
};

#endif
