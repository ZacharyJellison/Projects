#include <stdio.h>
#include <stdlib.h>

void bubble(int burst[], int n) {        
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst[j] > burst[j + 1]) {
                int tempBurst = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = tempBurst;
            }
        }
    }
}

int search(int rep, int list[1000]){
    int score = 0;
    for(int i = 0; i < 1000; i++){
        if(rep == list[i]){
            score++;
        }
    }

    return score;
}

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

    bubble(right, 1000);
    bubble(left, 1000);

//Print to ouput to see sorted 
    output = fopen(out_file, "w");
    all_index = 0;
    for (int i = 0; i < 1000; i++){
        fprintf(output, "%d\t", left[all_index]);
        fprintf(output, "%d\n", right[all_index + 1]);
        all_index += 2;
    }
    fclose(output);
//All above good for input :)

    int dist[1000];

    for(int i = 0; i < 1000; i++){
        dist[i] = left[i] - right[i];
    //Negative check
        if (dist[i] < 0){
            dist[i] = dist[i] * -1;
        }
    }

    int sum = 0;
    for(int i = 0; i < 1000; i++){
        sum += dist[i];
    }
    printf("WE DID IT JOE:   %d\n", sum);

//PART 2 **********************************************************************************
    int score;
    int sim_sum = 0;

    for(int i = 0; i < 1000; i++){
        score = search(left[i], right);
        left[i] = score * left[i];
    }
    for(int i = 0; i < 1000; i++){
        sim_sum += left[i];
    }
    printf("WE DID IT AGAIN JOE:   %d\n", sim_sum);

    return 0;
}