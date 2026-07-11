#include <stdio.h>
#include <stdbool.h>
enum ConfigKind { CFG_INT, CFG_BOOL, CFG_PAIR };
struct Config {
    const char *name;
    enum ConfigKind kind;
    union {
        int ival;
        bool bval;
        struct { int first; int second; };
    };
};
static int config_sum(const struct Config *cfg) {
    if (cfg->kind == CFG_INT)  return cfg->ival;
    if (cfg->kind == CFG_BOOL) return cfg->bval ? 1 : 0;
    return cfg->first + cfg->second;
}
int main(void) {
    struct Config cfgs[3] = {
        {.name="retries", .kind=CFG_INT,  .ival=3},
        {.name="enabled", .kind=CFG_BOOL, .bval=true},
        {.name="range",   .kind=CFG_PAIR, .first=10, .second=20}
    };
    int total = 0;
    for (int i = 0; i < 3; i++) total += config_sum(&cfgs[i]);
    printf("c1114 config=%d\n", total);
    return total != 34;
}
