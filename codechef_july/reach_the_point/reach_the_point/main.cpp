#include<iostream>

using namespace std;

int main(){

	int t;
	cin>>t;
	long long int x,y;
	while(t>0){
		cin>>x>>y;
		x = x<0?-1*x:x;
		y = y<0?-1*y:y;
		long long int min = x>y?y:x;
		long long int max = x<y?y:x;
		long long int len = 2*min;
		max -= min;
		if(x>y){
			if(max%2)
				len += 2*max + 1;
			else
				len += 2*max;
		}
		if(x<y){
			if(max%2)
				len += 2*max - 1;
			else
				len += 2*max;
		}
		cout<<len<<endl;
		t--;
	}
	return 0;
}