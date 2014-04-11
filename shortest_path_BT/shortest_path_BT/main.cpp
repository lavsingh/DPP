#include<iostream>

using namespace std;
int shortest_path(int x,int y){
	int count=0;
	while(x!=y)
	{
		if(x>y){
			x=x/2;
		}else if (x<y){
			y=y/2;
		}
		count++;
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	while(t>0){
		int num1,num2;
		cin>>num1>>num2;
		cout<<shortest_path(num1,num2)<<endl;
		t--;
	}
	return 0;
}