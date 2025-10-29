#include "system.h"
#include <raylib.h>
#include <raymath.h>

void updatePosition(Universe *universe) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (!hasComponent(universe, i, COMP_VELOCITY_FLAG))
      continue;

    float dt = GetFrameTime();
    Vector2 heading = Vector2Scale(universe->velocity[i].velocity, dt);
    universe->position[i].position =
        Vector2Add(universe->position[i].position, heading);
  }
}

void renderEntities(Universe *universe) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    bool isRenderable = hasComponent(
        universe, i, COMP_ROUND_FLAG | COMP_TRIANGLE_FLAG | COMP_SQUARE_FLAG);
    if (!isRenderable)
      continue;

    Color color = WHITE;
    if (hasComponent(universe, i, COMP_COLOR_FLAG))
      color = universe->color[i].color;

    switch (universe->mask[i]) {
    case COMP_ROUND_FLAG:
      if (!hasComponent(universe, i, COMP_POSITION_FLAG))
        break;
      Vector2 position = universe->position[i].position;
      float radius = universe->round[i].radius;
      DrawCircle(position.x, position.y, radius, color);
      break;
    }
  }
}
