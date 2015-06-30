/*
 * main_stack.h
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#ifndef MAIN_STACK_H
#define MAIN_STACK_H

typedef struct main_stack {
	int *data;
	int n;
	int c;
} main_stack;

void main_stack_initial(main_stack *stack);
void main_stack_ninitial(main_stack *stack, int c);
void main_stack_release(main_stack *stack);

void main_stack_push(main_stack *stack, int v);
int main_stack_pop(main_stack *stack);

int main_stack_front(main_stack *stack);
int main_stack_back(main_stack *stack);

/**
 * 堆栈是否位空,如果位空返回1，否则返回0
 */
int main_stack_is_empty(main_stack *stack);
#endif
