#include<iostream>
using namespace std;

int factorial(int a,int b){
	int product = 1;
	for(int i=a+1;i<=b;i++)
		product*=i;
	return product;
}
int function(int c, int n){
	int size = c;
	int t=1,k=1;
	int product=1;

	while((n-4*k)>=0){
		t+= factorial(n-4*k,n-3*k)/product;
		k++;
		product*=k;
	}
	return t;
}
int primeToLimit(int num){
	int count=0;
	for(int i=2;i<=num;i++)
	{	bool prime = true;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0){
				prime = false;
				break;
			}
		}
		if(prime == true)
			count++;
	}
	return count;
}
int main(){
	int c = 4,n;
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int number = function(c,n);
		cout<<primeToLimit(number)<<endl;
	}
	return 0;
}
