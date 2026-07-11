#include <stdio.h>

struct Command { char operation; int value; };

static int parse_command(const char *text, struct Command *command)
{
    int value = 0; char operation;
    if ((text[0] != 'A' && text[0] != 'S') || text[1] != ':') return 0;
    operation = text[0];
    text += 2; if (*text == '\0') return 0;
    while (*text >= '0' && *text <= '9') { value = value * 10 + *text - '0'; ++text; }
    if (*text != '\0') return 0;
    command->operation = operation;
    command->value = value; return 1;
}

int main(void)
{
    struct Command command; int ok = parse_command("A:125", &command);
    printf("c8933 command=%d,%c,%d\n", ok, command.operation, command.value);
    return !(ok && command.operation == 'A' && command.value == 125);
}
