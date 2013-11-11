#include <stdio.h>
#include <assert.h>

void test(int a[]) {
  printf("%d\n", (int)(sizeof(a) / sizeof(*a)));
}

int main(void) {
  int arr[] = { 1,2,3,4,5,6 };
  test(arr);
   


  return 0;
}
