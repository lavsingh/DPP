#include<iostream>
using namespace std;


int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

void word_break(string s){
	int A[100], B[100];
	memset(A,100,INT_MAX);
	for(int i=1;i<s.length();i++){
		if(A[i] == INT_MAX && dictionaryContains(s.substr(0,i)))
			A[i] = 1;
		if(A[i] != INT_MAX){
			for(int j=i+1; j<s.length();j++){
				if(dictionaryContains(s.substr(j, j-i))){
					int val = A[i] + 1;
					if(val < A[j]){
						A[j] = val;
						B[j] = i;
					}
				}
			}	
		}
	}
	
}
int main(){

	return 0;
}