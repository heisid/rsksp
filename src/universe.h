#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "components.h"
#include "defs.h"
#include <stdbool.h>

typedef struct {
  unsigned int entityCount;
  bool active[MAX_ENTITIES];
  unsigned int mask[MAX_ENTITIES];
  PositionComp position[MAX_ENTITIES];
  VelocityComp velocity[MAX_ENTITIES];
  ColorComp color[MAX_ENTITIES];
  RoundComp round[MAX_ENTITIES];
  TriangleComp triangle[MAX_ENTITIES];
  RectangleComp rectangle[MAX_ENTITIES];

} Universe;

bool hasComponent(Universe *universe, EntityId id, unsigned int componentFlag);

EntityId createEntity(Universe *universe);
void killEntity(Universe *universe, EntityId id);
void resurectEntity(Universe *universe, EntityId id);

void attachPosition(Universe *universe, EntityId id, Vector2 position);
void attachVelocity(Universe *universe, EntityId id, Vector2 velocity);
void attachColor(Universe *universe, EntityId id, Color color);
void attachCircle(Universe *universe, EntityId id, float radius);
void attachTriangle(Universe *universe, EntityId id, Vector2 a, Vector2 b,
                    Vector2 c);
void attachRectangle(Universe *universe, EntityId id, float width,
                     float height);

#endif
