#include <stdio.h>
#include <stdlib.h>
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
int my_loop ( void );
int my_list ( void );
void my_branch ( int n );
void termination ( void ); //since its not returning or receiving void for both declarations
//____________________________________________________________________________
int main(int argc, char *argv[]) { // must be main in every C program; by using functions this becomes table of contents
   
    int n;

    n = my_loop(); // this is telling the pc to go to that department 'function'

    my_branch( n );

    my_list();

    termination(); //single responsibility principle

    return 0;

}
//____________________________________________________________________________
//____________________________________________________________________________
int my_loop ( void ){
    int n, outer_cntr;

    printf("enter the number of cycles ");
    scanf("%d", &n);
    for (outer_cntr = 0; outer_cntr < n; outer_cntr++){ //the inner loop controls the count, the rows are controlled by the outer
        for (size_t i = 1; i <= n; i++)
        {
            printf("%-8d %-8d %-8d ", i, i*i,i*i*i);
        }
        printf("\n");
    }
    



    return (n) ; //function can only return one value through this
}
//____________________________________________________________________________
int my_list ( void ){
    int n, outer_cntr;
    double f1,f2,f3;

    printf("enter the number of cycles ");
    scanf("%d", &n);
    for (outer_cntr = 0; outer_cntr < n; outer_cntr++){ 
        f1 = outer_cntr + 1.5; // double precision floating points
        f2 = f1 * f1;
        f3 = f2 * f1;
        printf("%lf %lf %lf", f1, f2, f3); //lf signifies long float
        printf(" \n");
    }

    return (n) ; //function can only return one value through this
}
//____________________________________________________________________________
void my_branch ( int n ){
        int i ;
        
        printf("this is n %d \n", n);

    if ( n < 10 ){ // introducing branching

        printf("This is small \n");

    } else { //now nesting
        printf("wow");

        
    } 
    return;
}
//____________________________________________________________________________
void termination ( void ){
    int n;

    printf("enter key to end \n");
    scanf("%d", &n);

    return ;
}
//____________________________________________________________________________