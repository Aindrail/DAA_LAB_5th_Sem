#include<bits/stdc++.h>
using namespace std;

void OddEven(int arr[] , int n){
 int o =0, e=0;
 while(e<n && o<n){
    if(arr[o]%2==0){
        int t = arr[e];
        arr[e] = arr[o];
        arr[o] = t;
        o++; e++;
    }
    o++;
 }
}
int main(){
   int n ;
   cout<<"Enter the n\n";
   cin>>n;
   int arr[n];
   for(int i = 0 ; i<n ; i++){
    cin>>arr[i];
   }
   OddEven(arr,n);
   for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
   }
    return 0;
}