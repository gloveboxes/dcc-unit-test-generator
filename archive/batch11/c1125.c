#include <stdio.h>
#include <stdint.h>
struct EepromSlot {
    uint8_t flags;
    union {
        struct { uint8_t major; uint8_t minor; };
        uint16_t version;
    };
    uint16_t checksum;
};
int main(void) {
    struct EepromSlot slot = {.flags=0x01U, .major=3, .minor=7, .checksum=0};
    slot.checksum = (uint16_t)(slot.flags + slot.major + slot.minor);
    printf("c1125 eeprom=%u.%u,%u\n", (unsigned)slot.major, (unsigned)slot.minor, (unsigned)slot.checksum);
    return !(slot.major==3 && slot.minor==7 && slot.checksum==11U);
}
