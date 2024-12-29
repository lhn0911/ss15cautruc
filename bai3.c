#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void dfs(int vertex, int V)
{
    visited[vertex] = 1;
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i, V);
        }
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
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("Nhap danh sach canh:\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    dfs(0, V);

    int isConnected = 1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            isConnected = 0;
            break;
        }
    }

    if (isConnected)
    {
        printf("Do thi lien thong\n");
    }
    else
    {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}