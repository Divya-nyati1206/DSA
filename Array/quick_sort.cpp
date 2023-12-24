#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int partition(int arr[] , int low , int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        swap(arr[i+1],arr[high]);
        return (i+1);
    }
}

void quicksort(int arr[] , int low , int high)
{
    if(low<high)
    {
        int pi=partition(arr , low , high);

        quicksort(arr , low , pi-1);
        quicksort(arr , pi+1 , high);
    }
}

int main()
{
    int arr[50];
    cout<<"Enter size of array :";
    int n;
    cin>>n;
    cout<<"Enter elements of array :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Before Sorting :"<<endl;
    printArray(arr,n);
    quicksort(arr,0,n-1);
    cout<<"After Sorting :"<<endl;
    printArray(arr,n);

    return 0;
}