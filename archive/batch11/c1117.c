#include <stdio.h>
#include <stdint.h>
struct MotorCmd {
    union {
        uint16_t word;
        struct { unsigned speed:8; unsigned dir:1; unsigned brake:1; unsigned reserved:6; };
    };
};
int main(void) {
    struct MotorCmd cmd = {.speed=200, .dir=1, .brake=0};
    cmd.speed = (unsigned)(cmd.speed / 2);
    printf("c1117 motor=%u,%u,%u\n", (unsigned)cmd.speed, (unsigned)cmd.dir, (unsigned)cmd.brake);
    return !(cmd.speed == 100 && cmd.dir == 1 && cmd.brake == 0);
}
