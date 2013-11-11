/* Opgave 7.2 (Test af programmet der beregner timer, minutter og sekunder)
*/

#include <stdio.h>
#include <assert.h>
#define SEC_IN_HR 3600


void calculate_sec (int input_sec, int *sec, int *min, int *hr) {
  *hr = input_sec / SEC_IN_HR;
  *min = (input_sec % SEC_IN_HR) / 60;
  *sec = (input_sec % SEC_IN_HR) % 60;
}

void test1(void) {
  int input_sec = 4000;
  int sec, min, hr;
  calculate_sec(input_sec, &sec, &min, &hr);
  assert(hr == 1);
  assert(min == 6);
  assert(sec == 40);
}

void test2(void) {
  int input_sec = 75;
  int sec, min, hr;
  calculate_sec(input_sec, &sec, &min, &hr);
  assert(hr == 0);
  assert(min == 1);
  assert(sec == 15);
}

void test3(void) {
  int input_sec = 3700;
  int sec, min, hr;
  calculate_sec(input_sec, &sec, &min, &hr);
  assert(hr == 1);
  assert(min == 1);
  assert(sec == 40);
}

void test4(void) {
  int input_sec = 55;
  int sec, min, hr;
  calculate_sec(input_sec, &sec, &min, &hr);
  assert(hr == 0);
  assert(min == 0);
  assert(sec == 55);
}

void test5(void) {
  int input_sec = 3661;
  int sec, min, hr;
  calculate_sec(input_sec, &sec, &min, &hr);
  assert(hr == 1);
  assert(min == 1);
  assert(sec == 1);
}

void all_test(void) {
  test1();
  test2();
  test3();
  test4();
  test5();
}

int main (int argc, char *argv[])
{
  int input_sec, sec, min, hr;

  if (argc == 2 && strcmp(argv[1], "-t") == 0) {
    all_test();
    printf("All test pass\n");
  } else {
    puts ("Intast et antal sekunder der skal omregnes: ");
    scanf ("%d", &input_sec);

    calculate_sec(input_sec, &sec, &min, &hr);

    printf ("\n%d sekunder omregnet til timer, minutter og sekunder:\n", input_sec);
    printf ("%d time, %d minutter og %d sekunder\n", hr, min, sec);
  }
  return 0;
}

