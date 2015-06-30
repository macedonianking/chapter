/*
 * main_btree.h
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#ifndef MAIN_BTREE_H
#define MAIN_BTREE_H

struct main_bree_node;

typedef struct main_btree_node {
	struct main_btree_node *p;
	struct main_btree_node *l;
	struct main_btree_node *r;
	int k;
	int status;
} main_btree_node;

/**
 * 添加一个二叉树的节点
 */
main_btree_node *main_btree_add(main_btree_node *root, main_btree_node *node);

/**
 * 完全销毁一个二叉树的所有节点
 */
void main_btree_release(main_btree_node *tree);

/**
 * 二叉树中序遍历
 */
void main_btree_inorder_tree_walk(main_btree_node *tree);


#endif
