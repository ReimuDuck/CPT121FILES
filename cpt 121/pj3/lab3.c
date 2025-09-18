#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
void * input ( int rows );
void * print ( double *array);
void calc ( double *array );
void termination ( void ); //since its not returning or receiving void for both declarations
//____________________________________________________________________________
int main(int argc, char *argv[]) { // must be main in every C program; by using functions this becomes table of contents
   
    int rows = 10;

    double *array;

    array = input(rows); // this is telling the pc to go to that department 'function'

    calc( array );

    termination(); //single responsibility principle

    return 0;

}
//____________________________________________________________________________
//____________________________________________________________________________
void * input ( int rows ){
    double * array = (double *)malloc( rows * sizeof( double *));
    bool valid;

    valid = false;
    while ( valid == false)
    {
        printf("enter the initial time: \n ");
        scanf("%lf", &array[0]);
        printf("enter the final time: \n ");
        scanf("%lf", &array[1]);
        printf("enter the time increment: \n ");
        scanf("%lf", &array[2]);
        if ( 0 <= array[0] && 0 <= array[1] && 0 <= array[2]){
            valid = true;
        }else{
            printf("please try again \n");
        }

    }

    



    return (array) ; //function can only return one value through this
}
//____________________________________________________________________________
//____________________________________________________________________________
void calc ( double array[] ){
        double outer_cntr;
        
    for (outer_cntr = array[0]-array[2]; outer_cntr <= array[1];){ //the inner loop controls the count, the rows are controlled by the outer
        outer_cntr= outer_cntr+array[2];
        printf("t: %lf ", outer_cntr);
        array[3] = outer_cntr*5;
        printf("| x: %lf", array[3]);
        array[4] = (outer_cntr*8.66)-(4.905*(outer_cntr*outer_cntr));
        printf("| y: %lf \n", array[4]);

    }

}
//____________________________________________________________________________
//____________________________________________________________________________
void termination ( void ){
    int n;

    printf("enter key to end \n");
    scanf("%d", &n);

    return ;
}
//____________________________________________________________________________
