#include <stdio.h>
#include <limits.h>     //helps iclude INT_MAx, i.e. lagest integer number that can be entered

#define V 9          //Number of vertices in the graph
 
int minDistance(int dist[], int sptSet[]) {          //finds the vertex with the smallest temporary(will be updated later) distance that hasn’t been included in the Shortest Path Tree 
    int min = INT_MAX;     // initialize all minimum distances as ifinity
    int min_index;

    for (int v = 0; v < V; v++) {    //iterates through all vertices to find the vertex (v) not yet included in the sptSet
        if (sptSet[v] == 0 && dist[v] <= min) {         //update min if vertex not already in sptSet and distance smaller than current min for that vertex
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int n) {                 //to print the constructed distance array
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {                // iterates over each vertex and prints it's index and its distance from the source
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {               //Dijkstra's single-source shortest path algorithm
    int dist[V];                                //output array that holds the shortest distance from src to i
    int sptSet[V];  //sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from the source is finalized
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;               //Initialize all distances as infinite and sptSet[] as false, i.e. no mindist finalised yet
        sptSet[i] = 0;
    }

    dist[src] = 0;              //Distance from the source to itself is always 0

    for (int count = 0; count < V - 1; count++) {                   //Find shortest path for all vertices
        
        int u = minDistance(dist, sptSet);   //Pick the minimum distance vertex from the set of vertices not yet processed amd consider it new temporary source

        sptSet[u] = 1;       //Mark the picked vertex as processed

        for (int v = 0; v < V; v++) {     //Update dist[] value of the adjacent vertices of the picked vertex
            // Update dist[v] if and only if the current vertex is not in sptSet, i.e. it's minimum distance not yet finalised
            //Update when there is an edge from u to v, and the total distance from src to v, through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];        //Updating distance value
            }
        }
    }

    printSolution(dist, V);      //Print the constructed distance array
}

int main() {
    
    int graph[V][V] = {                          //adjacency matrix
        {0, 4, 0, 0, 0, 0, 0, 8, 0},          //2D array where graph[i][j] represents the weight of the edge from vertex i to vertex j
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int source = 0;                //source vertex

    dijkstra(graph, source);

    return 0;
}
