// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "Character.hpp"
#include "SDL.h"

namespace PhysicsGame {

Character::Character( SDL_Renderer *renderer_,
                      float radius_, float acceleration_,
                      float xPosInitial, float yPosInitial,
                      float fWidth, float fHeight,
                      int sWidth, int sHeight ) {
   renderer = renderer_;
   radius = radius_;
   acceleration = acceleration_;
   xPos = xPosInitial;
   yPos = yPosInitial;
   xMinPos = -0.5 * fWidth;
   xMaxPos =  0.5 * fWidth;
   yMinPos = -0.5 * fHeight;
   yMaxPos =  0.5 * fHeight;
   xPixels = sWidth;
   yPixels = sHeight;
}

void
Character::update() {
   // get time info from caller (possibly as argument)
   // get inputs from mouse
   // update position based on velocity and boundary conditions
   // update velocity based on acceleration and boundary conditions
   // update acceleration based on mouse inputs (and position)
}

void
Character::draw() {
   // possibly calculate radius in pixels (or keep this constant)
   // calculate centerX and centerY in pixels from xPos and yPos (float)
   // call drawCircle
}

void
Character::drawCircle( int centerX, int centerY, int radius ) {
   // SDL refresh screen
   SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
   SDL_RenderClear( renderer );
   SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

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

   // SDL update screen
   SDL_RenderPresent( renderer );
}

} // namespace PhysicsGame
