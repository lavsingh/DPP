#include<iostream>
#include<string>

#define MIN_LIMIT 1
using namespace std;

bool compare(const void *a, const void *b){
	return *(const char *)a < *(const char *)b;
}

void mycpy(void *a, void *b, int n){
	*(char *)b = *(char *)a;
}

void mySwap(void *a, void *b, int size){
	char *temp = (char *)malloc(size*sizeof(char));
	mycpy(a, temp, size);
	mycpy(b, a, size);
	mycpy(temp, b, size);
	return;
}

void qsort(void *A, int n, int size, bool (*compare)(const void *, const void *)){
	if( n <= MIN_LIMIT ) return;
	int partition = 1;
	for(int i=0;i<n;i++){
		if(compare( (char *) A + i*size , A) == true ){
			mySwap((char *)A + i*size , (char *)A + partition*size, size);
			partition++;
		}
	}
	mySwap((char *)A  , (char *)A + (partition-1)*size, size);
	
	qsort(A,partition-1, size, compare);
	qsort((char *)A + size*(partition + 1),(int)n - partition-1, size, compare);
	return;
}

int main(){
	char A[6] = "lbarp";
	qsort(A,5,sizeof(char),compare);
	for(int i=0;i<5;i++)
		cout<<A[i]<<endl;
	return 0;
}