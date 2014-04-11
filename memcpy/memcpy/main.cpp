#include<iostream>

using namespace std;

void *own_memcpy(void *src, void *dest, int size_num){
	char *src_c = (char *)src;
	
	//dest = malloc(sizeof(char)*size_num);
	char *dest_c = (char *)dest;
	if(src<dest)
	{
		for(int i=0;i<size_num;i++)
			dest_c[size_num-i]=  src_c[size_num-i];
	}
	else
	{
		for(int i=0;i<size_num;i++)
			dest_c[i]=  src_c[i];
	}
	return dest;
}
int main(){
	char *src="lavsingh";
	char *dest = src+2;
	own_memcpy(src,dest,3);
	cout<<src<<"   "<<dest<<endl;
	cin>>src;
	return 0;
}