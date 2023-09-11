// #include <stdio.h>
// int main()
// {
//     int i;
//     int Array[10], n, j;
//     int key; // key is number to be searched
//     int Size = sizeof(Array) / sizeof(int);
//     printf("Enter the array elements:");
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &Array[i]);
//     }
//     printf("Enter the number to be searched:");
//     scanf("%d", &key);
//     for (i = 0; i < Size; i++)
//     {
//         if (Array[i] == key)
//         {
//             printf("Yes, it is in Array.\nArray[%d]=%d\n", i, Array[i]);
//         }
//     }
//     return 0;
// }

// Linear Search in C

#include <stdio.h>

int linearSearch(int array[], int n, int x)
{

    // Going through array sequencially
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
    return -1;
}

int main()
{
    int array[10];
    int key, i;
    int n = sizeof(array) / sizeof(array[0]);
    printf("Linear Search:\n");
    printf("Enter Array Elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &key);
    int result = linearSearch(array, n, key);

    (result == -1) ? printf("Element not found\n") : printf("Element found at index: %d\n", result);
}