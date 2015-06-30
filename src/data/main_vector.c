/*
 * main_vector.c
 *
 *  Created on: 2015年6月28日
 *      Author: lhb
 */

#include <stdlib.h>

#include "main_math.h"
#include "main_vector.h"

#define MAIN_VECTOR_DEFAULT_CAPACITY 512

static void main_vector_check_capacity(main_vector *ptr, int c) {
	if (c < ptr->c)
		return;

	ptr->c = MAX(c, 2 * ptr->c);
	ptr->data = (void**) realloc(ptr->data, ptr->c);
}

void main_vector_initial(main_vector *ptr) {
	main_vector_ninitial(ptr, MAIN_VECTOR_DEFAULT_CAPACITY);
}

void main_vector_ninitial(main_vector *ptr, int n) {
	ptr->c = 0 < n ? n : MAIN_VECTOR_DEFAULT_CAPACITY;
	ptr->n = 0;
	ptr->data = (void**) malloc(sizeof(void*) * ptr->c);
	ptr->delete_func = NULL;
}

/**
 * 销毁对象
 */
void main_vector_release(main_vector *ptr) {
	main_vector_reset(ptr);
	free(ptr->data);
	ptr->c = 0;
}

/**
 * 释放成员并销毁内存
 */
void main_vector_reset(main_vector *ptr) {
	for (int i = 0; i < ptr->n; ++i) {
		if (ptr->data[i]) {
			if (ptr->delete_func)
				(*ptr->delete_func)(ptr->data[i]);
			free(ptr->data[i]);
		}
	}
	ptr->n = 0;
}

void main_vector_reset_own(main_vector *ptr) {
	ptr->n = 0;
}

void main_vector_append(main_vector *ptr, void *p) {
	main_vector_check_capacity(ptr, ptr->n + 1);
	ptr->data[ptr->n++] = p;
}

void main_vector_nappend(main_vector *ptr, void **data, int n) {
	if (n > 0) {
		main_vector_check_capacity(ptr, ptr->n + n);
	}

	while (n-- > 0) {
		ptr->data[ptr->n++] = *data++;
	}
}

int main_vector_index(main_vector *ptr, void *p) {
	for (int i = 0; i != ptr->n; ++i) {
		if (ptr->data[i] == p)
			return i;
	}
	return -1;
}

int main_vector_contains(main_vector *ptr, void *p) {
	return main_vector_index(ptr, p) != -1;
}
