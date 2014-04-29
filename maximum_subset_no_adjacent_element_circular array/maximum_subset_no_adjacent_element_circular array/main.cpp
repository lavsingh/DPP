#include<iostream>

using namespace std;

int function(int A[], int startindex, int endindex){
	int includedPrev = A[startindex];
	int excludedPrev = 0;
	
	for (int i = startindex+1; i <= endindex; i++)
	{	int temp;
		if(includedPrev > excludedPrev)	
			temp = includedPrev;
		else 
			temp = excludedPrev;
		
		includedPrev = excludedPrev + A[i];
		excludedPrev = temp;
	}
	return ((includedPrev > excludedPrev)? includedPrev : excludedPrev);
}

int max(int A[], int n)
{
	int firstSum = function(A,0, n-2);
	int secondSum = function(A,1, n-1);
	return firstSum>secondSum?firstSum:secondSum;
}

int main()
{
	int n;
	cin>>n;
	int A[1000];
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<max(A, n);
	cin>>n;
	return 0;
}