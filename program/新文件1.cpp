#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
struct node{
	node *left,*right;
	int data; 
};
struct node *root=nullptr;
struct node* create(int d){
	struct node* n = new node;
	n->data=d;
	n->left=nullptr;n->right=nullptr;
	return n;
}
void add_r(struct node *&r,int i){
	if(!r){
	r=create(i);
	return;
	} 
	else if(r->data==i)return;
	else if(r->data>i){
		if(r->left)  add_r(r->left,i);
		else  r->left=create(i);
	}
	else{
		if(r->right) add_r(r->right,i);
		else  r->right=create(i);
	}
}
void add(struct node *&r,int i){
	struct node *x=r;
	while(x){
		if(x->data==i)return;
		else if(x->data>i){
			if(x->left)  x=x->left;
			else  {
				x->left=create(i);
				return;
			}
		}
		else{
			if(x->right) x=x->right;
			else  {
				x->right=create(i);
				return;
			}
		}
	}
	r=create(i);
	return;
}
bool search_r(struct node *r,int i){
	return r&&(r->data==i||((r->data>i) ? search_r(r->left,i) : search_r(r->right,i)));
}
bool search(struct node *r,int i){
	while(r){
		if(r->data==i)return 1;
		r=(r->data>i) ? r->left : r->right;
	}
	return 0;
}
void randAdd(struct node *&r,int L,int c){
	for(;c!=0;c--)add(r,rand()%L);
}
void randAdd_r(struct node *&r,int L,int c){
	for(;c!=0;c--)add_r(r,rand()%L);
}
string Pre_r(struct node *r){
	if(!r)return "";
	string n="";
	n+=to_string(r->data)+" ";
	if(r->left)n+=Pre_r(r->left);
	if(r->right)n+=Pre_r(r->right);
	return n;
}
string In_r(struct node *r){
	if(!r)return "";
	string n="";
	if(r->left)n+=In_r(r->left);
	n+=to_string(r->data)+" ";
	if(r->right)n+=In_r(r->right);
	return n;
}
string Pos_r(struct node *r){
	if(!r)return "";
	string n="";
	if(r->left)n+=Pos_r(r->left);
	if(r->right)n+=Pos_r(r->right);
	n+=to_string(r->data)+" ";
	return n;
}
string Pre(struct node *r){
	if(!r)return "";
	stack<pair<int,node*>> s;
	string n="";
	s.push(make_pair(0,r));
	while(!s.empty()){
		pair<int,node*> k=s.top();s.pop();
		if(k.first==0){
			n+=to_string(k.second->data)+" ";
			s.push(make_pair(1,k.second));
			if(k.second->left)s.push(make_pair(0,k.second->left));
		}
		else if(k.first==1){
			if(k.second->right)s.push(make_pair(0,k.second->right));
		}
	}
	return n;
}
string In(struct node *r){
	if(!r)return "";
	stack<pair<int,node*>> s;
	string n="";
	s.push(make_pair(0,r));
	while(!s.empty()){
		pair<int,node*> k=s.top();s.pop();
		if(k.first==0){
			s.push(make_pair(1,k.second));
			if(k.second->left)s.push(make_pair(0,k.second->left));
		}
		else if(k.first==1){
			n+=to_string(k.second->data)+" ";
			if(k.second->right)s.push(make_pair(0,k.second->right));
		}
	}
	return n;
}
string Pos(struct node *r){
	if(!r)return "";
	stack<pair<int,node*>> s;
	string n="";
	s.push(make_pair(0,r));
	while(!s.empty()){
		pair<int,node*> k=s.top();s.pop();
		if(k.first==0){
			s.push(make_pair(1,k.second));
			if(k.second->left)s.push(make_pair(0,k.second->left));
		}
		else if(k.first==1){
			s.push(make_pair(2,k.second));
			if(k.second->right)s.push(make_pair(0,k.second->right));
		}
		else if(k.first==2){
			n+=to_string(k.second->data)+" ";
		}
	}
	return n;
} 
string BFS(struct node *r){
	string n="";
	queue<node*> q;
	q.push(r);
	while(!q.empty()){
		struct node* c=q.front();q.pop();
		n+=to_string(c->data)+" ";
		if(c->left)q.push(c->left);
		if(c->right)q.push(c->right);
	}
	return n;
} 
void del_r(struct node *&k,int i){
	if(!k)return;
	if(k->data==i){
		struct node *n;
		if(k->left&&k->right){
			n=k->left;
			while(n->right){
				n=n->right;
			}
			k->data=n->data;
			del_r(k->left,n->data);
		}
		else if(k->left){
			n=k;
			k=k->left; 
			delete n;
		}
		else if(k->right){
			n=k;
			k=k->right; 
			delete n;
		}
		else{
			delete k;
			k=nullptr;
		}
	}
	else if(k->data>i){
		del_r(k->left,i);
	}
	else{
		del_r(k->right,i);
	}
}
void del(struct node *&k,int i){
	if(!k)return;
	if(k->data==i){
		struct node *n=k;
		if(k->left&&k->right){
			n=k->left;
			struct node *m=k;
			while(n->right){
				m=n;
				n=n->right;
			}
			k->data=n->data;
			(m==k) ? m->left=n->left:m->right=n->left;		
		}
		else{
			k=(k->left) ?  k->left : k->right;	
		}
		delete n;
		return;
	}
	struct node *n=k,*m=nullptr;
	while(n->data!=i){
		m=n;
		if(n->data>i)n=n->left;
		else n=n->right;
		if(!n) return;
	}
	if(n->left&&n->right){
		struct node *x=n;m=n;n=n->left;
		while(n->right){
			x=n;
			n=n->right;
		}
		m->data=n->data;
		(x==m) ? x->left=n->left : x->right=n->left;
	}
	else{
		struct node *c = (n->left) ? n->left : n->right;
		(m->left==n) ? m->left=c : m->right=c;	
	}
	delete n;
}

int main(){
    srand(time(NULL));

    add(root, 50);
    add(root, 30);
    add(root, 70);
    add(root, 20);
    add(root, 40);
    add(root, 60);
    add(root, 80);
    
    cout << "中序遍歷: " << In(root) << endl;
    cout << "前序遍歷: " << Pre(root) << endl;
    cout << "後序遍歷: " << Pos(root) << endl;
    cout << "廣度優先遍歷: " << BFS(root) << endl;
    
    cout << "搜尋 40: " << (search(root, 40) ? "找到" : "未找到") << endl;
    cout << "搜尋 90: " << (search(root, 90) ? "找到" : "未找到") << endl;

    cout << "刪除 30" << endl;
    del(root, 30);
    cout << "刪除 30 後的中序遍歷: " << BFS(root) << endl;

    cout << "刪除 50 (根節點)" << endl;
    del(root, 50);
    cout << "刪除 50 後的中序遍歷: " << BFS(root) << endl;
    
    return 0;
}
