#include<iostream>

using namespace std;

typedef struct n {
	int data;
	n* next;
}node;

void print(node *root){
	if(root==NULL)
		cout<<"no data"<<endl;
	while(root!=NULL)
	{
		cout<<root->data<< " ";
		root = root->next;
	}
	cout<<endl;
}

node* insert(node *root, int data){
	node *temp = (node * )malloc(sizeof(node));
	temp->data = data;
	temp->next = root;
	//cout<<temp->data<<endl;
	print(temp);
	return temp;
}


node *partition_array(node* root, int x){
	
	node*temp = root;
	node *partition = root;
	//cout<<"in here"<<endl;
	while(root!=NULL){
		//print(temp);
		//cout<<"inside here"<<endl;
		if(root->data < x){
			int yy = root->data;
			root->data = partition->data;
			partition->data = yy;
			//cout<<"data: "<<yy<<" " << root->data<<endl;
			partition = partition->next;
		}
		root = root->next;
	}
	//print(temp);
	root=temp;
	return partition;
}

int main(){
	node* root = NULL;
	root = insert(root,1);
	//print(root);
	root = insert(root,5);
	root = insert(root,8);
	root = insert(root,0);
	root = insert(root,2);
	root = insert(root,110);
	root = insert(root,12);
	//print(root);
	node *partition = partition_array(root, 2);
	print(root);
	int num;
	cin>>num;
}
