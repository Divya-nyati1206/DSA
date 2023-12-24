#include<iostream>
using namespace std;

void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<"\t";
}

int partition(int arr[] , int low , int high)
{
	int pivot = arr[high];
	int j = low;
	int flag =0;
	for(int i=low;i<=high;i++)
	{
		if(arr[i]<pivot)
		{
			swap(arr[i],arr[j]);
			j=i;
		}
		else if(arr[i]>pivot && flag == 0)
		{
			j=i; flag=1;
		}
	}
    if(arr[j]>arr[high])
	swap(arr[high],arr[j]);
	return j;
}

void quicksort(int arr[] , int low , int high)
{
	if(low<high)
	{
		int pi = partition(arr,low,high);
		
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int main()
{
	int arr[] = {3,12,2,10,4,16,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Before Sorting :"<<endl;
	printarray(arr,size);
	quicksort(arr,0,size-1);
	cout<<endl<<"After Sorting :"<<endl;
	printarray(arr,size);
	
	return 0;
}