#include<iostream>
#define COL 5
using namespace std;

void DFS(int M[][COL],bool visited[][COL],int i,int j){
	visited[i][j]=true;
	for(int row=i-1;row<i+2;row++)
		for(int col=j-1;col<j+2;col++)
		{
			if(row>=0 && col>=0 && row<COL && col<COL){
				if(visited[row][col]== false)
					DFS(M,visited,row,col);
			}
		}
}
int countIslands(int M[][COL]){
	bool visited[][COL]={false};
	int count = 0;

	for(int i=0;i<COL;i++){
		for(int j=0;j<COL;j++){
			if(!visited[i][j])
			{	DFS(M,visited,i,j);
				count++;
			}
		}
	}
	return count;
}
int main(){

	int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", countIslands(M));

	return 0;
}