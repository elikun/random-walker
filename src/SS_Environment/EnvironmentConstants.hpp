#ifndef ENVIRONMENT_CONSTANTS_H
#define ENVIRONMENT_CONSTANTS_H

#include <QtGlobal>

// Display constants
const qreal SCREEN_SIZE = 640;                               // Unit: pixel
const qreal ENVIRONMENT_SIZE = 540;                          // Unit: pixel
const qreal ENVIRONMENT_ORIGIN_X = 50;                       // Unit: pixel
const qreal ENVIRONMENT_ORIGIN_Y = 80;                       // Unit: pixel
const int ENVIRONMENT_MAP_SIZE = 10;                         // Size of the square environment map

// Dot dimension
const qreal DOT_DIAMETER = 30;                               // Unit: pixel
const qreal DOT_RADIUS = DOT_DIAMETER / 2;                   // Unit: pixel

// Title constants
const qreal TITLE_POSITION_X = 210;                          // Unit: pixel
const qreal TITLE_POSITION_Y = 15;                           // Unit: pixel
const qreal TITLE_FONT_SIZE = 16;                            // Unit: pixel

// Axis labels constants
const int AXIS_LABEL_FONT_SIZE = 8;                          // Unit: pixel
const qreal AXIS_LABEL_ORIGIN_X = ENVIRONMENT_ORIGIN_X;      // Unit: pixel
const qreal AXIS_LABEL_ORIGIN_Y = ENVIRONMENT_ORIGIN_Y - 20; // Unit: pixel

// Movement constants
const int MOVEMENT_DURATION_MS = 1000;                       // Unit: millisecond
const int MOVEMENT_INTERVAL_MS = 100;                        // Unit: millisecond
const qreal MOVEMENT_STEP = ENVIRONMENT_SIZE / 9;            // Unit: pixel

// Undirected graph constants
const int HIGHEST_GRAPH_VERTEX = 99;                         // Format: 2-digit XY vertex

#endif