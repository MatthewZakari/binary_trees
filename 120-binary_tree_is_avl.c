#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree starting at @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l;
    size_t height_r;

    if (!tree)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int diff_height;
    size_t height_l;
    size_t height_r;

    if (!tree)
        return (0);

    height_l = binary_tree_height(tree->left);
    height_r = binary_tree_height(tree->right);

    diff_height = height_l - height_r;

    if (diff_height < -1 || diff_height > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}

