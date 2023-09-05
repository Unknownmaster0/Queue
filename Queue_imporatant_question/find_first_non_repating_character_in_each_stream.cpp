/*
Question -> https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/

#include<iostream>
#include<map>
#include<queue>
using namespace std;

string FirstNonRepeating(string A){
/*
concept -> step 1-> make a map to store the frequency
    step 2-> make a queue to iterate entire string
    step 3-> first increase frequency of charcter
    step 4-> push it into queue
    step 5-> check the occurrence of element in queue, if it is greater than 1 pop the element.
    step 6-> if the queue becomes empty after the pop, insert # inside string
    step 7-> store it in answer
*/

map<char,int>count;
string ans = "";
queue<char>q;

for(int i = 0; i<A.length(); i++)
{
    count[A[i]]++;
    
    // push the element in queue
    q.push(A[i]);
    
    while(q.size() != 0)
    {
        // checking frequency of front element of queue.
        if(count[q.front()] > 1)
            q.pop();
            
// if frequency is 1 of front element, we get the first unique element,and then push it into the ans.
        else{
            ans.push_back(q.front());
            break;
        }
    }
    
// after poping while checking queue element frequency, if queue becomes empty, means no unique element is present
// if no unique element for this substring, push the # sign.
    if(q.empty())
        ans.push_back('#');
}

return ans;
}


int main()
{
    string str = "aabc";
    string ans = FirstNonRepeating(str);
    cout<<"The final answer is -> "<<ans<<endl;
    return 0;
}