#include<iostream>
#include<string>
using namespace std;

void print_combination(string input, string output, int pos){
	if(pos == input.length()){
		cout<<output<<endl;
		return;
	}
	print_combination(input,output,pos+1);
	print_combination(input,output + input[pos],pos+1);
	return;
}
int main(){

	string s="lavsingh";
	
	string output;
	print_combination(s,output,0);
	cin>>s;
	return 0;
}