#ifndef __list_H__  
#define __list_H__  

#define DEFAULT_MAX_SIZE 5
#define DEFAULT_CURRENT_CAPACITY 0

/**
 * @brief Struct that defines a list object.
 * @param maxCapacity is a private variable and should NEVER be touched by the client
 * @param currentCapacity is a private variable and should NEVER be touched by the client
 * @param ptr_to_chunk_of_memory keeps track of where the list elements will go
 * 
 */
typedef struct List{
        int maxCapacity;
        int currentCapacity;
        int* ptr_to_chunk_of_memory;
}List;

/**
 * @brief Append val to the end of the given list
 * 
 * @param list 
 * @param val 
 */
void append(List* list, int val);


/**
 * @brief Print the contents of the List in a readable format
 * @param list 
 * @return void
 */
void print(List* list);


/**
 * @brief Destroy or deallocate the List from memory
 * No garbage collector here so need to explicitly do it yourself :)
 * @param list 
 * @return void
 */
void destroy(List* list);


/**
 * @brief Initialize an empty List. 
 * @return List*
 * 
 */ 
List* create_empty_list();


/**
 * @brief Initialize an List with elements. 
 * Cast the type of numbers to (int []) so you can pass in an List like {1, 2, 3}
 * @param numbers 
 * @param size
 * @return List* 
 * 
 */ 
List* initialize_list_with_elements(int numbers[], int size);


/**
 * @brief Get the length of the List
 * @param ls 
 * @return int 
 */
int len(List* list);


/**
 * @brief Return the number at the given index otherwise return -1
 * @param list 
 * @param index 
 * @return int 
 */
int get_item(List* list, int index);


/**
 * @brief Set an item at a pre-existing index in the list. 
 * Will fail silently if a valid index is not provided
 * @param list 
 * @param index 
 * @param new_number 
 * @return void
 */
void set_item(List* list, int index, int new_number);


#endif