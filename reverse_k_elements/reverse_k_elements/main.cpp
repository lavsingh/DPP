#include<iostream>

using namespace std;

typedef struct n {
	int data;
	struct n *next;
}node;

node *insert (int A[], int n){
	node *list = NULL;
	while(n!=0){
		node *temp = (node *)malloc(sizeof(node));
		temp->data = A[n-1];
		temp->next = list;
		list = temp;
		n--;
	}
	return list;
}
void print(node *test){
	while(test!=NULL){
		cout<<test->data<<" ";
		test= test->next;
	}
	cout<<endl;
}
node *nReverse(node *list, int n, node **nextList){
	if( list->next == NULL || n==1){
		*nextList = list->next;
		return list;
	}
	node *head = nReverse(list->next,n-1, nextList);
	node *temp = list->next;
	list->next = temp->next;
	temp->next = list;
	return head;
}
node *reverse(node *list, int n){
	node *head= NULL,*nextList=list, *tail=list,*prevTail;
	tail = list;
	while(nextList != NULL){
		prevTail = tail;
		tail = nextList;
		node *returnPointer = nReverse(nextList,n,&nextList);
		if(head == NULL)
			head = returnPointer;
		else {
			prevTail->next=returnPointer;
		}
	}
	return head;
}
int main(){
	int A[11]={1,2,3,4,5,6,7,8,9,10,11};
	node *test = insert(A,11);
	print(test);
	test = reverse(test,3);
	print(test);
	int k;
	cin>>k;
	return 0;
}