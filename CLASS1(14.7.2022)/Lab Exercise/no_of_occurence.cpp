#include<bits/stdc++.h>
using namespace std;

int main(){
   int n ;
   cout<<"Enter the n\n";
   cin>>n;
   int arr[n];
   unordered_map<int,int>mp;
   for(int i = 0 ; i<n ; i++){
    cin>>arr[i];
   
    
   }
   for(int i = 0 ; i<n ; i++){
    
    mp[arr[i]]++;
    
   }
   
  
   int maxC =0 , max=0, ans;
   for(int i =0 ; i<n ; i++){
    int c = mp[arr[i]];
    if(maxC<c){
       maxC = c;
       ans = arr[i];
    }
   }
   cout<<"Max occured "<< ans<<" occured "<<maxC<<" times";


    return 0;
}