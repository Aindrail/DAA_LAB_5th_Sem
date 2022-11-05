/*
Given a set of n intervals, input through keyboard, R = {I1, 12, I3,....., In} where
each Ij =[aj, bj] is an interval from the real line having length bj - aj and bj>aj. The
objective is to find all possible largest sub set of intervals S ⊆ R, excluding all intervals of
least length, such that no two intervals in S overlap each other.
Exact Input/Output Sample-1
Enter maximum number of intervals: 11
Enter the name of intervals with their start and end number:
(p, 3, 5) (q, 0, 6) (r, 3, 9) (s, 5, 9) (t, 6, 10) (u, 8, 11) (v, 2, 14) (w, 12, 16) (x,
5, 7) (y, 8, 12) (z, 1, 4)

The intervals with their lengths sorted in ascending order with their end number.
Intervals Length of Intervals
(z, 1, 4) - 3
(p, 3, 5) - 2
(q, 0, 6) - 6
(x, 5, 7) - 2
(r, 3, 9) - 6
(s, 5, 9) - 4
(t, 6, 10) - 4
(u, 8, 11) - 3
(y, 8, 12) - 4
(v, 2, 14) - 12
(w, 12, 16) - 4
The least length intervals :{p, x}
Excluding the least length intervals,
the largest sub set of non-overlapping intervals: {z, s, w}, {z, t, w}, {z, u, w}, {z, y, w},
{q, t, w}, {q, u, w}, {q, y, w}
Exact Input/Output Sample-1
If the input (x, 5, 7) is changed to (x, 5, 8),
then output will be The least length intervals :{p}
Excluding the least length intervals,
the largest sub set of non-overlapping intervals: {z, x, u, w}, {z, x, y, w}
*/

#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
    char name;
    int start;
    int end;
    Interval(char name, int start, int end){
        this->name = name;
        this->start = start;
        this->end = end;
    }
};

bool compare(Interval a, Interval b){
    return a.end < b.end;
}

void printMaxIntervals(Interval arr[], int n){
    sort(arr, arr+n, compare);
    // display all maximum intervals
    cout<<"The intervals with their lengths sorted in ascending order with their end number."<<endl;
    cout<<"Intervals\tLength of Intervals"<<endl;
    
    int i=0;
    cout<<"The maximum set of intervals that can be executed by a single person is {";
    cout<<arr[i].name<<", ";
    for(int j=1; j<n; j++){
        if(arr[j].start >= arr[i].end){
            
            if(j==n-2){
                cout<<arr[j].name;
            }
            else{
                cout<<arr[j].name<<", ";
                i = j;
            }
            
        }
    }
    cout<<"}"<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;

    vector<Interval> intervals;
    char name;
    int start, end;
    for(int i=0; i<n; i++){
        cout<<"Enter the name, start and end time of interval "<<i+1<<": ";
        cin>>name>>start>>end;
        intervals.push_back(Interval(name, start, end));
    }
    


    printMaxIntervals(intervals.data(), n);
    return 0;
}