#include "lab3.h"

//Add TA party item request to the list
int add_request(struct party_node **head, char *item, double price, char *ta){
    // Checking for IDE
    
    if (strcmp(item, "IDE") == 0) {
        return -1;
    }

    struct party_node *new;
    new = (struct party_node *)malloc(sizeof(struct party_node));

    // Adding item
    /* weird way to do it with 1 loop
    new->item = malloc(100 * sizeof(char)); // Assuming size of string is less than 100
    int counter = 0;
    while (*(item+counter) != '\0') {
        (new->item)[counter] = *(item+counter);
        counter += 1;
    }
    (new->item)[counter] = '\0';
    new->item = realloc(new->item, counter * sizeof(char));
    */
    int counter = 0;
    while (item[counter] != '\0') {
        counter += 1;
    }
    counter += 1;
    new->item = malloc(counter*(sizeof(char)));
    for (int i = 0; i<counter; i++) {
        (new->item)[i] = item[i];
    }

    new->price = price;

    // Adding ta
    counter = 0;
    while (ta[counter] != '\0') {
        counter += 1;
    }
    counter += 1;
    new->ta = malloc(counter*sizeof(char));
    for (int i = 0; i<counter; i++) {
        (new->ta)[i] = ta[i];
    }

    new->next = *head;

    // Adjusting head
    *head = new;

    return 0;
}

//Remove the last item added
void remove_request(struct party_node **head){

    if (*head == NULL) {
        return;
    }

    struct party_node *delete = *head;
    *head = delete->next;
    
    free(delete->item);
    free(delete->ta);
    free(delete);
}

//Sort party item requests - in place baby lets gooo this took me way too long
void make_sorted(struct party_node **head){
    int flag = 0;
    struct party_node *start = *head;
    struct party_node *previous_max = NULL;
    while (flag != -1) {
        int flag2 = 0;
        struct party_node *max = start;
        struct party_node *before_max;
        struct party_node *after_max;
        struct party_node *current = start;
        current = current->next;
        struct party_node *previous = start;

        // Check if start is the last node (indicates entire list was traversed)
        if (start->next == NULL) {
            flag = -1;
            continue;
        }

        // Finds the node with the largest price
        while (flag2 != -1) {
            if (max->price < current->price) {
                before_max = previous;
                max = current;
                after_max = max->next;
            }

            previous = current;
            current = current->next;
            if (current == NULL) {
                flag2 = -1;
            }
        }

        // Check if max is the first node
        if (max == start) {
            previous_max->next = start;
            previous_max = start;
            start = start->next;
            continue;
        }

        // Swap max to "front"
        before_max->next = after_max;
        max->next = start;
        // This is for the first iteration
        if (previous_max == NULL) {
            previous_max = max;
            *head = max;
            continue;
        }
        // This is for all other iterations
        else {
            previous_max->next = max;
            previous_max = max;
        }
    }
}

//Trim list to fit the budget
double finalize_list(struct party_node **head, double budget){
    int flag = 0;
    struct party_node *current = *head;
    struct party_node *previous = NULL;
    while (flag != -1) {
        if (current->price <= budget) {
            budget -= current->price;
            previous = current;
            current = current->next;
        }
        else {
            if (previous != NULL) {
                previous->next = current->next;
            }
            else {
                *head = current->next;
            }
            struct party_node *temp = current;
            current = current->next;
	        free(temp->item);
            free(temp->ta);
            free(temp);
        }

        if (current == NULL) {
            flag = -1;
        }

    }

    return budget;
}

//Print the current list - hope this is helpful!
void print_list(struct party_node *head){
    int count = 1;
    printf("The current list contains:\n");
    while(head!=NULL){
        printf("Item %d: %s, %.2lf, requested by %s\n",
            count, head->item, head->price, head->ta);
        count++;
        head = head->next;
    }
    printf("\n\n");
    return;
}

/*

1. Is LIFO a good method for handling part requests?
In terms of processing the requests, in the way set out in this lab, not really.
But in general, it would probably make more sense that the requests that come first
are fulfilled first.

2. What are other ways to sort the data and trim the list? What are the advantages and
    disadvantages?
Could sort it chronologically (as in when the requests are submitted). Advantages are that it may
be more fair (following the idea of first come first serve) and is much easier to implement since
the list would be automatically sorted as requests are added. A disadvantage of this idea however
is that the best items (based on price at least) may not be chosen.

*/
