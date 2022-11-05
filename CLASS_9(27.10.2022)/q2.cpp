/*
You are given n activities with their start and finish times, input through
keyboard. Write a program to select all possible maximum number of activities that
can be performed by a single person including one activity of his/her choice,
assuming that a person can only work on a single activity at a time.
Exact Input/Output Sample-1
Enter maximum number of activities: 11
Enter the name of activities with their start and finish time:
(p, 3, 5) (q, 0, 6) (r, 3, 9) (s, 5, 9) (t, 6, 10) (u, 8, 11)
(v, 2, 14) (w, 12, 16) (x, 5, 7) (y, 8, 12) (z, 1, 4)

*/

#include<bits/stdc++.h>
using namespace std;

struct activity
{
    char name;
    int start;
    int finish;
};

bool compare(activity a, activity b)
{
    return a.finish < b.finish;
}

void printMaxActivities(activity arr[], int n)
{
    sort(arr, arr+n, compare);
    int i = 0;
    cout << arr[i].name << " ";
    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << arr[j].name << " ";
            i = j;
        }
    }
}

int main()
{
    int n;
    cout << "Enter maximum number of activities: ";
    cin >> n;
    activity arr[n];
    cout << "Enter the name of activities with their start and finish time: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].start >> arr[i].finish;
    }
    printMaxActivities(arr, n);
    return 0;
}
