#include<iostream>
#include <string>
#include "monster.h"

using namespace std;

//Monster
Monster::Monster(string name, int healthPoint,int attack) {
	this->name = name;
	this->healthPoint = healthPoint;
	this->attack = attack;
	this->healthPointFull = healthPoint;
}

string Monster::getName() {
	return this->name;
}

int  Monster::getHealthPoint() {
	return this->healthPoint;
}

int  Monster::getHealthPointFull() {
	return this->healthPointFull;
}

int  Monster::getAttackPower(){
	return this-> attack;
}

Role* Monster::getRole(){
	return this->role;
}

void  Monster::setName(string name) {
	this->name = name;
}

void  Monster::setHealthPoint(int healthPoint) {
	this->healthPoint = healthPoint;
}

void  Monster::setRole(Role* role){
	this->role = role;
}

void  Monster::handle(int healthPoint){
	if (this->role==NULL){
		cout <<"Moster[ "<< this->getName() <<" ] no enemy" <<endl;
		return;
	}
	
	this->healthPoint -= healthPoint;
	if (this->getHealthPoint() <= 0) {
		cout<<"attack Monser [ "<< this->getName() <<" ], " << this->getName() <<"is dead."<<endl;
		// cout<<"Role[ "<< this->getRole()->getName() << " ] attack Monser [ "<< this->getName() <<" ], " << this->getName() <<"is dead."<<endl;
		// this->getRole()->setMonster(NULL);
		this->setRole(NULL);
	} else {
		cout<<"attack Monser [ "<< this->getName() <<" ], " << this->getName() <<" loss "<<healthPoint<<" life."<<endl;
		// cout<<"Role[ "<< this->getRole()->getName() << " ] attack Monser [ "<< this->getName() <<" ], " << this->getName() <<" loss "<<healthPoint<<"life."<<endl;
	}
}

ostream &operator << (ostream &output, Monster &m){
	output << "Moster[ "<< m.getName() <<" ]'s status is [ life:"<< m.getHealthPoint() <<" attackPower:"<< m.getAttackPower() << "]" << endl;
	return output;
}