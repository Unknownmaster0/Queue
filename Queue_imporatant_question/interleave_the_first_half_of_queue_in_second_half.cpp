#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
Question -> https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

Solution -> input queue -> 11 12 13 14 15 16 17 18

            solution ->    11 15 12 16 13 17 14 18

            first half element is mashed up with the second half element.

            here the mid is -> 14, after (mid + 1)
            split the queue in two halves
                    1st half -> 11 12 13 14
                    2nd half -> 15 16 17 18
final queue will come from taking the first element from the 1st half and second from the 2nd half, till the 1st half become empty.
                        11 15 12 16 12 17 14 18

method 1 -> using the queue.
            step 1-> split the input queue in two half.
            step 2 -> push the element of first half in new queue
            step 3 -> while the new queue is not empty, then
                    do, push the front element of new queue in input queue and then pop it from new queue.
                        push the front element from input queue in input queue and then pop it.

                    do these steps inside the loop and condition is till new queue not becomes empty.

method 2 -> using the stack.
            step 1 -> split the input queue in two half. 11 12 13 14, 15 16 17 18
            step 2 -> push the elements of first half in new stack (14 13 12 11 in stack.)
            step 3 -> again push the elements of stack in queue.  (15 16 17 18 14 13 12 11) = new q
            step 4 -> now push the front half element of queue q in queue itself.  q = 14 13 12 11 15 16 17 18
            step 5 -> again push the first half of element in stack -> stack = 11 12 13 14
            step 6 -> push the top element of stack in q and then pop it,
                        similarly push the front element of q in q and then pop it.
            step 7 -> finally return the original q.
*/

int findMid(queue<int> q)
{
    int length = 0;
    while (!q.empty())
    {
        length++;
        q.pop();
    }
    if (length % 2 == 0)
        return length / 2;

    return (length / 2) + 1;
}

int findLength(queue<int> q)
{
    int length = 0;
    while (!q.empty())
    {
        length++;
        q.pop();
    }
    return length;
}

/*

// method 1 -> using the queue
queue<int> interleaveHalf(queue<int> q)
{
    queue<int> newQueue;

    int length = findLength(q);
    int mid = findMid(q);

    // pushing the half first half element of queue in newQueue.
    while (mid)
    {
        newQueue.push(q.front());
        q.pop();
        mid--;
    }

// again pushing the newQueue elements in q and also the q elements in q itself.
    while(!newQueue.empty())
    {
        // here the front element of newQueue is pushed in input queue(q)
        int val = newQueue.front();
        newQueue.pop();
        q.push(val);

        //  here the front element of q is pushed in input queue(q)
        val = q.front();
        q.pop();
        q.push(val);

        if(length % 2 != 0 && newQueue.size() == 1)
            break;

    }
    if(!newQueue.empty())
    {
        q.push(newQueue.front());
        newQueue.pop();
    }
    return q;
}

*/


void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


// method 2 -> using stack
queue<int> interleaveHalf(queue<int> q)
{
    stack<int> s;
    // step 1 ->
    int mid = findMid(q);

    // step 2->
    int index = 0;
    while (index < mid)
    {
        s.push(q.front());
        q.pop();
        index++;
    }

    // step 3 ->
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // step 4 -> if the length is odd, then we need to move back only the (length -  mid) elements of queue.
    // example -> 15 16 17 11 12 13 14
    index = 0;
    while (index <  mid)
    {
        q.push(q.front());
        q.pop();
        index++;
    }

    // step 5 ->
    index = 0;
    while (index < mid)
    {
        s.push(q.front());
        q.pop();
        index++;
    }

    // step 6 ->
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);

    }

    return q;
}


int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    // q.push(18);

    print(q);

    queue<int> ans = interleaveHalf(q);

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}