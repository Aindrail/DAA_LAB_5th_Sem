/*
In a social gathering, there are b boys and g girls (b > g) of different ages. You have two
unsorted arrays giving their ages (one for the boys, the other for the girls). Write a program
by devising an efficient O(b log g) algorithm to find out the ages that are common between
both the boys and girls.
Example:
If Arrayboy = {10, 20, 11, 89, 23, 21} and Arraygirl = {12, 30, 11, 20},
Then Arraycommon = {11, 20}
*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    int b,g;
    cout<<"Enter the boys array length\n";
    cin>>b;
    cout<<"Enter the ages of boys\n";
    int arr1[b];
    for(int i=0;i<b;i++){
        cin>>arr1[i];
    }
        sort(arr1,arr1+b);
    cout<<"Enter the girls array length\n";    
    cin>>g;
    int arr2[g];
    cout<<"Enter the ages of girls\n";
    for(int i=0;i<g;i++){
        cin>>arr2[i];
    }

    sort(arr2,arr2+g);
    int i=0,j=0;
    while(i<b && j<g){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            while(arr1[i]==arr2[j] && i<b && j<g){
                i++; j++;
            }
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return 0;
}