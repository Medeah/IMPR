/* Opgave 2.7 (Uinitialiserede variable) fra slides.
*/

#include <stdio.h>

int main(void) {

  int courses = 1, groups, students = 176,
      average_pr_group;

  /* The variable groups is uninitialized */
  // med gcc bliver groups 0, så vi for en Floating point exception
  // med clang bliver groups 32767 hver gang

  average_pr_group = students / groups;

  printf("Groups: %d\n", groups);

  printf("There are %d students pr. group in %d course(s)\n", 
         average_pr_group, courses);
  
  return 0;
}

