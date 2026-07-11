#include <stdio.h>

struct Fraction { int numerator; int denominator; };
static struct Fraction add(struct Fraction a, struct Fraction b)
{
    struct Fraction result = {a.numerator * b.denominator + b.numerator * a.denominator,
                              a.denominator * b.denominator};
    return result;
}
int main(void)
{
    struct Fraction total = add((struct Fraction){1, 3}, (struct Fraction){1, 6});
    printf("c9902 fraction=%d/%d\n", total.numerator, total.denominator);
    return 0;
}
