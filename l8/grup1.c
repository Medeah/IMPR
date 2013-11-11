#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum forret {guacamole, tarteletter, lakseruller, graskarsuppe} forret;
void prnt_forret(forret f){
  switch (f) {
    case guacamole: printf("guacamole");
       break;
    case tarteletter: printf("tarteletter");
       break;
    case lakseruller: printf("lakseruller");
       break;
    case graskarsuppe: printf("græskarsuppe");
       break;
  }
}  

typedef enum hovedret {gyldenkal, hakkebof, gullash, forloren_hare} hovedret;
void prnt_hovedret(hovedret f){
  switch (f) {
    case gyldenkal: printf("gyldenkål");
       break;
    case hakkebof: printf("hakkebof");
       break;
    case gullash: printf("gullash");
       break;
    case forloren_hare: printf("forloren hare");
       break;
  }
}

typedef enum dessert {pandekager_med_is, gulerodskage, choklademousse, citronfromage} dessert;
void prnt_dessert(dessert f){
  switch (f) {
    case pandekager_med_is: printf("pandekager med is");
       break;
    case gulerodskage: printf("gulerodskage");
       break;
    case choklademousse: printf("choklademousse");
       break;
    case citronfromage: printf("citronfromage");
       break;
  }
}


void maaltid(void) { 
    printf("Vi skal ha: ");
    prnt_forret((forret) (rand() % 4));
    printf(", ");
    prnt_hovedret((hovedret) (rand() % 4));
    printf(" og ");
    prnt_dessert((dessert) (rand() % 4));
    printf("\n");
}

int main(void)
{
    assert(guacamole == 0);
    assert(hakkebof == 1);
    assert(citronfromage == 3);
    srand(42);

    int i;

    for (i = 0; i < 25; ++i) {
        maaltid();
    }
    
    return 0;
}

