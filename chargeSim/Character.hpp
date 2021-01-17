// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "EventCollector.hpp"
#include "SDL.h"

namespace PhysicsGame {

class Character{
private:
   // radius of circle and acceleration magnitude
   float radius = 0;
   float acceleration = 0;
   float diagAccel = 0;

   // position, velocity, acceleration
   float xPos = 0;
   float yPos = 0;
   float xVel = 0;
   float yVel = 0;
   float xAcc = 0;
   float yAcc = 0;

   // time in milliseconds since SDL initialized
   Uint32 sdlTime = 0;

   // map boundaries
   float xMinPos = 0;
   float xMaxPos = 0;
   int xPixels = 0;
   float yMaxPos = 0;
   float yMinPos = 0;
   int yPixels = 0;


public:
   // Constructor
   Character( float radius, float acceleration,
              float xPosInitial, float yPosInitial,
              float fWidth, float fHeight,
              int sWidth, int sHeight );

   // Main functionality
   void update( EventCollector *collector );
   void draw( SDL_Renderer *renderer );

   // Helpers
   void drawCircle( int x, int y, int radius, SDL_Renderer *renderer );

}; //class Character

} // namespace PhysicsGame
#endif // CHARACTER_HPP
