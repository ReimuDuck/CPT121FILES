#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //.header
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
void my_input( int *rows );
int * my_array( int rows );//the asterisk to share the array anywhere
void display_goob( int *goob, int rows );
int **my_matrix( int rows, int columns );//the 2 asterisk says we want a matrix
void display_goof( int **goof, int rows, int columns );

//____________________________________________________________________________
int main(int argc, char *argv[]) { 
    int *goob; //sized at run time and its now an identifier, functions like a variable
    int **goof;
    int rows[ 2 ];

    my_input( rows );


    goob = my_array( rows[0] );//funcy arrays

    display_goob( goob, rows[0] );

    goof = my_matrix( rows[0], rows [ 1 ] );//funcy matrices

    display_goof( goof, rows[0], rows[ 1 ] );

    return 0;

}
//____________________________________________________________________________
//____________________________________________________________________________

int * my_array( int rows ){

    printf("thats my array \n"); //array is a collection of variables in a thing aboo

    int *goob = ( int *)malloc( rows * sizeof( int *));


    for ( int i = 0; i < rows; i++){ //hard coded count in loop is limiting
        goob[ i ] = i+1;
    }
    
    return ( goob);
}
//____________________________________________________________________________
void display_goob( int *goob, int rows ){

    for ( int i = 0; i < rows; i++)
    {
        printf("%d \n", goob[ i ]);
    }

    return;
}
//____________________________________________________________________________
void my_input( int *rows ){
    printf("ENTER ROW NUMBER: ");
    scanf( "%d", &rows[ 0 ]);

    printf("ENTER column NUMBER: ");
    scanf( "%d", &rows[ 1 ]);

    printf("%d %d \n", rows[0], rows[1]);
}
//____________________________________________________________________________
//____________________________________________________________________________

int ** my_matrix( int rows, int columns ){
    int x;

    printf("thats my matrix \n"); //array is a collection of variables in a thing aboo

    int **goof = ( int **)malloc( rows * sizeof( int *));//this tells us the amount of memory each row occupies

    for( int i = 0; i < rows; i++){
        goof[ i ] = ( int *)malloc( columns * sizeof( int *));
    }


    for ( int i = 0; i < rows; i++){ //hard coded count in loop is limiting
    
        for (int j = 0; j < columns; j++){
            x = (i+1)*(j+1);
                goof[ i ][ j ] = x;
        }


    }
    
    return ( goof);
}
//____________________________________________________________________________
void display_goof( int **goof, int rows, int columns ){

    for ( int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++){
            printf("%d ", goof[ i ][ j ]);
        }
        printf("\n");
    }

    return;
}
//____________________________________________________________________________