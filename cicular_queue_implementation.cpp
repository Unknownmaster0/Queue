#include <iostream>
#include "Circular_Queue_class_using_array.cpp"
using namespace std;

int main()
{

    CircularQueue c1(5);
    c1.enqueue(5);
    cout << c1.first() << endl;
    c1.dequeue();
    c1.enqueue(9);
    cout << c1.first() << endl;

    return 0;
}