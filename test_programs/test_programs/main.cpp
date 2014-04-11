#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

bool palindrome(string s){
	
	int left =0, right = s.length()-1;
	while(left<right){
		while(s[left] == ' ')
			left++;
		while(s[right] == ' ')
			right--;
		if(s[left] != s[right])
			return false;
		left++;
		right--;
	}
	return true;
}

void printarray(int A[],int k){
	for(int i=0;i<k;i++)
		cout<<A[i]<< " ";
	cout<<endl;
}

void array_subsets(int A[], int n, int elementPos, int subsets[], int pos, int k){
	
	if(pos == k)
	{	
		cout<<"here";
		printarray(subsets,k);
		return;
	}
	if(elementPos == n )
		return;
	subsets[pos] = A[elementPos];
	array_subsets(A,n,elementPos+1,subsets,pos+1,k);
	array_subsets(A,n,elementPos+1,subsets,pos,k);
	
}

map<string, string> memoized;

string string_tokenize(string s, set<string> dict){
	if(dict.contains(s)) return s;
	if(memoized.has(s)) return memoized.get(s);
	for(int i =1;i<s.length();i++)
	{
		string left = s.substring(0,i);
		if(dict.contains(left)){
			string right = s.substring(i);
			string segsuffix = string_tokenize(right, dict);
			if(segsuffix != null)
			{
				memoized[right]=segsuffix;
				return left + ' ' + segsuffix;
			}
		}

	}
	memoized[input] = null;
	return null;
}
int main(){

	string s = "  r";
	int A[100] = {1,2,3,4,5,6,7,8,9,10};
	int subsets[10] = {};
	array_subsets(A,10,0,subsets,0,5);
	cin>>s;
}