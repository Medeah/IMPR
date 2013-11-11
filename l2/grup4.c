// Opgave 2.6 (Erfaringer med scanf).

#include <stdio.h>

int main(void) {

  int c1, c2, c3, c4,   scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%c%c%c%c", &c1, &c2, &c3, &c4); 
  // her for vi en compile time error fordi vi indlæser char in i en variable der har typen int


  printf("c1 = %c, c2 = %c, c3 = %c, c4 = %c\n", c1, c2, c3, c4);
  printf("scanRes = %d\n", scanRes); // antal af tal inlæst

  return 0;
}

// ved disse inputs for jeg, og hvorfor
// abcd -> her kommer abcd bare ind i c{1,2,3,4}
// ab -> her hænger den bare fordi den venter på to flere chars
// a b c d -> her får vi også spaces med