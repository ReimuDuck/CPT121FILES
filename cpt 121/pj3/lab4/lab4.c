#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]) ;
void input ( double *x, double *x2, double *inc, double *y);
double piecewis( double x, double y);
void print( double x, double y, double inc, double x2);
void terminate( void );
//____________________________________________________________________________
int main(int argc, char *argv[]) { 
    double x, x2, y, inc;
// input
// validate: final x > initial x, inc > 0
    input(&x, &x2, &inc, &y);
// piecewise
// print
    print(x, x2, inc, x2);

// possible an array would be or could be used
    //terminate();
}
//____________________________________________________________________________
void input ( double *x, double *x2, double *inc, double *y ){
    bool valid = false;

    while ( !valid){
        printf("Enter initial X: \n");
        scanf("%lf", x);
        printf("Enter final X (Set higher than initial): \n");
        scanf("%lf", x2);

        if (*x > *x2)
        {
            printf("Error: Initial is greater than Final please try again. \n");
            continue;
        }
    

        printf("Enter increment (CANNOT BE BELOW 0): \n");
        scanf("%lf", inc);
        if ( 0 >= *inc ){
            printf("Error: Increment is below 0 please try again. \n" );
            continue;
        }
        printf("Enter default Y value (0 unless x lies outside the piecewise function): \n");
        scanf("%lf", y);
        if ( 0 <= *inc &&  *x < *x2){
            valid = true;
            printf("%lf", inc);
        }else{
            printf("Error: Either Final X or Increment were set incorrectly, please try again. \n");
        }

    }
    return;
}
//____________________________________________________________________________

double piecewis( double x, double y){
    double cos1 ;
    if(x >= -2.5 && x < -1.5 ){
        return(-x*x);
    }else if( x >= -1.5 && x < -0.5 ){
        return(x*x*x);
    }
    else if( x >= -0.5 && x < 0.5 ){
        cos1= cos(x);
        return(cos1);
    }
    else if( x >= 0.5 && x < 1.5 ){
        return(log(x));
    }
    else if( x >= 1.5 && x <= 2.5 ){
        return(exp(3*(1.5-x)));
    }
    else{
        return(y);
    }


}

//____________________________________________________________________________
void print( double x, double y, double inc, double x2 ){

    FILE  *ext_file;


    ext_file = fopen("data.txt", "w"); 

    for( double i = x-inc; i < x2;){
        i = i + inc;
        x = i;
        y = piecewis(x, y);
        printf("%lf ", x);
        printf("%lf \n", y);
        fprintf(ext_file,"%lf ", x);
        fprintf(ext_file,"%lf \n", y);

    }
    fclose( ext_file);
    printf("File 'data.txt' created \n");
    
    return;
}
//____________________________________________________________________________
void terminate( void ){
    int n;

    printf("Enter an integer to end the program \n");
    scanf("%d", &n);

    return ;
}
//____________________________________________________________________________