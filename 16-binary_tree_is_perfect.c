#include "binary_trees.h"

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

		i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((i > j) ? i : j);
	}
	return (0);
}

/**
 * binary_tree_nodes - a function that counts the nodes with
 * at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_nodes = 0;

	if (tree == NULL)
		return (0);

	else
	{
		count_nodes += (tree->left || tree->right) ? 1 : 0;
		count_nodes += binary_tree_nodes(tree->left);
		count_nodes += binary_tree_nodes(tree->right);
	}
	return (count_nodes);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, node_count, perfect_node_count;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	node_count = binary_tree_nodes(tree);
	perfect_node_count = (1 << height) - 1;

	return ((node_count == perfect_node_count) ? 1 : 0);
}
