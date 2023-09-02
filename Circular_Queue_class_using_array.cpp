#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        // if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full." << endl;
            exit(1);
        }

        // if the first element is being inserted
        else if (front == -1)
            front = rear = 0;

        // if the rear reaches to the last index of the array size
        else if (rear == size - 1)
            rear = 0;

        // the normal case
        else
            rear++;

        arr[rear] = data;

        return;
    }

    void dequeue()
    {
        // if the list is empty or not
        if (front == -1)
        {
            cout << "Queue is empty. Nothing to dequeue." << endl;
            return;
        }
        // if the single element is present
        else if (front == rear)
            front = rear = -1;

        // if the list is not empty and the front is reached the last
        else if (front == size - 1)
            front = 0;

        // the normal case.
        else
            front++;

        return;
    }

    int first()
    {
        return arr[front];
    }
};