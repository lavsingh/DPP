#include<iostream>
#include<string>
using namespace std;

int main(){

	string s;
	int T,k;
	
	cin>>T;
	while(T>0){
		cin>>k;
		cin>>s;
		int n=0,count = 0;
		long long int ans = 0;
		for(int i=0;i<s.length();i++){
			if(s[i] == '1'){
				ans += count + 1;
				count++;

			}
		}
		cout<<ans<<endl;
		T--;
	}
	return 0;
}