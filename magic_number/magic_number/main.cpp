#include<iostream>
#include<math.h>
using namespace std;

int function(int n){
	if(n<6) return 0;
	int power = log10(n*1.0);
	int numToSkip = 0;
	int ten_power = (int)pow(10*1.0,power);
	int msb = n / ten_power;
	int current = 0 ;
	while(current < power ){
		numToSkip = numToSkip *9 + pow(10*1.0,current);
		current++;
	}
	if( msb > 7 )
		numToSkip = numToSkip * (msb-1) + ten_power;
	else if(msb<7)
		numToSkip = numToSkip * msb;
	else 
		numToSkip = numToSkip * (msb-1);
	return numToSkip + function(n - msb*ten_power);
}
int newNumber(int n){
	if (n<0){
		return (n + function(n*-1));
	}
	else {
		return (n- function(n));
	}
}
int main(){

	cout<<newNumber(6);
	cout<<newNumber(98);
	int k;
	cin>>k;
	return 0;
}