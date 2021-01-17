// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

// Library functions
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "stdio.h"

// My functions
#include "GameScreen.hpp"

//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
   PhysicsGame::Screen *gs = new PhysicsGame::Screen( SCREEN_WIDTH, SCREEN_HEIGHT );

   while( !gs->shouldQuit() ) {
      gs->drawDot();
   }

   delete gs;
   return EXIT_SUCCESS;
}

//int WinMain() {
//   return main();
//}

int SDL_main() {
   return main();
}
