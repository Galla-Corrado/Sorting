#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

#define DIM 100000
#define RANGE 1000

int main(){

    int *v1, *v2, *v3, *v4, *v5, *v6, *v7;
    float t;
    int i, x;
    FILE *fp1, *fp2;

    /**
     * apertura e controllo file
     */
    fp1 = fopen("README.md", "w");
    fp2 = fopen("benchMark.csv", "w");
    if(fp1 == NULL || fp2 ==NULL){
        printf("error!\n");
        exit(-1);
    }
    /**
     * allocazione dinamica dei vettori
     */
    v1 = malloc(DIM*sizeof(int));
    v2 = malloc(DIM*sizeof(int));
    v3 = malloc(DIM*sizeof(int));
    v4 = malloc(DIM*sizeof(int));
    v5 = malloc(DIM*sizeof(int));
    v6 = malloc(DIM*sizeof(int));
    v7 = malloc(DIM*sizeof(int));
    /**
     * riempio i vettori con numeri casuali tra 0 e DIM-1
     */
    srand(time(NULL));
    for(i=0; i<DIM; i++){
        x = rand()%RANGE;
        v1[i]=x;
        v2[i]=x;
        v3[i]=x;
        v4[i]=x;
        v5[i]=x;
        v6[i]=x;
        v7[i]=x;
    }
    /**
     * creazione file.md
     */
    fprintf(fp1, "# SORTING\nThis file display the execution times of some sorting algorithms.\nEvery single algorithms manipulate the same vector of **%d** elements, in this way the comparison between the times are more accurate.\nVector is randomly generated evrey time the program is run.\nResults are in the *benchMark.csv* file.\n### Algorithms list:\n- Bouble sort\n- Insertion sort\n- Selection sort\n- Merge sort\n- Quick sort\n- Counting sort\n", DIM);
    /**
     * esecuzione dei vari algoritmi
     */
    fprintf(fp2, "%s,%s,%s\n", "Algorithms", "Execution time(sec)", "type");

    bouble_sort(v1, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Bouble sort", t, "iterative");

    insertion_sort(v2, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Insertion sort", t, "iterative");

    selection_sort(v3, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "selection sort", t, "iterative");

    merge_sort(v4, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Merge sort rec", t, "recursive");

    quick_sort(v5, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Quick sort", t, "recursive");

    counting_sort(v6, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Counting sort", t, "iterative");

    HeapSort(v7, DIM, &t);
    fprintf(fp2, "%s,%.3f,%s\n", "Heap sort", t, "recursive");
    
    
    /**
     * libero la memoria
     */
    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);
    free(v6);
    free(v7);
    /**
     * chiusura file
     */
    fclose(fp1);
    fclose(fp2);
    return 0;
}



