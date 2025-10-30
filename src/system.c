#include "system.h"
#include "components.h"
#include "defs.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

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
    bool isRenderable = hasComponent(universe, i,
                                     COMP_CIRCLE_FLAG | COMP_TRIANGLE_FLAG |
                                         COMP_RECTANGLE_FLAG);
    if (!isRenderable)
      continue;

    Color color = WHITE;
    if (hasComponent(universe, i, COMP_COLOR_FLAG))
      color = universe->color[i].color;

    // printf("%u\n", universe->mask[i]);

    switch (universe->mask[i]) {
    case COMP_CIRCLE_FLAG:
      if (!hasComponent(universe, i, COMP_POSITION_FLAG))
        break;
      Vector2 position = universe->position[i].position;
      float radius = universe->round[i].radius;
      DrawCircle(position.x, position.y, radius, color);
      break;
    case COMP_TRIANGLE_FLAG:
      DrawTriangle(universe->triangle[i].a, universe->triangle[i].b,
                   universe->triangle[i].c, color);
      break;
    case COMP_RECTANGLE_FLAG:
      if (!hasComponent(universe, i, COMP_POSITION_FLAG))
        break;
      DrawRectangle(
          universe->position[i].position.x, universe->position[i].position.y,
          universe->rectangle[i].width, universe->rectangle[i].height, color);
      break;
    }
  }
}
