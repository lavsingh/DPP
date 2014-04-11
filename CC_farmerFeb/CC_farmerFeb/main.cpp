#include<iostream>
#include<math.h>
using namespace std;

int next_prime(int n){
	int result=n+1;
	int flag=0;
	while(1){
		flag=1;
		for(int i=2;i<=sqrt(result*1.0);i++){
			if(result%i == 0){
				flag = 0;
				break;
			}
		}
		if(flag==1)
			return result;
		result++;
	}
}


int main(){
	int t;
	cin>>t;
	while(t>0){
		int num1,num2;
		cin>>num1>>num2;
		cout<<next_prime(num1+num2) -num1 - num2<<endl;
		t--;
	}
	return 0;
}