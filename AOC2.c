#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_inc(int arr[], int size){
    //all data increase
    for(int i = 0; i < size - 1; i++){
        if (arr[i] > arr[i + 1]){
            return 1; //false
        }
    }
    return 0; // true
}

int check_dec(int arr[], int size){
    //all data decreases
    for(int i = 0; i < size - 1; i++){
        if (arr[i] < arr[i + 1]){
            return 1; //false
        }
    }
    return 0; // true
}

int check_space(int arr[], int size){
    //check greater than one but max of three
    for(int i = 0; i < size - 1; i++){
        if ((arr[i] == arr[i + 1]) || (abs(arr[i] - arr[i + 1]) > 3)){
            return 1; //false
        }
    }
    return 0; // true
}

//Will make this reuseable *******************************************************************************
#define MAX_ROWS 1000

void build_matrix(const char *filename, int **matrix, int *rowSizes, int *rows){
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Error: Couldn't open file\n");
    }

    int *tempRow;
    int value;
    *rows = 0;

    while (!feof(file)){
        tempRow = malloc(MAX_ROWS * sizeof(int));
        if (tempRow == NULL){
            printf("Error: Memory failed\n"); 
        }

        int currentCol = 0;
        while (fscanf(file, "%d", &value) == 1){
            tempRow[currentCol++] = value;
            if(fgetc(file) == '\n'){
                break;
            }
        }

        matrix[*rows] = malloc(currentCol * sizeof(int));
        if (matrix[*rows] == NULL){
            printf("Error: Memory failed\n");
        }

        for (int i = 0; i < currentCol; i++){
            matrix[*rows][i] = tempRow[i];
        }

        rowSizes[*rows] = currentCol;
        free(tempRow);
        (*rows)++;

    }

    fclose(file);

}


int main(int argc, char **argv){
//Read Input *********************************************************************
    const char filename[] = "AOC2_input.txt";
    int *matrix[MAX_ROWS];
    int rowSizes[MAX_ROWS];
    int rows = 0;
    build_matrix(filename, matrix, rowSizes, &rows);
//Copy above for input reading ***************************************************

    int numSafe = 0;
    int *tempRow;

    for(int i = 0; i < MAX_ROWS; i++){
        int rowsize;

        rowsize = rowSizes[i];

        printf("length:\t%d\n", rowsize);

        tempRow = (int*)malloc(sizeof(rowsize * sizeof(int)));
        for (int j = 0; j < rowsize; j++){
            tempRow[j] = matrix[i][j];
        }

        for (int i = 0; i < rowsize; i++){
            printf("%d ", tempRow[i]);

        }
        printf("\n");

        int dec, inc, spc;
        dec = check_dec(tempRow, rowsize);
        inc = check_inc(tempRow, rowsize);
        spc = check_space(tempRow, rowsize);

        if((dec == 0 || inc == 0) && spc == 0){
            numSafe++;
        }

        free(tempRow);

        printf("Check num safe:\t%d\n", numSafe);
    }


    printf("Safe Reports:\t%d\n", numSafe);
//Part 2 ***********************************************************************************************




    return 0;
}