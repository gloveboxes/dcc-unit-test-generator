#include <stdio.h>

struct Fraction { int numerator; int denominator; };

static int gcd(int left, int right)
{
    int remainder;
    while (right != 0) {
        remainder = left % right;
        left = right;
        right = remainder;
    }
    return left < 0 ? -left : left;
}

static void reduce(struct Fraction *value)
{
    int divisor = gcd(value->numerator, value->denominator);
    value->numerator /= divisor;
    value->denominator /= divisor;
    if (value->denominator < 0) {
        value->numerator = -value->numerator;
        value->denominator = -value->denominator;
    }
}

int main(void)
{
    struct Fraction value = {-42, -56};
    reduce(&value);
    printf("c8909 fraction=%d/%d\n", value.numerator, value.denominator);
    return !(value.numerator == 3 && value.denominator == 4);
}
