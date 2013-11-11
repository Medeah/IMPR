/*
 * Programmer: Frederik Andersen   Date completed: Oct 27, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * Finds the area under a curve y = f(x) from a to b.
 * We are using the trapezoidal rule to approximate the area by splitting it
 * in to n subintervals
 */
#include <stdio.h>
#include <math.h>
#include <assert.h>
#define TOLERANCE 0.005
#define PI 3.14159265358979323846

double trap(double a, double b, int n, double (*f) (double))
{
    double T = 0, sum = 0, h = (b - a) / n;
    int i = 1;
    for (; i <= n - 1; ++i) {
        sum += f(a + i * h);
    }

    T = h / 2 * (f(a) + f(b) + 2 * sum);
    return T;
}

double h(double x)
{
    return sqrt(4 - x * x);
}

double g(double x)
{
    return x * x * sin(x);
}

void assert_approx_equal(double a, double b)
{
    assert(fabs(a - b) < TOLERANCE);
}

int main(void)
{
    printf("Approximated area under h(x)=√(4-x²): %lf\n",
           trap(-2, 2, 128, &h));

    assert_approx_equal(trap(-2, 2, 128, &h), 6.28);
    assert_approx_equal(trap(0, PI, 128, &g), PI * PI - 4);
    return 0;
}