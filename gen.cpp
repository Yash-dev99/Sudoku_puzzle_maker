#include<bits/stdc++.h>
#include<time.h>

using namespace std;

int board[9][9]={
{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0},

{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0},

{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0},
{0,0,0, 0,0,0 ,0,0,0}
};

bool valid(int i,int j,int n){
	for(int t=0;t<9;t++){
		if (board[i][t]==n){
			return false;
		}
		if (board[t][j]==n){
			return false;
		}
	}
	int startrow=i - i%3;
	int startcol=j - j%3;
	for(int t=0;t<3;t++){
		for(int u=0;u<3;u++){
			if (board[startrow+t][startcol+u]==n){
			return false;
			}
		}
	}
	return true;

}

int main()
{
	srand (time(NULL));
	int number_of_val=rand()%25+25;
	for( int t=0;t<number_of_val;t++){
		int i,j,n;
		i=rand()%9;
		j=rand()%9;
		n=rand()%8+1;
		while(!(board[i][j]==0 && valid(i,j,n))){
			i=rand()%9;
			j=rand()%9;
			n=rand()%8+1;
		}
		board[i][j]=n;
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
		cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
