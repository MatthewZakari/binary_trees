#include "binary_trees.h"


/**
 * heapify_down - Fixes the heap property starting from a given node downwards
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest; /* *temp; */
    int value;

    if (!root)
        return;

    largest = root;
    if (root->left && root->left->n > largest->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root)
    {
        value = root->n;
        root->n = largest->n;
        largest->n = value;
        heapify_down(largest);
    }
}

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
 * get_last_node - Gets the last node of the heap (bottom right)
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    while (root && (root->left || root->right))
    {
        if (!root->right)
            root = root->left;
        else if (root->left && height(root->left) > height(root->right))
            root = root->left;
        else
            root = root->right;
    }
    return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node; /* *temp; */
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last_node->n;
    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;
    free(last_node);
    heapify_down(*root);

    return (value);
}

