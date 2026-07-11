#include <stdio.h>
#include <stdint.h>
struct TimerWord {
    union {
        uint16_t packed;
        struct { unsigned ticks:10; unsigned prescale:3; unsigned enabled:1; unsigned mode:2; };
    };
};
int main(void) {
    struct TimerWord tw = {.ticks=512, .prescale=3, .enabled=1, .mode=2};
    printf("c1115 timer=%u,%u,%u\n", (unsigned)tw.ticks, (unsigned)tw.enabled, (unsigned)tw.packed);
    return !(tw.ticks == 512 && tw.enabled == 1);
}
