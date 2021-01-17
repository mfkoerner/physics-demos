// Author:  Mitchell Koerner
// Email:   mfkoerner@gmail.com
// Copyright (c) 2021 Mitchell Koerner

#include "EventCollector.hpp"
#include "SDL.h"

namespace PhysicsGame {

EventCollector::EventCollector() {
   clearEvents();
}

void
EventCollector::clearEvents() {
   left_pressed = false;
   right_pressed = false;
   up_pressed = false;
   down_pressed = false;
}

void
EventCollector::addIfImportant( SDL_Event event ) {
   // stub
}

} // namespace PhysicsGame
