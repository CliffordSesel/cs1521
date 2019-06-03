#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 
#include "Queue.h"
 
void initQueue (Queue *q)
{
	q->nitems = q->head = q->tail = 0;
}
 
void enterQueue (Queue *q, int item)
{
	assert (q->nitems < MAXQ);
	if (q->nitems != 0)
		q->tail++;
	q->items[q->tail] = item;
	q->nitems++;
}
 
int leaveQueue (Queue *q)
{
	assert (q->nitems > 0);
	int old = q->items[q->head];
	for (int i = 0; i < q->nitems - 1; i++)
		q->items[i] = q->items[i + 1];
	q->tail--;
	q->nitems--;
	return old;
}
 
int lengthQueue (Queue q)
{
	return q.nitems;
}
 
void showQueue (Queue q)
{
	int i; // index
	printf ("H");
	for (i = 0; i < q.nitems; i++) {
		printf (" %d", q.items[i]);
	}
	printf (" T");
	printf ("   h=%d, t=%d, n=%d\n", q.head, q.tail, q.nitems);
}