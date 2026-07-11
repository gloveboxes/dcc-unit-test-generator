#include <stdio.h>

enum MessageType { MESSAGE_TEXT, MESSAGE_CODE };
struct Message { enum MessageType type; union { struct { char text[8]; }; int code; }; };
int main(void)
{
    struct Message messages[2] = {{MESSAGE_TEXT, {.text = {'O','K','\0'}}}, {MESSAGE_CODE, {.code = 404}}};
    printf("c1114 message=%s/%d\n", messages[0].text, messages[1].code);
    return 0;
}
