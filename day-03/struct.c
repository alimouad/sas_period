#include <stdio.h>



struct Plan {
    int x;
    int y;
}; 

struct  Plan plan;
void updateYear(struct Plan *c) {
   c->x = 20;  // Change the year
   c->y = 23;
}


int main() {
  plan  = (struct Plan){22, 20};

  updateYear(&plan);  

  printf("X: %d\n", plan.x);
  printf("Y: %d\n", plan.y);

  return 0;
}