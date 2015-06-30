/*
 * main_stack.c
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#include <stdlib.h>

#include "main_help.h"
#include "main_math.h"
#include "main_stack.h"

#define MAIN_STACK_DEFAULT_CAPACITY	512

static void main_stack_check_capacity(main_stack *stack, int c) {
	if (c < stack->c)
		return;

	stack->c = MAX(c, 2 * stack->c);
	stack->data = (int*) realloc(stack->data, stack->c * sizeof(int));
}

void main_stack_initial(main_stack *stack) {
	main_stack_ninitial(stack, MAIN_STACK_DEFAULT_CAPACITY);
}

void main_stack_ninitial(main_stack *stack, int c) {
	stack->c = 0 < c ? c : MAIN_STACK_DEFAULT_CAPACITY;
	stack->data = (int*) malloc(sizeof(int) * stack->c);
	stack->n = 0;
}

/**
 * 堆栈销毁
 */
void main_stack_release(main_stack *stack) {
	free(stack->data);
	stack->data = NULL;
	stack->n = stack->c = 0;
}

/**
 * 数据压入堆栈
 */
void main_stack_push(main_stack *stack, int v) {
	main_stack_check_capacity(stack, stack->n + 1);
	stack->data[stack->n++] = v;
}

/**
 * 弹出底部数据
 */
int main_stack_pop(main_stack *stack) {
	DCHECK(stack->n > 0);
	return stack->data[--stack->n];
}

/**
 * 返回头部数据
 */
int main_stack_front(main_stack *stack) {
	DCHECK(stack->n > 0);
	return stack->data[stack->n - 1];
}

/**
 * 返回底部数据
 */
int main_stack_back(main_stack *stack) {
	DCHECK(stack->n > 0);
	return stack->data[0];
}

/**
 * 堆栈是否位空
 */
int main_stack_is_empty(main_stack *stack) {
	return stack->n == 0;
}
