#include<iostream>
using namespace std;

void print_array(int arr[] , int size)
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"\t";
}

void merge(int arr[] , int low , int mid , int high)
{
	int b[15];
	int size = high-low+1;
	int k=0;
	int i = low;
	int j = mid+1;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k] = arr[i];
			i++;
		}
		else
		{
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k] = arr[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k] = arr[j];
		j++;
        k++;
	}
	for(int z=0;z<size;z++){
		//cout<<b[z]<<" ";
		arr[z] = b[z];
	}
	//cout<<"next";
}

void merge_sort(int arr[] , int low , int high)
{
	if(low<high)
	{
		int mid = low + (high-low)/2;
	
	    merge_sort(arr , low , mid);
	    merge_sort(arr , mid+1 , high);
	    merge(arr , low , mid , high);
	}
}

int main()
{
	int arr[] = {34,1,45,2,8,12};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Before Sorting :"<<endl;
	print_array(arr,size);
	merge_sort(arr,0,size-1);
	cout<<endl<<"After Sorting :"<<endl;
	print_array(arr,size);
	
    return 0;
}