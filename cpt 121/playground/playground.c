#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //.header
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
void my_while( void ); //the statement in the prefacet is the prototype
void my_array( double *goob, int size );//the asterisk to share the array anywhere
void my_print( double *goob, int size );
int my_standards( int var, int *dw);//this combos with & to build a road btwn func and main
//____________________________________________________________________________
int main(int argc, char *argv[]) { // must be main in every C program; by using functions this becomes table of contents
    double goob[ 30 ];
    int size = 15;

    //my_while();//func allows us to test while

    my_array( goob, size );//funcy arrays

    my_print( goob, size );
/* MY STANDARD
    int var = 0; //defining the var in func it only exists here
    int dw = 0;

    printf("enter var then dw: \n");
    scanf("%d %d", &var, &dw);

    printf("these are var and dw: %d %d \n", var, dw);
    var = my_standards( var, &dw ); //& is a variable to be returned
    printf("no this is var and dw: %d %d \n", var, dw);
*/
    return 0;

}
//____________________________________________________________________________
//____________________________________________________________________________
void my_while( void ){//testing is an important part of the process
    bool go_on;
    double n;
    printf("im in my wile \n");
    go_on = true;

    while ( go_on == true ){//in the for loop we know the # of cycles, while loop loops till a condition is met
  
    printf("Put that number ");
    scanf("%lf", &n);

    if (n <= 10 && 1 <= n)
    {
        go_on = false;
        printf("wtf is %lf \n", n);
    }else{
        printf("L bot \n");

    }


    }
    


    return ;
}
//____________________________________________________________________________
void my_array( double *goob, int size ){

    printf("thats my array \n"); //array is a collection of variables in a thing aboo

    for ( int i = 0; i < size; i++){ //hard coded count in loop is limiting
        goob[ i ] = i+1;
    }
    
    return;
}
//____________________________________________________________________________
void my_print( double *goob, int size ){

    for ( int i = 0; i < size; i++)
    {
        printf("%lf \n", goob[ i ]);
    }

    return;
}
//____________________________________________________________________________
int my_standards( int var, int *dw ){

    printf("whoops \n");
    printf("this is var: %d \n", var);
    printf("this is dw: %d \n", dw);
    var = 23;
    *dw = 40;
    printf("lets change var: %d \n", var);

    return (var);
}
//____________________________________________________________________________