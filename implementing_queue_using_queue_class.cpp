#include <iostream>
#include "Queue_class_using_array.cpp"
using namespace std;

int main()
{
    Queue q1(5);
    // q1.dequeue();
    q1.enqueue(4);
    // cout << q1.front() << endl;
    // q1.dequeue();
    q1.enqueue(5);
    // cout << q1.front() << endl;
    // q1.dequeue();
    q1.enqueue(7);
    // cout << q1.front() << endl;
    // q1.dequeue();
    q1.enqueue(6);
    q1.enqueue(9);
    q1.enqueue(8);
    // cout << q1.front() << endl;
    // q1.dequeue();
    cout << q1.total_size() << endl;
    return 0;
}