#include <iostream>
#include <cstdlib>
using namespace std;
struct mush{
	struct mush *left,*right;
	int data;
};
struct mush* root;
struct mush** serch(int n,struct mush** r){
	if(!*r||(*r)->data==n)return r;
	else if(n>(*r)->data)serch(n,&((*r)->right));
	else serch(n,&((*r)->left));
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
void show(struct mush* r){
	if(r) {
		if(r->left||r->right)cout<<r->data<<"[";
		if(r->left)show(r->left);
		if(r->left&&r->right)cout<<",";
		if(r->right)show(r->right);
		if(r->left||r->right)cout<<"]";
	}
	else return ;
}
int main(){
	root=NULL;
	for(int i=0;i!=10;i++)add(i,&root);
	show(root);
}
