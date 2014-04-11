#include<iostream>

using namespace std;

void function(int A){
	int soln=0,power=0;
	while(A!=0){
		int t = A%9;
		if(t>=7) t++;
		soln=soln + t*pow(10*1.0,power);
		power++;
		A= A/9;
	}
	cout<<soln;
	cin>>power;

}
int main(){
	int A=34;
	function(A);
	return 0;
}