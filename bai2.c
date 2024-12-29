#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *adjList[MAX];

int visited[MAX];

Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v)
{
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);
    Node *temp = adjList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
    {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Nhap danh sach cac canh (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    printf("Thu tu duyet DFS: ");
    DFS(start);

    return 0;
}