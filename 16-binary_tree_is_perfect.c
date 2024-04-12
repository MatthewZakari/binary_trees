#include "binary_trees.h"

/**
 * depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth_left, depth_right;

    if (!tree)
        return (0);

    depth_left = binary_tree_depth(tree->left);
    depth_right = binary_tree_depth(tree->right);

    if (depth_left != depth_right)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    return (binary_tree_is_perfect(tree->left) &&
            binary_tree_is_perfect(tree->right));
}

