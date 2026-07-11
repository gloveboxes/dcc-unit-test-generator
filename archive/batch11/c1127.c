#include <stdio.h>
#include <stdbool.h>
struct PID {
    int kp, ki, kd;
    union {
        struct { int integral; int prev_error; };
        int state[2];
    };
};
static int pid_step(struct PID *pid, int setpoint, int measured) {
    int error = setpoint - measured;
    pid->integral += error;
    int output = pid->kp * error + pid->ki * pid->integral + pid->kd * (error - pid->prev_error);
    pid->prev_error = error;
    return output;
}
int main(void) {
    struct PID pid = {.kp=2,.ki=1,.kd=1,.integral=0,.prev_error=0};
    int o1 = pid_step(&pid, 100, 80);
    int o2 = pid_step(&pid, 100, 90);
    printf("c1127 pid=%d,%d\n", o1, o2);
    return !(o1 == 80 && o2 == 40);
}
