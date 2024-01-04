#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance
 * factor of a binary tree.
 * @tree: a pointer to the root node of the tree to measure
 * the balance factor.
 *
 * Return: if tree is NULL return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height on succssess, 0 if NULL(tree).
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        if (tree)
        {
                size_t i = 0, j = 0;

                i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
                j = tree->right ? 1 + binary_tree_height(tree->right) : 1;

                return ((i > j) ? i : j);
        }
        return (0);
}
