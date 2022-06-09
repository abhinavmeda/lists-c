#ifndef __list_H__  
#define __list_H__  

#define DEFAULT_MAX_SIZE 5
#define DEFAULT_CURRENT_CAPACITY 0

typedef struct Array{
        int maxCapacity;
        int currentCapacity;
        int* ptr_to_chunk_of_memory;
}Array;


void append(Array* ls, int val);
void print(Array* ls);
void destory(Array* ls);
Array* create_empty_array();
Array* initialize_array_with_elements(int numbers[], int size);
#endif