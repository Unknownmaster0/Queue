#include <bits/stdc++.h>
using namespace std;

/*
Question -> https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

sum of minimum and maximum element of each window of size k.

example =  2 5 -1 7 -3 -1 -2  and k = 4 // k is the size of the window
            ans = 18
*/

/*
This can be solved in two ways ->
1. using the outer loop for each elements and inner loop for the window size iteration and finding the min and max element of window
2. using the two deque one for maximum and other for minimum, and find the summation.
*/

// But this will take O(N*N) time complexity.
/*
int solve(int *arr, int n, int k)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int ans = 0;
    for (int i = 0; i <= n - k; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
        }
        ans += mini + maxi;
    }

    return ans;
}
*/

/*Next method using the two deque.*/
int solve(int *arr,int n, int k)
{
    int sum = 0;
    deque<int>maxi(k);
    deque<int>mini(k);

// iterating the first k size window.
    for(int i = 0; i<k; i++)
    {
        // addition logic 
        // if element is pushed in the maxi queue then it must follow the descending order.
        // checking the descending order of the maxi.
        while( !maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop_back();

// same case with mini.
        // if element is pushed in the mini queue then it must follow the ascending order.
        while( !mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop_back();

        // do push in the maxi and mini
        maxi.push_back(i);
        mini.push_back(i);
    }
    sum += arr[maxi.front()]+arr[mini.front()];

    for(int i = k; i<n; i++)
    {
        /*Removal logic of the element if the any element in queue is out of range of K size window*/
        while( !maxi.empty() && i - maxi.front() >= k )
            maxi.pop_back();

        while( !maxi.empty() && i - maxi.front() >= k )
            maxi.pop_back();

        // addition of the elements in the maxi and mini
        // checking the ascending and descending order trend of both.
        while( !maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop_back();

        while( !mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop_back();
        
        // do push in the maxi and mini
        maxi.push_back(i);
        mini.push_back(i);

        // finding sum
        sum += arr[maxi.front()]+arr[mini.front()];
    }

    return sum;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int arrSize = 7;
    int windowSize = 4;

    int summation = solve(arr, arrSize, windowSize);
    cout << "sum -> " << summation << endl;

    return 0;
}