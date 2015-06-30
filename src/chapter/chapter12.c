/*
 * main_chapter12.c
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "chapter12.h"
#include "main_help.h"
#include "main_btree.h"
#include "main_stack.h"
#include "main_vstack.h"
#include "main_vector.h"

static main_btree_node *main_btree_create(int *argv, int argc, int status) {
	main_btree_node *head;
	main_btree_node *node;

	head = NULL;
	while (argc-- > 0) {
		node = (main_btree_node*) malloc(sizeof(main_btree_node));
		memset(node, 0, sizeof(main_btree_node));
		node->k = *argv++;
		node->status = status;
		head = main_btree_add(head, node);
	}

	return head;
}

/**
 * 使用堆栈实现二叉树的中序遍历
 */
static void main_btree_inorder_tree_walk_by_stack(main_btree_node *node) {
	main_stack stack;
	main_vstack vstack;

	main_stack_initial(&stack);
	main_vstack_initial(&vstack);

	while (node != NULL || !main_stack_is_empty(&stack)) {
		if (node == NULL) {
			fprintf(stdout, "%d ", main_stack_pop(&stack));
			if (!main_vstack_is_empty(&vstack)) {
				node = (main_btree_node*) main_vstack_pop(&vstack);
			}
		} else {
			main_stack_push(&stack, node->k);
			main_vstack_push(&vstack, node->r);
			node = node->l;
		}
	}

	main_stack_release(&stack);
	main_vstack_release(&vstack);
}

/**
 * 通过节点状态来完成中序遍历
 */
static void main_btree_inorder_tree_walk_by_status(main_btree_node *node) {
	main_vector node_vector;

	main_vector_initial(&node_vector);
	while (node != NULL) {
		if (node->l && !main_vector_contains(&node_vector, node->l)) {
			node = node->l;
		} else if (!main_vector_contains(&node_vector, node)) {
			main_vector_append(&node_vector, node);
			fprintf(stdout, " %d", node->k);
		} else if (node->r && !main_vector_contains(&node_vector, node->r)) {
			node = node->r;
		} else {
			/**
			 * 升级到父成员
			 */
			node = node->p;
		}
	}

	main_vector_reset_own(&node_vector);
	main_vector_release(&node_vector);
}

/**
 * 第十二章问题1-3
 */
void main_chapter12_1_3() {
	main_btree_node *head;
	int buffer[] = { 6, 5, 2, 5, 7, 8 };

	head = main_btree_create(buffer, ARRAY_SIZE(buffer), 0);
	fprintf(stdout, "main_btree_inorder_tree_walk: ");
	main_btree_inorder_tree_walk(head);
	fprintf(stdout, "\n");

	fprintf(stdout, "main_btree_inorder_tree_walk_by_stack: ");
	main_btree_inorder_tree_walk_by_stack(head);
	fprintf(stdout, "\n");

	fprintf(stdout, "main_btree_inorder_tree_walk_by_status: ");
	main_btree_inorder_tree_walk_by_status(head);
	fprintf(stdout, "\n");

	main_btree_release(head);
	head = NULL;
}

static void main_btree_preorder_tree_walk(main_btree_node *node) {
	if (!node)
		return;

	fprintf(stdout, " %d", node->k);
	main_btree_preorder_tree_walk(node->l);
	main_btree_preorder_tree_walk(node->r);
}

static void main_btree_postorder_tree_walk(main_btree_node *node) {
	if (!node)
		return;

	main_btree_postorder_tree_walk(node->l);
	main_btree_postorder_tree_walk(node->r);
	fprintf(stdout, " %d", node->k);
}

/**
 * 第十二章问题1-4
 */
void main_chapter12_1_4() {
	main_btree_node *head;
	int buffer[] = { 6, 5, 2, 5, 7, 8 };

	head = main_btree_create(buffer, ARRAY_SIZE(buffer), 0);
	fprintf(stdout, "main_btree_preorder_tree_walk: ");
	main_btree_preorder_tree_walk(head);
	fprintf(stdout, "\n");

	fprintf(stdout, "main_btree_postorder_tree_walk: ");
	main_btree_postorder_tree_walk(head);
	fprintf(stdout, "\n");

	main_btree_release(head);
	head = NULL;
}
