#include <iostream>
#include <stack>
#include <string>
using namespace std;

int OperatorLayerIn(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 4;
        case '#': return -1;
        default: return 0;
    }
}
int OperatorLayerOut(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case ')': return 0;
        case '#': return -1;
        default: return 0;
    }
}
bool isOperator(char n) {
    return n == '+' || n == '-' || n == '*' || n == '/' || n == '^' || n == '(' || n == ')';
}
string It(string n,bool h){
	stack<string> S1;
	stack<char> S2;
	S2.push('#');
	int a=0;
	while(n[a]!='\0'){
		if(n[a]==')'){
			while(S2.top()!='('){
				string m=S1.top();S1.pop();
				string n=S1.top();S1.pop();
				string o=string(1,S2.top());S2.pop();
				if(h)S1.push(o+n+m);
				else S1.push(n+m+o);
			}
			S2.pop();
		}
		else if(!isOperator(n[a])){
			S1.push(string(1,n[a]));
		}
		else{
			while(OperatorLayerIn(n[a])<OperatorLayerOut(S2.top())){
				string m=S1.top();S1.pop();
				string n=S1.top();S1.pop();
				string o=string(1,S2.top());S2.pop();
				if(h)S1.push(o+n+m);
				else S1.push(n+m+o);
			}
			S2.push(n[a]);
		}
		a++;
	}
	while(S2.top()!='#'){
		string m=S1.top();S1.pop();
		string n=S1.top();S1.pop();
		string o=string(1,S2.top());S2.pop();
		if(h)S1.push(o+n+m);
		else S1.push(n+m+o);
	}
	S2.pop();
	return S1.top();
}
string PTI(string n,bool u){
	stack <string>S;
	if(u){
		for(int i=n.length()-1;i!=-1;i--){
			if(isOperator(n[i])){
				string x=S.top();S.pop();
				string y=S.top();S.pop();
				if(x.length()>=3&&OperatorLayerOut(x[x.length()-2])<OperatorLayerOut(n[i]))x="("+x+")";
				if(y.length()>=3&&OperatorLayerOut(y[y.length()-2])<OperatorLayerOut(n[i]))y="("+y+")";
				S.push(x+string(1,n[i])+y);
			}
			else{
				S.push(string(1,n[i]));
			}
		}
	}
	else{
		for(int i=0;i!=n.length();i++){
			if(isOperator(n[i])){
				string x=S.top();S.pop();
				string y=S.top();S.pop();
				if(x.length()>=3&&OperatorLayerOut(x[x.length()-2])<OperatorLayerOut(n[i]))x="("+x+")";
				if(y.length()>=3&&OperatorLayerOut(y[y.length()-2])<OperatorLayerOut(n[i]))y="("+y+")";
				S.push(y+string(1,n[i])+x);
			}
			else{
				S.push(string(1,n[i]));
			}
		}
	}
	return S.top();
}
// ´ú¸Õ¨ç¦¡
int main() {
    string infix = "y+(a+b)*(c+m*d)^p";
    string prefix = It(infix,1);
    string posfix = It(infix,0);
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << prefix << endl;
    cout << "Posfix: " << posfix << endl;
    cout << "pre to Infix: " << PTI(prefix,1) << endl;
    cout << "pos to Infix: " << PTI(posfix,0) << endl;
    return 0;
}

