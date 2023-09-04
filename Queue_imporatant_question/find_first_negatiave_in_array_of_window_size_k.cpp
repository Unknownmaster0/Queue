/*
Question -> https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
    Example -> 8 -8 0 7 -2 8 -1  (k = 3) window size
    ans ->     -8  -8 -2 -2 -2.

/*
Lecture -> 62
Approach -> step 1 -> first store the first negative element index from k size.
            step 2 -> then store its ans, in some vector or array.
            step 3 -> start traversing over whole array after the first window.
            step 4 -> first remove the index from deque if it not lies in the window size.
            step 5 -> if the next element of window is negative then only store its index in deque.
            step 6 -> again store ans in same vector or array.
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> printFirstNegative(vector<int> v, int k)
{
    vector<int> ans;
    // step 1
    deque<int> d;

    for (int i = 0; i < k; i++)
    {
        if (v[i] < 0)
            d.push_back(i);
    }

    // step 2 ->
    if (!d.empty())
        ans.push_back(v[d.front()]);
    else
        ans.push_back(0);

    // step 3 ->
    int i = k;
    while (i < v.size())
    {
        // step 4 -> removal of non-window element.
        if (!d.empty())
        {
            // checking if index inside deque lies in current window or not
            if (i - d.front() >= k)
                d.pop_front();
        }

        // step 5 -> addition new window element.
        if (v[i] < 0)
            d.push_back(i);

        // step 6 -> storing the answer // step 2 ->
        if (!d.empty())
            ans.push_back(v[d.front()]);
        else
            ans.push_back(0);

        i++;
    }

    return ans;
}

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {8, -8, 0, 7, -2, 8, -1};

    vector<int> print = printFirstNegative(v, 3);
    printVector(print);
    return 0;
}