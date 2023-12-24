#include<iostream>
using namespace std;

void printArray(int arr[],int size)
{   
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int arr[50];
    int size,i,j;
    cout<<"Enter size of array : ";
    cin>>size;
    cout<<"Enter elements of array : ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Elements of array are :"<<endl;
    printArray(arr,size);

    //insertion sort

    for(i=1;i<size;i++)
    {
        int temp=arr[i];
        int j=i-1;
        // for(;j>=0;j--)
        // {
        //     if(arr[i]>temp)
        //     arr[j+1]=arr[j];
        //     else 
        //     break;
        // }
        // arr[j+1]=temp;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }

    cout<<endl<<"Elements in sorted array :"<<endl;
    printArray(arr,size);

    return 0;
}