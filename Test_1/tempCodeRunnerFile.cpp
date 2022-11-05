#include<bits/stdc++.h>
using namespace std;


class Item
{
    public:
    int value;
    int weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}


double fractionalKnapsack(int W, vector<Item> arr, int n)
{
    sort(arr.begin(), arr.end(), compare);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}


int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;

    vector<Item> items;
    int value, weight;
    for(int i=0; i<n; i++){
        cout<<"Enter the value and weight of item "<<i+1<<": ";
        cin>>value>>weight;
        items.push_back(Item(value, weight));
    } 
    int W;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>W;
    cout<<"Maximum value we can obtain = "<<fractionalKnapsack(W, items, n);
    return 0;
}
