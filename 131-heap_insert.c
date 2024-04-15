#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *temp;
    int tmp_val;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
        return (*root = new_node);

    temp = *root;
    while (temp->left && temp->right)
    {
        if (temp->left && !temp->right)
            temp = temp->left;
        else if (!temp->left && temp->right)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (!temp->left)
        temp->left = new_node;
    else
        temp->right = new_node;

    new_node->parent = temp;

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        tmp_val = new_node->parent->n;
        new_node->parent->n = new_node->n;
        new_node->n = tmp_val;
        new_node = new_node->parent;
    }

    return (new_node);
}

