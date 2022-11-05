/*
Write a program to implement the Activity-Selection problem stated as follows:
You are given n activities with their start and finish times. Select the maximum
number of activities that can be performed by a single person, assuming that a
person can only work on a single activity at a time.
Test Case: Consider the following 6 activities ( 0, 1, 2, 3, 4, 5).
start[] = {1, 3, 0, 5, 8, 5};
finish[] = {2, 4, 6, 7, 9, 9};
The maximum set of activities that can be executed by a single person is {0, 1, 3,
4}.
*/

#include<bits/stdc++.h>
using namespace std;

//class Activity
class Activity{
    public:
    int start;
    int finish;
    Activity(int start, int finish){
        this->start = start;
        this->finish = finish;
    }
};

bool compare(Activity a, Activity b){
    return a.finish < b.finish;
}

void printMaxActivities(Activity arr[], int n){
    sort(arr, arr+n, compare);
    int i=0;
    cout<<"The maximum set of activities that can be executed by a single person is {";
    cout<<i<<", ";
    for(int j=1; j<n; j++){
        if(arr[j].start >= arr[i].finish){
            
            if(j==n-2){
                cout<<j;
            }
            else{
                cout<<j<<", ";
                i = j;
            }
            
        }
    }
    cout<<"}"<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of activities: ";
    cin>>n;

    vector<Activity> activities;
    int start, finish;
    for(int i=0; i<n; i++){
        cout<<"Enter the start and finish time of activity "<<i+1<<": ";
        cin>>start>>finish;
        activities.push_back(Activity(start, finish));
    }

    printMaxActivities(activities.data(), n);
    return 0;
}

   