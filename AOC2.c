#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
//Read Input
    FILE *fptr, *output;
    char filename[] = "AOC1_input.txt";
    char out_file[] = "output.txt";
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Error-bros\n");
        return 1;
    }

    int all[2000];
    int left[1000];
    int right[1000];
    int count = 0;

    while(fscanf(fptr, "%d", &all[count]) != EOF && count < 2000){
        count++;
    }
    fclose(fptr);

    int all_index = 0;
    for (int i = 0; i < 1000; i++){
        left[i] = all[all_index];
        right[i] = all[all_index + 1];
        all_index += 2;
    }


    return 0;
}