#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

vector <string> input_parser(string s){
	int i=0,start=0;
	vector<string> list;
	while(i<s.length()){
		if(s[i] == ','){
			list.push_back(s.substr(start, i-start));
			start = i + 1;
		}
		i++;
	}
	list.push_back(s.substr(start, i-start));
	return list;
}



vector<vector<string>> parse_condition(string s){
	int i=0 ,start = 0;
	vector<vector<string>> v;
	vector<string> conds;
	int cond = 0;

	bool hasbracket = false;
	string operatorStr = "";
	while(i<s.length()){
		if(s[i]=='('){
			i++;
			start = i;
			hasbracket = true;
			while(s[i] != ')'){
				i++;
			}
			conds.push_back(s.substr(start,i-start));
			start = i+4;
			cond++;
		}
		operatorStr = operatorStr + s[i];
		i++;
	}

	if(hasbracket == false)
		conds.push_back(s);
	int len=0;
	for(int i=0;i<conds.size();i++){

			string k = conds[i];
			int and = k.find('and');
			vector<string> temp;
			if(and !=-1){
				temp.push_back(k.substr(0,and-3));
				temp.push_back(k.substr(and + 2,k.length() - and));
				v.push_back(temp);
			}
			else{
				
				temp.push_back(k);
				v.push_back(temp);
			}
	}
	
	return v;
	
}


bool contains(std::vector<string> const& a, std::vector<string> const& b) {
   set<string> s1;
   for(int i=0;i<a.size();i++)
	   s1.insert(a[i]);
   for(int i=0;i<b.size();i++)
	   if(s1.find(b[i]) == s1.end())
		   return false;
   return true;
}

void finalOptimize(vector<string> column_tofind, vector<vector<string>> conditions){
	for(int i=0;i<conditions.size();i++){
		for(int j=i+1; j<conditions.size();j++){
			if(contains(conditions[i],conditions[j]) || contains(conditions[j],conditions[i])){
				if(conditions[i].size() >  conditions[j].size())
					while(conditions[i].size()!=0)
						conditions[i].pop_back();
				else
					while(conditions[j].size()!=0)
						conditions[j].pop_back();
			}
		}
	}
	for(int i=0;i<conditions.size();i++){
		for(int j=0;j<conditions[i].size();j++){
			cout<<conditions[i].at(j)<<"and ";
		}
		cout<<endl;
	}

	return;

}

bool checkColumns(vector<string>column_list,vector<string> column_tofind){
	if(contains(column_list,column_tofind))
		return true;
	return false;
}
int main(){
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	vector<string> column_list = input_parser(s);
	string query;
	while(n>0){
		getline(cin,query);
		int whereStart = query.find("where");
		vector<string> column_tofind = input_parser(query.substr(0,whereStart-1));
		if(!checkColumns(column_list, column_tofind)){
			cout<<"invalid query"<<endl;
		}
		else{
			vector<vector<string>> conditions = parse_condition(query.substr(whereStart + 6, query.length()));
			finalOptimize(column_tofind, conditions);
		}
		n--;
	}
	

	return 0;
}