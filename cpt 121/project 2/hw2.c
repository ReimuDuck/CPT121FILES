#include <stdio.h>
#include <stdlib.h>
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
int my_loop ( void ); //void means there is nothing to send or receive, this function not sending anything
void my_branch ( int n );
//____________________________________________________________________________
int main(int argc, char *argv[]) { // must be main in every C program
    int n;

    n = my_loop();
    my_branch( n );

    printf("enter key to end \n");
    scanf("%d", &n);

    return 0;

}
//____________________________________________________________________________
//____________________________________________________________________________
int my_loop ( void ){
    int n, o, l, sum;
    //checks for 3 inputs and sums them together, I'm not sure how to check for invalid inputs
    printf("Enter 3 numbers seperated by spaces:");
    scanf("%d %d %d", &n, &o, &l);
    sum = n+o+l;

    printf("%d \n ", sum);
    return (n);
}
//____________________________________________________________________________
void my_branch ( int n ){
        int sum;
        

    if ( sum < 15 ){

        printf("This sum is below expectation \n");

    }else if ( sum = 15 ){ 

        printf("This sum is just right \n");

    }else{
        
        printf("This is far past my capabilities \n");

    }
    return ;
}
//____________________________________________________________________________