#include <stdio.h>



struct Rectangle{
    int length;
    int breadth;
}; 

struct Rectangle rectangle;

void initRectangle(struct Rectangle rectangle){
    int l,b;
    l = rectangle.length;
    b = rectangle.breadth ;
    int S = l * b;   
    printf("Area of rectangle: %d\n", S);  //
}

int main(){

    rectangle = (struct Rectangle){12,22};
    initRectangle(rectangle);
    return 0;
}   
