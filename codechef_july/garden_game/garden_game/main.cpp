#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
#define MOD 1000000007	

int gcd( int n1,  int n2){
	if(n2==0)
		return n1;	
	return gcd(n2,n1%n2);
}

int main(){

	int T,N;
	cin>>T;
	while(T>0){
		cin>>N;
		int A[100], count[100], num=0;
		bool visited[100];
		memset(visited,false,N);
		for(int i=0;i<N;i++){
			cin>>A[i];
			A[i] -= 1;
		}
		vector<int> v;
		for(int i=0;i<N;i++){
			int j=i;	
			int loop = 0;
			while(visited[j] == false){
				visited[j] = true;
				j = A[j];
				loop++;
			}
			
			if(loop>0){
				v.push_back(loop);
			}
		}
		int g = v.at(0);
		for(int i=1;i<v.size();i++){
			g = gcd(g,v.at(i));
		}
		long long int ans = v[0];
		for(int i=1;i<v.size();i++)
		{	
			ans = ans *(v[i]/g); 
			if(ans>=MOD)
				ans %= MOD;
		}
		cout<<ans<<endl;
		T--;
	}

	return 0;
}