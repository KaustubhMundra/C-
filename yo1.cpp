#include <iostream>

using namespace std;

int main(){
	int *a=new int[5];
	a[0]=1;
	a[1]=5;
	cout << a[0]<< " " << a[1];
	return 0;
}