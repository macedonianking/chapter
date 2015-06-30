/*
 * main_vstack.h
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#ifndef MAIN_VSTACK_H
#define MAIN_VSTACK_H

typedef struct main_vstack {
	void **data;
	int c;
	int n;
	void (*delete_func)(void*);
} main_vstack;

/**
 * 指针堆栈的销毁和创建
 */
void main_vstack_initial(main_vstack *stack);
void main_vstack_ninitial(main_vstack *stack, int c);
void main_vstack_release(main_vstack *stack);

/**
 * 当前堆栈是否为空
 */
int main_vstack_is_empty(const main_vstack *stack);

void main_vstack_push(main_vstack *stack, void *p);
void *main_vstack_pop(main_vstack *stack);
#endif
