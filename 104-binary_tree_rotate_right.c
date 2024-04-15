#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *pivot, *temp;

    if (!tree || !tree->left)
        return (NULL);

    pivot = tree->left;
    temp = pivot->right;
    pivot->right = tree;
    tree->left = temp;

    if (temp)
        temp->parent = tree;

    pivot->parent = tree->parent;
    tree->parent = pivot;

    return (pivot);
}

