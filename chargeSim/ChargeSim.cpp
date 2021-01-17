// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

// Library functions
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "stdio.h"

// My functions
#include "GameScreen.hpp"
#include "EventCollector.hpp"

//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
   PhysicsGame::EventCollector *eventCollector = new PhysicsGame::EventCollector();
   PhysicsGame::Screen *screen = new PhysicsGame::Screen( SCREEN_WIDTH, SCREEN_HEIGHT );

   bool quit = false;
   SDL_Event event;

   while ( !quit ) {
      eventCollector->clearEvents();
      // Hanle every event on the queue
      while( SDL_PollEvent( &event ) != 0 ) {
         // Handle quit request
         if ( event.type == SDL_QUIT ) {
            quit = true;
         }
         
         // Collect imporant events
         eventCollector->addIfImportant( event );
      }
      
      // Pass collected events to screen for handling
      screen->update( eventCollector );
   }

   delete screen;
   delete eventCollector;
   return EXIT_SUCCESS;
}

//int WinMain() {
//   return main();
//}

int SDL_main() {
   return main();
}
