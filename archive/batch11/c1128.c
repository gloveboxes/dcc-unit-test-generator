#include <stdio.h>
#include <stdint.h>
struct UsbDescriptor {
    uint8_t length;
    uint8_t type;
    union {
        struct { uint16_t bcd; uint8_t device_class; uint8_t subclass; uint8_t protocol; };
        uint8_t raw[5];
    };
};
int main(void) {
    struct UsbDescriptor d = {.length=18,.type=1,.bcd=0x0200U,.device_class=0,.subclass=0,.protocol=0};
    uint16_t sum = 0;
    for (int i = 0; i < 5; i++) sum = (uint16_t)(sum + d.raw[i]);
    printf("c1128 usb=%u,%04x\n", (unsigned)d.length, (unsigned)d.bcd);
    return !(d.length==18 && d.bcd==0x0200U);
}
