#include<iostream>

using namespace std;

bool interleaved(string a,string b,string c){

	bool A[100][100]={false};
	A[0][0]=true;
	int topStringLength = b.length();
	int leftStringLength = a.length();
	for(int k=1;k<c.length()+1;k++){
		int i = k>b.length()?k-topStringLength:0;
		int j = k>b.length()?topStringLength:k;
		while(i<=leftStringLength && j>=0){
			if(j>0 && b[j-1] == c[k-1] && A[i][j-1] == true)
				A[i][j]= true;
			if(i>0 && a[i-1] == c[k-1] && A[i-1][j] == true)
				A[i][j]= true;
				i++;j--;
		}
	}
	return A[leftStringLength][topStringLength];
}

int main(){
	if(interleaved("abcd","efgh","efghabcd"))
		cout<<"interleaved"<<endl;
	else 
		cout<<"not interleaved"<<endl;
	int k;
	cin>>k;

	return 0;

}