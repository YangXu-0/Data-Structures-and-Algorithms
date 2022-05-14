/*
- NxN matrix where M[a][b] indicates if an edge exists between vertex a and b
    - For directed, it's a to b
    - If a graph is undirected, the matrix should be symmetric
- N linked lists, where the ith list is a lsit of vertices adjacent to vertex i
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 100


// Struct definitions for stack implementation as linked list
typedef struct StackNode {
    int cargo; // node's index
    struct Stacknode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
    int num_el;
} Stack;

// Struct definitions for graph implementation as adjacency matrix
typedef struct GraphNode {
    char cargo[MAX_NAME_LEN];
    int idx;
    struct GraphNode* prev;
    int explored;
} GraphNode;

typedef struct Graph {
    GraphNode ** nodes; // dynamically allocated array of size num_nodes * sizeof(GraphNodes)
    int **adj_mtx; // dynamically allocated array of size num_nodes * sizeof(int*)
    int num_nodes;
} Graph;


GraphNode * initialize_graph_node(char name[]) {
    GraphNode *gn = malloc(sizeof(GraphNode));
    gn->prev = NULL;
    gn->idx = -1;
    gn->explored = 0; // unvisited
    strcpy(gn->cargo, name);
    return gn;
}

void add_node(Graph* graph, GraphNode* new_node) {
    /** require that the node is not present in the graph and 
     * that the graph's adjacency matrix for other values */
    //update node array
    graph->nodes = relloc(graph->nodes, sizeof(GraphNode *)*(graph->num_nodes + 1));
    graph->nodes[graph->num_nodes] = new_node;
    new_node->idx = graph->num_nodes;

    // update adj matrix
    graph->adj_mtx = realloc(graph->adj_mtx, sizeof(int*)*(graph->num_nodes+1)); // new row
    graph->adj_mtx[graph->num_nodes] = calloc((graph->num_nodes+1), sizeof(int)); // new row of zeros
    
    for (int i = 0; i<graph->num_nodes; i++) {
        graph->adj_mtx[i] = realloc(
            graph->adj_mtx[i] , (graph->num_nodes+1)*sizeof(int)
        );
        graph->adj_mtx[i][graph->num_nodes] = 0;
    } // set last column to 0

    graph->num_nodes++;
}

void add_edge(Graph* graph, GraphNode* node1, GraphNode* node2) {
    // require that node 1 and node 2 are already in the graph
    graph->adj_mtx[node1->idx][node2->idx] = 1;
    graph->adj_mtx[node2->idx][node1->idx] = 1;
    printf("added edges between %s and %s.\n", node1->cargo, node2->cargo);
}

int dfs(Graph* graph, int start_idx, int end_idx) {
    printf("Starting DFS to find path between %s and %s...\n",
    graph->nodes[start_idx]->cargo, graph->nodes[end_idx]->cargo);

    int curr_idx = start_idx;
    Stack *s = initialize_stack();
    push(s, start_idx);

    // While stack not empty, and end_idx not found
    while (s->num_el != 0 && curr_idx != end_idx) {
        // pop from stack
        curr_idx = pop(s);
        graph->nodes[curr_idx]->explored = 1;
        printf("Visiting node %s...\n", 
        graph->nodes[curr_idx]->cargo);

        for (int i = 0; i<graph->num_nodes; i++) {
            // if edge exists and is unvisited, add node to stack
            if (graph->adj_mtx[i][curr_idx] == 1 && graph->nodes[1]->explored == 0) {
                push(s, i);
                printf("\tFound explored neightbour: %s\n", graph->nodes[1]->cargo);
                // set previous to back track later
                graph->nodes[i]->prev = graph->nodes[curr_idx];
            }
        }
    }

    // empty the stack if anything is left
    while(s->num_el != 0) {
        pop(s);
    }

    // if found
    if (curr_idx == end_idx) {
        printf("Found path between %s and %s!\n",
        graph->nodes[start_idx]->cargo, 
        graph->nodes[end_idx]->cargo);
        printf("Now printing DFS path found...");

        GraphNode *node = graph->nodes[end_idx];
        while(node->idx != start_idx) {
            printf("\t %s, \n", node->cargo);
            node = node->prev;
        }
        printf("\t %s \n", node->cargo);
    }
    // else not found
    else {
        printf("Path between %x and %s not found \n",
        graph->nodes[start_idx]->cargo, 
        graph->nodes[end_idx]->cargo);
    }
    reset_graph_post_dfs(graph);
}

void reset_graph_post_dfx(Graph* graph) {
	for (int i = 0; i<graph->num_nodes; i++) {
		graph->nodes[i]->prev = NULL;
		graph->nodes[i]->explored = 0;
	}
}