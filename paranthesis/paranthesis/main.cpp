#include<iostream>
#include<string>

using namespace std;
void paranthesis(int num, int left, int right, string result){
	
	if(left==(num+1) || right>left)
		return;
	if(left==num && right ==num)
	{
		cout<<result<<endl;
		return;
	}
	if (left<(num+1))
	{
		paranthesis(num,left+1, right,result + '(');
		paranthesis(num,left,right + 1, result + ')');
	}
	return;
}


int main(){
	int num;
	cin>>num;
	string result="";
	paranthesis(num, 0, 0 , result);
	cin>>num;
	return 0;
}