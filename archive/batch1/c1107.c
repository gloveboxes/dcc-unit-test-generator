#include <stdio.h>

enum ResultKind { RESULT_OK, RESULT_ERROR };
struct Result { enum ResultKind kind; union { int value; int error; }; };
static int unwrap(struct Result result) { return result.kind == RESULT_OK ? result.value : -result.error; }
int main(void)
{
    struct Result a = {RESULT_OK, {27}}, b = {RESULT_ERROR, {5}};
    printf("c1107 result=%d\n", unwrap(a) + unwrap(b));
    return 0;
}
