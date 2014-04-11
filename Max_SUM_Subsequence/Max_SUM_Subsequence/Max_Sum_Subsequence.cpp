#include<iostream>
using namespace std;
void max_value_cont_seq(int num, int A[], int &start, int &end, int &sum)
{
	int cur_sum=0,cur_start=0,cur_end=0;
	for(int i=0;i<num; i++)
	{
		if(cur_sum + A[i] < 1){
			cur_sum = 0;
			cur_start = i+1;
		}
		else {
			cur_sum += A[i];
			cur_end = i;
		}
		       	
		if(cur_sum > sum)
		{
			sum = cur_sum;
			end = cur_end;
			start = cur_start;
		}
	}
	return;
}
int main(){
	int num;
	cin>> num;
	int A[100];
	for(int i=0;i<num;i++)
		cin>>A[i];
	int start=0, end=0, sum=0;
	max_value_cont_seq(num, A, start, end, sum);
	cout<< start << " " <<  end << " " << sum <<endl;	
	return 0;
}