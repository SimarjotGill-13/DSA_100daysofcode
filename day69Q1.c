/* Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

struct MinHeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct MinHeapNode pop(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];
    struct MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = pop(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < graph->V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    struct Graph graph;
    graph.V = 5;

    for (int i = 0; i < graph.V; i++)
        graph.adj[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 4, 1, 3);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 0, 7);

    dijkstra(&graph, 0);

    return 0;
}
