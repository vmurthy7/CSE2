#ifndef ROBOTS
#define ROBOTS

#include <string>
#include <iostream>
#include<vector>
#include "SDL/SDL.h"

using namespace std;

class Robots
{

public:

 Robots (int, int);
 float getHealth ();
 float getMaxHealth ();
 float getArmor ();
 float getDamage ();
 float getMoveSpeed ();
 float getXPos ();
 float getYPos ();
 int getRobotType ();
 void printStats ();
 float dealDamage (Robots);
 void addWeapons (int);
 void addArmor (int);
 void getPosition (double[]);
 void calcDistance ();
 int getID ();
 void calcTargets ();
 float getRange ();
 int getRobotTyoe ();
 void move (float, double[]);
 void checkAttack ();
 void runAI (vector < SDL_Surface *>);
 void checkDead ();
 void play (vector < SDL_Surface *>);
 void apply_surface(int, int, SDL_Surface *, SDL_Surface *);
 SDL_Surface * load_image(const char *);
 void drawRobot(vector < SDL_Surface *>);


private:

 float Health;
 float MaxHealth;
 float Damage;
 float Armor;
 float MoveSpeed;
 float xPos;
 float yPos;
 int RobotType;	 // 0 for friendly bot, 1 for enemy
 float Weight;
 float MaxWeight;
 float Range;
 float AttackSpeed;
 int id;
 float range;
 int attackID;	 // contains the id of the robot that the current robot will attack
 float distance;


};

#endif
