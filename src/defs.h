#ifndef DEFS_H
#define DEFS_H

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int CENTER_WIDTH;
extern const int CENTER_HEIGHT;

typedef unsigned int EntityId;

#define MAX_ENTITIES 5000

#define COMP_POSITION_FLAG (1 << 0)
#define COMP_VELOCITY_FLAG (1 << 1)
#define COMP_COLOR_FLAG (1 << 2)
#define COMP_CIRCLE_FLAG (1 << 3)
#define COMP_TRIANGLE_FLAG (1 << 4)
#define COMP_RECTANGLE_FLAG (1 << 5)

#endif
