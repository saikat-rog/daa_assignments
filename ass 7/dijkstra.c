#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

// Function prototypes
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int source, int numVertices);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], numVertices, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, numVertices);

    return 0;
}

// Dijkstra's algorithm to find shortest paths from source
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int source, int numVertices) {
    int dist[MAX_VERTICES]; // Array to store shortest distances
    bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices

    // Initialize all distances as INFINITE and mark all vertices as unvisited
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INF;
    }

    // Distance from source to itself is 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Choose the vertex with the minimum distance from the set of vertices
        // not yet processed
        int minDist = INF, minIndex;
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update distance value of the adjacent vertices of the selected vertex
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INF && dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Print shortest distances
    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < numVertices; i++) {
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
// Enter the adjacency matrix:
// 0 4 5 0
// 4 0 2 0
// 5 2 0 3
// 0 0 3 0
// Enter the source vertex: 0
