#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int first;
    int rear;

public:
    // Queue class constructor.
    Queue(int data)
    {
        this->size = data;
        arr = new int[size];
        first = 0;
        rear = 0;
    }

    // function to push the data in the queue.
    void enqueue(int data)
    {
        // check if the queue is full
        if (rear == size)
        {
            cout << "Queue is Full." << endl;
            exit(1);
        }

        // if not full, then push
        arr[rear] = data;
        rear++;
    }

    void dequeue()
    {
        // check whether the queue is empty
        if (first == rear)
        {
            cout << "Queue Empty. No element to dequeue." << endl;
            exit(1);
        }

        arr[first] = -1;
        first++;
        // after incrementing the front, if the front and rear becomes equal then the queue becomes empty.
        if (first == rear)
        {
            first = 0;
            rear = 0;
        }
    }

    int front()
    {
        if (first == rear)
            return -1;

        return arr[first];
    }

    bool isEmpty()
    {
        if (first == rear)
            return -1;

        return 1;
    }

    int total_size()
    {
        return rear;
    }
};