#include "universe.h"
#include "defs.h"

bool hasComponent(Universe *universe, unsigned int entityId,
                  unsigned int componentFlag) {
  return (universe->mask[entityId] & componentFlag) != 0;
}

EntityId createEntity(Universe *universe) {
  EntityId id = universe->entityCount++;
  universe->active[id] = true;
  return id;
}

void killEntity(Universe *universe, EntityId id) {
  universe->active[id] = false;
}

void resurectEntity(Universe *universe, EntityId id) {
  universe->active[id] = true;
}

void attachPosition(Universe *universe, EntityId id, Vector2 position) {
  universe->mask[id] |= COMP_POSITION_FLAG;
  universe->position[id].position = position;
}

void attachVelocity(Universe *universe, EntityId id, Vector2 velocity) {
  universe->mask[id] |= COMP_VELOCITY_FLAG;
  universe->position[id].position = velocity;
}

void attachColor(Universe *universe, EntityId id, Color color) {
  universe->mask[id] |= COMP_COLOR_FLAG;
  universe->color[id].color = color;
}

void attachCircle(Universe *universe, EntityId id, float radius) {
  universe->mask[id] =
      (~(COMP_TRIANGLE_FLAG | COMP_RECTANGLE_FLAG)) | COMP_CIRCLE_FLAG;
  universe->round[id].radius = radius;
}

void attachTriangle(Universe *universe, EntityId id, Vector2 a, Vector2 b,
                    Vector2 c) {
  universe->mask[id] =
      (~(COMP_CIRCLE_FLAG | COMP_RECTANGLE_FLAG)) | COMP_TRIANGLE_FLAG;
  universe->triangle[id].a = a;
  universe->triangle[id].b = b;
  universe->triangle[id].c = c;
}
