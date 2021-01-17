// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "GameScreen.hpp"
#include "SDL.h"

namespace PhysicsGame {

Screen::Screen( int width, int height ) {
   sWidth = width;
   sHeight = height;

   // Initialize SDL
   SDL_Init( SDL_INIT_VIDEO );
   SDL_CreateWindowAndRenderer( width, height, 0, &window, &renderer );
}

Screen::~Screen() {
   // Clean up SDL objects
   SDL_DestroyRenderer( renderer );
   SDL_DestroyWindow( window );
   SDL_Quit();
}

void
Screen::draw( int xmin, int ymin ) {
   SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
   SDL_RenderClear( renderer );
   SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

   // render a box
   for ( int x = xmin; x < xmin+100; ++x ) {
      for ( int y = ymin; y < ymin+100; ++y ) {
         SDL_RenderDrawPoint( renderer, x, y );
      }
   }

   // update screen
   SDL_RenderPresent( renderer );
}

bool
Screen::shouldQuit() {
   return SDL_PollEvent( &event ) && event.type == SDL_QUIT;
}

} // namespace PhysicsGame
