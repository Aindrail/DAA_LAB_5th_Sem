/*Write a program to use divide and conquer method to determine the time required to
find the maximum and minimum element in a list of n elements. The data for the list
can be generated randomly. Compare this time with the time taken by straight forward
algorithm or brute force algorithm for finding the maximum and minimum element for the
same list of n elements. Show the comparison by plotting a required graph for this problem*/

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int findMax(int arr[],int l,int r){
    if(l==r){
        return arr[l];
    }
    int mid = (l+r)/2;
    int max1 = findMax(arr,l,mid);
    int max2 = findMax(arr,mid+1,r);
    return max(max1,max2);
}
 int findMin(int arr[],int l,int r){
    if(l==r){
        return arr[l];
    }
    int mid = (l+r)/2;
    int min1 = findMin(arr,l,mid);
    int min2 = findMin(arr,mid+1,r);
    return min(min1,min2);
 }
 void find_max(int arr[],int n){
     int max = arr[0];
     for(int i=1;i<n;i++){
         if(arr[i]>max){
             max = arr[i];
         }
     }
     cout<<"Max element is: "<<max<<endl;
 }
    void find_min(int arr[],int n){
        int min = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<min){
                min = arr[i];
            }
        }
        cout<<"Min element is: "<<min<<endl;
    }
int main(){
    clock_t start, end;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    // cout<<"Array is: ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
     start = clock();
    find_max(arr,n);
     end = clock();
    double time_taken=(((double)(end-start))*100/CLOCKS_PER_SEC);
    cout << "Time taken by function: "<< time_taken<< " microseconds" << endl<<endl;
    start = clock();
    find_min(arr,n);
    end = clock();
    time_taken=(((double)(end-start))*100/CLOCKS_PER_SEC);
    cout << "Time taken by function: "<< time_taken << " microseconds\n" << endl;
   start = clock();
    cout<<"Max element is: "<<findMax(arr,0,n-1)<<endl;
    end = clock();
    time_taken=(((double)(end-start))*100/CLOCKS_PER_SEC);
    cout << "Time taken by function: "<< time_taken << " microseconds\n" << endl;
    start = clock();
    cout<<"Min element is: "<<findMin(arr,0,n-1)<<endl;
    end = clock();
    time_taken=(((double)(end-start))*100/CLOCKS_PER_SEC);
    cout << "Time taken by function: "<< time_taken << " microseconds\n" << endl;

    return 0;
}
// #include<iostream>
// using namespace std;
// int main(){
//     int x = 1;
//     for(int i =0 ; i<=128; i+=i){
//         x+=x;
//     }
//     cout<<"hello";
//     cout<<x<<endl;
//     return 0;
// }
// int countSubstrings(string input_str) {
// unordered_map<char,int>map;
//     map['a']=1;
//     map['b']=1;
//     map['c']=2;
//     map['d']=2;
//     map['e']=2;
//     map['f']=3;
//     map['g']=3;
//     map['h']=3;
//     map['i']=4;
//     map['k']=4;
//     map['l']=5;
//     map['m']=5;
//     map['n']=5;
//     map['o']=6;
//     map['p']=6;
//     map['q']=7;
//     map['r']=7;
//     map['s']=7;
//     map['t']=7;
//     map['u']=8;
//     map['v']=8;
//     map['w']=8;
//     map['x']=9;
//     map['y']=9;
//     map['z']=9;
//     vector<int> count_rem (k,0);
//         count_rem[0]=1;
//         int sum =0;
//         int ans =0;

//         for(int i =0 ; i<input_str.length(); i++){
//             int rem;
//             sum+=mp[input_str[i]];
//             rem= sum%k;
//             if(rem<0){
//                 rem+=k;
//             }
//             if(count_rem[rem]!=0){
//                 ans+=count_rem[rem];
//                 count_rem[rem]++;
//             }
//             else{
//                 count_rem[rem]++;
//             }
            
//         }
//         return ans;
// }
