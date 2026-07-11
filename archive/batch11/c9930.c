#include <stdio.h>
#include <stdint.h>
struct Coord { int16_t lat_deg; int16_t lon_deg; };
static int32_t box_area(const struct Coord *corners, int n) {
    int min_lat = corners[0].lat_deg, max_lat = corners[0].lat_deg;
    int min_lon = corners[0].lon_deg, max_lon = corners[0].lon_deg;
    for (int i = 1; i < n; i++) {
        if (corners[i].lat_deg < min_lat) min_lat = corners[i].lat_deg;
        if (corners[i].lat_deg > max_lat) max_lat = corners[i].lat_deg;
        if (corners[i].lon_deg < min_lon) min_lon = corners[i].lon_deg;
        if (corners[i].lon_deg > max_lon) max_lon = corners[i].lon_deg;
    }
    return (int32_t)(max_lat - min_lat) * (max_lon - min_lon);
}
int main(void) {
    struct Coord pts[4] = {{10,20},{10,50},{30,20},{30,50}};
    int32_t area = box_area(pts, 4);
    printf("c9930 area=%ld\n", (long)area);
    return area != 600L;
}
