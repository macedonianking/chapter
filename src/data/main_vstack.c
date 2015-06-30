/*
 * main_vstack.c
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#include <stdlib.h>

#include "main_help.h"
#include "main_math.h"
#include "main_vstack.h"

#define MAIN_VSTACK_DEFAULT_CAPACITY 512

static void main_vstack_check_capacity(main_vstack *stack, int c) {
	if (c < stack->c)
		return;

	stack->c = MAX(c, 2 * stack->c);
	stack->data = (void**) realloc(stack->data, sizeof(void*) * stack->c);
}

void main_vstack_initial(main_vstack *stack) {
	main_vstack_ninitial(stack, MAIN_VSTACK_DEFAULT_CAPACITY);
}

/**
 * 指针堆栈的初始化
 */
void main_vstack_ninitial(main_vstack *stack, int c) {
	stack->c = 0 < c ? c : MAIN_VSTACK_DEFAULT_CAPACITY;
	stack->data = (void**) malloc(sizeof(void*) * stack->c);
	stack->n = 0;
	stack->delete_func = NULL;
}

/**
 * 堆栈销毁
 */
void main_vstack_release(main_vstack *stack) {
	for (int i = 0; i < stack->n; ++i) {
		if (stack->delete_func)
			(*stack->delete_func)(stack->data[i]); // 执行销毁函数
		free(stack->data[i]);
	}

	free(stack->data);
	stack->data = NULL;
	stack->c = stack->n = 0;
	stack->delete_func = NULL;
}

int main_vstack_is_empty(const main_vstack *stack) {
	return stack->n == 0;
}

void main_vstack_push(main_vstack *stack, void *p) {
	main_vstack_check_capacity(stack, stack->n + 1);
	stack->data[stack->n++] = p;
}

void *main_vstack_pop(main_vstack *stack) {
	DCHECK(stack->n > 0);
	return stack->data[--stack->n];
}
