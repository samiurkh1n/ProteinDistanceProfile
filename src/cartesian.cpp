#include "cartesian.h"

double distance(const Coordinate& first, const Coordinate& second) {
  double diff_x = std::abs(first.x - second.x);
  double diff_y = std::abs(first.y - second.y);
  double diff_z = std::abs(first.z - second.z);
  return sqrt((diff_x * diff_x) + (diff_y * diff_y) + (diff_z * diff_z));
}
