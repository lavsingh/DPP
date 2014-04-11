#include<iostream>
#include<stdlib.h>	
#include<string>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	string s;
	cin>>s;

	int *A = (int*)malloc(m* sizeof(int));
	for(int i=0;i<m;i++)
		A[i] = 0;

	int count[10]={0};
	int cur = s[0]-'0';
	count[cur]++;
	for(int i=1;i<s.size();i++){
		cur = s[i]-'0';
		count[cur]++;
		for(int j=0;j<10;j++){
			A[i] += abs(count[j]*(cur - j));
		}
	}
	while(n>0){
		int loc;
		cin>>loc;
		cout<<A[loc-1]<<endl;
		n--;
	}

	return 0;
}