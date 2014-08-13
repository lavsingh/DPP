#include<iostream>
#include<string>
#include<set>
using namespace std;
bool isPerfectString(string s){
	bool value = true;
	for(int i=1;i<s.length()-1;i++){
		set<string> p;
		for(int j=0;j<s.length()-i;j++){
			
			string t;
			t = t + s[j] + s[j+i];
			if(p.find(t) != p.end())
				return false;
			else
				p.insert(t);
		}
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	cout<<isPerfectString(s)<<endl;

	int k;
	cin>>k;

	return 0;
}