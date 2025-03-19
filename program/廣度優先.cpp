#include <iostream>
#include <stack>
using namespace std;
char N[4][4]=
{{'A','B','C','D'},
{'E','F','G','H'},
{'I','J','K','L'},
{'M','N','O','P'}};
class p{
	public:
		int x,y;
		p(int a,int b){
			x=a;y=b;
		}
};
bool k[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
int main(){
	stack<p> S;
	p P(3,1);
	S.push(P);
	cout<<N[3][1]<<",";
	while(1){
		if(P.x>0&&k[P.x-1][P.y])		{k[P.x-1][P.y]=0;P.x-=1;S.push(P);cout<<N[P.x][P.y]<<",";}		
		else if(P.y>0&&k[P.x][P.y-1])	{k[P.x][P.y-1]=0;P.y-=1;S.push(P);cout<<N[P.x][P.y]<<",";}
		else if(P.y<3&&k[P.x][P.y+1])	{k[P.x][P.y+1]=0;P.y+=1;S.push(P);cout<<N[P.x][P.y]<<",";}
		else if(P.x<3&&k[P.x+1][P.y])	{k[P.x+1][P.y]=0;P.x+=1;S.push(P);cout<<N[P.x][P.y]<<",";}
		else{
			if(S.empty())break;
			P=S.top();
			S.pop();
		}
	}
} 
