/*******************************************************************************
 * search.h
 * header of search
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _SEARCH_H
#define _SEARCH_H

#define ELEMENT_TYPE int

int is_same(const ELEMENT_TYPE src, const ELEMENT_TYPE dst);

int sequential_search(
		ELEMENT_TYPE a[],
		int n,
		ELEMENT_TYPE key,
		int (*is_same)(const ELEMENT_TYPE, const ELEMENT_TYPE)
		);

int fibonacci_search(
		ELEMENT_TYPE a[],
		int n,
		ELEMENT_TYPE key,
		int (*is_same)(const ELEMENT_TYPE, const ELEMENT_TYPE)
		);
#endif

/* end of file */

