// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "SDL.h"

namespace PhysicsGame {

class Screen {
private:
   // Screen properties
   int sWidth = 0;
   int sHeight = 0;

   // SDL variables
   SDL_Event event;
   SDL_Renderer *renderer = NULL;
   SDL_Window *window = NULL;

public:
   // Constructor and Destructor
   Screen( int width, int height );
   ~Screen();
   void draw( int x, int y );
   bool shouldQuit();
}; // class Screen

} // namespace PhysicsGame
