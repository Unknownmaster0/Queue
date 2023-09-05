#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

/*
Concept -> step 1 -> start with the first index and calculate the balance, if the balance becomes less then 0, means
                    truck can't travel from this starting petrol pump to reach the next petrol pump.
                if the balance less than 0 means -> the truck has less petrol and it has to travel more.
           step 2 -> if the balance is less then 0, then the truck have to go to next petrol pump, and make this as starting point and start
                    from there.
          step 3 -> if the balance not becomes 0, then calculte balance and move further always.
*/

// balance -> to check the remaning amount of petrol left in the truck.

/*
// Having the time complexity more than the (n^2);
int circularTour(petrolPump p[], int n)
{
    int balance = 0, start = 0;
    bool Tour = true;

    for (int i = 0; i < n; i++)
    {
        Tour = true;
        start = i;

        int j = i + 1;
        while (j != i)
        {
            if (j == n)
            {
                j = 0;
            }

            balance = balance + p[j].petrol - p[j].distance;

            if (balance < 0)
            {
                Tour = false;
                balance = 0;
                break;
            }

            j++;
        }

        if (Tour == true)
            return start;
    }

    return -1;
}
*/

// Time complexity -> O(n)
int tour(petrolPump p[], int n)
{
    // Concept in copy.
    int deficit = 0, balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (balance + deficit >= 0)
        return start;

    return -1;
}

int main()
{
    petrolPump p[4];
    p[0].petrol = 4;
    p[1].petrol = 6;
    p[2].petrol = 7;
    p[3].petrol = 4;

    p[0].distance = 6;
    p[1].distance = 5;
    p[2].distance = 3;
    p[3].distance = 5;

    int starting = tour(p, 4);
    cout << "the starting place of Truck is -> " << starting << endl;

    return 0;
}