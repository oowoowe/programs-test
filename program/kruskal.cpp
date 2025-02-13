#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

bool** creatMaze(int side){
	const int n=(side+1)/2;
	const int side_count=(n-1)*n*2;
	int Tside [side_count][4];
	srand(time(NULL));
	bool** maze = new bool* [side];
	for(int i=0;i!=side;i++){
		maze[i] = new bool [side];
	}
	for(int i=0;i!=side;i++){
		for(int k=0;k!=side;k++){
			maze[i][k]=0;
			if(i==0||i==side-1||k==0||k==side-1)maze[i][k]=1;
			else if(!(i%2||k%2))maze[i][k]=1;
		}
	}
	for(int k=0;k!=side_count;k++){
		Tside[k][0]=0;
		Tside[k][3]=k;
	}
	for(int k=0;k!=n-1;k++){
		Tside[k][1]=k;
		Tside[k][2]=k+1;
	}
	for(int i=0;i!=n-1;i++){
		for(int k=0;k!=n;k++){
			Tside[n-1+k+i*(2*n-1)][1]=k+i*n;
			Tside[n-1+k+i*(2*n-1)][2]=k+(i+1)*n;
		}
		for(int k=0;k!=n-1;k++){
			Tside[n-1+k+i*(2*n-1)+n][1]=k+(i+1)*n;
			Tside[n-1+k+i*(2*n-1)+n][2]=k+1+(i+1)*n;
		}
	}
	int count=0;
	for(int i=0;i!=side;i++){
		for(int k=0;k!=side;k++){
			if((!(i%2))&&k%2||(!(k%2))&&i%2){
				if(i==0||i==side-1||k==0||k==side-1){
					Tside[count][0]=1;
					Tside[count][1]=0;
					Tside[count][2]=0;
				}
				else if(i==1||k==1)	Tside[count][1]=0;
				else if(i==side-2||k==side-2)Tside[count][2]=0;
				count++;
			}
		}
	}
	for(int i=0;i!=side_count;i++){
		int a[4],b=rand()%side_count;
		a[0]=Tside[b][0];
		a[1]=Tside[b][1];
		a[2]=Tside[b][2];
		a[3]=Tside[b][3];
		Tside[b][0]=Tside[i][0];
		Tside[b][1]=Tside[i][1];
		Tside[b][2]=Tside[i][2];
		Tside[b][3]=Tside[i][3];
		Tside[i][0]=a[0];
		Tside[i][1]=a[1];
		Tside[i][2]=a[2];
		Tside[i][3]=a[3];
	}
	for(int i=0;i!=side_count;i++){
		if(Tside[i][1]!=Tside[i][2]){
			Tside[i][0]=1;
			for(int k=0;k!=side_count;k++){
				if(k!=i){
					if(Tside[k][1]==Tside[i][2])Tside[k][1]=Tside[i][1];
					if(Tside[k][2]==Tside[i][2])Tside[k][2]=Tside[i][1];
				}
			}
			Tside[i][2]=Tside[i][1];
		}
	}
	for(int j=0;j!=side_count;j++){
		for(int i=0;i!=side_count-1;i++){
			for(int k=i+1;k!=side_count;k++){
				int a[4];
				if(Tside[i][3]>Tside[k][3]){
					a[0]=Tside[i][0];
					a[1]=Tside[i][1];
					a[2]=Tside[i][2];
					a[3]=Tside[i][3];
					Tside[i][0]=Tside[k][0];
					Tside[i][1]=Tside[k][1];
					Tside[i][2]=Tside[k][2];
					Tside[i][3]=Tside[k][3];
					Tside[k][0]=a[0];
					Tside[k][1]=a[1];
					Tside[k][2]=a[2];
					Tside[k][3]=a[3];
				}
			}
		}
	}
	
	count=0;
	for(int i=0;i!=side;i++){
		for(int k=0;k!=side;k++){
			if((!(i%2))&&k%2||(!(k%2))&&i%2){
				maze[i][k]=Tside[count][0];
				count++;
			}
		}
	}
	return maze;
}
int** maze_ans(bool** maze,int size,int start_x,int start_y,int end_x,int end_y){
	if(maze[start_x][start_y]&&maze[end_x][end_y])return NULL;
	const int heap_size=(size*size+2)/2;
	const int Size=size;
	const int ways[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	bool test[Size][Size];
	for(int i=0;i!=Size;i++)
		for(int k=0;k!=Size;k++)
			test[i][k]=0;
	int heap[heap_size][2],heap_count=0;
	heap[0][0]=start_x;
	heap[0][1]=start_y;
	heap_count++;
	test[start_x][start_y]=1;
	while(heap_count!=0){
		bool moved=0;
		if(heap[heap_count-1][0]==end_x&&heap[heap_count-1][1]==end_y)break;
		for(int i=0;i!=4;i++){
			int x=heap[heap_count-1][0]+ways[i][0];
			int y=heap[heap_count-1][1]+ways[i][1];
			
			if(x>=0&&x<size&&y>=0&&y<size&&!test[x][y]&&!maze[x][y]){
				heap[heap_count][0]=x;
				heap[heap_count][1]=y;
				heap_count++;
				moved=1;
				test[x][y]=1;
				break;
			}
		}
		if(!moved){
			heap_count--;
		}
	}
	int** ans = new int* [size];
	for(int i=0;i!=size;i++)
		ans[i] = new int [size];
	for(int i=0;i!=size;i++){
		for(int k=0;k!=size;k++){
			if(maze[i][k])ans[i][k]=-1;
			else ans[i][k]=0;
		}
	}
	for(int i=0;i!=heap_count;i++){
		cout<<heap[i][0]<<" "<<heap[i][1]<<endl;
		ans[heap[i][0]][heap[i][1]]=i+1;
	}
	return ans;
}
int main(){
	bool** m=creatMaze(7);
	int** a=maze_ans(m,7,1,1,5,5);
	for(int i=0;i!=7;i++){
		for(int k=0;k!=7;k++){
			if(a[i][k]==-1)cout<<"¢i¢i";
			else if(a[i][k]!=0){
				cout<<a[i][k]%10<<" ";
			} 
			else cout<<"  ";
		}
		cout<<endl;
	}
	
}



 
