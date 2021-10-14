#include <iostream>
using namespace std;
int BinarySearch(int x,int arr[],int n)
	{int start=0,end=n-1,mid=0;
     while(start<=end)
     {
     	mid = (start+end)/2;
     	if(arr[mid]==x)
     		return mid;
     	else if(arr[mid]<x)
     		start=mid+1;
     	else
     		end=mid-1;
     }
	return -1;
    }

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cin>>x;
	int index = BinarySearch(x,arr,n);
	cout<<index<<endl;
}
