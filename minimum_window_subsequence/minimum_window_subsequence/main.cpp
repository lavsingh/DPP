#include<iostream>

using namespace std;

int windowLength(string s, string t, int &start, int &end){
	int needToFind[256]={0},hasFound[256]={0};
	
	for(int i=0; i<t.length(); i++){
		needToFind[t.at(i)]++;
	}
	int window = INT_MAX, count=0;
	bool found = false;
	for(int i=0; i<s.length(); i++){
		hasFound[s.at(i)]++;
		if( found == false && needToFind[s.at(i)] != 0 )
		{	
			if( needToFind[s.at(i)] >= hasFound[s.at(i)] )
				count++;
			if( count == t.length() )
				found = true;
		}
		
		if(found)
			while(start<=end){
				if( (hasFound[s.at(start)] - 1) >= needToFind[s.at(start)] ) {
					hasFound[s.at(start)]--;
					start++;
					if(end - start <window)
						window = end - start;
				}
				else 
					break;
			}
		end++;
	}
	return window;
}

int main(){
	int start=0, end=0;
	cout<<windowLength("ADOBECODEBANC","ABC",start,end);
	int k;
	cin>>k;
	return 0;
}