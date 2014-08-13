#include<iostream>
#include<string>

using namespace std;

#define INT_MAX 1000000
#define INF 100

void calculate(string s, int *A){
	int index = 0, i = 0;
	while(index !=-1){
		index = s.find(" ");
		
		if(index == -1)
			A[i++] = s.length();
		else
			A[i++] = index;
		s = s.substr(index+1);
	}
	return;
}


int print(string s, int *p, int n){
	int k;
	if(p[n] == 1)
		k = 1;
	else
		k = 1 + print(s ,p , p[n]-1);
	cout<<k<< " "<<p[n]<<" "<<n<<endl;
	return k;
}

void function(string s, int *A, int n, int M){
	int L[100][100];
	memset(L,0,100*100*sizeof(int));
	int ext[100][100];
	memset(ext,0,100*100*sizeof(int));
	for(int i=1;i<=n;i++){
		ext[i][i] = M - A[i-1];
		for(int j=i+1;j<=n;j++){
			ext[i][j] = ext[i][j-1] - 1 - A[j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ext[i][j] < 0 )
				L[i][j] = INT_MAX;
			else if(j==n && ext[i][j] >= 0)
				L[i][j] = 0;
			else
				L[i][j] = ext[i][j] * ext[i][j];
		}
	}

	int c[100];
	int p[100];
	for(int i=0;i<100;i++)
		c[i] = INT_MAX;
	c[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(c[j-1]!=INT_MAX && L[j][i] !=INT_MAX && (c[i]> c[j-1]+L[j][i])){
				c[i] = c[j-1] + L[j][i];
				p[i] = j;
			}
		}
	}
	print(s,p,n);
}

int main(){

	string s =	"aaa bb cc ddddd";
	int A[100];
	calculate(s,A);
	//solveWordWrap(A,4,6);
	function(s,A,4,6);
	return 0;
}