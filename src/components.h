#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <raylib.h>

typedef struct {
  Vector2 position;
} PositionComp;

typedef struct {
  Vector2 velocity;
} VelocityComp;

typedef struct {
  Color color;
} ColorComp;

typedef struct {
  float radius;
} RoundComp;

typedef struct {
  Vector2 a;
  Vector2 b;
  Vector2 c;
} TriangleComp;

typedef struct {
  unsigned int width;
  unsigned int height;
} SquareComp;

#endif
