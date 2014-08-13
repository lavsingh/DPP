#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct e {
	int x;
	int y;
}edge;

typedef struct n { 
	int v;
	vector<int> edge;
}Graph;

string serialize(Graph G){
	string s;
	queue<int> q;
	vector<int> adj [G->v];

}

int main(){
	Graph *g = (Graph *)malloc(sizeof(Graph));


	return 0;
}