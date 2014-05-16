#include<iostream>
#include<vector>
#include<string>

using namespace std;

class listNode {

private:
	int data;	
	vector<listNode*> list;
public:
	listNode(int n){
		data = n;
	}

	void insertChild(listNode *k){
		list.push_back(k);
		return;
	}
	void serialize(string *k){
		char buffer [5];	
		k->append(itoa(data,buffer,10));
		k->append(" ");
		for(int i=0;i<list.size();i++)
			list[i]->serialize(k);
		k->append("#");
		return;
	}
};

int main(){
	listNode *root = new listNode(10);
	listNode *child1 = new listNode(3);
	listNode *child2 = new listNode(5);
	listNode *child3 = new listNode(7);
	listNode *child4 = new listNode(9);

	root->insertChild(child1);
	root->insertChild(child2);
	root->insertChild(child3);
	root->insertChild(child4);
	listNode *gc1 = new listNode(20);
	listNode *gc2 = new listNode(21);
	listNode *gc3 = new listNode(22);
	listNode *gc4 = new listNode(23);
	listNode *gc5 = new listNode(24);
	listNode *gc6 = new listNode(25);
	listNode *gc7 = new listNode(26);
	listNode *gc8 = new listNode(27);
	listNode *gc9 = new listNode(28);
	listNode *gc10 = new listNode(29);
	listNode *gc11 = new listNode(40);

	gc1->insertChild(new listNode(5));
	gc2->insertChild(new listNode(15));
	gc3->insertChild(new listNode(25));
	gc4->insertChild(new listNode(35));
	gc5->insertChild(new listNode(45));
	gc6->insertChild(new listNode(45));
	gc7->insertChild(new listNode(35));
	gc7->insertChild(new listNode(35));
	gc7->insertChild(new listNode(35));
	gc8->insertChild(new listNode(25));
	gc9->insertChild(new listNode(15));
	gc10->insertChild(new listNode(5));
	
	child1->insertChild(gc1);
	child1->insertChild(gc2);
	child1->insertChild(gc3);
	child2->insertChild(gc4);
	child2->insertChild(gc5);
	child3->insertChild(gc6);
	child3->insertChild(gc7);
	child3->insertChild(gc8);
	child4->insertChild(gc9);
	child4->insertChild(gc10);
	child4->insertChild(gc11);

	
	child4->insertChild(new listNode(4));
	child3->insertChild(new listNode(9));
	child2->insertChild(new listNode(43));

	string k = "";
	root->serialize(&k);
	cout<<k<<endl;
	int r;
	cin>>r;
	return 0;
}