#ifndef DEFS_H
#define DEFS_H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CENTER_WIDTH = SCREEN_WIDTH / 2;
const int CENTER_HEIGHT = SCREEN_HEIGHT / 2;

#define MAX_ENTITIES 5000

#define COMP_POSITION_FLAG (1 << 0)
#define COMP_VELOCITY_FLAG (1 << 1)
#define COMP_COLOR_FLAG (1 << 2)
#define COMP_ROUND_FLAG (1 << 3)
#define COMP_TRIANGLE_FLAG (1 << 4)
#define COMP_SQUARE_FLAG (1 << 5)

#endif
