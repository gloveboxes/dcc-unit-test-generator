#include <stdio.h>
enum LogLevel { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR };
struct LogEntry {
    enum LogLevel level;
    int code;
    union {
        const char *message;
        int detail;
    };
};
static int log_weight(const struct LogEntry *e) {
    return (int)e->level * 10 + e->code;
}
int main(void) {
    struct LogEntry entries[3] = {
        {.level=LOG_INFO,  .code=1, .detail=0},
        {.level=LOG_WARN,  .code=5, .detail=7},
        {.level=LOG_ERROR, .code=2, .detail=99}
    };
    int total = 0;
    for (int i = 0; i < 3; i++) total += log_weight(&entries[i]);
    printf("c1118 log=%d,%d\n", total, entries[2].detail);
    return !(total == (10+1)+(20+5)+(30+2) && entries[2].detail == 99);
}
