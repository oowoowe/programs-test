#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct mush{
	struct mush *left,*right;
	int data;
};
struct mush* root;
struct mush** serch(int n,struct mush** r){
	if(!*r||(*r)->data==n)return r;
	if(n>(*r)->data)return serch(n,&((*r)->right));
	return serch(n,&((*r)->left));
}
	string re="root"; 
	void F(mush* r) {
	    if (!r) return;
	    re=re+"->"+to_string(r->data);
		F(r->left);
		F(r->right);
	}
	void M(mush* r) {
	    if (!r) return;
		M(r->left);
		re=re+"->"+to_string(r->data);
		M(r->right);
	}
	void B(mush* r) {
	    if (!r) return;
		B(r->left);
		B(r->right);
		re=re+"->"+to_string(r->data);
	}
bool add(int n,struct mush** r){
	struct mush **m=serch(n,r);
	if(*m)return 0;
	else{
		*m=(struct mush *)malloc(sizeof(struct mush));
		(*m)->left=NULL;(*m)->right=NULL;
		(*m)->data=n;
		return 1;
	}
}
string show(struct mush* r,void (*fun)(mush*)){
	re="root";
	fun(r);
	return re;
}
bool is(mush* r,int n) {
	if(!r)return 0;
	if(r->data==n)return 1;
	return (n>r->data) ? is(r->right,n) : is(r->left,n);
}
int main(){
	srand(time(NULL));
	root=NULL;
	for(int i=0;i!=10;i++)add(rand() % 100, &root);
	cout<<show(root,F)<<endl;
	cout<<show(root,M)<<endl;
	cout<<show(root,B)<<endl;

}
