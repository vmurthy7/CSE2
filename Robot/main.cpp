#include "SDL/SDL.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Robots.h"


using namespace std;

int
main (int argc, char* args[])
{

 Robots R0(0,1);
 SDL_Init (SDL_INIT_EVERYTHING);
 
 SDL_WM_SetCaption ("Robots", NULL);
 SDL_Surface *health1 = NULL;
 SDL_Surface *health2 = NULL;
 SDL_Surface *health3 = NULL;
 SDL_Surface *health4 = NULL;
 SDL_Surface *background = NULL;
 SDL_Surface *bullet = NULL;
 SDL_Surface *screen = NULL;
 SDL_Surface *robot1 = NULL;
 SDL_Surface *robot2 = NULL;  
 screen = SDL_SetVideoMode (1240, 640, 32, SDL_SWSURFACE);
 background = SDL_LoadBMP ("background.bmp");
 background = R0.load_image ("background.bmp");
 bullet = SDL_LoadBMP ("bullet.bmp");
 bullet = R0.load_image ("bullet.bmp");
 health1 = SDL_LoadBMP ("greenhealth.bmp");
 health1 = R0.load_image ("greenhealth.bmp");
 health2 = SDL_LoadBMP ("yellowhealth.bmp");
 health2 = R0.load_image ("yellowhealth.bmp");
 health3 = SDL_LoadBMP ("orangehealth.bmp");
 health3 = R0.load_image ("orangehealth.bmp");
 health4 = SDL_LoadBMP ("redhealth.bmp");
 health4 = R0.load_image ("redhealth.bmp");
 robot1 = SDL_LoadBMP ("bluebot1.bmp");
 robot1 = R0.load_image ("bluebot1.bmp");
 robot2 = SDL_LoadBMP ("redbot1.bmp");
 robot2 = R0.load_image ("redbot1.bmp");
 vector < SDL_Surface * > SurfaceArray;
 SurfaceArray.push_back(health1);
 SurfaceArray.push_back(health2);
 SurfaceArray.push_back(health3);
 SurfaceArray.push_back(health4);
 SurfaceArray.push_back(background);
 SurfaceArray.push_back(bullet);
 SurfaceArray.push_back(screen);
 SurfaceArray.push_back(robot1);
 SurfaceArray.push_back(robot2);
 R0.apply_surface (0, 0, background, screen);
 SDL_Flip (screen);
 usleep(50000);

 
 Robots R1(1,1);	
 R1.addWeapons(1);
 
 Robots R3(3,1);
 R3.addWeapons(3);
 for (int i = 0; i < 10; i++){
 R0.play(SurfaceArray);
 }
 
     	  
 



 

}
