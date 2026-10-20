#pragma once

#include "berzerk/point.hpp"

#define RENDER_WIDTH (256)
#define RENDER_HEIGHT (224)
#define RENDER_SCALE (2)

namespace Berzerk {

// Returns the position of the camera.
Point getCameraPos();

// Sets the position of the camera.
void setCameraPos(const Point& pos);

// Recenters the position of the camera.
void recenterCamera();

// Draws the map to the screen.
void drawWalls();

// Draws all objects to the screen.
void drawObjects();

}  // namespace Berzerk
