#include <stdio.h>
#include <stdbool.h>
enum TaskState { TASK_IDLE, TASK_RUNNING, TASK_DONE, TASK_ERROR };
struct Task {
    int id;
    enum TaskState state;
    union {
        int progress;
        int error_code;
    };
};
static void tick(struct Task *t) {
    if (t->state == TASK_RUNNING) {
        t->progress++;
        if (t->progress >= 5) t->state = TASK_DONE;
    }
}
int main(void) {
    struct Task t = {.id=1, .state=TASK_RUNNING, .progress=0};
    for (int i = 0; i < 7; i++) tick(&t);
    printf("c1112 task=%d,%d\n", (int)t.state, t.progress);
    return !(t.state == TASK_DONE && t.progress == 5);
}
