/*
 * main_help.h
 *
 *  Created on: 2015年6月27日
 *      Author: lhb
 */

#ifndef MAIN_HELP_H
#define MAIN_HELP_H

#define E_CHAR	'\n'
#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(a[0]))

#define DO_DEATH() \
do { \
	(*(int*)0) = 0xDEADBEEF; \
}while (0)

#ifndef NDEBUG
#define DCHECK(cond)
#else
#define DCHECK(cond) \
do { \
	if (!(cond)) \
		DO_DEATH(); \
} while(0)
#endif

#endif
