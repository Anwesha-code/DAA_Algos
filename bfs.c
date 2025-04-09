#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node{                      //Node Structure for Adjacency List
    int vertex;
    struct Node* next;
};

struct Graph {                           //Graph Structure
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Queue {                             //Queue for BFS
    int items[MAX_VERTICES];
    int front, rear;
};

struct Node* createNode(int v) {                        //Create a New Node
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {                       //Create Graph
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;  // Mark all as not visited
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {             //Add Edge (Undirected)
    // src -> dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // dest -> src (since it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct Queue* createQueue() {                         //Queue Functions
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        return;
    }
    if (q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return item;
}

void bfs(struct Graph* graph, int startVertex) {          //BFS Algorithm
    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);          //Add edges
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    bfs(graph, 0);  // Start BFS from vertex 0

    return 0;
}
