#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int count=0;
	long long int n;
	cin >> n;
	while(n!=0){
		if (n%2==1)count++;
		n=n/2;
	}
	int flag=1;
	for (int i = 2; i*i <= count; ++i)
	{
		if(count%i==0)flag=0;

	}
	if(flag==1)cout << "prime";
	else cout << "not prime";
	return 0;
}