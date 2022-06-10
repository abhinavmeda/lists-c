#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main() {
    List* ls = initialize_list_with_elements((int []){1, 2, 3}, 3);
    print(ls);
    set_item(ls, 0, 4);
    print(ls);
    printf("%d\n", get_item(ls, 0));
}
