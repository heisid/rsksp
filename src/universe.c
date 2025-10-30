#include "universe.h"
#include "defs.h"

bool hasComponent(Universe *universe, unsigned int entityId,
                  unsigned int componentFlag) {
  return (universe->mask[entityId] & componentFlag) != 0;
}

void activateEntity(Universe *universe, EntityId id) {
  universe->active[id] = true;
}

void deactivateEntity(Universe *universe, EntityId id) {
  universe->active[id] = false;
}

void attachPosition(Universe *universe, EntityId id, Vector2 position) {
  universe->mask[id] |= COMP_POSITION_FLAG;
  universe->position[id].position = position;
}

void attachVelocity(Universe *universe, EntityId id, Vector2 velocity) {
  universe->mask[id] |= COMP_VELOCITY_FLAG;
  universe->position[id].position = velocity;
}

void attachCircle(Universe *universe, EntityId id, float radius) {
  universe->mask[id] =
      (~(COMP_TRIANGLE_FLAG | COMP_SQUARE_FLAG)) | COMP_ROUND_FLAG;
  universe->round[id].radius = radius;
}

void attachTriangle(Universe *universe, EntityId id, Vector2 a, Vector2 b,
                    Vector2 c) {
  universe->mask[id] =
      (~(COMP_ROUND_FLAG | COMP_SQUARE_FLAG)) | COMP_TRIANGLE_FLAG;
  universe->triangle[id].a = a;
  universe->triangle[id].b = b;
  universe->triangle[id].c = c;
}
