/*******************************************************************************
 * dynarray.h
 * dyanamic array
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _DYN_ARRAY_H
#define _DYN_ARRAY_H

#include <stdlib.h>
#include <string.h>

#define ELEMENT_TYPE int
#define INCREMENT_SIZE 10

typedef struct _DYN_ARRAY
{
	ELEMENT_TYPE *array;
	size_t used;
	size_t size;
} DYN_ARRAY;

DYN_ARRAY* da_create(int init_size);
void da_destroy(DYN_ARRAY **ppa);
void da_insert(DYN_ARRAY *pa, int idx, ELEMENT_TYPE data);
void da_delete(DYN_ARRAY *pa, int idx);

#endif

/* end of file */

