// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include "Character.hpp"
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

   // objects
   PhysicsGame::Character *character = NULL;

public:
   // Constructor and Destructor
   Screen( int width, int height );
   ~Screen();
   void draw( int x, int y ); // FIXME no coords
   void update();
   void drawDot(); // FIXME experimental
   bool shouldQuit();
}; // class Screen

} // namespace PhysicsGame
#endif // GAME_SCREEN_HPP
