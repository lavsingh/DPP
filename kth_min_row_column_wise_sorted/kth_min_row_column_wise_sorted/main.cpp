#include<iostream>

using namespace std;

typedef struct n{
	int num;
	int col;
}heapElement;


typedef struct h{
	heapElement *A;
	int count;
	int length;
}heap;


heap *createHeap(int n){
	heap *H = (heap *)malloc(sizeof(heap));
	H->A = (heapElement *)malloc(sizeof(heapElement)*(n+1));
	H->length = n;
	H->count = 0;
	H->A[0].num = INT_MIN;
	return H;
}

void heapify(heap *H){
	int val = H->count;
	while(H->A[val].num < H->A[val/2].num){
		heapElement x = H->A[val];
		H->A[val] = H->A[val/2];
		H->A[val/2] = x;
		val/=2;
	}
}

void insert(heap *H, int num, int col){
	H->count++;
	heapElement *el = (heapElement *)malloc(sizeof(heapElement));
	el->col = col;
	el->num = num;
	H->A[H->count] = *el;
	heapify(H);
}

int main(){
	int n;
	cin>>n;
	heap *H = createHeap(n);
	


	return 0;
}