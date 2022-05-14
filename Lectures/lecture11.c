/*
Inserting at front
void insert_node(struct node **head, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

Deleting a node a the front

int delete_node(struct node **head, int value) {
    struct node *curr=*head, *prev=NULL;
    while(curr!=NULL && curr->data!=value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr==NULL) {
        return -1;   // Couldn't find
    }
    else if (prev==NULL) {  // deleting first node
        *head = (*head)->next;  // safe because curr is pointing to first node
    }
    else {  // deleting non-first node
        prev->next = curr->next;    // bypass
    }

    int data_save = curr->data;
    free(curr);
    return data_save;
}

- Can use recursion to insert, delete, index
- Insert into a linked list
    - Base case: if (...) then insert
        - Check value, check end of list
    - Otherwise, recursive case: call insert() on smaller portion of the list
        - insert(current_node->next, value);
        - insert(&(current_node->next), value);
    - Similar for using recursion to delete(...) or index(...)

- Need dynamic memory allocation for nodes since when a function ends, all
  the static variables are freed up and their memory can be overwritten
    - Undefined behaviour
- Can declare a static node and return a pointer to it (error/warning)
- If you allocate memory for a variable, it will not be freed/overwritten unless you free it/accidentally overwrite it
  with your code

- atoi and atof return 0, 0.0, for "0" and "not a number"
    - need isdigit(int character);
        - from ctype.h
        - returns non-zero integer for numeric characters
        - returns 0 for non-numeric characters

- be careful, *x[*n] will shift the x pointer before dereferencing
*/