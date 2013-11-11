/*
 * Programmer: Frederik Andersen   Date completed: Sep 8, 2013
 * Instructor: Kurt Nørmark        Class: IMPR
 *
 * Indlæser et helt antal sekunder og omregner dette tal til timer, minutter og
 * sekunder på sædvanlig vis.
 */

#include <stdio.h>

int
main (void)
{
  int input_sec, sec, min, hr;

  /* Indlæser input fra brugeren. */
  puts ("Intast et antal sekunder der skal omregnes: ");
  scanf ("%d", &input_sec);

  /* 
   * Laver omregningerne.
   * Modulo operatoren (%) er brugt til at få resten ved division.
   */
  hr = input_sec / 3600;
  min = (input_sec % 3600) / 60;
  sec = (input_sec % 3600) % 60;

  /* Udskriver resultatet til brugeren. Der var intet krav om korrekt grammatik */
  printf ("\n%d sekunder omregnet til timer, minutter og sekunder:\n", input_sec);
  printf ("%d time, %d minutter og %d sekunder\n", hr, min, sec);
  return 0;
}
