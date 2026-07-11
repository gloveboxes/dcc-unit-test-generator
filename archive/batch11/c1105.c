#include <stdio.h>
#include <stdint.h>
struct SensorReading {
    uint16_t id;
    union {
        struct { int16_t temperature; int16_t humidity; };
        struct { uint16_t raw_hi; uint16_t raw_lo; };
    };
};
int main(void) {
    struct SensorReading r = {.id=42, .temperature=235, .humidity=600};
    int16_t t = r.temperature;
    r.temperature = (int16_t)(r.temperature - 273);
    printf("c1105 sensor=%u,%d,%d\n", (unsigned)r.id, (int)r.temperature, (int)r.humidity);
    return !(r.id==42 && r.temperature==-38 && r.humidity==600);
}
