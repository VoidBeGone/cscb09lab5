#ifndef POINT_H
#define POINT_H

#include <stddef.h>
// for size_t, ssize_t

typedef struct point {
  int x, y;
} point;

ssize_t save_points(const char *pathname, const point *a, size_t n);
ssize_t load_points(const char *pathname, point *a, size_t n);
ssize_t scan_points(const char *pathname, point *a, size_t n);

#endif  // #ifndef POINT_H
