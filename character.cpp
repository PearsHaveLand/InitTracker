#include "character.h"

bool isZero(const struct effect eff){return (eff.duration == 0);}

Character::Character(const string name, int hp, int initiativeRoll, int dexMod){
	if(initiativeRoll == NO_INITIATIVE){
		m_initiativeRoll = (rand() % 20) + dexMod;
	}
	m_name = name;
	m_initiativeRoll = initiativeRoll;
	m_hp = hp;
}

void Character::addEffect(string desc, int rounds){
	effect newEffect;
	newEffect.desc = desc;
	newEffect.duration = rounds;
	m_effects.push_front(newEffect);
}

void Character::removeDoneEffects(){
	m_effects.remove_if(isZero);
}

void Character::display(){
	cout << m_name << ", HP: " << m_hp << "\n";
	if(!m_effects.empty()){
		cout << "Effects: \n";
		for(list<effect>::iterator it=m_effects.begin(); it != m_effects.end(); it++){
			cout << "\t" << it->desc << ", rounds left: " << it->duration;
		}
	}
}

void Character::takeDamage(int dmg){
	m_hp -= dmg;
}
