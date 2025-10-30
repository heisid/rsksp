#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "system.h"
#include "universe.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RSKSP");

  Universe *universe = createUniverse();

  for (int i=0; i<20; i++) {
    EntityId entity = createEntity(universe);
    int posX = rand() % SCREEN_WIDTH + 1;
    int posY = rand() % SCREEN_HEIGHT + 1;
    Vector2 a = {posX, posY};
    Vector2 b = {posX+25, posY-50};
    Vector2 c = {posX-25, posY-50};
    attachTriangle(universe, entity, a, b, c);
    attachColor(universe, entity, RED);
  }

  while (!WindowShouldClose()) {
    updatePosition(universe);
    BeginDrawing();
    ClearBackground(BLACK);

    // DrawText("Setup test...", CENTER_WIDTH, CENTER_HEIGHT, 12, WHITE);
    renderEntities(universe);

    EndDrawing();
  }

  free(universe);
  return EXIT_SUCCESS;
}
