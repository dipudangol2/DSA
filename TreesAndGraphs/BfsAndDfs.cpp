#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int visited_node[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
void BFS(struct queue *q, int a[MAX][MAX], int visited[], int start, int size)
{
    int j;
    printf("%d ", start);
    visited[start] = 1;
    enqueue(q, start);
    while (!isEmpty(q))
    {
        int node = dequeue(q);

        for (j = 0; j < size; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    printf("\n");
}
void DFS(int A[MAX][MAX], int start, int size)
{
    printf("%d ", start);
    visited_node[start] = 1;
    for (int j = 0; j < size; j++)
    {
        if (A[start][j] == 1 && !visited_node[j])
        {
            DFS(A, j, size);
        }
    }
}
int main()
{
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int node, size, i = 0, j;
    int start = 1;
    int a[MAX][MAX];
    printf("BFS and DFS:\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &size);
    int visited[size];
    for (i = 0; i < size; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the Adjacency matrix:\n ");

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("\nBFS: ");
    BFS(&q, a, visited, start, size);
    printf("\nDFS: ");
    DFS(a, start, size);
    printf("\n");
    free(q.arr);
    return 0;
}
