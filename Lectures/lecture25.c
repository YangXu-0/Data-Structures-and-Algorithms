/*
Graph ADT
- A graph consists of a set of verticies/nodes and a set of edges
    - Recall sets are collections of unqiue entities
    - Edges indicate the relationship between vertices
    - Every edge connects exactly 2 vertices
        - Two adjacent/neighbour vertices connected are by 1 edge
    - A path connecting two vertices is the set of edges that join them
        - Each vertex is adjacent to the next in the sequence of edges
        - The path length is the number of edges

Directed vs Undirected
- Directed graph: edges have a specified direction (one-way connection)
    - E.g. trees
- Undirected graph: adjacent nodes are connected in both directions
- There is no root vertex but you can choose a starting vertex

Weighted vs. Unweightted
- Weighted graph: there is a weight value associated with each edge
- Unweighted graph: all edges are weighted equally

Connected vs. Disconnected
- Connected graph: thre is a path between every possible pair of vertices
- Disconnected graph there is at least one pair of vertices that cannot be connected by a path

Cyclic vs Acyclic
- Cyclic graph: there is a vertex with a path to itself
    - This path is called a cycle
- Acyclic graph: thre are no vertices with a path to itself

Graphs
- Graphs are a collection of vertices and edges G(V, E)
- How do we implement a graph of (N vertices)?
    - Adjacency matrix
        - N x N matrix where M[a][b] indicates if an edge exists between vertex a and vertex b
        - Can store edge weight at M[a][b]
        - Need a value to indicate no edge exists, e.g. 0
    - Adjacency list
        - N linked lists, where the ith list is the list of vertices adjacent to vertex i
        - Can store edge weifghts in the linked lis nodes

Finding a path between vertices
- For an arbitrary graph, does a path exist between two vertices, A and B?
    - Designate the start vertex (A) and destination vertex (B)
        - Traverse graph from start vertex, searching for the destination vertex
        - Keep track vertices explored (and path taken)
- If a path exists between A and B, is it unique?
    - May want to find all possible paths
    - Usually want to know if it is the shortest path

General Algorithm - Graph Traversal
- Create helper data structure (DS) to store unvisted vertices
    - Add a starting vertex to the DS
- While (there is a vertex to visit)
    - Remove a vertex, V, from the DS
    - Visit V, if it is unvisited,
    - Add unvisited vertices adjacent to V in the DS

General Algorithm - Search
- Create a helper DS to store unvisited verticesd
    - Add a starting vertex to the DS
- While (there is a vertex to visit and target not found)
    - Get a vertex, V, from the DS
    - Visit V, if it is unvisited
        - If V is the target, return
    - Add unvisited vertices adjacent to V to the DS
- Depth-First Search (DFS) - expands by depth
    - Use a stack as the DS, LIFO
- Breadth First Search - expand current level before deepning the search
    - Use a queue as the DS, FIFO

Graph Traversal - DFS
- Create a stack to store unvisited vertices
    - Push starting vertex to the stack
- While (stack not empty and target not found)
    - Pop a vertex, V, from the stack
    - Visit V, if unvisited
        - If V is the target, return
    - Push unvisited vertices adjacent to V to the stack
- If a path does not exist between A and B, the search would stop when the stack is empty

Graph Traversal - BFS
- Create queue to store unvisited vertices
    - Enqueue starting vertex to the queue
- While (queue not empty and target not found)
    - Dequeue a vertex, V, from the queue
    - Visit V, if unvisited
        - If V is the target, return
    - Enqueue unvisited vertices adjacent to V to the queue
- If a path does not exist between A and B, the search would stop when the queue is empty
- Should find the shortest path when the graph is unweighted
    - Could modify to keep going to find other paths
    - To retrieve the path, need to keep track of previous nodes and back-track
    - What if the graph was weighted?


*/