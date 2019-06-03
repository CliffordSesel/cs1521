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
		q->tail = (q->tail + 1) % MAXQ;
	q->items[q->tail] = item;
	q->nitems++;
}
 
int leaveQueue (Queue *q)
{
	assert (q->nitems > 0);
	int old = q->items[q->head];
	q->head = (q->head + 1) % MAXQ;
	q->nitems--;
	return old;
}
 
int lengthQueue (Queue q)
{
	return q.nitems;
}
 
void showQueue (Queue q)
{
	int n; // counter
	int i; // index
	printf ("H");
	i = q.head;
	for (n = 0; n < q.nitems; n++) {
		printf (" %d", q.items[i]);
		i = (i + 1) % MAXQ;
	}
	printf (" T");
	printf ("   h=%d, t=%d, n=%d\n", q.head, q.tail, q.nitems);
}