#include<iostream>
#include <string>
#include "weapon.h"
using namespace std;

Weapon::Weapon(){
	this->name = "Fist";
	this->attack =1;
}
Weapon::Weapon(string name,int attack){
	this->name = name;
	this->attack = attack;
}
string Weapon::getName() {
	return this->name;
}
int Weapon::getAttack(){
	return this->attack;
}
void Weapon::attackMonster(Monster *monster) {
	monster->handle(this->attack);
}

// WoodWeapon
WoodWeapon::WoodWeapon():Weapon("Wood Sword",20){};
	void WoodWeapon::attackMonster(Monster *monster) {
	monster->handle(this->attack);
}

// IronWeapon
IronWeapon::IronWeapon():Weapon("Iron Sword",50){};
	void IronWeapon::attackMonster(Monster *monster) {
	monster->handle(this->attack);
}

// MagicWeapon
MagicWeapon::MagicWeapon():Weapon("Magic Sword",100){};
	void MagicWeapon::attackMonster(Monster *monster) {
	monster->handle(this->attack);
}

ostream &operator << (ostream &output, Weapon *w){
	output << "Weapon[ "<< w->getName() <<" ]'s attack is "<< w->getAttack() << endl;
	return output;
}
