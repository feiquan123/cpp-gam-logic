#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

//Role
class Role {
	private:
		string name ;
		Weapon *weapon;
		int healthPoint ;
		Monster *monster;
	public:
		Role(string name, int healthPoint );
		Role(string name,Weapon *weapon,int healthPoint);
		int getHealthPoint();
		int getAttackPower();
		string getName();
		Weapon* getWeapon();
		string getWeaponName();
		Monster* getMonster();
		void setWeapon(Weapon *weapon);
		void setMonster(Monster *monster);
		void attackAction(Monster *monster);
		void beAttackAction(Monster *monster);
		void handle(int healthPoint);
		void run();
		void skill_斩杀();
		friend ostream &operator << (ostream &output, Role &r);
};
