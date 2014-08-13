#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void getNumber(int n) {

    int temp = n;
    int a[4] ={2,3,5,7};
	int result[11]={0};
    for(int i=0;i<4;++i)
    {
        int val = temp%a[i];
        while(val == 0)
        {
			result[a[i]]++;
			temp = temp/a[i];
			val = temp%a[i];
        }
    }
	if(temp!=1){
		cout<<-1<<endl;
		return;
	}
	result[8] = result[2]/3;
	result[2] = result[2]%3;
	result[9] = result[3]/2;
	result[3] = result[3]%2;
	if(result[2]>0){
		if(result[2]%2 == 1 && result[3]%2 == 1)
		{	result[6]++;
			result[2]--;
			result[3]--;
		}
		else if(result[2]%2 == 0 && result[3]%2 == 1)
		{	result[6]++;
			result[2]--;
			result[3]--;
		}
		else if(result[2]%2 == 0 && result[3]%2 == 0)
		{	result[4]++;
			result[2]-=2;
		}
	}
	int x=0;
	for(int i=1;i<11;i++)
	{
		while(result[i]){
			x = x*10 + i;
			result[i]--;
		}
	}
	cout<<x<<endl;
}

int main (void){
	getNumber(1000);
	int k;
	cin>>k;
}