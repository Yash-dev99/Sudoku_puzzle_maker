#include<bits/stdc++.h>

using namespace std;

int board[9][9];

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
	return true;

}



bool solve(int row,int col){
	if (row==9 && col==8){
		return true;
	}
	if (row==9){
		row=0;
		col++;
	}
	if (board[row][col]>0)
		return solve(row+1,col);
	for(int i=1;i<10;i++){
		if(valid(row,col,i)){
			board[row][col]=i;
			if(solve(row+1,col))
				return true;
		}
		board[row][col]=0;
	}
	return false;
}



int main()
{
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>board[i][j];
		}
	}
	bool t=solve(0,0);
	if(t){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	return 0;
}
