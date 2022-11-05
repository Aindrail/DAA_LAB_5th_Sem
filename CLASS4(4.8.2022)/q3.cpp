/*Let A[n] be a list of n (not necessarily distinct) integers. Write a program by using suitable User Defined Functions (UDF) as per the following specifications to test whether any item in A[n] occurs more than n/2 times in it.
(a)UDF takes O(n2) time and use no additional space
(b)UDF takes O(n) time and may use O(n) additional space
(c)UDF take O(n) time and may use at most O(1) additional space
*/

#include<bits/stdc++.h>
using namespace std;

void checkMajorityALgo1(int arr[], int n)
{
    int count = 0;
    int majorityElement;
    for (int i = 0; i < n; i++)
    {
        int uniqueCount = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                uniqueCount++;
                if (uniqueCount > count)
                {
                    count = uniqueCount;
                    majorityElement = arr[j];
                }
            }
        }
    }

    if (count + 1 > n / 2)
    {
        printf("\n%d is the majority element", majorityElement);
    }
    else
    {
        printf("\nNone element is present more than %d times", n / 2);
    }
}

void check_majority_On_space(int arr[], int n){

    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            count =1;
            cout << "Majority found :- " << i.first<<endl;
            break;
        }
    }
    if(count == 0)
        cout << "No Majority element" << endl;

}
int mooreVoting(int arr[], int n){
    int maj = arr[0];
    int count = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] == maj)
            count++;
        else
            count--;
        if(count == 0)
            maj = arr[i];
    }
    return maj;
}
int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"Enter n interger"<<endl;
    int arr[n];
    for(int i =0; i<n;i++){
    cin>>arr[i];
    }
    checkMajorityALgo1(arr, n);
    check_majority_On_space(arr, n);
    cout<<"\n"<<mooreVoting(arr, n);
    return 0;
}

