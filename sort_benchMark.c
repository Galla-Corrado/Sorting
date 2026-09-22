#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

#define DIM 100000
#define RANGE 1000

int main(){

    int *v1, *v2, *v3, *v4, *v5, *v6;
    float t1, t2, t3, t4, t5, t6;
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
    v3 = malloc (DIM*sizeof(int));
    v4 = malloc (DIM*sizeof(int));
    v5 = malloc(DIM*sizeof(int));
    v6 = malloc(DIM*sizeof(int));
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
    }
    /**
     * creazione file.md
     */
    fprintf(fp1, "# SORTING\nThis file display the execution times of some sorting algorithms.\nEvery single algorithms manipulate the same vector of **%d** elements, in this way the comparison between the times are more accurate.\nVector is randomly generated evrey time the program is run.\nResults are in the *benchMark.csv* file.\n### Algorithms list:\n- Bouble sort\n- Insertion sort\n- Selection sort\n- Merge sort\n- Quick sort\n- Counting sort\n", DIM);
    /**
     * esecuzione dei vari algoritmi
     */
    bouble_sort(v1, DIM, &t1);
    insertion_sort(v2, DIM, &t2);
    selection_sort(v3, DIM, &t3);
    merge_sort(v4, DIM, &t4);
    quick_sort(v5, DIM, &t5);
    counting_sort(v6, DIM, &t6);
    /**
     * stampa dei risultati sul file.csv
     */
    fprintf(fp2, "%-20s;%20s;%20s;\n", "Algorithms", "Execution time", "type");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "Bouble sort", t1, "sec", "iterative");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "Insertion sort", t2, "sec", "iterative");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "selection sort", t3, "sec", "iterative");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "Merge sort rec", t4, "sec", "recursive");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "Quick sort", t5, "sec", "recursive");
    fprintf(fp2, "%-20s;%16.2f%4s;%20s;\n", "Counting sort", t6, "sec", "iterative");
    /**
     * libero la memoria
     */
    free(v1);
    free(v2);
    free(v3);
    free(v4);
    free(v5);
    free(v6);
    /**
     * chiusura file
     */
    fclose(fp1);
    fclose(fp2);
    return 0;
}



