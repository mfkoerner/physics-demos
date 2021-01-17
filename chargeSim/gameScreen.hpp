// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
#include "SDL.h"

namespace GameScreen {

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

} // namespace GameScreen
