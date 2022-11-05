/*Write a menu driven program as given below, to sort an array of n integers in ascending
order by insertion sort algorithm and determine the time required (in terms of step/frequency
count) to sort the elements. Repeat the experiment for different values of n and different
nature of data (i.e.apply insertion sort algorithm on the data of array that are already sorted,
reversly sorted and random data). Finally plot a graph of the time taken versus n for each
type of data. The elements can be read from a file or can be generated using the random
number generator.
0. Quit
1. n Random numbers=>Array
2. Display the Array
3. Sort the Array in Ascending Order by using Insertion Sort
Algorithm
4. Sort the Array in Descending Order by using any sorting
algorithm
5. Time Complexity to sort ascending of random data
6. Time Complexity to sort ascending of data already sorted in
ascending order
7. Time Complexity to sort ascending of data already sorted in
descending order
8. Time Complexity to sort ascending of data for all Cases (Data
Ascending, Data in Descending & Random Data) in Tabular form
for values n=5000 to 50000, step=5000

*/


#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void menu()
{   cout<<"\n\n**********************************************************************************************\n\n";
    cout << "Press 0 to Quit\n";
    cout << "Press 1 to Make Random Array\n";
    cout << "Press 2 to Display The Array\n";
    cout << "Press 3 to Sort the Array in Ascending Order by using Insertion Sort Algorithm\n";
    cout << "Press 4 to Sort the Array in Descending Order by using any sorting algorithm\n";
    cout << "Press 5 to Time Complexity to sort ascending of random data\n";
    cout << "Press 6 Time Complexity to sort ascending of data already sorted in ascending order\n";
    cout<<"Press 7 Time Complexity to sort ascending of data already sorted in descending order\n";
    cout<<"Press 8 for display the table of Time complexity of 3 cases in tabular form\n";
    cout<<"\n\n**********************************************************************************************\n";
}

void insertion_sort(vector<int>&ar)
{
    int n=ar.size();
    for(int i=1;i<n;i++)
    {
        int key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>key)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }

 //display
    // for(int i=0;i<n;i++)
    // {
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl;


}


int main()
{   
    int choice;
    vector<int> Size;
        vector<double> time_asc;
        vector<double> time_desc;
        vector<double> time_rand;
        vector<int>arr;
        vector<int>arr2;
menu();
    while(1){
        
    
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 0: {
        cout << "Quitting\n";
        exit(0);
        break;
    }
    case 1: {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        Size.push_back(n);
        arr.resize(n);
        
        for (int i = 0; i < n; i++)
        {
             arr[i] = rand() % 10000;
        }
        arr2 = arr;
        break;
    }
    case 2: {
        cout << "The array is: ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        break;
    }
    case 3: {
        // cout << "The sorted array is: ";
    
 
//    auto start = high_resolution_clock::now();
// clock_t start,end;
//         start=clock();
        insertion_sort(arr);
        // end=clock();
        // double time=(double)(end-start)/CLOCKS_PER_SEC;
// auto stop = high_resolution_clock::now();
//  auto time_taken=duration_cast<microseconds>(stop - start);
// cout<<"Time taken by insertion sort is: "<<time_taken.count()<<endl;
// double t = (double)time_taken.count();

//  time_rand.push_back(time);
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        break;
    }
    case 4: {
        // cout << "The sorted array is: ";
        sort(arr.begin(), arr.end(), greater<int>());
        // for (int i = 0; i < arr.size(); i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        break;
    }
    case 5:{
        clock_t start,end;
        start=clock();
        insertion_sort(arr2);
        end=clock();
        double time=(double)(end-start)/CLOCKS_PER_SEC;
        // int n = time_rand.size();
        // cout<<"Time Complexity to sort ascending of random data is: "<<time_rand[n-1]<<endl;
        time_rand.push_back(time);
        cout<<"Time Complexity to sort ascending of random data is: "<<time<<endl;
        break;
    }
    case 6:{
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        clock_t start,end;
         start=clock();
        //auto stt = high_resolution_clock::now();
        insertion_sort(temp);
         end=clock();
        //  cout<<start<<" "<<end<<endl;
        //  auto stp = high_resolution_clock::now();
        // auto time_take=duration_cast<microseconds>(stp - stt);
   double time_taken=(((double)(end-start))/CLOCKS_PER_SEC );
 cout<<"Time taken for the array already sorted in ascending order is: "<<time_taken<<endl;
     
     time_asc.push_back(time_taken);
    // time_asc.push_back(t);
            break;
        }
        case 7:{
             vector<int> temp = arr;
             sort(temp.begin(),temp.end(),greater<int>());
            clock_t start,end;
            start=clock();
            // auto start = high_resolution_clock::now();
            insertion_sort(temp);
            // auto stop = high_resolution_clock::now();
            // auto time_taken=duration_cast<microseconds>(stop - start);
            // double t = (double)time_taken.count();
            end=clock();
            double time_taken=(((double)(end-start))/CLOCKS_PER_SEC);
            cout<<"Time taken for the array already sorted in descending order is: "<<time_taken<<"ms\n";
              time_desc.push_back(time_taken);
break;
    }
    case 8:{
        int n = Size.size();
        cout<<"Sl NO."<<"\t"<<"Val of n"<<"\t"<<"T.C. rand."<<"\t"<<"T.C. sort in asc"<<"\t"<<"T.C. sort in des"<<endl;
        for(int i = 0 ; i<n ; i++){
            cout<<i+1<<"\t"<<Size[i]<<"\t\t"<<time_rand[i]<<" ms\t\t"<<time_asc[i]<<" ms\t\t"<<time_desc[i]<<" ms\n";
        }

        break;
    }
       
    
    default:
        break;
    }


    } 
    return 0;
}