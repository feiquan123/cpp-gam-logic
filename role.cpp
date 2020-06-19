#include<iostream>
#include <string>
#include "role.h"
using namespace std;

Role::Role(string name, int healthPoint ){
	this->name= name;
	this->weapon = NULL;
	this->healthPoint = healthPoint;
}

Role::Role(string name,Weapon *weapon,int healthPoint) {
	this->name = name;
	this->weapon = weapon;
	this->healthPoint = healthPoint;
}

string Role::getName(){
	return name;
}

Weapon* Role::getWeapon() {
	return weapon;
}

string Role::getWeaponName(){
	if (weapon == NULL){
		return "";
	};
	return weapon->getName();
}

int Role::getHealthPoint(){
	return healthPoint;
}

int Role::getAttackPower(){
	if (weapon == NULL){
		return 0;
	}
	return weapon->getAttack();
}

Monster* Role::getMonster(){
	return monster;
}

void Role::setWeapon(Weapon *w) {
	cout<< "Role[ "<<name<<" ] pick up weapon[ "<< w->getName() <<" ], attack power is "<< w->getAttack()<<endl;
	weapon = w;
}

void Role::setMonster(Monster *m){
	if (monster ==NULL || monster != m){
		cout<<"Role[ "<< name << " ] meet Monser [ "<< m->getName() <<" ]"<<endl;
	}
	monster=m;
	m->setRole(this);
}

void Role::attackAction(Monster *m){
	this->setMonster(m);
	if (m ==NULL){
		return;
	}

	if(weapon==NULL){
		cout<<"Role[ "<< name << " ] no have weapon, you just attack name by your fist."<<endl;
		Weapon w = Weapon();
		this->setWeapon(&w);
	}
	this->weapon->attackMonster(m);
	if (m->getHealthPoint()>0){
		m->setRole(this);
	}else{
		// monster dead
		m->setRole(NULL);
	}
}

void Role::beAttackAction(Monster *m){
	if ( monster ==NULL){
		return ;
	}

	if (m == NULL){
		m = monster;
	}

	this->handle(m->getAttackPower());
	if (healthPoint>0){
		m ->setRole(this);
		this->setMonster(m);
	}else{
		// role dead
		m->setRole(NULL);
		monster = NULL;
	}
}

void Role::handle(int h){
	if (monster == NULL){
		cout <<"Role[ "<< name <<" ] no enemy" <<endl;
		return;
	}

	this->healthPoint -= h;
	if (this->getHealthPoint() <= 0) {
		cout<<"attack Role[ " << name <<" ] is dead "<<endl;
	} else {
		cout<<"attack Role[ " << name <<" ] loss "<<h<<"life "<<endl;
	}
}

void Role::run(){
	if (monster == NULL){
		return;
	}

	cout<<"Role[ "<< name << " ] leave Monser [ "<< monster->getName() <<" ]"<<endl;
	monster->setRole(NULL);
	monster = NULL;
}

void Role::skill_斩杀(){
	if (monster == NULL){
		return;
	}
	int old = monster->getHealthPoint();

	// this monster dead when it's life lower 20% 
	double rate = double(monster->getHealthPoint()) / double(monster->getHealthPointFull());
	if (rate<0.2){
		monster->setHealthPoint(0);
		cout <<"Role[ "<< name <<" ] user skill [斩杀] attack Monser [ "<< monster->getName() <<" ], " << monster->getName() <<"is dead."<<endl;

		monster->setRole(NULL);
		monster = NULL;
	}else{
		double loss = 0.9;
		int curLife = monster->getHealthPoint() * loss;
		monster->setHealthPoint(curLife);
		cout <<"Role[ "<< name <<" ] user skill [斩杀] attack Monser [ "<< monster->getName() <<" ], " << monster->getName() <<" loss "<< this->getHealthPoint() * (1-loss)<<" life."<<endl;
	}
}

ostream &operator << (ostream &output, Role &r){
	output << "Role[ "<< r.getName() <<" ]'s status is [ life:"<< r.getHealthPoint() <<" weapon:"<< r.getWeaponName()<< " attackPower:"<< r.getAttackPower() <<"]" << endl;
	return output;
}