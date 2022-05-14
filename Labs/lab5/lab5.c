#include "lab5.h"

void print_queue(Vnode **queue, int count_queue) {// debugging
    printf("The queue is currently: ");
    for (int i = 0; i<count_queue; i++) {
        printf("%s ", queue[i]->station);
    }
    printf("\n");
}

void dijkstra(Vnode **queue, Graph *gr) {
    // Steps: (old)
    // Take node from queue
    // Add edges to queue if node not visited (realloc if size too small)
    // For each edge, add cost of node + edge and check if smaller than cost (or if cost -1)
    // If new cost is smaller of cost == -1, replace. Add node to queue again to recalculate children. Make visited
    // If not move on
    // If queue empty end loop
    
    int count_queue = 1;
    int queue_index = 0;

    // iterate through nodes
    while (count_queue != queue_index) {
        Vnode *cur_node = queue[queue_index];

        if (queue_index == 0) {
            cur_node->prev = NULL;
            cur_node->cost = 0;
        }

        cur_node->visited = 0;
        //print_queue(queue, count_queue);
        Enode *temp = cur_node->edges;
        // iterate through edges
        while (temp != NULL) {
            Vnode *temp_vertex;
            for (int i = 0; i<gr->count; i++) {
                if (strcmp(gr->adj_list[i]->station, temp->vertex) == 0) {
                    temp_vertex = gr->adj_list[i];
                }
            }

            int temp_cost = temp->weight + cur_node->cost;

            if (temp_vertex->cost > temp_cost || temp_vertex->cost == -1) {
                temp_vertex->cost = temp_cost;
                temp_vertex->visited = -1;
                temp_vertex->prev = cur_node;
            }

            if (temp_vertex->visited == -1) {
                queue = realloc(queue, (count_queue+1)*sizeof(Vnode *));
                queue[count_queue] = temp_vertex;
                count_queue += 1;
            }

            temp = temp->next;
        }

        queue_index += 1;
    }

    free(queue);
}

void reset_gr(Graph *gr) {
    for (int i = 0; i < gr->count; i++) {
        gr->adj_list[i]->cost = -1;
        gr->adj_list[i]->prev = NULL;
        gr->adj_list[i]->visited = -1; // -1 for not visited, 0 for visited
    }
}

char **plan_route(Graph *gr, char *start, char *dest){
    // Steps:
    // Make queue array and add start
    // Make array with copy of each vertex and set cost to -1
    // Call dijkstra's algorithm
    // Iterate through to find shortest path
    // Free everything
    // Return values

    /* drunk code
    Graph *gr_copy = (Graph *)malloc(sizeof(Graph));
    gr_copy->count = gr->count;
    gr_copy->adj_list = (Vnode **)malloc(sizeof(Vnode *) * gr->count);

        gr_copy->adj_list[i] = (Vnode *)malloc(sizeof(Vnode));
        strcpy(gr_copy->adj_list[i]->station, gr->adj_list[i]->station);
    */ 

    reset_gr(gr);

    Vnode **queue = (Vnode **)malloc(sizeof(Vnode *));
    Vnode *dest_node = NULL;
    Vnode *start_node = NULL;

    for (int i = 0; i<gr->count; i++) {
        if (strcmp(gr->adj_list[i]->station, start) == 0) {
            queue[0] = gr->adj_list[i];
            start_node = gr->adj_list[i];
        }

        if (strcmp(gr->adj_list[i]->station, dest) == 0) {
            dest_node = gr->adj_list[i];
        }
    }

    if (start_node == NULL || dest_node == NULL) {
        free(queue);
        return NULL;
    }
    
    dijkstra(queue, gr);

    if (dest_node->visited == -1) {
        return NULL;
        // No connection
    }
    
    char **r = (char **)malloc(sizeof(char*));
    int r_count = 1;    
    int r_index = 0;
    
    Vnode *temp = dest_node;
    while (temp != NULL) {
        if (r_count <= r_index) {
            r = realloc(r, (r_count+1)*sizeof(char *));
            r_count += 1;
        }

        r[r_index] = malloc(sizeof(char)*MAX_LEN);
        strcpy(r[r_index], temp->station); // for some reason they're freeing the elements so I must do this
        r_index += 1;

        temp = temp->prev;
    }

    //free(queue);
    return r;
}

void add(Graph *gr, char *station){
    for (int i = 0; i<gr->count; i++) {
        if (strcmp(station, gr->adj_list[i]->station) == 0) {
            return;
        }
    }

    if (gr->adj_list == NULL) {
        gr->adj_list = (Vnode **)malloc(sizeof(Vnode *));
    }
    else {
        gr->adj_list = realloc(gr->adj_list, (gr->count+1)*sizeof(Vnode *));
    }
    
    Vnode *new = (Vnode *)malloc(sizeof(Vnode));
    strcpy(new->station, station);
    new->edges = NULL;
    gr->adj_list[gr->count] = new;
    gr->count += 1;
    return;
}

void update(Graph *gr, char *start, char *dest, int weight){
    // If weight == 0 cases
    if (weight == 0) {
        for (int i = 0; i<gr->count; i++) {
            if (strcmp(gr->adj_list[i]->station, start) != 0) {
                continue;
            }
            else {
                Enode *temp = gr->adj_list[i]->edges;
                Enode *prev = NULL;

                while (temp != NULL) {
                    if (strcmp(temp->vertex, dest) == 0) {
                        if (prev == NULL) {
                            gr->adj_list[i]->edges = temp->next;
                        }
                        else {
                            prev->next = temp->next;
                        }
                        free(temp);
                        return;
                    }
                    
                    prev = temp;
                    temp = temp->next;
                }
                
            }
        }
    }
    else {
        // Weight != 0 cases
        int flag = -1; // if start or dest not in, will be set to 0

        // Check if start is in
        Vnode *start_node = NULL;
        for (int i = 0; i<gr->count; i++) {
            if (strcmp(start, gr->adj_list[i]->station) == 0) {
                start_node = gr->adj_list[i];
            }
        }
        if (start_node == NULL) {
            flag = 0;
            add(gr, start);
            start_node = gr->adj_list[gr->count - 1];
        }

        // Check if dest is in
        Vnode *dest_node = NULL;
        for (int i = 0; i<gr->count; i++) {
            if (strcmp(dest, gr->adj_list[i]->station) == 0) {
                dest_node = gr->adj_list[i];
            }
        }
        if (dest_node == NULL) {
            flag = 0;
            add(gr, dest);
            dest_node = gr->adj_list[gr->count - 1];
        }

        // Both should now be in, check if edge exists
        if (flag != 0) {
            Enode *edge = start_node->edges;
            while (edge != NULL) {
                if (strcmp(dest, edge->vertex) == 0) {
                    edge->weight = weight;
                    return;
                }
                edge = edge->next;
            }
            flag = 0; // edge doesn't exist, set flag to 0;
        }

        if (flag == 0) { // not really necessary ik
            // Constructing edge
            Enode *new = (Enode *)malloc(sizeof(Enode));
            strcpy(new->vertex, dest);
            new->weight = weight;
            new->next = NULL; // all linked lists of edges will end with NULL

            // Linking edge
            Enode *edge = start_node->edges;
            if (edge != NULL) {
                while (edge->next != NULL) {
                    edge = edge->next;
                }
                edge->next = new;
            }
            else {
                start_node->edges = new;
            }
        }
    }
}

void disrupt(Graph *gr, char *station){
    // Grab station node
    Vnode *station_node = NULL;
    for (int i = 0; i<gr->count; i++) {
        if (strcmp(gr->adj_list[i]->station, station) == 0) {
            station_node = gr->adj_list[i];
            //gr->adj_list[i] = NULL; // setting station to null in the adj_list
        }
    }
    
    // Free edges directed to station;
    for (int i = 0; i < gr->count; i++) {
        Vnode *temp = gr->adj_list[i];
        Enode *prev = NULL;
        Enode *edge = temp->edges;

        while (edge != NULL) {
            if (strcmp(edge->vertex, station) == 0) {
                if (prev == NULL) {
                    temp->edges = edge->next;
                }
                else {
                    prev->next = edge->next;
                }
                free(edge);
                break; // assuming only one connection between 2 stations
            }

            prev = edge;
            edge = edge->next;
        }
    }

    // Free station memory
    if (station_node->edges != NULL) {
        Enode *cur_node = station_node->edges;
        Enode *next = cur_node->next;

        free(cur_node);
        while (next != NULL) {
            cur_node = next;
            next = next->next;

            free(cur_node);
        }
    }
    
    // Moving everything
    Vnode **new = (Vnode **)malloc(sizeof(Vnode *)*(gr->count - 1));
    int ind = 0;
    for (int i = 0; i<gr->count; i++) {
        if (strcmp(station_node->station, gr->adj_list[i]->station) != 0) {
            new[ind] = gr->adj_list[i];
            ind += 1;
        }
    }

    free(station_node);
    gr->count -= 1;
    free(gr->adj_list);
    gr->adj_list = new;

    if (gr->count == 0) {
        free(gr->adj_list);
        gr->adj_list = NULL;
    }
}