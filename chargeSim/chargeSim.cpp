// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com

// Library functions
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "stdio.h"

// My functions
#include "gameScreen.hpp"

//Screen dimension constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
   PhysicsGame::Screen *gs = new PhysicsGame::Screen( SCREEN_WIDTH, SCREEN_HEIGHT );

   gs->draw( 300, 100 );
   SDL_Delay( 2000 );
   gs->draw( 250, 0 );
   SDL_Delay( 2000 );
   gs->draw( 0, 300 );
   SDL_Delay( 2000 );
   while( 1 ) {
      if ( gs->shouldQuit() ) break;
      gs->draw( 50, 100 );
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
