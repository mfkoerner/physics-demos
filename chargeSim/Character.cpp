// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "Character.hpp"
#include "SDL.h"

namespace PhysicsGame {

float ONE_OVER_SQRT2 = 0.70710678118;

Character::Character( float radius_, float acceleration_,
                      float xPosInitial, float yPosInitial,
                      float fWidth, float fHeight,
                      int sWidth, int sHeight ) {
   radius = radius_;
   acceleration = acceleration_;
   diagAccel = acceleration * ONE_OVER_SQRT2;
   xPos = xPosInitial;
   yPos = yPosInitial;
   xMinPos = -0.5 * fWidth;
   xMaxPos =  0.5 * fWidth;
   yMinPos = -0.5 * fHeight;
   yMaxPos =  0.5 * fHeight;
   xPixels = sWidth;
   yPixels = sHeight;
   sdlTime = SDL_GetTicks();
}

void
Character::update( EventCollector *collector ) {

   // Update time and find time since last update
   Uint32 oldTime = sdlTime;
   sdlTime = SDL_GetTicks();
   Uint32 dt = sdlTime - oldTime;

   // update position based on velocity
   xPos += xVel * float( dt );
   yPos += yVel * float( dt );

   // update velocity based on acceleration
   xVel += xAcc * float( dt );
   yVel += yAcc * float( dt );

   // enforce boundaries
   if ( xPos + radius > xMaxPos ) {
      xPos = xMaxPos - radius;
      xVel = 0;
   }
   if ( xPos - radius < xMinPos ) {
      xPos = xMinPos + radius;
      xVel = 0;
   }
   if ( yPos + radius > yMaxPos ) {
      yPos = yMaxPos - radius;
      yVel = 0;
   }
   if ( yPos - radius > yMinPos ) {
      yPos = yMinPos + radius;
      yVel = 0;
   }

   // Enumerate on bitmap of inputs to update acceleration
   short bitmap = 0;
   short up = short( collector->up() );
   short down = short( collector->down() );
   short left = short( collector->left() );
   short right = short( collector->right() );
   bitmap = up + ( down << 1 ) + ( left << 2 ) + ( right << 3 );

   switch( bitmap ) {
      case 0b0000:
      case 0b1100:
      case 0b0011:
      case 0b1111:
            // No net direction
            xAcc = 0;
            yAcc = 0;
            break;
      case 0b1000:
      case 0b1011:
            // Net direction up
            xAcc = 0;
            yAcc = acceleration * -1;
            break;
      case 0b0100:
      case 0b0111:
            // Net direction down
            xAcc = 0;
            yAcc = acceleration;
            break;
      case 0b0010:
      case 0b1110:
            // Net direction left
            xAcc = acceleration * -1;
            yAcc = 0;
            break;
      case 0b0001:
      case 0b1101:
            // Net direction right
            xAcc = acceleration;
            yAcc = 0;
            break;
      case 0b1010:
            // Net direction up-left
            xAcc = diagAccel * -1;
            yAcc = diagAccel * -1;
            break;
      case 0b1001:
            // Net direction up-right
            xAcc = diagAccel;
            yAcc = diagAccel * -1;
            break;
      case 0b0110:
            // Net direction down-left
            xAcc = diagAccel * -1;
            yAcc = diagAccel;
            break;
      case 0b0101:
            // Net direction down-right
            xAcc = diagAccel;
            yAcc = diagAccel;
            break;
   }
}

void
Character::draw( SDL_Renderer *renderer ) {
   // possibly calculate radius in pixels (or keep this constant)
   // calculate centerX and centerY in pixels from xPos and yPos (float)
   // call drawCircle
}

void
Character::drawCircle( int centerX, int centerY, int radius,
                       SDL_Renderer *renderer ) {

   // Handle radius 1 and 2 which do not work well in algorithm manually
   if ( radius == 1 ) { // special case r=1
      SDL_RenderDrawPoint( renderer, centerX, centerY );
   } else if ( radius == 2 ) { // special case r=2
      for ( int xdiff = -1; xdiff <= 1; ++xdiff ) {
         for ( int ydiff = -1; ydiff <= 1; ++ydiff ) {
            SDL_RenderDrawPoint( renderer, centerX+xdiff, centerY+ydiff );
         }
      }

   } else { // General case

      int x = 0;
      int y = radius;
      int r2 = radius * radius;
      int offset = 0;

      while ( y >= x ) {
         // First, draw all guaranteed points in circle based on symmetry from (x,y)
         //
         // All "+" are guaranteed to be part of a circle with center 0.
         // Current point "%" is on the edge of circle in North-North-East octant
         //
         //                        (a) (b)
         //                         +   % <- (x, y) current point off of center "0"
         //                         +   +
         //                 (c) + + + + + + +
         //                         + 0 +
         //                 (d) + + + + + + +
         //                         +   +
         //                         +   +
         //                    |_ _ _ _ _ _ _| Width is -y <= offset <= y

         for( offset = -y; offset <= y; offset++ ) {
            SDL_RenderDrawPoint( renderer, centerX - x, centerY + offset ); // (a)
            SDL_RenderDrawPoint( renderer, centerX + x, centerY + offset ); // (b)
            SDL_RenderDrawPoint( renderer, centerX + offset, centerY + x ); // (c)
            SDL_RenderDrawPoint( renderer, centerX + offset, centerY - x ); // (d)
         }

         // Then, calculate next point (round by checking for y-0.5 > y_actual)
         x += 1;
         // x**2 + y_actual**2 = r**2
         while ( y*(y-1) > r2 - x*x ) { // y*(y-1) ~= (y-0.5)**2
            y -= 1;
         }
      }
   }
}

} // namespace PhysicsGame
