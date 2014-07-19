#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	vector <int> stack;
	string token1[5] ={"2","1","+","3","*"};
	int i = 0;
	while(i<5){
		string token = token1[i];
		if(token.at(0) > '0' && token.at(0) <'9'){
			stack.push_back(std::stoi(token));
			
		}
		else{
			int l = stack.back();
			stack.pop_back();
			int r = stack.back();
			stack.pop_back();
			if(token.compare("+") == 0){
				stack.push_back(l+r);
			}
			if(token.compare("*") == 0){
				stack.push_back(l*r);
			}
		}
		i++;
	}
	if(stack.size() != 1)
	{	cout<<"error"<<endl;
		return 0;
	}
	cout<<stack.at(0);
	return 0;
}