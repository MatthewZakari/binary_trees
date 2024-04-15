#include "binary_trees.h"

/**
 * @binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue to store tree nodes */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1000); /* Assuming max 1000 nodes */
    if (queue == NULL)
        return;

    int front = 0, rear = 0;
    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        /* Call the function with the value of the current node */
        func(current->n);

        /* Enqueue left child */
        if (current->left != NULL)
            queue[rear++] = current->left;

        /* Enqueue right child */
        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    free(queue);
}

