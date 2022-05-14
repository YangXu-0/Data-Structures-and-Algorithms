/*
struct node {
    int data;
    struct node *next;
}
- need the * in *next or else it is recursively declaring nodes which is infinite memory

int main() {
    struct node *head = NULL;
    head = insert_node(head, 1);
    return 0;
}

- insertion function
    - allocate memory for a new node
    - store the node data,
    - connect the node to the list
        - make the new node point to somewhere in the list
        - make the previous node point to the new node

struct node* insert_node(struct node *head, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;        // this current code doesn't change the head pointer in the main func.
}

- indexing
    - search for a value, return value, return pointer to node
    - operations on node data
- use a pointer to loop through the list
    - until value is found or until we get to the end of the list
        - next value is null --> end of the list

int search_list(struct node *head, int value) {
    while (head!=NULL) {
        if (head->data == value) {
            return 1;
        }
        head = head->next;   // can move head in this case since it is a copy
    }
    return 0;
}

- deleting
    - locate the node in front of the node to be deleted (previous node)
    - hold on to the memory address of the node to be deleted
    - connect the previous node to the node after the node to be deleted
    - free the node to be deleted

struct node* delete_node(struct node *head, int value) {
    struct node *curr=head, *prev=NULL;
    while(curr != NULL && curr->data!=value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr==NULL) {           // couldn't find
        return head;
    }
    else if (prev==NULL) {      // deleting first node
        head = head->next;
    }
    else {                      // deleting non-first node
        prev->next = curr->next;
    }
    free(curr);
    return head;
}

void delete_list(struct node **head) {
    struct node *curr=*head, *prev=curr;

    while(curr->next != NULL) {
        curr = curr->next;
        free(prev);
        prev = curr;
    }
    free(curr);
    *head = NULL;
    return;
}

- when returning a value instead of using a double pointer, it can return extra data
    Ex. confirmation of the insertion/deletion, the data value inserted/deleted, pointer to the inserted/deleted node

-size_t getline(char **lineptr, size_t *n, FILE *stream); <stdio.h>
    - fscanf() alternative, returns # of characters read
    - stores a line from stream into *lineptr, will realloc() if needed
    - if *lineptr is NULL, getline() will allocate *n bytes of memory
- int atoi(const char *str) <stdlib.h>
    - returns the integer interpretation of *str or 0
- double atof(const char *str) <stdlib.h>
    - returns the float interpretation *str
*/