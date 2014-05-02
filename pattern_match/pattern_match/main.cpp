#include <iostream>
#include <String>

using namespace std;

bool patternMatch(string s, int index, string pat, int m){
	
	if(m == pat.length())
		return true;

	if(pat[m] == '^'){
		m++;
		while(pat[m+1]!='\0'){
			if(pat[m+1]!='*' && pat[m]!='.'&& pat[m] == s[index])
			{	index++;
				m++;
			}
			else if(pat[m+1]=='*')
				return patternMatch(s, index, pat, m);
			else if(pat[m]=='.')
				return patternMatch(s, index, pat, m);
			else 
				return false;
		}
	}
	if(pat[m] == '$'){
		if(index == s.length())
			return true;
		else
			return false;
	}
	if(m+1< pat.length() && pat[m+1] == '*'){

		while(m+1 < pat.length() && index< s.length() && pat[m+2] != s[index]){
			if(pat[m+1] == '$')
				return false;
			if(pat[m] != s[index])
				return false;
			index++;
		}
		if(index == s.length() && m+1 < pat.length())
			return false;
		return patternMatch(s, index, pat, m+2);
		
	}

	if(pat[m] == '.'){
		if(pat[m+1] == '$')
			return true;
		while(m+1 < pat.length() && index< s.length() && pat[m+1] != s[index]){
			
			index++;
		}
		if(index == s.length() && m+1 < pat.length())
			return false;
		return patternMatch(s, index, pat, m+1) || patternMatch(s, index + 1, pat, m);
	}

	if(pat[m] == s[index])
		return patternMatch(s, index + 1, pat, m + 1);
	return patternMatch(s, index + 1, pat, m);

}


int main() {
	
	string s="lavvvvvvsingh", pat="^lav*si.h$";
	if(patternMatch(s, 0, pat, 0))
		cout<<"pattern accepted";
	else
		cout<<"pattern mismatch";
	int n;
	cin>>n;
	return 0;
}