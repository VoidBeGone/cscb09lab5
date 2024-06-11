#include <stdio.h>
#include "point.h"

ssize_t save_points(const char *pathname, const point *a, size_t n) {
 	FILE *f = NULL;
	f = fopen(pathname, "r+w");
	if (f == NULL) return -1;
	int num = fwrite(a, sizeof(point), n, f);
	fclose(f);
	return num;
}

ssize_t load_points(const char *pathname, point *a, size_t n) {
	FILE *f = NULL;
	f = fopen(pathname, "r+w");
	if (f == NULL) return -1;
	int num = fread(a, sizeof(point), n, f);
	fclose(f);
	return num;
}

ssize_t scan_points(const char *pathname, point *a, size_t n) {
	FILE *f = NULL;
	f = fopen(pathname, "r");
	if (f == NULL) return -1;
	int help;
	int help2;
	int num = 0;
	while ( fscanf(f,"%d %d", &help, &help2 ) == 2){
		//okay now we are reading things one at a time
		point helper = {help, help2};
		*a = helper;
		a++;
		num++;
	}
	return num;
}
