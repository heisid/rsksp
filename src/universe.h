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
  SquareComp square[MAX_ENTITIES];

} Universe;

bool hasComponent(Universe *universe, unsigned int entityId,
                  unsigned int componentFlag);

#endif
