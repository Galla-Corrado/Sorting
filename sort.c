#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

/*Bouble sort*/
void bouble_sort(int *vett, int n, float *time){
    int i, j, tmp;
    clock_t t_start = clock();
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(vett[j] < vett[i]){
                tmp = vett[j];
                vett[j] = vett[i];
                vett[i] = tmp;
            }
        }
    }
    clock_t t_finish= clock();

    *time = (float) (t_finish-t_start) / CLOCKS_PER_SEC;
}
/*Insertion sort*/
void insertion_sort(int *vett, int n, float *time){
    int i, j, tmp;
    clock_t t_start = clock();
    for(i =0; i<n; i++){
        tmp = vett[i];
        for(j=i-1; j>=0; j--){
            if(tmp < vett[j]){
                vett[j+1] = vett[j];
                vett[j] = tmp;
            }
        }
    }
    clock_t t_finish = clock();

    *time = (float) (t_finish-t_start) / CLOCKS_PER_SEC;
}
/*Selection sort*/
void selection_sort(int *vett, int n, float *time){
    int i, j, min, pos, tmp;
    pos = -1;
    clock_t t_start = clock();
    for(i=0; i<n; i++){
        min = vett[i];
        for(j = i; j<n; j++){
            if(vett[j]<min){
                min = vett[j];
                pos = j;
            }
        }
        if(pos != -1){
            tmp = vett[i];
            vett[i] = min;
            vett[j] = tmp;
        }
    }
    clock_t t_finish = clock();
    *time = (float) (t_finish-t_start) / CLOCKS_PER_SEC;
    
}
/************merge Sort***********************/
/*Merge function*/
static void mergeFunct(int *vett, int left, int mid, int right){
    int i, j, k, dim1, dim2, x, y;
    int *v1, *v2;
    i=0; j=0;

    dim1=mid-left+1;
    dim2=right-mid;
    v1=malloc(dim1*sizeof(int));
    v2= malloc(dim2*sizeof(int));
    for(k=left; k<=right; k++){
        if(k<=mid){
            v1[i]=vett[k];
            i++;
        }
        else{
            v2[j]=vett[k];
            j++;
        }
    }
    x=0;
    y=0;
    for(k=left; k<=right; k++){
        if(x<i && y<j){
            if(v1[x]<v2[y]){
                vett[k] = v1[x];
                x++;
            }
            else{
                vett[k] = v2[y];
                y++;
            }
        }
        else{
            if(x>=i){
                vett[k] = v2[y];
                y++;
            }
            else{
                vett[k] = v1[x];
                x++;
            }
        }
    }
   free(v1);
   free(v2);
}
static void merge_sort_r(int *vett, int l, int r){
    int m;
    if(l>=r){
        return;
    }
    m=(r+l)/2;
    
    merge_sort_r(vett, l, m);
    merge_sort_r(vett, m+1, r);
    //printf("left: %d mid: %d right: %d\n", l, m, r);
    mergeFunct(vett, l, m, r);
}

void merge_sort(int *vett, int n, float *time){
    int l=0;
    int r=n-1;
    clock_t t_start = clock();
    merge_sort_r(vett, l, r);
    clock_t t_finish = clock();

    *time = (float)(t_finish-t_start) / CLOCKS_PER_SEC;
}

static void quick_sort_r(int *vett, int start, int finish){
    int pivot = vett[finish-1];
    int i, j, tmp;
    i=start-1;
    if(start>=finish){
        return;
    }
    for(j=start; j<finish; j++){
        if(vett[j]<pivot || j==finish-1){
            i++;
            tmp=vett[j];
            vett[j]= vett[i];
            vett[i] = tmp;
        }
    }
    quick_sort_r(vett, start, i-1);
    quick_sort_r(vett, i+1, finish);
}


void quick_sort(int *vett, int n, float *time){
    clock_t t_start, t_finish;

    t_start = clock();
    quick_sort_r(vett, 0, n);
    t_finish = clock();

    *time = (float) (t_finish-t_start) / CLOCKS_PER_SEC;
}


