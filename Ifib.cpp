#include <iostream>

using namespace std;

int Ifib(long long int n){
	int a,temp,b;
	if (n==0)	return 0;
	else if (n==1) return 1;
	else {
		a=0;b=1;
		for (int i = 2; i < n+1; ++i)
		{
			temp=b;
			b=a+b;
			a=temp;
		}
	}
	return b;
}

int main(int argc, char const *argv[])
{
	long long int n;
	cin >> n;
	cout << Ifib(n);
}