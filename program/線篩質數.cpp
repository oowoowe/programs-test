#include <iostream>
#include <set>
using namespace std;
int main(){
	int n;
	bool *N;
	set<int> S;
	cin>>n;
	N=new bool [n+1];
	for(int i=0;i!=n+1;i++)	N[i]=1;
	N[1]=0;
	
	for(int i=2;i!=n+1;i++){
		if(N[i]){
			S.insert(i);
			for(set<int>::iterator it=S.begin();it!=S.end();it++){
				if(*it*i<=n)N[*it*i]=0;
			}
		}
		else{
			for(set<int>::iterator it=S.begin();it!=S.end();it++){
				if(*it*i<=n)N[*it*i]=0;
				if(i%(*it)==0)break;
			}	
		}
	}
	
	for(set<int>::iterator it=S.begin();it!=S.end();it++)
			cout<<*it<<" ";
} 
