#include <stdio.h>
#include <string.h>
#include "point.h"

// Size of my array
#define N 5

void print_result(const point *a, ssize_t r) {
  printf("return value %zd\n", r);
  for (ssize_t i = 0; i < r; i++) {
    printf("(%d, %d)\n", a[i].x, a[i].y);
  }
}

int main(void)
{
  point a[N];
  ssize_t r;

  printf("Testing binary read\n");
  memset(a, 0, sizeof(a));
  r = load_points("sample-binary", a, N);
  print_result(a, r);

  printf("Testing free-formatted read\n");
  memset(a, 0, sizeof(a));
  r = scan_points("sample-free.txt", a, N);
  print_result(a, r);

  return 0;
}
