#include <iostream>
#include <set>
using namespace std;
class mash{
	public:
		mash *left,*right;
		int ascii,weight;
		mash(mash* L,mash* R){
			left=L;right=R;
			ascii=(L->ascii>R->ascii) ? R->ascii : L->ascii;
			weight=L->weight+R->weight;
		}
		mash(){
			left=NULL;right=NULL;
			ascii=-1;weight=-1;
		}
		mash(int a,int w){
			left=NULL;right=NULL;
			ascii=a;weight=w;
		}
		void set(int W,int A,mash* L=NULL,mash* R=NULL){
			left=L;right=R;
			ascii=A;weight=W;
		}
		void operator+(mash N){
			left=N.left;right=N.right;
			weight=N.weight;ascii=N.ascii;
		}
		bool operator==(mash N){
			return left==N.left&&right==N.right&&weight==N.weight&&ascii==N.ascii;
		}
	static mash* root;
	friend std::ostream& operator<<(std::ostream &out, const mash &m) {
        out << "(" <<ascii<<","<<weight<< ")";
        return out;
	}
};

int input[128];mash Q[10000];
int main(){
	string in;cin>>in;int count=0;
	while(in[count]!='\0'){
		input[(int)in[count]]++;
		count++;
	}
/*	count=0;
	for(int i=0;i!=128;i++){
		//if(input[i])cout<<i<<" "<<input[i]<<endl;
		if(input[i]){
			Q[count].ascii=i;Q[count].weight=input[i];count++;
		}
	}
	for(int i=0;i!=10000;i++)if(Q[i].ascii!=-1)cout<<Q[i].ascii<<" "<<Q[i].weight<<endl; 

		mash fmash(10000,10000),smash(10000,10000);
		for(int i=0;i!=10000;i++){
			if(	Q[i].weight!=-1&&Q[i].ascii!=-1&&
				Q[i].weight<fmash.weight||Q[i].weight==fmash.weight&&Q[i].ascii<fmash.ascii){
				smash=fmash;fmash=Q[i];
			}
			if(	Q[i].weight!=-1&&Q[i].ascii!=-1&&
				Q[i].weight<smash.weight&&Q[i].ascii!=fmash.ascii
				||Q[i].weight==smash.weight&&Q[i].ascii<smash.ascii){
				smash=Q[i];
			}
		}
		
		for(int i=0;i!=10000;i++){
			if(Q[i]==fmash||Q[i]==smash)Q[i].set(-1,-1);
		}
		cout<<endl<<fmash.ascii<<" "<<smash.ascii;
		for(int i=0;i!=10000;i++)if(Q[i].ascii!=-1)cout<<Q[i].ascii<<" "<<Q[i].weight<<endl; 
		
*/
	set<mash> S;
	for(int i=0;i!=128;i++){
		if(input[i])S.insert(mash(i,input[i]));
	}
	for(set<mash>::iterator x=S.begin();x!=S.end();x++){
		cout<<*x<<" ";
	}

} 
