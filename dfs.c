#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100              

struct Node {                        //Node Structure for Adjacency List
    int vertex;
    struct Node* next;                            //stores address to next vertex
};

struct Graph {                         //Graph Structure
    int numVertices;                               //how many nodes are in the graph
    struct Node** adjLists;               //an array of linked lists (each index represents a vertex)
    int* visited;                //array to mark whether a vertex has been visited during DFS
};

struct Node* createNode(int v) {                       //Create a New Node; allocates memory for a new neighbor node
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {                           //Create Graph
    struct Graph* graph = malloc(sizeof(struct Graph));            //allocate memory for new graph structure
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));             //memory for adjacency list
    graph->visited = malloc(vertices * sizeof(int));                          //memory for visited array

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;                              // mark all as not visited
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {                       //Add Edge (Undirected)
    // src -> dest
    struct Node* newNode = createNode(dest);                        //
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // dest -> src (because undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfs(struct Graph* graph, int vertex) {                //DFS Algorithm (Recursive)
    graph->visited[vertex] = 1;
    printf("%d ", vertex);                            //Visit the node

    struct Node* temp = graph->adjLists[vertex];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (graph->visited[adjVertex] == 0) {
            dfs(graph, adjVertex);                               // Recursive call
        }

        temp = temp->next;
    }
}

int main() {
    struct Graph* graph = createGraph(6);           // Create a graph with 6 vertices (0-5)

    addEdge(graph, 0, 1);                       // Add some edges (feel free to modify)
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("DFS traversal starting from vertex 0: ");
    dfs(graph, 0);
    printf("\n");

    return 0;
}
