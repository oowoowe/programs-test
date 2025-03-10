#include <iostream>
#include <cstdlib>
struct mush{
	struct mush *left,*right;
	int data;
};
struct mush* root;
struct mush** serch(int n,struct mush* r){
	if(!r||r->data==n)return &r;
	else if(n>r->data)serch(n,r->right);
	else serch(n,r->left);
}
bool add(int n){
	struct mush **m=serch(n,root);
	if(*m)return 0;
	else{
		*m=(struct mush *)malloc(sizeof(struct mush));
		(*m)->left=NULL;(*m)->right=NULL;
		(*m)->data=n;
		return 1;
	}
}
int main(){
	
}
