#ifndef ENVIRONMENT_CONSTANTS_H
#define ENVIRONMENT_CONSTANTS_H

// Display parameters
#define SCREEN_SIZE          (640)                       // Unit: pixel
#define ENVIRONMENT_SIZE     (540)                       // Unit: pixel
#define ENVIRONMENT_ORIGIN_X (50)                        // Unit: pixel
#define ENVIRONMENT_ORIGIN_Y (80)                        // Unit: pixel
#define DOT_DIAMETER         (30)                        // Unit: pixel
#define DOT_RADIUS           (DOT_DIAMETER / 2)          // Unit: pixel
#define TITLE_POSITION_X     (130)                       // Unit: pixel
#define TITLE_POSITION_Y     (15)                        // Unit: pixel
#define TITLE_FONT_SIZE      (16)                        // Unit: pixel
#define AXIS_LABEL_FONT_SIZE (8)                         // Unit: pixel
#define AXIS_LABEL_ORIGIN_X  (ENVIRONMENT_ORIGIN_X)      // Unit: pixel
#define AXIS_LABEL_ORIGIN_Y  (ENVIRONMENT_ORIGIN_Y - 20) // Unit: pixel
#define ENVIRONMENT_MAP_SIZE (10)                        // Size of the square environment map

// Movement parameters
#define MOVEMENT_DURATION_MS (1000)                      // Unit: millisecond
#define MOVEMENT_INTERVAL_MS (100)                       // Unit: millisecond
#define MOVEMENT_STEP        (ENVIRONMENT_SIZE / 9)      // Unit: pixel

// Graph parameters
#define HIGHEST_GRAPH_VERTEX (99)                        // Format: 2-digit XY vertex

#endif