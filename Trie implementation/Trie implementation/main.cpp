#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;
#define charCount 256

typedef struct n{
	bool wordEnd;
	struct n **nextElement;
}node;

node *createTrieNode(){
	node *trie = (node *) malloc (sizeof(node));
	trie->wordEnd = false;
	trie->nextElement = (node **) malloc(sizeof(node *)*charCount);
	for( int i=0;i<charCount; i++)
		trie->nextElement[i] = NULL;
	return trie;
}

node *insert(node *trie, string s){
	if(trie == NULL){
		trie = createTrieNode();
	}
	node *temp = trie;
	for(int i=0;i<s.length();i++){
		if(trie->nextElement[s[i]] == NULL){
			trie->nextElement[s[i]] = createTrieNode();
			
		}
		trie = trie->nextElement[s[i]];

		if( i + 1 == s.length()){
			trie->wordEnd = true;
		}
	}
	return temp;
}

node *findEndPoint(node *trie, string s){
	node *temp = trie;
	for(int i=0;i<s.length();i++){
		if(temp->nextElement[s[i]]==NULL)
			return NULL;
		temp= temp->nextElement[s[i]];
	}
	return temp;
}

bool find(node *trie, string s){
	if(findEndPoint(trie,s)->wordEnd == true)
		return true;
	else
		return false;
}

void getPrefixes(node *trie,vector<string> &v, string s){
	if(trie->wordEnd == true)
	{	
		v.push_back(s);
	}

	for(int i=0;i<charCount;i++){
		if(trie->nextElement[i] !=NULL){
			getPrefixes(trie->nextElement[i], v, s + (char)(i+97));
		}
	}
	return;
}

vector<string> prefixSearch(node *trie, string s){
	vector<string> v;
	node *temp = findEndPoint(trie,s);
	if(temp == NULL)
		return;
	getPrefixes(temp,v, s);
	return v;
}

int main(){
	node *trie = NULL;
	int n;
	cin>>n;
	string s;
	while(n>0){
		cin>>s;
		trie = insert(trie,s);
		n--;
	}
	cin>>s;
	if(find(trie, s))
		cout<<"pattern found"<<endl;
	else
		cout<<"pattern not found"<<endl;
	string p;
	cin>>p;
	vector<string> v = prefixSearch(trie,p);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	cin>>n;
	return 0;
}