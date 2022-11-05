/*
Given a set S of n integers and another integer x, determine whether or not there exist two
elements in S whose sum is exactly x. Describe a Θ(nlogn) time algorithm for the above problem.
*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the sum: ";
    cin>>x;
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==x){

            cout<<"The sum is present in the array";
             return 0;
        }
        else if(arr[i]+arr[j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"The sum is not present in the array";
    return 0;
}