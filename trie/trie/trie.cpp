#include<iostream>
#include<string>
using namespace std;
#define ALPHABET_SIZE 26

typedef struct a{
	int value;
	a* child[ALPHABET_SIZE];	
}node;

typedef struct b{
	int count;
	node *root;
}trie_root;

node* getNode(){
	node *newNode = NULL;
	newNode = (node *)malloc(sizeof(node));
	newNode->value = 0;
	for(int i=0;i<ALPHABET_SIZE; i++)
		newNode->child[i]=NULL;
	return newNode;
}

void insert(trie_root *trie, string key){
	trie->count++;
	node *crawl=trie->root;
	for(int i=0;i< key.length(); i++){
		int index = key[i]-97;
		if(crawl->child[index] == NULL){ 
			crawl->child[index] = getNode();
		}
		crawl = crawl->child[index];
	}
	crawl->value = trie->count;
	return;
}

int search(trie_root *trie, string key){
	node *crawl = trie->root;
	for(int i=0; i<key.length();i++){
		int index = key[i]-97;
		if( crawl->child[index] == NULL)
			return -1;
		crawl = crawl->child[index];
	}
	return (0!= crawl->value && crawl->value);
}

int main(){

	trie_root *trie= (trie_root *)malloc(sizeof(trie_root));
	trie->count = 0;
	trie->root = getNode();

	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

	for(int i = 0; i < 8; i++)
    {
        insert(trie, keys[i]);
    }
	char output[][32] = {"Not present in trie", "Present in trie"};
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(trie, "the")] );
    printf("%s --- %s\n", "these", output[search(trie, "these")] );
    printf("%s --- %s\n", "their", output[search(trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(trie, "thaw")] );
	int num;
	cin>>num;
	return 0;
}