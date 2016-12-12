#include <iostream>

using namespace std;

int local_minima(int arr[],int m,int n)
{
	if(m==0 || m==n-1)return 1;
	if((arr[m+1]>arr[m]) && (arr[m-1]>arr[m]))return 1;
	return 0;	
}

int local_minima_in_array(int arr[],int n)
{
	
	int l=0,r=n-1,found=0,mid;

	while(!found)
	{
		mid=(l+r)/2;
		//cout << mid;
		if(local_minima(arr,mid,n)==1)found=1;
		else if(arr[mid+1]<arr[mid])l=mid+1;
		else r=mid-1;
	}

	cout << mid;
	return 0;
}



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	local_minima_in_array(arr,n);

	return 0;
}