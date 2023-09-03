#include <iostream>
using namespace std;

class Deque
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check if full or not
        if (isFull())
            return false;

        // pushing the first element in queue, but front and rear is at -1 this time.
        else if (isEmpty())
            front = rear = 0;

        // maintaing the cyclic order.
        else if (front == 0 && rear != size - 1)
            front = size - 1;

        // normal flow in other cases
        else
            front--;

        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // check if full or not
        if (isFull())
            return false;

        // pushing the first element in queue, but front and rear is at -1 this time.
        else if (isEmpty())
            front = rear = 0;

        // maintaing the cyclic order.
        else if (rear == size - 1 && front != 0)
            rear = 0;

        // normal flow in other cases
        else
            rear++;

        arr[rear] = x;

        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // check if empty
        if (isEmpty())
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        // single element in the queue
        if (front == rear)
            front = rear = -1;

        // to maintain the cyclic order.
        else if (front == size - 1)
            front = 0;

        // normal flow
        else
            front++;

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // check if empty
        if (isEmpty())
            return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        // single element in the queue
        if (front == rear)
            front = rear = -1;

        // to maintain the cyclic order.
        else if (rear == 0)
            rear = size - 1;

        // normal flow
        else
            rear--;

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
            return true;

        return false;
    }
};