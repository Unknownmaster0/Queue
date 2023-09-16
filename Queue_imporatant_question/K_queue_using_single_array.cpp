#include<iostream>
using namespace std;

/*
question -> 
    you have given K number of queues and have to implement the push and pop operation on them using single array.
*/

class Kqueue
{
    // The variabels that we required.
    private:
        int size; // size of array
        int k; // number of queues
        int *arr; // original array in which we push the elements
        int *front; // the size of front is equal to number of queues
        int *rear; // size of rear = number of queues
        int *next; // size of next = size of original array i.e. size
        int freeSpot; // first freeSpot of in the original array.

    public:
        // constructor to initialise the queue.
        Kqueue(int size, int k)
        {
            this->size = size;
            this->k = k;
            arr = new int[size];
            next = new int [size];
            for(int i = 0; i<size; i++)
                next[i] = i+1;
            next[size-1] = -1;
            front = new int[k];
            rear = new int[k];
            for(int i = 0; i<k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }    
            freeSpot = 0;
        }

        // push operation in the queue.
        void enqueue(int data, int n) // n is the number of queue where you want to insert
        {
            // if the array is full or queue is full
            if(freeSpot == -1)
                return ;

            // find the index where you need to push
            int index = freeSpot;

            // update the freespot
            freeSpot = next[index];

            // if we are going to insert the first element.
            if(front[n-1] == -1)
            {
                front[n-1] = index;
            }
            else{
                // link new element to the prev element of the same queue
                next[ rear[n-1] ] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[n-1] = index;

            // push element
            arr[index] = data;
        }

        int dequeue(int n) // n is the nth queue whose element is dequeued
        {
            // check underflow condition
            if(front[n-1] == -1)
            {
                cout<<"underflow condition"<<endl;
                return -1;
            }

            // find the index to dequeue
            int index = front[n-1];

            // update the front
            front[n-1] = next[index];

            // update the next;
            next[index] = freeSpot;

            // update the freespot -> as the index is poped, then it become the freespot, hence freespot = index
            freeSpot = index;

            // return the element to dequeued
            return arr[index];
        }

};


int main()
{
    Kqueue q(10,3); // we make queue q of size 10 and have to implement 3 queues

    // dequeue the elements
    cout<<q.dequeue(1)<<endl;

    // pushing the elements in queue
    q.enqueue(10,1);
    q.enqueue(15,2);
    q.enqueue(20,1);
    q.enqueue(25,1);
    q.enqueue(130,2);

    
    // dequeing the elements
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;

    return 0;
}