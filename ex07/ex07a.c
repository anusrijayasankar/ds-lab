#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node *next;
};

// Structure for the graph
struct Graph {
    struct Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Structure for the queue
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Create a new node
struct Node *createNode(int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Create a graph
struct Graph *createGraph() {
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));

    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i;

    for (i = 0; i < MAX_VERTICES; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {

    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    // This makes the graph undirected
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Create a queue
struct Queue *createQueue() {
    struct Queue *queue =
        (struct Queue *)malloc(sizeof(struct Queue));

    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// Check whether queue is empty
int isEmpty(struct Queue *queue) {
    return queue->rear == -1;
}

// Add an element to the queue
void enqueue(struct Queue *queue, int value) {

    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    }
    else {

        if (queue->front == -1) {
            queue->front = 0;
        }

        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove an element from the queue
int dequeue(struct Queue *queue) {

    int item;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    }
    else {

        item = queue->items[queue->front];
        queue->front++;

        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }

    return item;
}

// Print the adjacency list
void printGraph(struct Graph *graph) {

    int v;

    for (v = 0; v < MAX_VERTICES; v++) {

        if (graph->adjLists[v] != NULL) {

            printf("Vertex %d: ", v);

            struct Node *temp = graph->adjLists[v];

            while (temp != NULL) {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }

            printf("NULL\n");
        }
    }
}

// BFS traversal
void BFS(struct Graph *graph, int startVertex) {

    struct Queue *queue = createQueue();

    // Mark starting vertex as visited
    graph->visited[startVertex] = 1;

    // Insert starting vertex into queue
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {

        int currentVertex = dequeue(queue);

        printf("Visited %d\n", currentVertex);

        struct Node *temp =
            graph->adjLists[currentVertex];

        while (temp != NULL) {

            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {

                graph->visited[adjVertex] = 1;

                enqueue(queue, adjVertex);
            }

            temp = temp->next;
        }
    }

    free(queue);
}

int main() {

    // Create graph
    struct Graph *graph = createGraph();

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    // Print graph
    printf("Graph adjacency list:\n");
    printGraph(graph);

    // BFS traversal
    printf("\nBFS Traversal starting from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}

