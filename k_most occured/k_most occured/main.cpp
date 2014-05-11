#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

template<class T>
class node{
	public :
		T data;
		int occurance;
	
		node(int occu, T d){
			occurance = occu;
			data = d;
		}
};

template <class T>
class Heap {
	private: 
		int count;
		map<string,	int> m;
		node<T>* A[100];
	
	public:
	
		Heap(){
			node<T> *temp = new node<T>(INT_MAX, "");
			A[0] = temp;
			count=0;
			return;
		}

		void insert(T val){
			node<T> *temp = new node<T>(1, val);
			A[++count] =  temp;
			heapify(count);
		}

		void update(int val) {
			A[val]->occurance++;
			heapify(val);
		}

		void heapify(int pos){
			int i=pos;
			while(A[i/2]->occurance<A[i]->occurance){
				node<T>* tt = A[i];
				A[i] = A[i/2];
				A[i/2]= tt;
				m.insert(pair<T,int>(A[i]->data, i));
				i /= 2;
			}
			m.insert(pair<T,int>(A[i]->data, i));
			return;
		}

		template<class T>
		int contains(T data){
			if(m.find(data) !=m.end())
				return m.find(data)->second;
			return -1;
		}

		void print(){
			for(int i=1;i<count;i++)
				cout<<A[i]->data<<" "<<A[i]->occurance<<endl;
		}

		void deleteMax(int val){
			int i=0;
			while(i<val){
				int pos =1;
				cout<<A[pos]->data<<" "<<A[pos]->occurance<<endl;
				m.erase(A[pos]->data);
				A[1]=A[count];

				count--;
				while((2*pos <= count && A[pos]->occurance < A[2*pos]->occurance) || (2*pos+1 <= count && A[pos]->occurance < A[2*pos+1]->occurance)){
					if(2*pos+1 <=count && A[2*pos + 1]->occurance > A[2*pos]->occurance)
					{
						node<T> *tt = A[pos];
						A[pos] = A[2*pos+1];
						A[2*pos+1]=tt;
						m.insert(pair<T,int>(A[pos]->data, pos));
						m.insert(pair<T,int>(A[2*pos+1]->data, 2*pos+1));
						pos = 2*pos + 1;
					}
					else {
						node<T> *tt = A[pos];
						A[pos] = A[2*pos];
						A[2*pos]=tt;
						m.insert(pair<T,int>(A[pos]->data, pos));
						m.insert(pair<T,int>(A[2*pos]->data, 2*pos));
						pos = 2*pos;
					}
				}
				i++;
			}
			return;
		}
		
};

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<std::string> split(string s, char delim) {
    vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){
	
	Heap<string> h;
	string input;
	getline(cin, input);

	vector<string> x = split(input, ' ');
	for(int i=0;i<x.size();i++){
		int pos = h.contains(x[i]);
		if( pos == -1 )
			h.insert(x[i]);
		else
			h.update(pos);
	}
	h.print();
	h.deleteMax(3);
	int t;
	cin>>t;
	return 0;
}