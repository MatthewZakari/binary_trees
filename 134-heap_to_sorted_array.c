#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers, NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    size_t count = 0, i;
    int *sorted_array;

    if (!heap || !size)
        return (NULL);

    count = binary_tree_size(heap);
    sorted_array = malloc(sizeof(int) * count);
    if (!sorted_array)
        return (NULL);

    for (i = 0; i < count; i++)
    {
        sorted_array[i] = heap->n;
        heap_extract(&heap);
    }

    *size = count;
    return (sorted_array);
}

