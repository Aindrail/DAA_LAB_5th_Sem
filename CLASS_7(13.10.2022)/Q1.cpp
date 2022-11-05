/*
A and B are playing a guessing game where B first thinks up an integer X (positive,
negative or zero, and could be of arbitrarily large magnitude) and A tries to guess it. In
response to A’s guess, B gives exactly one of the following three replies:
a) Try a bigger number
b) Try a smaller number or
c) You got it.
Write a program by designing an efficient algorithm to minimize the number of guesses
A has to make. An example (not necessarily an efficient one) below:
Let B thinks up the number 35
A’s guess B’s response
10 Try a bigger number
20 Try a bigger number
30 Try a bigger number
40 Try a smaller number
35 You got it

*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    // int number_generated;
    // number_generated = rand()%100;
    // int guess;
    // int count = 0;
    // while(number_generated!=guess){
    //     cout<<"Enter your guess: ";
    //     cin>>guess;
    //     if(guess>number_generated){
    //         cout<<"Try a smaller number"<<endl;
    //     }
    //     else if(guess<number_generated){
    //         cout<<"Try a bigger number"<<endl;
    //     }
    //     else{
    //         cout<<"You got it"<<endl;
    //     }
    //     count++;
    // }

    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int l=INT_MIN,r=INT_MAX;
    int mid;

    int count=0;
    while(l<=r){
        mid = (l+r)/2;
        if(mid==n){
            cout<<"You got it"<<endl;
            break;
        }
        else if(mid<n){
            cout<<"Try a bigger number"<<endl;
            l=mid+1;
        }
        else{
            cout<<"Try a smaller number"<<endl;
            r=mid-1;
        }
        count++;
    }
    cout<<"Number of guesses: "<<count<<endl;
    return 0;
}