#include <iostream>

using namespace std;

int compute_sum(int a[],int i,int j)
{
	int sum=a[i];
	for (int k=i+1; k <=j; ++k)
	{
		sum=sum+a[k];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int max,n,temp;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	max=arr[0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp=compute_sum(arr,i,j);

			if(max<temp)max=temp;
		}
	}

	cout << max;

	return 0;
}