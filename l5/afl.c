/*
 * Programmer: Frederik Andersen   Date completed: Oct 15, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * Prints roots of the quadratic equation a * x*x + b * x + c = 0
 * Will continue accept input until the user inputs 0 0 0
 * Programmed using a top-down approach
 */

#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c);
double calculate_discriminant(double a, double b, double c);
double calculate_first_root(double a, double b, double discriminant);
double calculate_second_root(double a, double b, double discriminant);

int main(void)
{
  double a, b, c;

  while (1) {
    printf("Enter coeficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0 && b == 0 && c == 0) {
      break;
    }
    solveQuadraticEquation(a, b, c);
  }
  return 0;
}

void solveQuadraticEquation(double a, double b, double c)
{
  double discriminant, root1, root2;

  discriminant = calculate_discriminant(a, b, c);

  if (discriminant < 0) {
    printf("No roots\n");
  } else if (discriminant == 0) {
    root1 = calculate_first_root(a, b, 0);
    printf("One root: %f\n", root1);
  } else {
    root1 = calculate_first_root(a, b, discriminant);
    root2 = calculate_second_root(a, b, discriminant);
    printf("Two roots: %f and %f\n", root1, root2);
  }

}

double calculate_discriminant(double a, double b, double c)
{
  return b * b - 4 * a * c;
}

double calculate_first_root(double a, double b, double discriminant)
{
  return (-b + sqrt(discriminant)) / (2 * a);
}

double calculate_second_root(double a, double b, double discriminant)
{
  return (-b - sqrt(discriminant)) / (2 * a);
}
