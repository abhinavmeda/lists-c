#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void append(Array* ls, int val){
    if(ls->currentCapacity == ls->maxCapacity){
        ls->ptr_to_chunk_of_memory = realloc(ls->ptr_to_chunk_of_memory, sizeof(int) * ls->maxCapacity * 2);
        ls->maxCapacity = ls->maxCapacity * 2;
    }
    
    ls->ptr_to_chunk_of_memory[ls->currentCapacity] =  val;
    ls->currentCapacity += 1;
}

Array* create_empty_array(){
    Array* new_array = malloc(sizeof(Array));
    new_array->maxCapacity = DEFAULT_MAX_SIZE;
    new_array->currentCapacity = DEFAULT_CURRENT_CAPACITY;
    new_array->ptr_to_chunk_of_memory =  malloc(sizeof(int) * new_array->maxCapacity);
    return new_array;
}
/*
type numbers like this (int []) so you can pass in an array like {1, 2, 3} 
*/
Array* initialize_array_with_elements(int numbers[], int size){
    Array* new_array = create_empty_array();
    for(int i = 0; i < size; i++){
        append(new_array, numbers[i]);
    }
    return new_array;
}

void print(Array* ls){
    printf("[");
    for(int i = 0; i < ls->currentCapacity; i++){
        printf("%d", ls->ptr_to_chunk_of_memory[i]);
        if(i != ls->currentCapacity - 1){
            printf(",");
        }
    }
    printf("]");
    printf("\n");
}

void destroy(Array* ls){
    free(ls->ptr_to_chunk_of_memory);
    free(ls);
}
int main(){
    Array* ls = initialize_array_with_elements((int []) {1, 2, 3}, 3);
    print(ls);
}
