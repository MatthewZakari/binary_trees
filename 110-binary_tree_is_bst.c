#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    /* Check if the left subtree is a valid BST */
    if (tree->left && (tree->left->n >= tree->n || !binary_tree_is_bst(tree->left)))
        return (0);

    /* Check if the right subtree is a valid BST */
    if (tree->right && (tree->right->n <= tree->n || !binary_tree_is_bst(tree->right)))
        return (0);

    /* The tree is a valid BST */
    return (1);
}

