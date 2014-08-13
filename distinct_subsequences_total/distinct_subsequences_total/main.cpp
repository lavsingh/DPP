#include<iostream>
#include<string>
using namespace std;

int function(string s, string t){
	int A[100][100];
	memset(A,0,100*100*sizeof(int));
	for(int i=0;i<s.length()+1;i++)
		A[i][0] = 1;
	for(int i=1;i<s.length()+1;i++){
		for(int j=1;j<t.length()+1;j++){
			if(s.at(i-1) == t.at(j-1)){
				A[i][j] = A[i-1][j-1] + A[i-1][j];
			}
			else {
				A[i][j] = A[i-1][j];
			}
		}
	}
	return A[s.length()][t.length()];
}
int main(){

	string s = "rabbbit";
	string t = "rabbit";
	cout<<function(s,t);
	return  0;
}