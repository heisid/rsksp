#include "universe.h"
#include "defs.h"

bool hasComponent(Universe *universe, unsigned int entityId,
                  unsigned int componentFlag) {
  return (universe->mask[entityId] & componentFlag) != 0;
}

void activateEntity(Universe *universe, unsigned int entityId) {
  universe->active[entityId] = true;
}

void deactivateEntity(Universe *universe, unsigned int entityId) {
  universe->active[entityId] = false;
}

void setPosition(Universe *universe, unsigned int entityId, Vector2 position) {
  universe->mask[entityId] |= COMP_POSITION_FLAG;
  universe->position[entityId].position = position;
}

void setVelocity(Universe *universe, unsigned int entityId, Vector2 velocity) {
  universe->mask[entityId] |= COMP_VELOCITY_FLAG;
  universe->position[entityId].position = velocity;
}

void setRound(Universe *universe, unsigned int entityId, unsigned int radius) {
  universe->mask[entityId] =
      (~(COMP_TRIANGLE_FLAG | COMP_SQUARE_FLAG)) | COMP_ROUND_FLAG;
  universe->round[entityId].radius = radius;
}

void setTriangle(Universe *universe, unsigned int entityId, Vector2 a,
                 Vector2 b, Vector2 c) {
  universe->mask[entityId] =
      (~(COMP_ROUND_FLAG | COMP_SQUARE_FLAG)) | COMP_TRIANGLE_FLAG;
  universe->triangle[entityId].a = a;
  universe->triangle[entityId].b = b;
  universe->triangle[entityId].c = c;
}
