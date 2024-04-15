#include "binary_trees.h"
#include <limits.h>

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree
 * @index: The index of the current node
 * @node_count: The number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, unsigned int index, unsigned int node_count)
{
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * is_heap - Checks if a binary tree is a valid max heap
 * @tree: A pointer to the root node of the tree
 * @max: The maximum value among all nodes
 * Return: 1 if the tree is a valid max heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n > max)
        return (0);

    return (is_heap(tree->left, tree->n) && is_heap(tree->right, tree->n));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid max binary heap
 * @tree: A pointer to the root node of the tree
 * Return: 1 if the tree is a valid max binary heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    unsigned int node_count = 0;
    int max = INT_MAX;

    if (tree == NULL)
        return (0);

    while (tree)
    {
        node_count++;
        tree = tree->left;
    }

    if (!is_complete(tree, 0, node_count))
        return (0);

    return (is_heap(tree, max));
}

