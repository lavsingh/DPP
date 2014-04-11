#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<string.h>
#include<cstdio>
#include<math.h>
#define gc getchar_unlocked
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int n,k,p;

	int left,right;
	set<int> A;
	while(t>0){
		scanf("%d",&n);
		scanf("%d",&k);
		scanf("%d",&p);
		int flag = 0;
		while(k>0){
			scanf("%d",&left);
			scanf("%d",&right);
			A.insert((left-1)%n);
			A.insert(right%n);

			k--;
		}
		while(p>0){
			scanf("%d",&left);
			scanf("%d",&right);
			if(A.find((left-1)%n) == A.end() || A.find(right%n)== A.end())
                     {      flag = 1;
                           
                     }

			p--;
		}
		if(flag == 0 )
			printf("Yes\n");
		else 
			printf("No\n");
		t--;
	}
	
	return 0;
}
