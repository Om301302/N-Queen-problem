#include <iostream>
using namespace std;


const int n = 4;
char q = 'Q';
char dot = '.';


void print_board(char arr[][n]){
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){  
			cout << arr[i][j] << " ";						
		}
		cout << endl;
	}
}



bool check_queen(char arr[][n], int row, int col){
// Will cheack for rows and colums if that will have  1 we can't put queen there.
	
	int a = row;
	int b = col;
	
	for(int i=0; i<n; i++){
		if(arr[row][i] == q){
			return false;
		}else if(arr[i][col] == q){
			return false;
		}
		
	}
	
	row = a;
	col = b;
	
	
	
	
	
// will check for the diagonal if it have 1 in it.
	// part 1 will check from that position to uper side
	while (row >= 0 && col >= 0){
		if(arr[row][col] == q){
			return false;
		}
		row = row-1;
		col = col-1;
	}
	row = a;
	col = b;
	
	//Part 2 will check from that position to down diagonal
	while (row <= n-1 && col <= n-1){
		if(arr[row][col] == q){
			return false;
		}
		row = row+1;
		col = col+1;
	}
// will check for the right diagonal if it have 1 o
	// Part 1 right upper
	
	row = a;
	col = b;
	
	while (col <= n-1 && row >=0){
		if(arr[row][col] == q){
			return false;
		}
		row = row-1;
		col = col+1;
	}
	//part2
	row = a;
	col = b;
	
	while (row <=n-1 && col>=0){
		if(arr[row][col] == q){
			return false;
		}
		row = row+1;
		col = col-1;
	}
	return true;	
}

// To assign 1 to first position and check further if we can put it or no.

bool place_queen(char arr[][n], int row){
	/*cout << row << endl;
	print_board(arr);
	*/
	if(row >= n){
		return true;
	}
	for (int i = 0; i < n; i++){
		if((check_queen(arr, row, i)) == true){
			arr[row][i] = q; // if the place will be good for queen place a 1 (place's row and column and diagonal won't have 1)
			/*
			if(row == n-1 and i == n-1){
				cout<<"ggg"<<endl;
				return true;
			}*/
			if(place_queen(arr, row+1) == true){
				return true;
			}// if it false assign that number 0 and i willtake new from that positon.
			arr[row][i] = dot;		
		}
	}
	return false;	
}
int main(){
	
	char arr[n][n];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){  
			arr[i][j]=dot;								
		}
	}
	if(place_queen(arr, 0) == true){
		print_board(arr);
		}
	else{
		cout <<"There is no solution";
	}
	
	/*
	if(place_queen(arr, 0) == true){
		print_board(arr);
	}*/
	
	
	
	
	
	
	return 0;
}
