#include<iostream>
#include<string>
using namespace std;

void count(string s, int A[]){
	for(int i=0;i<s.length();i++)
		A[s.at(i) - 'A']++;
	return;
}

void function(string s, string pat){
	int patCount[26], currentCount[26];
	memset(patCount, 0, 26*sizeof(int));
	count(pat, patCount);
	memset(currentCount, 0, 26*sizeof(int));
	int flag = 0, num = 0;
	int pos = 0, start = 0;
	while(pos < s.length()){
		int currentPos = s.at(pos) - 'A';
		currentCount[currentPos]++;
		
		if(flag == 0 ){
			if(currentCount[currentPos] <= patCount[currentPos])
				num++;
			if(num == pat.length())
				flag = 1;
		}
		if(flag == 1){
			int startPos = s.at(start) - 'A';
			while(currentCount[startPos] > patCount[startPos]){
				currentCount[startPos]--;
				start++;
				startPos = s.at(start) - 'A';
			}
			if(pos-start == pat.length()-1)
				cout<<"position		"<<start<<endl;
		}
		pos++;
	}
}

int main(){
	string s = "BACDGABCDA";
	string pat = "ABCD";
	function(s,pat);

	return 0;
}