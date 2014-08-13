#include<iostream>
#include<string>
#include<math.h>

using namespace std;

/*basically only two test cases possible
 1. start from min and move to min and continue
 2. start from min and move to 2nd min and switch back to min 

 all other patterns will cost more than the two mentioned above
*/

void function(int r, int g, int b, int cs, int cd, int n){
	string mincolor, min2color;
	int min = r<g ? (r<b? r:b) : (g<b?g:b);
	mincolor = (min==r)?"red": (min==g)? "green": "blue";

	int max = r>g ? (r>b?r:b) : (g>b?g:b);
	
	int min2 = 0;
	if(r<max && r>min)
		min2 = r;
	if(g<max && g>min)
		min2 = g;
	if(b<max && b>min)
		min2 = b;

	min2color = (min2==r)?"red": (min2==g)? "green": "blue";
	
	int t1 = min*n + cs*(n-1);
	int t2 = min*ceil((double)n/2) + min2*(n/2) + cd*(n-1);
	
	if(t1<t2){
		cout<<"total cost of painting : "<<t1<<endl;
		string output = "paint all the houses in color : ";
		output.append(mincolor);
		cout<<output<<endl;
	}
	else {
		cout<<"total cost of painting : "<<t2<<endl;
		string output = "Alternate between ";
		output.append(mincolor);
		output.append(" and ");
		output.append(min2color);
		output.append(", Staring with ");
		output.append(mincolor);
		cout<<output<<endl;
	}
	
}

int main(){
	// cs : cost of keeping same color 
	// cd : cost of moving to different color

	int cs , cd; 
	cin>>cs>>cd;
	
	int r,g,b;
	cin>>r>>g>>b;

	// number of houses
	int n;
	cin>>n; 
	
	function(r, g, b, cs, cd, n);

	int k;
	cin>>k;
	return 0;
}