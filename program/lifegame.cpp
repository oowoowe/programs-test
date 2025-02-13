#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
using namespace std;
void Show_World(bool** N,int size){
	for(int i=0;i!=size;i++){
		for(int k=0;k!=size;k++){
			if(N[i][k]||i==0||i==size-1||k==0||k==size-1)cout<<"¢i¢i";
			else cout<<"  ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
void Next_World(bool** &N,bool** &M,int size){
	for(int i=1;i!=size-1;i++){
		for(int k=1;k!=size-1;k++){
			M[i][k]=0;
			int C=0;
			C=C+N[i+1][k]+N[i-1][k]+N[i][k+1]+N[i][k-1]+N[i+1][k+1]+N[i+1][k-1]+N[i-1][k+1]+N[i-1][k-1];
			M[i][k]=(N[i][k]&&(C==2||C==3))||(C==3);
		}
	}
}
int pulsar[13][13] = {
    {0,0,1,1,1,0,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {0,0,1,1,1,0,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1,1,0,0},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,1,1,1,0,0}
};


int main(){
	srand( time(NULL) );
	const int WORLD_SIZE=47;
	bool swich=0;
	bool **World_A,**World_B;
	World_A=new bool* [WORLD_SIZE];
	World_B=new bool* [WORLD_SIZE];
	for(int i=0;i!=WORLD_SIZE;i++ ){
		World_A[i]=new bool [WORLD_SIZE];
		World_B[i]=new bool [WORLD_SIZE];
	}
	for(int i=0;i!=WORLD_SIZE;i++ ){
		for(int k=0;k!=WORLD_SIZE;k++){
			World_A[i][k]=0;
			World_B[i][k]=0;
		}
	}
	for(int i=0;i!=13;i++){
		for(int k=0;k!=13;k++){
			if(pulsar[i][k])World_A[i+15][k+15]=1;
		}
	}
	Show_World(World_A,WORLD_SIZE);
	while(1){
		
		Next_World(World_A,World_B,WORLD_SIZE);
		Show_World(World_B,WORLD_SIZE);
		Sleep(200);
		Next_World(World_B,World_A,WORLD_SIZE);
		Show_World(World_A,WORLD_SIZE);
		Sleep(200);
	}
	for (int i=0;i<WORLD_SIZE;i++) {
        delete[] World_A[i];
        delete[] World_B[i];
    }
    delete[] World_A;
    delete[] World_B;
	
}
