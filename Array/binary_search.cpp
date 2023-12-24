#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key)
{
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;

    while(start<=end)
    {
        if(arr[mid]==key)
        return mid;

        if(key>arr[mid])
        start=mid+1;

        if(key<arr[mid])
        end=mid-1;

        mid=start + (end-start)/2;
    }

    return -1;
}
int main()
{
    int arr[10];
    int max,min,temp;
    int a=0;
    int b=9;
    int n=10;
    cout<<"Enter the values you want to insert in array";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    max=min=arr[0];
    for(int i=1;i<10;i++)
    {
        if(arr[i]<min)
        min=arr[i];
        if(arr[i]>max)
        max=arr[i];
    }
    cout<<"Maximum element is : "<<max<<endl;
    cout<<"Minimum element is : "<<min<<endl;

    //reverse array;
    // while(a<=b)
    // {
    //     swap(arr[a],arr[b]);
    //     a++;
    //     b--;
    // }
    
    // for(int i=0;i<n/2-1;i++)
    // {
    //     temp=arr[i];
    //     arr[i]=arr[n-i];
    //     arr[n-i]=temp;
    // }

    // cout<<"Reverse Array : "<<endl;
    // for(int k=0;k<10;k++)
    // {
    //     cout<<arr[k]<<"\t";
    // }

    //binary search
    temp=binarySearch(arr,10,12);
    cout<<temp;
    return 0;
}