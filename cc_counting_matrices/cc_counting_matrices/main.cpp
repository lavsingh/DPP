#include<iostream>
#include<math.h>
using namespace std;
long long int count_matrices(int n){
	long long int total= 0;
	for(int i=1;i<=n/2;i++)
	{	long long int count =0;
		int product = i*(n-i);
		for(int j=1;j<sqrt(product*1.0);j++){
			int nums = (product-1)/j;
			int count_nums = nums -j + 1;
			int r = 2*count_nums - 1 ;
			count += r;
		}
		if(i != n-i)
			count*=2;

		total += count;
	}
	return total;
}
int main(){
	int t;
	cin>>t;
	while(t>0){
		int n;
		cin>>n;
		cout<<count_matrices(n)<<endl;
		t--;
	}
	return 0;
}