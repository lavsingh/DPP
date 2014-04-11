#include<iostream>

using namespace std;
typedef struct Edge {
	int src,dest,weight;
}edge;

typedef struct Graph{
	int V,E;
	struct Edge* edge;
}graph;

graph *createGraph(int v,int e){
	graph *g = (graph *)malloc(sizeof(graph));
	g->E = e;
	g->V = v;
	g->edge = (edge *)malloc(sizeof(edge) *e);
	return g;
}

void printgraph(graph *g){
	for(int i=0;i<g->E;i++)
		cout<<g->edge[i].src<<" "<<g->edge[i].dest<<" "<<g->edge[i].weight;
	cout<<endl;
}

void sortGraph(graph *g){
	for(int i=0;i<g->E-1;i++){
		for(int j=0;j<i;j++){
			if(g->edge[j].weight > g->edge[j+1].weight){
				int temp_src = g->edge[j].src;
				g->edge[j].src = g->edge[j+1].src;
				g->edge[j+1].src = temp_src;
				int temp_dest = g->edge[j].dest;
				g->edge[j].dest = g->edge[j+1].dest;
				g->edge[j+1].dest = temp_dest;
				int temp_weight = g->edge[j].weight;
				g->edge[j].weight = g->edge[j+1].weight;
				g->edge[j+1].weight = temp_weight;
			}
		}
	}
}

int myComp(const void *a,const void *b){
	edge *e1 = (edge *)a;
	edge *e2 = (edge *)b;
	return e1->weight>e2->weight?e1->weight:e2->weight;
}

typedef struct s {
	int rank;
	int root;
}subsets;

int find(subsets *s, int node){
	
	if(s[node].root != node )
		s[node].root = find(s,node);
	return s[node].root;
}

void Union(subsets *sub,int x,int y){

	if(sub[x].rank< sub[y].rank)
		sub[x].root = sub[y].root;
	if(sub[x].rank > sub[y].rank)
		sub[y].root = sub[x].root;
	if(sub[x].rank == sub[y].rank){
		sub[x].root = sub[y].root;
		sub[y].rank++;
	}

}
graph *kruskals(graph *g){

	qsort(g->edge,g->E,sizeof(edge),myComp);
	graph *minGraph = (graph *)malloc(sizeof(graph));
	minGraph->edge = (edge *) malloc(sizeof(edge)*g->V-1);
	subsets *sub = (subsets *)malloc(sizeof(subsets) * g->V);
	for(int i=0; i < g->E; i++){
		sub[i].rank = 0;
		sub[i].root = i;
	}

	int i=0,j=0;
	while(j<g->V-1){
		
		edge EDGE = g->edge[i++];
		int x = find(sub,i);
		int y = find(sub,j);
		if(x!=y){
			minGraph->edge[j++] = EDGE;
			Union(sub,x,y);
		}
	}

	return minGraph;

}
int main(){
	int v =4,e=5;
	graph *g = createGraph(v,e);
	 // add edge 0-1
    g->edge[0].src = 0;
    g->edge[0].dest = 1;
    g->edge[0].weight = 10;
 
    // add edge 0-2
    g->edge[1].src = 0;
    g->edge[1].dest = 2;
    g->edge[1].weight = 6;
 
    // add edge 0-3
    g->edge[2].src = 0;
    g->edge[2].dest = 3;
    g->edge[2].weight = 5;
 
    // add edge 1-3
    g->edge[3].src = 1;
    g->edge[3].dest = 3;
    g->edge[3].weight = 15;
 
    // add edge 2-3
    g->edge[4].src = 2;
    g->edge[4].dest = 3;
    g->edge[4].weight = 4;

	printgraph(g);

	graph *minGraph = kruskals(g);
	return 0;
}