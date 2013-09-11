#include <stdlib.h>
#include <string.h>
#include "algorithm-common.h"
#include "heap.h"

struct heap{
	int *data;
	int max_size;
	int size;
	int flag;
};

void heap_print(struct heap *h)
{
	print_int_array(h->data, h->size);
}

static int heap_add_adjust(struct heap *h, int start, int end)
{
	int i = start;

	if (h->flag) {
		for (i = end - 1; i > start; ) {
			int parent = (i - 1) >> 1;
			if (h->data[i] > h->data[parent]) {
				swap(h->data + i, h->data + parent);
				i = parent;
			} else {
				break;
			}
		}
	} else {
		for (i = end - 1; i > start; ) {
			int parent = (i - 1) >> 1;
			if (h->data[i] < h->data[parent]) {
				swap(h->data + i, h->data + parent);
				i = parent;
			} else {
				break;
			}
		}
	}
	return 0;
}

static int heap_delete_adjust(struct heap *h, int start, int end)
{
	int i = start;
	int next = 0;

	if (h->flag) {
		for (i = start; i < end;) {
			int left = (i * 2) + 1;
			int right = (i * 2) + 2;
			if (right < end) {
				if (h->data[left] > h->data[right]) {
					next = left;
				} else {
					next = right;
				}
				swap(h->data + i, h->data + next);
				i = next;
			} else if (right == end){
				if (h->data[left] > h->data[i]) {
					swap(h->data + i, h->data + left);
				}
				break;
			} else {
				break;
			}
		}
	} else {
		for (i = start; i < end;) {
			int left = (i * 2) + 1;
			int right = (i * 2) + 2;
			if (right < end) {
				if (h->data[left] > h->data[right]) {
					next = right;
				} else {
					next = left;
				}
				swap(h->data + i, h->data + next);
				i = next;
			} else if (right == end){
				if (h->data[left] < h->data[i]) {
					swap(h->data + i, h->data + left);
				}
				break;
			} else {
				break;
			}
		}
	}

	return 0;
}

int heap_add(struct heap *h, int value)
{
	if (h->size >= h->max_size) {
		return -1;
	}

	h->data[h->size] = value;
	h->size++;

	heap_add_adjust(h, 0, h->size);

	return 0;
}

int heap_delete(struct heap *h, int index, int *value)
{
	if (h->size <= 0) 
		return -1;

	if (value)
		*value = h->data[index];

	h->size--;
	h->data[index] = h->data[h->size];
	
	heap_delete_adjust(h, index, h->size);

	return 0;
}

struct heap * heap_new(int max_size, int flag)
{
	struct heap *h = NULL;

	h = (struct heap *)malloc(sizeof(struct heap));
	if (!h) {
		return NULL;
	}

	h->data = (int *)malloc(sizeof(int) * max_size);
	if (!h->data) {
		free(h);
		return NULL;
	}

	h->max_size = max_size;
	h->size = 0;
	h->flag = flag;

	return h;
}

void heap_free(struct heap *h)
{
	if (h) {
		if (h->data)
			free(h->data);
		free(h);
	}
}

