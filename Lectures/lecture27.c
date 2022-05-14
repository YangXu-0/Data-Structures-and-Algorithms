/*
- Adjacency matrix: preferred for densely/highly connected graphs
- Adjacency list: preferred for sparsely connected graphs

- Checking if two vertices are neighbours
    - Adjacency matrix: O(1) using array indexing
    - Adjacency list: best case O(1), worst case O(n), for n neighbours

- Storing the graph
    - Adjacency matrix: O(V^2) for V vertices
    - Adjacency list: O(V+E) for V vertices and E edges

Graph + DFS Implementation
- Stack (linked list) + graph (adjacency matrix)
- Graph each graph node: index, previous, explored
- Add index to stack for DFS
- Track number of nodes in both the stack and the graph to use as index
- Update previous and explored DFS progress, reset afterwards

Code on previous lecture file

Traversal Runtime Complexity
- O(V+E) where V = number of vertices and E = number of edges for both DFS and BFS
- But implementation details matter
    - Adding and removing vertices from the DS
        - Can be O(2n) for n vertices if DS add/remove operations are O(1)
    - Checking if a vertex is visited
        - Can be O(1) if we can use array indexing
    - Checking for adjacent vertices
        - Can be O(m) for edges if using an adjacency list
        - Can be O(n^2) for n vertices if using an adjacency matrix (n^2 entries)

Graph Traversal + Search
- General algorithm:
    - Create helper DS to store unvisited vertices
- While (there is a vertex to visit and target not found)   
    - Get a vertex V from the DS
    - Visit V if it is unvisited
        - If V is the target return
    - Add unvisited vertices adjacent to V to the DS

- Runtime complexity
    - Best case: starting vertex is the vertex we're looking for O(1)
    - Worst case: need to traverse the entire graph -> O(V+E)

DFS For Exploration Time
- Add additional fields to each vertex based on a clock that ticks forward once for each vertex
  visited (including exploration and labelling visits)
- For each vertex, V, the:
    - Discovery time d[v] is the time it is visited and its neighbours are added to the stack
    - Finishing time f[v] is the time all neighbours of vertex V have been explored as deeply as possible

DFS for MSTs, Cycle Detection
- Minimum spanning tree: tree with minimum number of edges (tree edges) to span all the vertices in a connected graph
- Can identify ancestor - descendant relationships (ancestors have <Dt and >Ft)
- V-1 edges for undirected graph
- For a weighted graph, the sum of weighted edges should be the minimum among possible spanning trees
- For a disconnected graph, we get a forest (collection of trees)
- A cycle is indicated by an edge connecting ancestor and descendant that is not part of the MST
- For a directed graph:
    - Forward edges point from ancestor to descendant 
    - Back edges point from descendant to ancestor

Shortest Path for a Weighted Graph
- Recall path length is the number of edges in the path between two vertices
- If the edges are weighted, the path length is the sum of the weights of the edges in the path
- BFS may not find the shortest path if the weights are not considered 

Dijkstra's Algorithm
- Similar to BFS, but prioritizing low cost paths to find a shortest path in a weighted graph
    - A priority queue makes sense here for getting the next vertex to visit
    - Otherwise, loop through options
- Keep track of costs to get to each vertex from a starting vertex (initialize to infinity for each vertex)
  and list of vertices to consider (initialize to all vertices)
- Choosing a starting vertex V
    - Update the costs of v's neighbours to the weight of the edge between them 
    - Remove V from list of vertices to consider (v is now visited)
- Choose new vertex from list based on smallest cost and repeat
    - Update costs of nodes to be the new minimums 
- Stop when destination vertex is visited, or remaining vertices have infinite cost (there vertices are disconnected)
- If you need a path from vertex A and B, you can stop early when you encounter vertex B (not the shortest path, but codes runs faster)
- A*search Algorithm 
    - Sometimes you have other information about how far we are from the destination vertex
        - A heuristic function h(vertex) used to prioritize vertices
    - Useful when the graph is large and densly connected
*/