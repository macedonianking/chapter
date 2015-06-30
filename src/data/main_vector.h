/*
 * main_vector.h
 *
 *  Created on: 2015年6月28日
 *      Author: lhb
 */

#ifndef MAIN_VECTOR_H
#define MAIN_VECTOR_H

typedef struct main_vector {
	void **data;
	int n;
	int c;
	void (*delete_func)(void *);
} main_vector;

/**
 * 构造和销毁
 */
void main_vector_initial(main_vector *ptr);
void main_vector_ninitial(main_vector *ptrj, int c);
void main_vector_release(main_vector *ptr);

/**
 * 销毁成员
 */
void main_vector_reset(main_vector *ptr);
/**
 * 设置为空，但是销毁内部对象
 */
void main_vector_reset_own(main_vector *ptr);

void main_vector_append(main_vector *ptr, void *p);
void main_vector_nappend(main_vector *ptr, void **data, int n);

/**
 * 搜索操作
 */
int main_vector_index(main_vector *ptr, void *p);
int main_vector_contains(main_vector *ptr, void *p);

#endif
