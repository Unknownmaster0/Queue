#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // spelling is different, deque -> stands for "doubly ended queue".
    deque<int> d;
    d.push_back(4);
    d.push_front(5);
    d.push_front(78);
    d.push_front(87);
    d.push_back(9);
    d.push_back(100);
    cout << "the last element -> " << d.back() << endl;
    cout << "the first element -> " << d.front() << endl;

    cout << "size -> " << d.size() << endl;
    cout << "max size -> " << d.max_size() << endl;

    cout << "at index 0 -> " << d.at(0) << endl;
    cout << "at index 1 -> " << d.at(1) << endl;
    cout << "at index 2 -> " << d.at(2) << endl;
    cout << "at index 3 -> " << d.at(3) << endl;
    cout << "at index 4 -> " << d.at(4) << endl;
    cout << "at index 5 -> " << d.at(5) << endl;
    return 0;
}