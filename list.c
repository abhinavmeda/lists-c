#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void append(List* ls, int val){
    if(ls->currentCapacity == ls->maxCapacity){
        ls->ptr_to_chunk_of_memory = realloc(ls->ptr_to_chunk_of_memory, sizeof(int) * ls->maxCapacity * 2);
        ls->maxCapacity = ls->maxCapacity * 2;
    }
    
    ls->ptr_to_chunk_of_memory[ls->currentCapacity] =  val;
    ls->currentCapacity += 1;
}

List* create_empty_list(){
    List* new_array = malloc(sizeof(List));
    new_array->maxCapacity = DEFAULT_MAX_SIZE;
    new_array->currentCapacity = DEFAULT_CURRENT_CAPACITY;
    new_array->ptr_to_chunk_of_memory =  malloc(sizeof(int) * new_array->maxCapacity);
    return new_array;
}

List* initialize_list_with_elements(int numbers[], int size){
    List* new_array = create_empty_list();
    for(int i = 0; i != size; i++){
        append(new_array, numbers[i]);
    }
    return new_array;
}

void print(List* ls){
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

void destroy(List* ls){
    free(ls->ptr_to_chunk_of_memory);
    free(ls);
}

int len(List* ls){
    return ls->currentCapacity;
}

int get_item(List* ls, int index){

    // currentCapacity tells us how many elements are in the list
    // currentCapacity-1 represents the index of the last element in the list
    // index has to be 0 <= index <= currentCapacity-1

    if(0 <= index && index <= ls->currentCapacity - 1){
        return ls->ptr_to_chunk_of_memory[index];
    }
    return -1;

}

void set_item(List* list, int index, int new_number){
    if(0 <= index && index <= list->currentCapacity - 1){
        list->ptr_to_chunk_of_memory[index] = new_number;
    }
}
