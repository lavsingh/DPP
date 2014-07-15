#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;
typedef struct n {
	int index;
	int distance;
}node;

void updateAll(vector<int> indexes, int dist, queue<node> &Q, int B[]){
	for(int i = 0 ;i<indexes.size(); i++){
		if(B[indexes.at(i)] != -1)
			continue;
		B[indexes.at(i)] = dist;
		node t;
		t.index = indexes.at(i);
		t.distance = dist;
		Q.push(t);
	}
	return;
}


int function(queue<node> Q, vector<vector<int> > positions, int A[], int len){
	bool done[10];
	memset(done, false, 10*sizeof(bool));
	int B[len];
	memset(B,-1, len*sizeof(int));
	B[len - 1] = 0;
	while(!Q.empty()){
		node s = Q.front();
		if(done[A[s.index]] == false){
			updateAll(positions[A[s.index]], s.distance + 1, Q, B);
			done[A[s.index]] = true;
		}
		if(s.index-1 >= 0 && B[s.index -1] == -1){
			B[s.index - 1] = s.distance + 1;
			node t;
			t.index = s.index -1;
			t.distance = s.distance + 1;
			Q.push(t);
		}
		if(s.index + 1 < len && B[s.index + 1] == -1){
			B[s.index + 1] = s.distance + 1;
			node t;
			t.index = s.index + 1;
			t.distance = s.distance + 1;
			Q.push(t);
		}
		if(B[0]!=-1)
			return B[0];
		Q.pop();
	}
}

int main(){
	string s;
	cin>>s;

	int i=0;
	queue<node> Q;
	vector<vector<int> > positions(10);
	int A[s.length()];
	while(i < s.length()){
		A[i] = (int)s[i] - 48;
		positions[A[i]].push_back(i);
		i++;
	}

	node n;
	n.distance = 0;
	n.index = s.length() - 1;
	Q.push(n);
	cout<<function(Q,positions, A, s.length())<<endl;
	int k;
	cin>>k;
	return 0;
}