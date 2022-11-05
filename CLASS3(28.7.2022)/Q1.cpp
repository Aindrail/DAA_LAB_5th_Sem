/*Write a program to test whether a number n, entered through keyboard is prime or not by
using different algorithms you know for atleast 10 inputs and note down the time complexity
by step/frequency count method for each algorithm & for each input. Finally make a
comparison of time complexities found for different inputs, plot an appropriate graph &
decide which algorithm is faster*/
#include<bits/stdc++.h>
using namespace std;
bool prime_or_not(int n,int &step){
    int i, count=0;
    for(i=2;i<=n/2;i++){
        step++;
        if(n%i==0){
            count++;
            break;
        }
    }
    if(count==0){
    
        return true;
    }
    else{
        return false;
    }

}
void prime_2nd_method(int n,int &step){
    int i;
    for(int i = 2; i<=sqrt(n); i++){
        step++;
        if(n%i==0){
           
            break;
        }
    }
    

}

void prime_3rd_method(int n,int &step){
    if (n <= 1)
        return;
 
    for (int i = 2; i < n; i++)
    {
        step++;
          if (n % i == 0)
            return ;
    }
       
 
    return ;
    

}



int main(){
    int n;

    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"Enter n interger"<<endl;
    int arr[n];
    for(int i =0 ; i<n;i++){
   cin>>arr[i];
    }
    cout<<"Sl No."<<"\t"<<"Number"<<"\t"<<"Step1"<<"\t"<<"Step2"<<"\t"<<"Step3"<<"\t"<<"Prime or not"<<endl;
    for(int i =0 ; i<n ; i++){
        int step=0;
       bool isP= prime_or_not(arr[i],step);
        int step2=0;
        prime_2nd_method(arr[i],step2);
        int step3=0;
        prime_3rd_method(arr[i],step3);
        string s= isP?"Prime":"Not Prime";
        cout<<i+1<<"\t"<<arr[i]<<"\t"<<step<<"\t"<<step2<<"\t"<<step3<<"\t"<<s<<endl;

    }
    
    return 0;
}