#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNodeType;

typedef struct List{
    ListNodeType * head;
    ListNodeType * tail;
}ListType;
static void add_item(ListType* list, int num) {
    ListNodeType *temp = (ListNodeType*) malloc(sizeof(ListNodeType));
    temp->next = NULL;
    temp->val = num;
    if(list->tail == NULL) {
        list->tail = list->head = temp;
    }else{
        list->tail->next = temp;
        list->tail = temp;
    }
}
static void show_data(ListType* list){
    ListNodeType *temp = list->head;
    while(1){
        printf("value = %d\n", temp->val);
        if(temp == list->tail) {
            return;
        }
        temp = temp->next;
    };
}


int main(){
    ListType *my_list = (ListType*) malloc(sizeof(ListType));
    add_item(my_list, 12);
    add_item(my_list, 18);
    add_item(my_list, 22);
    show_data(my_list);
    return 0;
}
