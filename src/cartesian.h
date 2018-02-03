// Cartesian Utilties
// Methods and functions to handle 3D coordinates

#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <cmath>
#include <stdlib.h>

struct Coordinate {
    double x;
    double y;
    double z;
};

// Returns the distance between two cartesian coordinates
double distance(const Coordinate& first, const Coordinate& second);

#endif  // CARTESIAN_H
