#include <iostream>

using namespace std;

int Rfib(long long int n){
	if(n==0)return 0;
	else if (n==1) return 1;
	else return Rfib(n-1) + Rfib(n-2);
}

int main(){
	long long int n;
	cin >> n;
	cout << Rfib(n);
	return 0;
}