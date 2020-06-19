#include<iostream>
#include <string>  
#include "role.h"

using namespace std;

int main(){
	string roleName ;
	cout<<"Please intput your role's name:";
	cin >>roleName;
	cout<<endl;

	// cerate role entity
	Role role = Role(roleName,1000);
	cout<<role<<endl;

	//create moster entity
	Monster monsterA = Monster("Moster A", 300,10);
	Monster monsterB = Monster("Moster B", 50,15);
	Monster monsterC = Monster("Moster C", 200,30);
	Monster monsterBoss = Monster("Moster Boss", 1000,100);
	cout<<monsterA<<monsterB<<monsterC<<endl;
	
	// create weapon entity
	WoodWeapon woodSword = WoodWeapon();
	IronWeapon ironSword = IronWeapon();
	MagicWeapon magicSword = MagicWeapon();
	cout<<&woodSword<<&ironSword<<&magicSword<<endl;

	role.attackAction(&monsterA);
	cout<<monsterA<<endl;

	role.run();

	role.setWeapon(&woodSword);
	role.attackAction(&monsterA);
	cout<<monsterA<<endl;

	role.setWeapon(&ironSword);    
	role.attackAction(&monsterB);  
	cout<<monsterB<<endl;

	role.setWeapon(&magicSword);    
	role.attackAction(&monsterC);
	role.attackAction(&monsterC);
	cout<<monsterC<<endl;

	bool skill1 = true;
	bool skill2 = true;
	while(monsterBoss.getHealthPoint()>0){
		if ( skill1 &&monsterBoss.getHealthPoint()<monsterBoss.getHealthPointFull()*0.9) {
			role.beAttackAction(NULL);
			role.skill_斩杀();
			skill1 = false;
			cout<<role<<monsterBoss<<endl;
			continue;
		}

		if ( skill2 &&monsterBoss.getHealthPoint()<monsterBoss.getHealthPointFull()*0.15) {
			role.beAttackAction(NULL);
			role.skill_斩杀();
			skill2 = false;
			cout<<role<<monsterBoss<<endl;
			continue;
		}
		role.beAttackAction(NULL);
		role.attackAction(&monsterBoss);
		cout<<role<<monsterBoss<<endl;
	}

	cout<< endl << "Fight End" << endl;
	return 0;
}
