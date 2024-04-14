#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Global variables
struct Edge edges[MAX_EDGES];
struct Subset subsets[MAX_VERTICES];
int numEdges, numVertices;

// Function prototypes
void kruskalMST();
int find(int vertex);
void unionSets(int x, int y);
int compareEdges(const void* a, const void* b);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter source, destination, and weight of each edge:\n");
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST();

    return 0;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskalMST() {
    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    // Initialize subsets
    for (int v = 0; v < numVertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int mstWeight = 0; // Weight of MST
    printf("Edges in the Minimum Spanning Tree:\n");

    // Process each edge in sorted order
    for (int i = 0; i < numEdges; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        int srcParent = find(src);
        int destParent = find(dest);

        // If including this edge does not cause cycle, include it in the MST
        if (srcParent != destParent) {
            printf("%d - %d, Weight: %d\n", src, dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(srcParent, destParent);
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", mstWeight);
}

// Find set of an element
int find(int vertex) {
    if (subsets[vertex].parent != vertex) {
        // Path compression
        subsets[vertex].parent = find(subsets[vertex].parent);
    }
    return subsets[vertex].parent;
}

// Union of two sets
void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    // Union by rank
    if (subsets[xRoot].rank < subsets[yRoot].rank) {
        subsets[xRoot].parent = yRoot;
    } else if (subsets[xRoot].rank > subsets[yRoot].rank) {
        subsets[yRoot].parent = xRoot;
    } else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

// Comparison function used by qsort
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
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
