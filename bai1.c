#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    Node *head[MAX];
    int visited[MAX];
} Graph;

typedef struct Queue
{
    int items[MAX];
    int front, rear;
} Queue;

void initGraph(Graph *graph, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        graph->head[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("hang doi day\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("hang doi rong\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

void bfs(Graph *graph, int startVertex, int vertices)
{
    Queue q;
    initQueue(&q);

    printf("thu tu duyet BFS: ");
    enqueue(&q, startVertex);
    graph->visited[startVertex] = 1;

    while (!isEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        Node *temp = graph->head[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
            {
                enqueue(&q, adjVertex);
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    Graph graph;
    int vertices, edges, startVertex;

    printf("nhap so dinh: ");
    scanf("%d", &vertices);
    printf("nhap so canh: ");
    scanf("%d", &edges);

    initGraph(&graph, vertices);

    printf("nhap danh sach cac canh (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    printf("nhap dinh bat dau duyet: ");
    scanf("%d", &startVertex);

    bfs(&graph, startVertex, vertices);

    return 0;
}