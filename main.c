#include <stdio.h>
#include<stdlib.h>


struct linked_list_element
{
    void *data;
    struct linked_list_element  *next;
};

void init_list_element(struct linked_list_element* element)
{
    element->next = NULL;
    element->data = NULL;
}

struct linked_list_element* get_last_list_element(struct linked_list_element* head)
{
    struct linked_list_element* cur = head;
    while (cur != NULL)
    {
        if (cur->next == NULL)
            break;
        cur = cur->next;
    }
    return cur;
}


void add_list_element(struct linked_list_element* head,void* data)
{
    if(head->data == NULL)
    {
        head->data = data;
    } else{
        struct linked_list_element* last_elem = get_last_list_element(head);
        struct linked_list_element* elem  = (struct linked_list_element*)malloc(sizeof(struct linked_list_element));
        init_list_element(elem);
        elem->data = data;
        last_elem->next = elem;
    }
}
int main() {


    struct linked_list_element head;
    //initialize the list head
    init_list_element(&head);

    //add the first element to the list
    add_list_element(&head,"Hello World");

    //add the second element to the list
    add_list_element(&head,"second element");

    //add the third element to the list
    add_list_element(&head,"third");



    struct linked_list_element* cur = &head;

    while (cur != NULL)
    {
        printf("%s \n",(const char*) cur->data);
        cur = cur->next;
    }
    return 0;
}
