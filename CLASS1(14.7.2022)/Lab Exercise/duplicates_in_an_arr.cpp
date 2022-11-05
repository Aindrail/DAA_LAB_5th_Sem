#include<bits/stdc++.h>

using namespace std;
int  findDup(int arr[],int n){
    int count = 0;
    for(int i = 0 ; i<n-1 ; i++){
        if(arr[i]==arr[i+1]){
            
                count++;
            

        }
        
    }
    return count;
    
   
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

   int dup = findDup(arr,n);

cout<<"The no of duplicate\n"<<dup<<"\n";
    return 0;
}