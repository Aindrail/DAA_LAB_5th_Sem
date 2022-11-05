/*Write a program to search an element key in an array of n integers using Binary Search
algorithm that uses divide and conquer technique. Find out the best case, worst case and
average case time complexities for different values of n and plot a graph of the time taken
versus n. The n integers can be generated randomly and key can be chosen randomly or
any element in the array or middle or first or last element of the array depending on type
of time complexity analysis.*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void binary_search(int arr[], int l, int r, int key){
    int count=0;

    int mid;
    while(l<=r){
        count++;
        mid = (l+r)/2;
        if(arr[mid]==key){
            cout<<"Element found at index "<<mid<<" "<<count<<endl;
            return;
        }
        else if(arr[mid]>key){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<"Element not found"<<endl;
}
int main(){
    int n ;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    sort(arr,arr+n);
    // cout<<"Array is: ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int choice=1;
    
     cout<<arr[(n-1)/2 ]<<endl;
    while(choice){
       
    int key;
    cout<<"Enter the key to be searched: ";
    cin>>key;
    int low=0,high=n-1;
    int mid;
    
    auto start = high_resolution_clock::now();
    binary_search(arr,low,high,key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    cout<<"Enter 1 to continue and 0 to quit: ";
    cin>>choice;
    }
    return 0;

}