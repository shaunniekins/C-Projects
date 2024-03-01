#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// A structure to represent a graph node
struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

// A structure to represent a graph
struct Graph {
    struct GraphNode* vertices[MAX_VERTICES];
    int num_vertices;
};

// Function to create a new graph node
struct GraphNode* createNode(int vertex) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct GraphNode* newNode = createNode(dest);
    newNode->next = graph->vertices[src];
    graph->vertices[src] = newNode;

    // Add edge from dest to src (since it's an undirected graph)
    newNode = createNode(src);
    newNode->next = graph->vertices[dest];
    graph->vertices[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        struct GraphNode* temp = graph->vertices[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = 5;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
