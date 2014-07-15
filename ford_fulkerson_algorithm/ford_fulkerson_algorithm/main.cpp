#include<iostream>

using namespace std;

class Graph {
private:
	int nodes;
	int A[100][100];
public:
	void makeEdge(int src,int dest){
		A[src][dest] = 1;
		return;
	}

	bool bfs(){

	}

};

int main(){

	return 0;
}