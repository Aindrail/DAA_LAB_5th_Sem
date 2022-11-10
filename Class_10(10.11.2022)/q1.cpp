/*
Write a Program to implement Matrix Chain Multiplication and also find the
optimal parenthesization.
*/

#include<bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int arr[], int n){
    int dp[n][n];
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }
    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }


    return dp[1][n-1];
}

int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the dimensions of the matrices: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Minimum number of multiplications required: "<<MatrixChainMultiplication(arr, n);
    
}

//Expected Output:
//Enter the number of matrices: 4
//Enter the dimensions of the matrices: 1 2 3 4
//Minimum number of multiplications required: 18


 