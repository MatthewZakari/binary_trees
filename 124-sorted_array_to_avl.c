#include "binary_trees.h"

/**
 * create_avl_tree - Recursively creates an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the start of the subarray
 * @end: Index of the end of the subarray
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure      
 */
avl_t *create_avl_tree(int *array, size_t start, size_t end)
{
    if (start > end)
        return NULL;

    size_t mid = (start + end) / 2;

    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (root == NULL)
        return NULL;

    root->left = create_avl_tree(array, start, mid - 1);
    root->right = create_avl_tree(array, mid + 1, end);

    return root;
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return NULL;

    return create_avl_tree(array, 0, size - 1);
}

