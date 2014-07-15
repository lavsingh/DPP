#include<iostream>

using namespace std;


	void findTriplet(int array_size, int* A) {
		int k = 0;
		long long int count = 0;
		for(int i=0;i<array_size;i++){
			long long int left = i+1;
			long long int right = array_size-1;
			while(left<right){
				long long int sum = A[left]+A[right]+A[i];
				if(sum == k){
					int kl = 1, kr = 1 ;
					while(A[left]==A[left+1]){
						kl++;
						left++;
					}
					while(A[right]==A[right-1]){
						kr++;
						right--;
					}
					count += kl*kr ;
					left++;
					right--;
				}
				else if(sum<k)
					left++;
				else if(sum>k)
					right--;
			}
		}
		printf("%lld",count);
	}

int main(){
	int n;
	int A[9] = { -9,-7,-3,-1,0,1,2,3,4};
	findTriplet(9, A);
	int k;
	cin>>k;	
	return 0;
}