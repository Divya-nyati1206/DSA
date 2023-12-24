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

    //bubble_sort
    for(i=1;i<size;i++)
    {
        bool swapped=false;       //to optimise the code i.e. to reduce time complexity of code
        for(j=0;j<size-i;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
                swapped=true;
            }
        }
        if(swapped==false)
        break;
    }

    cout<<endl<<"Elements in sorted array :"<<endl;
    printArray(arr,size);

    return 0;
}