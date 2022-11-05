/*
Refer the following new sort algorithm for sorting an array A of n numbers. The
algorithm is described below:

(i) If there is only one number, return.
(ii) If there are two numbers, perform a single comparison to determine the order.
(iii) If there are more than two numbers, then first sort the top two-thirds of the
elements recursively. Follow this by sorting the bottom two-thirds of the
elements recursively and then sorting the top two-thirds of the elements again.
a) Write a program that uses a recursive algorithm to implement the above strategy.
b) What is the comparison complexity of this new-sort algorithm? Formulate a recurrence
relation and solve the same to justify your answer.
*/

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void new_sort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    if(r-l==1){
        if(arr[l]>arr[r]){
            swap(arr[l],arr[r]);
        }
        return;
    }
    int mid=(l+r)/2;
    new_sort(arr,l,mid);
    new_sort(arr,mid+1,r);
    new_sort(arr,l,mid);
}
int main(){
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    new_sort(arr,0,n-1);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}