#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "system.h"
#include "universe.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RSKSP");

  Universe *universe = malloc(sizeof(Universe));
  EntityId testEntity = createEntity(universe);
  printf("created entityId: %u\n", testEntity);
  attachCircle(universe, testEntity, 20);
  printf("flag after attach c-comp: %u\n", universe->mask[testEntity]);
  attachColor(universe, testEntity, RED);
  Vector2 position = {CENTER_WIDTH, CENTER_HEIGHT};
  attachPosition(universe, testEntity, position);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    // DrawText("Setup test...", CENTER_WIDTH, CENTER_HEIGHT, 12, WHITE);
    renderEntities(universe);

    EndDrawing();
  }

  free(universe);
  return EXIT_SUCCESS;
}
