#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <math.h>//.header
//whenever functions in program must be listed up here
int main(int argc, char *argv[]) ;
void my_input( int *rows );
int * my_array( int rows );//the asterisk to share the array anywhere
void display_goob( int *goob, int rows );
void array_to_file( int rows, int *goob);
int **my_matrix( int rows, int columns );//the 2 asterisk says we want a matrix
void display_goof( int **goof, int rows, int columns );
void matrix_to_file( int rows, int columns, int **goof);
void read_from_file( void );

//____________________________________________________________________________
int main(int argc, char *argv[]) { 
    int *goob; //sized at run time and its now an identifier, functions like a variable
    int **goof;
    int rows[ 2 ];

    my_input( rows );


    goob = my_array( rows[0] );//funcy arrays

    display_goob( goob, rows[0] );
    array_to_file( rows[0], goob);

    goof = my_matrix( rows[0], rows [ 1 ] );//funcy matrices

    display_goof( goof, rows[0], rows[ 1 ] );

    matrix_to_file(rows[0], rows[1], goof);

    read_from_file();

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
            x = (i*i+1)*(j*j*j+1);
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
void array_to_file( int rows, int *goob){
    //its caps just cuz it is bud
    FILE *ext_file ; //pointer to an external file?

    ext_file = fopen("goober.txt", "w"); // opens the file name goober and we want to write to it

    for (int i = 0; i < rows; i++)
    {
        fprintf( ext_file, "%d\n", goob[i]); //leading f means file, we choose which file we print to and how
    }
    //we then close the file
    fclose( ext_file );


    printf("filing! \n");
    


    return;
}
//____________________________________________________________________________
void matrix_to_file( int rows, int columns, int **goof){
    //its caps just cuz it is bud
    FILE *ext_file ; //pointer to an external file?

    ext_file = fopen("goofy.txt", "w"); // opens the file name goober and we want to write to it

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            fprintf( ext_file, "%d ", goof[i][j]);
        }
        fprintf(ext_file, "\n");
    }
    //we then close the file
    fclose( ext_file );


    printf("filing! \n");
    


    return;
}
//____________________________________________________________________________
void read_from_file( void ){
//c manages external files through characters and scripts
    bool tf = true;
    printf("reading... \n");
    FILE *ext_file;
    
    char string[ 100 ];
    ext_file = fopen ("goofy.txt", "r");
    //character type, c finds every string character by character

    
    while( tf == true){
        
        if ( *fgets( string, 100, ext_file )==EOF){ //all lines in a file are a string, if c reaches end of file it closes the loop
            
            tf = false;

        }
        
        printf( "%s", string);
        
    }//for each character there is an intereger
    //we then close the file
    fclose( ext_file );    




    return;
}
//____________________________________________________________________________