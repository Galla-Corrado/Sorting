#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

#define DIM 100000
#define RANGE 1000

int main(){

    int *v1, *v2, *v3, *v4, *v5;
    float t1, t2, t3, t4, t5;
    int i, x;
    FILE *fp;

    fp = fopen("benchMark.txt", "w");
    if(fp== NULL){
        printf("error!\n");
        exit(-1);
    }



    v1 = malloc(DIM*sizeof(int));
    v2 = malloc(DIM*sizeof(int));
    v3 = malloc (DIM*sizeof(int));
    v4 = malloc (DIM*sizeof(int));
    v5 = malloc(DIM*sizeof(int));

    srand(time(NULL));
    for(i=0; i<DIM; i++){
        x = rand()%RANGE;
        v1[i]=x;
        v2[i]=x;
        v3[i]=x;
        v4[i]=x;
        v5[i]=x;
    }

   

    /**
     * 
     */
    fprintf(fp, "This file display the execution times of some algorithms.\nEvery single algorithms manipulate the same vector, in this way the comparison between the times are more accurate.\n\n");
    bouble_sort(v1, DIM, &t1);
    insertion_sort(v2, DIM, &t2);
    selection_sort(v3, DIM, &t3);
    merge_sort(v4, DIM, &t4);
    quick_sort(v5, DIM, &t5);
    /**
     * 
     */
    fprintf(fp, "%-20s |%20s", "Algorithms", "execution time\n");
    fprintf(fp, "---------------------+--------------------\n");
    fprintf(fp, "%-20s |%18.2f\n", "Bouble sort", t1);
    fprintf(fp, "%-20s |%18.2f\n", "Insertion sort", t2);
    fprintf(fp, "%-20s |%18.2f\n", "selection sort", t3);
    fprintf(fp, "%-20s |%18.2f\n", "Merge sort rec", t4);
    fprintf(fp, "%-20s |%18.2f\n", "Quick sort", t5);


    
    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);

    fclose(fp);
    return 0;
}



