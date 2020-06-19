#include <iostream>
#include <string>
#include "monster.h"

using namespace std;

class Weapon{
	protected:
		string name;
		int attack;
	public:
		Weapon();
		Weapon(string name,int attack);
		string getName();
		int getAttack();
		virtual void attackMonster(Monster *monster);
		friend ostream &operator << (ostream &output, Weapon *w);
};

class WoodWeapon:public Weapon{
public :
	WoodWeapon();
	void attackMonster(Monster *monster);
};

class IronWeapon:public Weapon{
public :
	IronWeapon();
	void attackMonster(Monster *monster);
};

class MagicWeapon:public Weapon{
public :
	MagicWeapon();
	void attackMonster(Monster *monster);
};