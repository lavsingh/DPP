#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

void count_occur1(int A[10], int start){
	int flag = 0;
	int power = log10((double)start);
	while(start !=0){
		if(start == 0 ) return;
		int a = log10((double)start);
		int ten_power = pow(10*1.0,a*1.0);
		int msb = start/ ten_power;
		int nextNum = start - msb*ten_power;
		int nonZeroCount = a*pow(10*1.0,a-1);
		for(int i=0;i<10;i++){
			if(msb>i)
				A[i]+=ten_power + msb*nonZeroCount;
			else if(msb==i)
				A[i]+=nextNum + msb*nonZeroCount + 1;
			else
				A[i]+=msb*nonZeroCount;
		}
		if(nextNum !=0){
			int nextNumPower = log10((double)nextNum);
			int extra = (nextNum + 1) * (a-nextNumPower-1);
			A[0]+=extra;
		}
		else
			A[0]+=a;
		start = nextNum;
	}
	A[0]-= ((pow(10*1.0,power+1)-1)/9);
	return;
}
void count_occur(int A[10], int start, int end){
	int count_start[10] = {0},count_end[10]={0};
	count_occur1(count_start,start);
	count_occur1(count_end,end);
	for(int i=0;i<10;i++)
		cout<<count_start[i]<< " ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<count_end[i]<< " ";
	
	for(int i=0;i<10;i++)
		A[i] = count_end[i]-count_start[i];
}
int main(){
	int A[10];
	clock_t start,end;
	start = clock();
	count_occur(A,100,105);
	end = clock();
	double cpu_time_used = ((double) (end - start));
	cout<<"   "<<endl<<cpu_time_used<<endl;
	for(int i=0;i<10;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	int k;
	cin>>k;
	return 0;
}