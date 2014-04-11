#include<iostream>

using namespace std;

int ugly_numbers(int n){
	int A[100];
	A[0]=1;
	int counter2=0, counter3=0, counter5=0;
	for(int i=1;i<n+1;i++){
		if(A[counter2]*2 < A[counter3]*3){
			if(A[counter2]*2 < A[counter5]*5)
			{
				A[i]=A[counter2]*2;
				counter2++;
			}
			else if(A[counter2]*2 > A[counter5]*5){
				A[i]=A[counter5]*5;
				counter5++;
			}
			else {
				A[i]=A[counter5]*5;
				counter5++;counter2++;
			}
		}
		else if (A[counter2]*2 > A[counter3]*3){
			if(A[counter3]*3 < A[counter5]*5)
			{
				A[i]=A[counter3]*3;
				counter3++;
			}
			else if(A[counter3]*3 > A[counter5]*5){
				A[i]=A[counter5]*5;
				counter5++;
			}
			else {
				A[i]=A[counter5]*5;
				counter5++;counter3++;
			}
		}
		else {
			if(A[counter5]*5 < A[counter2]*2){
				A[i] = A[counter5]*5;
				counter5++;
			}
			else {
				if(A[counter2]*2 == A[counter5]*5)
					counter5++;
				A[i] = A[counter2]*2;
				counter2++;counter3++;
			}
		}
	}
	for(int i=0;i<n+1;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return A[n];
}
int main(){
	ugly_numbers(5);
	ugly_numbers(10);
	ugly_numbers(15);
	ugly_numbers(18);
	int k;
	cin>>k;
	return 0;
}