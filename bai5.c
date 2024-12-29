#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int vertex, int V)
{
    visited[vertex] = 1;
    recStack[vertex] = 1;

    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] == 1)
        {
            if (!visited[i] && dfs(i, V))
            {
                return 1;
            }
            else if (recStack[i])
            {
                return 1;
            }
        }
    }
    recStack[vertex] = 0;
    return 0;
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

    printf("Nhap danh sach canh (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, V))
            {
                printf("Do thi co chu trinh\n");
                return 0;
            }
        }
    }
    printf("Do thi khong co chu trinh\n");

    return 0;
}