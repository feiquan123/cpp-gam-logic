#include <iostream>
#include <string>

using namespace std;

class Role;

//Monster
class Monster {
	private:
		string name;
		int healthPoint;
		int healthPointFull;
		int attack;
		Role *role;

	public:
		Monster(string name, int healthPoint,int attack);
		string getName();
		int getHealthPoint();
		int getHealthPointFull();
		int getAttackPower();
		Role* getRole();
		void setName(string name);
		void setHealthPoint(int healthPoint);
		void setRole(Role* role);
		void handle(int healthPoint);
		friend ostream &operator << (ostream &output, Monster &m);
};