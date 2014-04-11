#include<iostream>
#include<vector>

using namespace std;

void function(int A[],int k){
	vector<int> elements;
	elements.push_back(0);
	int greater[4];
	for(int i=1;i<k;i++){
		
		while( elements.size()>0 && A[elements[elements.size()-1]] < A[i] )
		{	
			greater[elements[elements.size()-1]] = A[i];
			elements.pop_back();
		}
		elements.push_back(i);
	}
	while(elements.size() != 0){
		greater[elements[elements.size()-1]] = -1;
		elements.pop_back();
	}

	for(int i=0;i<k;i++)
		cout<<greater[i]<< " ";
	cout<<endl;
}
int main(){
	
	int A[4] = {11, 13, 21, 3};
	function(A,4);
	int k;
	cin>>k;
	return 0;
}