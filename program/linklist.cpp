#include <iostream>
using namespace std;

template <typename T>
class link_list{
	private:
		T* data;
		link_list* ptr;
		int size;
		link_list* This(){return this;}
	public:
		link_list(){
			ptr=NULL;
			data=NULL;
			size=0;
		}
		~link_list(){
			delete [] data;
		}
		int New(int i){
			size=i;
			data = new T [i];
			return 1;
		}
		void check_data(){
			for(int i=0;i!=size;i++)
				cout<<data[i]<<" ";
			cout<<endl;
		}
/////////////////////////////////////////////////
		void operator+(link_list& n){
			if		(this==&n)	return;
			if	(ptr==NULL)	ptr=n.This();
			else ptr->operator+(n);
		}
		T* operator[](int i){
			if	(i<0) return NULL;
			if	(i==0) return data;
        	else if (ptr==nullptr) return NULL;
			else	return ptr->operator[](i-1);
		}
		void operator/(link_list& n){
			if(this==&n)	return;
			if(ptr==NULL)	ptr=n.This();
			else{
				n.ptr=ptr;
				ptr=n.This();
			}
		}
		void operator-(){
			ptr=NULL;
		}
}; 
	/*
	link_list<data資料型態>	創建 link_list
	.New(data空間大小)		data 空間 
	.check_data() 			cout 輸出 
	a+c						a->b,c;	a->b->c
	a[2]					a->b->c; a[2]=*c
	a/c						a->b;  a->c->b
	a-						a->b->c; a,b->c
	*/
