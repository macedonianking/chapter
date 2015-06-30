/*
 * main_btree.c
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#include <stdio.h>
#include <stdlib.h>

#include "main_btree.h"

/**
 * 添加一个二叉树的节点
 */
main_btree_node *main_btree_add(main_btree_node *root, main_btree_node *node) {
	if (!root) {
		node->p = NULL;
		return node;
	}

	if (node->k < root->k) {
		if (root->l != NULL) {
			root->l = main_btree_add(root->l, node);
		} else {
			root->l = node;
			node->p = root;
		}
	} else {
		if (root->r != NULL) {
			root->r = main_btree_add(root->r, node);
		} else {
			root->r = node;
			node->p = root;
		}
	}
	return root;
}

void main_btree_release(main_btree_node *tree) {
	if (tree != NULL) {
		main_btree_release(tree->l);
		main_btree_release(tree->r);
		tree->l = tree->r = tree->p = NULL;
		free(tree);
	}
}

/**
 * 二叉树中序遍历
 */
void main_btree_inorder_tree_walk(main_btree_node *node) {
	if (!node)
		return;

	main_btree_inorder_tree_walk(node->l);
	fprintf(stdout, "%d ", node->k);
	main_btree_inorder_tree_walk(node->r);
}
