#include<iostream>
#include<string>

using namespace std;

void function2(string s, int A[]){
	int i=0;
	while(i<s.length()){
		A[s[i]-97]++;
		i++;
	}
	return;
}
void function(string s, string t){
	int count[26], seen[26];
	int countSeen = 0;
	memset(count,0,sizeof(count));
	memset(seen,0,sizeof(seen));

	function2(t,seen);
	int end=0, flag=0, i =0;
	while(i< s.length()){
		count[s[i]-97]++;
		if(flag == 0 ){
			if(count[s[i] - 97 ] <= seen[s[i]-97])
				countSeen++;
			if(countSeen == t.length())
				flag = 1;
		}
		if(flag==1) {
			while(1){
				if(count[s[end]-97] -1 >=seen[s[end]-97]){
					end++;
					count[s[end]-97]--;
				}
				else
					break;
			}
			if(i - end == t.length()-1)
				cout<<end<<endl;
		}
		i++;
	}
	return;
}

using namespace std;

int main(){
	string txt = "AABAACAADAABAAABAA";
	string pat = "AABA";
	function(txt,pat);
	return 0;
}