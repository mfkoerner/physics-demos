// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "Character.hpp"
#include "EventCollector.hpp"
#include "GameScreen.hpp"
#include "SDL.h"

namespace PhysicsGame {

Screen::Screen( int width, int height ) {
   sWidth = width;
   sHeight = height;

   // Initialize SDL
   SDL_Init( SDL_INIT_VIDEO );
   SDL_CreateWindowAndRenderer( width, height, 0, &window, &renderer );

   // Initialize character
   float fWidth = 100;
   float fHeight = 100 * float( height ) / float( width );

   //                                           float          pixel
   // Character( radius, acceleration, x, y, width, height, width, height )
   character = new Character( 5.0, 0.0001, 0.0, 0.0, fWidth, fHeight, width, height );
}

Screen::~Screen() {
   // Clean up SDL objects
   SDL_DestroyRenderer( renderer );
   SDL_DestroyWindow( window );
   SDL_Quit();

   // Clean up character
   delete character;
}

void
Screen::draw() {
   SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
   SDL_RenderClear( renderer );
   SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

   // draw static images (none for now)

   // draw character
   character->draw( renderer );

   // update screen
   SDL_RenderPresent( renderer );

   // What needs to be done in real version
   // draw blank (setRenderDraw->renderClear->setRenderDraw)
   // call into draw for character
   // call into draw for static objects
   // update screen
}

void
Screen::update( EventCollector *collector ) {
   // update state of character
   character->update( collector );
   // draw our new stuff
   draw();
}

} // namespace PhysicsGame
