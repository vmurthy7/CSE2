#include "Robots.h"
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include "SDL/SDL.h"

vector < Robots > RobotArray;	// stores the active Robots on the map

vector < SDL_Surface > SurfaceArray;

void
Robots::apply_surface (int x, int y, SDL_Surface * source,
      SDL_Surface * destination)
{
 //Make a temporary rectangle to hold the offsets
 SDL_Rect offset;

 //Give the offsets to the rectangle
 offset.x = x;
 offset.y = y;
//Blit the surface
 SDL_BlitSurface (source, NULL, destination, &offset);
}

SDL_Surface *
Robots::load_image (const char *filename)
{
 //The image that's loaded
 SDL_Surface *loadedImage = NULL;

 //The optimized image that will be used
 SDL_Surface *optimizedImage = NULL;

 //Load the image
//  loadedImage = SDL_LoadBMP (filename.c_str ());
 loadedImage = SDL_LoadBMP (filename);
 //If the image loaded
 if (loadedImage != NULL)
   {
     //Create an optimized image
     optimizedImage = SDL_DisplayFormat (loadedImage);

     //Free the old image
     SDL_FreeSurface (loadedImage);
   }
 //If the image was optimized just fine
 if (optimizedImage != NULL)
   {
     //Map the color key
     Uint32 colorkey = SDL_MapRGB (optimizedImage->format, 255, 255, 255);

     //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
     SDL_SetColorKey (optimizedImage, SDL_SRCCOLORKEY, colorkey);
   }
 return (optimizedImage);
}


float
Robots::getRange ()
{
 return RobotArray[id - 1].range;
}

int
Robots::getID ()
{
 return id;
}

int
Robots::getRobotType ()
{
 return RobotArray[id - 1].RobotType;
}

void
Robots::calcDistance ()	 // determines the robot closest to the current robot.
{
 float min = 1000;
 double pos[2];
 double temp[2];
 int minID;
 double distance;
 getPosition (pos);
 for (int i = 1; i < RobotArray.size (); i++)
   {
     if (RobotArray[i].getID () != getID ())
{
 RobotArray[i].getPosition (temp);
 distance = sqrt (pow ((temp[0] - pos[0]), 2) + pow ((temp[1] - pos[1]), 2));	// calculates the distance between the current robot and each other robot
 if (distance < min && (RobotArray[i].getRobotType () != RobotType)
     && (RobotType != 5) && (RobotArray[i].getRobotType () != 5))
   {
     min = distance;
     minID = RobotArray[i].getID ();
     attackID = minID;
   }
}
   }
 //cout << "Robot " << id << " will attack Robot " << attackID << endl;        // displays the robot closest to the current robot
}



void
Robots::getPosition (double posarray[2])
{
 posarray[0] = xPos;
 posarray[1] = yPos;
}

Robots::Robots (int base, int type)
{

 Damage = 0;
 Armor = 0;
 AttackSpeed = 0;

 switch (base)	 // base right now is just used to give the robots different types
   {
   case 0:
     Health = 2000;
     MaxHealth = 2000;
     MoveSpeed = 100;
     Weight = 7;
     MaxWeight = 20;
     xPos = -500;
     yPos = -500;
     range = 0;
     RobotType = 5;
     break;
   case 1:
     Health = 1000;
     MaxHealth = 1000;
     MoveSpeed = 100;
     Weight = 7;
     MaxWeight = 20;
     xPos = 21;
     yPos = 35;
     range = 500;
     RobotType = 1;
     break;
   case 2:
     Health = 1000;
     MaxHealth = 1000;
     MoveSpeed = 100;
     Weight = 7;
     MaxWeight = 20;
     xPos = 77;
     yPos = 98;
     range = 500;
     RobotType = 1;
     break;
   case 3:
     Health = 1000;
     MaxHealth = 1000;
     MoveSpeed = 100;
     Weight = 7;
     MaxWeight = 20;
     xPos = 111;
     yPos = 42;
     range = 500;
     RobotType = 0;
   }
 if (type == 1)
   {
     id = RobotArray.size () + 1;
     RobotArray.push_back (*this);
     cout << "Current Position of Robot " << id << " is " << xPos << "," <<
yPos << endl;
   }
}

void
Robots::calcTargets ()	 // determines which robots the current object can attack
{
 distance = 0;
 double pos[2];
 double temp[2];


 getPosition (pos);
 RobotArray[attackID - 1].getPosition (temp);
 distance = sqrt (pow ((temp[0] - pos[0]), 2) + pow ((temp[1] - pos[1]), 2));
 move (distance, temp);
 //cout<<"Current Position of Robot "<<id<<" is "<<xPos<<","<<yPos<<endl;
 //cout<<"Current distance is "<<distance<<endl;
 //cout<<"Current attack range is "<<range<<endl;


}

void
Robots::move (float distance, double temp[2])
{

 double xDif = temp[0] - xPos;
 double yDif = temp[1] - yPos;


 if (xDif == 0)
   {
     yPos += MoveSpeed * 0.05;
   }
 else
   {
     double slope = yDif / xDif;
     double angle = fabs (atan (slope));

     if ((xDif > 0) && (yDif > 0))
{
 xPos += MoveSpeed * cos (angle) * 0.005;
 yPos += MoveSpeed * sin (angle) * 0.005;
}
     else if ((xDif < 0) && (yDif > 0))
{
 xPos -= MoveSpeed * cos (angle) * 0.005;
 yPos += MoveSpeed * sin (angle) * 0.005;
}
     else if ((xDif > 0) && (yDif < 0))
{
 xPos += MoveSpeed * cos (angle) * 0.005;
 yPos -= MoveSpeed * sin (angle) * 0.005;
}
     else
{
 xPos -= MoveSpeed * cos (angle) * 0.005;
 yPos -= MoveSpeed * sin (angle) * 0.005;
}
   }

}

float
Robots::getHealth ()
{
 return RobotArray[id - 1].Health;
}

float
Robots::getMaxHealth ()
{
 return RobotArray[id - 1].MaxHealth;
}

float
Robots::getArmor ()
{
 return RobotArray[id - 1].Armor;
}

float
Robots::getDamage ()
{
 return RobotArray[id - 1].Damage;
}

float
Robots::getMoveSpeed ()
{
 return RobotArray[id - 1].MoveSpeed;
}

float
Robots::getXPos ()
{
 return RobotArray[id - 1].xPos;
}

float
Robots::getYPos ()
{
 return RobotArray[id - 1].yPos;
}

void
Robots::printStats ()	 // displays the current state of the current object
{

 if (RobotArray[id - 1].getRobotType () == 1)
   {
     cout << "Enemy robot has " << RobotArray[id -
      1].Health << "/" <<
RobotArray[id - 1].MaxHealth << " health and " << RobotArray[id -
    1].Armor
<< " armor and does " << RobotArray[id -
   1].Damage <<
" damage per attack and can move at " << RobotArray[id -
   1].MoveSpeed <<
" units per second and is at position " << RobotArray[id -
     1].xPos << ","
<< RobotArray[id - 1].yPos << endl;
   }
 else if (RobotArray[id - 1].getRobotType () == 0)
   {
     cout << "Friendly robot has " << RobotArray[id -
 1].Health << "/" <<
RobotArray[id - 1].MaxHealth << " health and " << RobotArray[id -
    1].Armor
<< " armor and does " << RobotArray[id -
   1].Damage <<
" damage per attack and can move at " << RobotArray[id -
   1].MoveSpeed <<
" units per second and is at position " << RobotArray[id -
     1].xPos << ","
<< RobotArray[id - 1].yPos << endl;
   }
}

void
Robots::addWeapons (int wepNum)	// adds the weapon to the current robot
{

 switch (wepNum)
   {

   case 1:

     RobotArray[id - 1].Damage = 100;
     RobotArray[id - 1].AttackSpeed = .5;
     RobotArray[id - 1].Weight += 2;
     break;
   case 2:

     RobotArray[id - 1].Damage = 80;
     RobotArray[id - 1].AttackSpeed = .35;
     RobotArray[id - 1].Weight += 1;
     break;
   case 3:

     RobotArray[id - 1].Damage = 105;
     RobotArray[id - 1].AttackSpeed = .55;
     RobotArray[id - 1].Weight += 4;
     break;

   }
 MoveSpeed -= Weight;

}


void
Robots::addArmor (int armorNum)	// adds the armour to the current robot
{
 switch (armorNum)
   {

   case 1:

     RobotArray[id - 1].Armor = 15;
     RobotArray[id - 1].Weight += 3;
     break;
   case 2:

     RobotArray[id - 1].Armor = 10;
     RobotArray[id - 1].Weight += 1;
     break;
   case 3:

     RobotArray[id - 1].Armor = 25;
     RobotArray[id - 1].Weight += 6;
     break;
   }


}


float
Robots::dealDamage (Robots ElRobot)
{

 float Damage = getDamage ();
 return Damage;


}

void
Robots::checkAttack ()
{

 if (distance < range)
   {

     float Damage = dealDamage (RobotArray[attackID]);
     RobotArray[attackID - 1].Health -= Damage;

   }


}

void
Robots::drawRobot (vector < SDL_Surface * >SurfaceArray)
{

 int x = getXPos ();
 int y = getYPos ();
 int type = getRobotType ();
 cout << x << " " << y << " " << type << endl;

 if (type == 1)
   {
     apply_surface (x, y, SurfaceArray[7], SurfaceArray[6]);
     if (RobotArray[id - 1].Health / MaxHealth > .75)
{
 apply_surface (x + 10, y - 20, SurfaceArray[0], SurfaceArray[6]);
}
     else if (RobotArray[id - 1].Health / MaxHealth > .50)
{
 apply_surface (x + 10, y - 20, SurfaceArray[1], SurfaceArray[6]);
}
     else if (RobotArray[id - 1].Health / MaxHealth > .25)
{
 apply_surface (x + 10, y - 20, SurfaceArray[2], SurfaceArray[6]);
}
     else
{
 apply_surface (x + 10, y - 20, SurfaceArray[3], SurfaceArray[6]);
}
     SDL_Flip (SurfaceArray[6]);
   }
 else if (type == 0)
   {
     apply_surface (x, y, SurfaceArray[8], SurfaceArray[6]);
     if (RobotArray[id - 1].Health / MaxHealth > .75)
{
 apply_surface (x + 10, y - 20, SurfaceArray[0], SurfaceArray[6]);
}
     else if (RobotArray[id - 1].Health / MaxHealth > .50)
{
 apply_surface (x + 10, y - 20, SurfaceArray[1], SurfaceArray[6]);
}
     else if (RobotArray[id - 1].Health / MaxHealth > .25)
{
 apply_surface (x + 10, y - 20, SurfaceArray[2], SurfaceArray[6]);
}
     else
{
 apply_surface (x + 10, y - 20, SurfaceArray[3], SurfaceArray[6]);
}
     SDL_Flip (SurfaceArray[6]);
   }


}

void
Robots::runAI (vector < SDL_Surface * >SurfaceArray)
{

 calcDistance ();
 calcTargets ();
 checkAttack ();
 checkDead ();
 drawRobot (SurfaceArray);
 printStats ();
 cout << endl;

}

void
Robots::checkDead ()
{

 for (int i = 0; i < RobotArray.size (); i++)
   {
     if (RobotArray[i].getHealth () <= 0)
{

 cout << "Dead" << endl;
 RobotArray.erase (RobotArray.begin () + i);
}
   }
}



void
Robots::play (vector < SDL_Surface * >SurfaceArray)
{
 for (int i = 1; i < RobotArray.size (); i++)
   {
     RobotArray[i].runAI (SurfaceArray);
   }
 apply_surface (0, 0, SurfaceArray[4], SurfaceArray[6]);
 SDL_Flip (SurfaceArray[6]);

}
