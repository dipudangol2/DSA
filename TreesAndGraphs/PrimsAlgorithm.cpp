#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int arr_size;

#define MAX 10

int minKey(int key[], bool mstSet[], int arr_size)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < arr_size; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[][MAX], int arr_size)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < arr_size; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}

void primMST(int graph[][MAX], int arr_size)
{
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < arr_size; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < arr_size - 1; count++)
    {

        int u = minKey(key, mstSet, arr_size);

        mstSet[u] = true;

        for (int v = 0; v < arr_size; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, arr_size);
}

// Driver's code
int main()
{
    printf("Prim's Algorithm:\n");
    printf("Enter the size of matrix:");
    scanf("%d", &arr_size);
    int graph[arr_size][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, arr_size);

    return 0;
}
