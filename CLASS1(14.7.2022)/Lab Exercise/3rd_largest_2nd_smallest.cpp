#include<bits/stdc++.h>

using namespace std;
int  findSmallest(int arr[],int n){
    
    
   return arr[n-1];
}
int  findLargest(int arr[],int n, int k){
    
 return arr[n-k-1];
}
int main(){
   int n ;
   cout<<"Enter the n\n";
   cin>>n;
   int arr[n];
   for(int i = 0 ; i<n ; i++){
    cin>>arr[i];
   }
   sort(arr,arr+n);

   
   int small =findSmallest(arr,2);
   int large = findLargest(arr,n,3);
   cout<<"The largest is : " << large << "\nThe min is : "<< small <<"\n";
    return 0;
}