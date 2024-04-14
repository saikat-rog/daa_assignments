#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Global variables
struct Edge edges[MAX_VERTICES];
int numEdges, numVertices;

// Function prototypes
void bellmanFord(int source);
void printDistances(int dist[]);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter source, destination, and weight of each edge:\n");
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(source);

    return 0;
}

// Bellman-Ford algorithm to find shortest paths from source
void bellmanFord(int source) {
    int dist[MAX_VERTICES];

    // Initialize distances from source to all other vertices as INFINITE
    for (int i = 0; i < numVertices; ++i) {
        dist[i] = INF;
    }
    dist[source] = 0; // Distance from source to itself is 0

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= numVertices - 1; ++i) {
        for (int j = 0; j < numEdges; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < numEdges; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print distances
    printf("Shortest distances from source vertex %d:\n", source);
    printDistances(dist);
}

// Function to print distances from source
void printDistances(int dist[]) {
    for (int i = 0; i < numVertices; ++i) {
        printf("Vertex %d: ", i);
        if (dist[i] == INF) {
            printf("INFINITE\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}



// Output:
// Enter the number of vertices: 4
// Enter the number of edges: 5
// Enter source, destination, and weight of each edge:
// 0 1 4
// 0 2 5
// 1 2 -2
// 1 3 6
// 2 3 1
// Enter the source vertex: 0
