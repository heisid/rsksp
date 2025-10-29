#include "defs.h"
#include <raylib.h>
#include <stdlib.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RSKSP");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("Setup test...", CENTER_WIDTH, CENTER_HEIGHT, 12, WHITE);

    EndDrawing();
  }
  return EXIT_SUCCESS;
}
