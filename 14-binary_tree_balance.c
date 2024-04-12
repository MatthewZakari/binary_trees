#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t height(const binary_tree_t *tree)
{
    size_t height_l, height_r;

    if (!tree)
        return 0;

    height_l = tree->left ? 1 + height(tree->left) : 0;
    height_r = tree->right ? 1 + height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    return height(tree->left) - height(tree->right);
}

