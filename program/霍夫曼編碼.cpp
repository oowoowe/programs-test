#include <iostream>
#include <set>
using namespace std;
class mash {
public:
	mash* left, * right;
	int ascii, weight;
	string str;
	mash(mash* L, mash* R) {
		left = L; right = R;
		ascii = L->ascii; 
		weight = L->weight + R->weight;
		str=L->str+R->str;
	}
	mash(int a, int w,string n) {
		left = NULL; right = NULL;
		ascii = a; weight = w;
		str=n;
	}
	mash() {
		left = NULL; right = NULL;
		ascii = NULL; weight = NULL;
		str="";
	}
	void set(int W, int A, mash* L = NULL, mash* R = NULL) {
		left = L; right = R;
		ascii = A; weight = W;
	}
	void operator+(mash N) {
		left = N.left; right = N.right;
		weight = N.weight; ascii = N.ascii;
	}
	bool operator==(mash N) {
		return left == N.left && right == N.right && weight == N.weight && ascii == N.ascii;
	}
	void operator=(const mash &N) {
		left=N.left;
		right=N.right;
		weight=N.weight;
		ascii=N.ascii;
		str=N.str;
	}
	friend std::ostream& operator<<(std::ostream& out, const mash& m);

	bool operator<(const mash& m)const {
		if (weight == m.weight)return ascii < m.ascii;
		else return weight < m.weight;
	}
};
std::ostream& operator<<(std::ostream& out, const mash& m) {
	out << "(" << m.ascii << "," << m.weight <<","<<m.str<< ")";
	return out;
}
string serch(const mash &n,char target,string ans=""){
	if(n.str==string(1,target))return ans;
	else if(n.left&&n.left->str.find(target) != string::npos) return serch(*n.left,target,ans+"0");
	else if(n.right&&n.right->str.find(target) != string::npos) return serch(*n.right,target,ans+"1");
	else return "error";
}


int main() {
	cout<<"type some words";
	int input[128]={};
	string in; cin >> in;
	for (char n : in) {
		input[(int)n]++;
	}
	//
	set<mash> S;
	for (int i = 0; i != 128; i++) {
		if (input[i])S.insert(mash(i, input[i],string(1,(char)i)));
	}
	for (set<mash>::iterator x = S.begin(); x != S.end(); x++) {
		cout << *x << " ";
	}
	cout<<endl;
	//
	mash *a,*b;
	while(S.size()!=1){
		a=new mash();b=new mash();
		*a=*(S.begin());
		*b=*(++S.begin());
		auto it = S.begin();advance(it,2);
		S.erase(S.begin(),it);
		S.insert(mash(a,b));
	}
	//
	cout << "Huffman Tree Root: " << *S.begin() << endl;
	for (char n : in) {
		cout<<serch(*S.begin(),n)<<" ";
	}

}
