#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
private:
	int edges;
	int nodes;
	vector< int > G[100];
	int indegree[100];
	queue<int> Q;

public:
	Graph(int e, int n){
		edges = e;
		nodes = n;
		for(int i=0;i<nodes;i++)
			indegree[i]=0;
		
	}
	void insert(int src, int dest){
		
		G[src].push_back(dest);
		indegree[dest]++;
	}

	void indegreeZero(){
		for(int i=0;i<nodes;i++)
			if(indegree[i]==0)
				Q.push(i);
	}
	
	void topological_sort(){
		indegreeZero();
		int count = 0;

		while(!Q.empty()){
			int p = Q.front();

			for(vector<int>::iterator it = G[p].begin(); it!=G[p].end();it++){
				indegree[*it]--;
				if(indegree[*it] == 0)
					Q.push(*it);
			}

			cout<<"popped node "<<p<<endl;
			Q.pop();

			count++;
		}
		if(count!=nodes)
			cout<<"it has a cycle"<<endl;
	}
};

int main(){
	int edges,nodes;
	cin>>edges>>nodes;
	Graph *g = new Graph(edges, nodes);
	while(edges>0){
		int src,dest;
		cin>>src>>dest;
		g->insert(src,dest);
		edges--;
	}
	g->topological_sort();
	cin>>edges;
	return 0;

}