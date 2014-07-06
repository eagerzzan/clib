/*******************************************************************************
 * sort.h
 * header of sort 
 *
 * @author		Theo Seo
 * @email		makeitafridaynight@gmail.com
 ******************************************************************************/

#ifndef _SORT_H
#define _SORT_H

#define ELEMENT_TYPE int

void quicksort(ELEMENT_TYPE a[], int low, int high);

void insertionsort(ELEMENT_TYPE a[], int n); 

void selectionsort(ELEMENT_TYPE a[], int n);

void exchangesort(ELEMENT_TYPE a[], int n);

void bubblesort(ELEMENT_TYPE a[], int n);

void heap_sort(ELEMENT_TYPE a[], int n);

void shellsort(ELEMENT_TYPE a[], int n);

void merge_sort(ELEMENT_TYPE a[], int low, int high);

void radix_sort(ELEMENT_TYPE a[], int length, int ndigits);

void counting_sort(ELEMENT_TYPE a[], int n, int maxk);

void bucket_sort(ELEMENT_TYPE a[], int n, int maxk);

#endif

/* end of file */

