#pragma once

#include "berzerk/point.hpp"

#define RENDER_WIDTH (400)
#define RENDER_HEIGHT (300)
#define RENDER_SCALE (2)

namespace Berzerk {

// Returns the position of the camera.
Point getCameraPos();

// Sets the position of the camera.
void setCameraPos(const Point& pos);

// Recenters the position of the camera.
void recenterCamera();

void drawWalls();

}  // namespace Berzerk
