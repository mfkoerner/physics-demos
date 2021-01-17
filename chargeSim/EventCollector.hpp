// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#ifndef EVENT_COLLECTOR_HPP
#define EVENT_COLLECTOR_HPP

#include "SDL.h"

namespace PhysicsGame {

class EventCollector {
private:
   // Individual button presses
   bool left_pressed;
   bool right_pressed;
   bool up_pressed;
   bool down_pressed;

public:
   EventCollector();
   void addIfImportant( SDL_Event event );

   // getters
   bool left() { return left_pressed; }
   bool right() { return right_pressed; }
   bool up() { return up_pressed; }
   bool down() { return down_pressed; }
}; // class EventCollector

} // namespace PhysicsGame
#endif // EVENT_COLLECTOR_HPP
