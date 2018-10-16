Cosc 320 Lab 5: Priority Queue with a Heap
Jackson Bellinger 10/16/2018

In this project, we implemented a priority queue using a heap.
I pretty much used all the standard implementations of the heap functions. I did use templates, so that's kind of interesting (a bit of a pain but also fun).

The Theoretical time complexity of
Insertion is O(logn) if there is room in the heap, and O(n + logn + c) if the array needs to be expanded: O(c) for allocating a new array, O(n) for copying the old data into the new array, and O(logn) for the insertion.
Heapify is still O(logn)
in this project, my buildHeap function was replaced by function to build a randomized heap for shuffling an array. I didn't have time to fully test this algorithm, but from the quick analysis I did, I think the chance that there is a collision is going to be the sum of i = 0->n of n/n^3, which is upper bounded by -1/2(n^2). for each new random spot you put something into, there are n places already taken out of the n^3 spots.

I didn't leave enough time to do the full delta time / delta elements analysis + graph again, but I added code in the main to output the timings for each operation.

Some applications of a priority queue would be in the operating system, for task scheduling. A PQueue would be better than other data structures because it wouldbe fast to both insert, get the top, and also change the priority of the elements.
 Basically a PQueue would be better than a queue in almost every situation that you would need a queue.
 
 I would still like to improve my timing code, but I think my PQueue implementation is pretty good. I could have done more testing for edge cases, like negative values, etc.
