/*
 * Programmer: Frederik Andersen   Date completed: Nov 7, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * Functions to determine if a given string is a palindrome.
 * Two variants: iterative and recursive.
 * Both functions have no side effects on the strings they work on
 * 
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>

int is_palindrome_iter(const char *str) {
  int i = 0, k = strlen(str) - 1;
  while(i < k)
    if (!(str[k--] == str[i++]))
      return 0;
  return 1;
}

// This helper keeps track of the length without mutation on the string
int is_palindrome_help(const char *str, const int len) {
  if (len <= 1)
    return 1;
  return str[0] == str[len - 1] && is_palindrome_help(str + 1, len - 2);
}

int is_palindrome_rec(char *str) {
  return is_palindrome_help(str, strlen(str));
}

int main(void) {
  char *ord[] = {"regninger", "regning", "", "i", "aa", "er", "regnimger"};

  assert(1 == is_palindrome_iter(ord[0]));
  assert(1 == is_palindrome_rec(ord[0]));

  assert(0 == is_palindrome_iter(ord[1]));
  assert(0 == is_palindrome_rec(ord[1]));
  
  assert(1 == is_palindrome_rec(ord[2]));
  assert(1 == is_palindrome_rec(ord[2]));
  
  assert(1 == is_palindrome_rec(ord[3]));
  assert(1 == is_palindrome_rec(ord[3]));

  assert(1 == is_palindrome_rec(ord[4]));
  assert(1 == is_palindrome_rec(ord[4]));

  assert(0 == is_palindrome_rec(ord[5]));
  assert(0 == is_palindrome_rec(ord[5]));

  assert(0 == is_palindrome_rec(ord[6]));
  assert(0 == is_palindrome_rec(ord[6]));
  return 0;
}   