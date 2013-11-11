/*
 * Programmer: Frederik Andersen   Date completed: Nov 3, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * The function merge will merge two sorted arrays.
 * The result is stored in a output parameter. The length of the output array
 * is assumed to be equal to the number of non-unique numbers in the two input
 * arrays.
 * 
 */
#include <stdio.h>
#include <assert.h>

void merge(const double a[], const double b[], double out[], int size_a, int size_b) {
  int counter_a = 0, counter_b = 0, counter_out = 0;
  while (counter_a < size_a && counter_b < size_b)
    if (a[counter_a] < b[counter_b])
      out[counter_out++] = a[counter_a++];
    else if (a[counter_a] > b[counter_b])
      out[counter_out++] = b[counter_b++];
    else
      counter_b++;
  while (counter_a < size_a)
    out[counter_out++] = a[counter_a++];
  while (counter_b < size_b)
    out[counter_out++] = b[counter_b++];
}

int array_equal(const double a[], const double b[], int size) {
  int i;
  for (i = 0; i < size; ++i)
    if (!(a[i] == b[i]))
      return 0;
  return 1;
}

// it should merge two sorted arrays
void test1(void) {
  double a[] = { 4, 15, 16 };
  double b[] = { 8, 23, 42 };
  double out[6];
  double expected[6] = { 4, 8, 15, 16, 23, 42 };

  merge(a, b, out, 3, 3);
  assert(array_equal(out, expected, 6));

  // the input order should not matter
  merge(b, a, out, 3, 3);
  assert(array_equal(out, expected, 6));
}

// it should merge arrays of different sizes
void test2(void) {
  double a[] = { 8.0 };
  double b[] = { 4.0, 15.0, 16.0, 23.0, 42.0 };
  double out[6];
  double expected[6] = { 4, 8, 15, 16, 23, 42 };

  merge(a, b, out, 1, 5);
  assert(array_equal(out, expected, 6));
  merge(b, a, out, 5, 1);
  assert(array_equal(out, expected, 6));
}

// it should work when two arrays end in the same value
void test3(void) {
  double a[] = { 4, 15, 16, 42 };
  double b[] = { 8, 23, 42 };
  double out[6];
  double expected[] = { 4, 8, 15, 16, 23, 42 };

  merge(a, b, out, 4, 3);
  assert(array_equal(out, expected, 6));
  merge(b, a, out, 3, 4);
  assert(array_equal(out, expected, 6));
}

// the result array should contain no duplicate values
void test4(void) {
  double a[] = { 4, 15, 16, 23 };
  double b[] = { 4, 8, 23, 42 };
  double out[6];
  double expected[] = { 4, 8, 15, 16, 23, 42 };
  
  merge(a, b, out, 4, 4);
  assert(array_equal(out, expected, 6));
  merge(b, a, out, 4, 4);
  assert(array_equal(out, expected, 6));
}

int main(void) {
  test1();
  test2();
  test3();
  test4();

  return 0;
}
