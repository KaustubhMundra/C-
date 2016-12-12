#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,max;
	cin >> n;
	int arr[n],s[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	
	s[0]=arr[0];
	max=s[0];

	for (int i = 1; i < n; ++i)
	{
		if(s[i-1]>0)s[i]=s[i-1]+arr[i];
		else s[i]=arr[i];

		if(s[i]>max)max=s[i];
	}

	// max=s[0];
	// for (int i = 1; i < n; ++i)
	// {
	// 	if(s[i]>max)max=s[i];
	// }

	cout << max;

	return 0;

}