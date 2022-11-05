// Write a prog to store a no in an array of n int and  find the smallest and largest in it

#include<iostream>
using namespace std;
int  findSmallest(int arr[],int n){
    int s = INT_MAX;
    for( int i = 0 ; i<n ; i++){
        s = min(s,arr[i]);
     
    }
   return s;
}
int  findLargest(int arr[],int n){
    int l = INT_MIN;
    for( int i = 0 ; i<n ; i++){
        l = max(l,arr[i]);
       
    }
 return l;
}
int main(){
   int n ;
   cout<<"Enter the n\n";
   cin>>n;
   int arr[n];
   for(int i = 0 ; i<n ; i++){
    cin>>arr[i];
   }
   
   int small =findSmallest(arr,n);
   int large = findLargest(arr,n);
   cout<<"The largest is :" << large << "\nThe min is :"<< small <<"\n";
    return 0;
}