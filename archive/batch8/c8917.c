#include <stdio.h>

enum State { STATE_IDLE, STATE_ACTIVE, STATE_DONE, STATE_ERROR };
enum Event { EVENT_START, EVENT_STEP, EVENT_FINISH };

static enum State transition(enum State state, enum Event event)
{
    if (state == STATE_IDLE && event == EVENT_START) return STATE_ACTIVE;
    if (state == STATE_ACTIVE && event == EVENT_STEP) return STATE_ACTIVE;
    if (state == STATE_ACTIVE && event == EVENT_FINISH) return STATE_DONE;
    return STATE_ERROR;
}

int main(void)
{
    enum State state = STATE_IDLE;
    state = transition(state, EVENT_START);
    state = transition(state, EVENT_STEP);
    state = transition(state, EVENT_FINISH);
    printf("c8917 state=%d\n", state);
    return state != STATE_DONE;
}
