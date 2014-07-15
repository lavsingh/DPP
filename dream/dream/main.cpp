#include<iostream>
#include<cstring>
#include<string>

using namespace std;
bool function(int A[5][5], string x, int c){
	if(c==x.length()-1)
		return 1;
	int pos = x[c] - 'A';
	int pos1 = x[c+1] - 'A';
	if (A[pos][pos1] > 0)
	{
		 
		A[pos][pos1]--;
		A[pos1][pos]--;
		
		int ret = (A[pos][pos1]+1)*function(A,x,c+1);
		A[pos][pos1]++;
		A[pos1][pos]++;
		if(ret == 0)
			return 0;
		return ret;
	}

	return 0;
}

int ways(int A[5][5], int start, int end){
	if(start == end)
		return 1;
	int way = 0;
	for(int i=0;i<=4;++i){
		if(A[start][i]>0){
			A[start][i]--;
			A[i][start]--;
			
			way += (A[start][i]+1)*ways(A,i,end);
			A[start][i]++;
			A[i][start]++;
		}
	}
	return way;
}

int main(){

	int A[5][5];
	memset(A,0,sizeof(A));
	A[0][1]=1;
	A[1][0]=1;
	A[1][2] = 3;
	A[2][1] = 3;
	A[2][3] = 3;
	A[3][2] = 3;
	A[3][4] = 1;
	A[4][3] = 1;
	A[1][3] = 2;
	A[3][1] = 2;

	string x;
	cin>>x;
	if(function(A, x, 0) == 0)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;
	cout<<ways(A,x[0]-'A',x[x.length()-1]-'A')<<endl;
	int k;
	cin>>k;

	return 0;
}