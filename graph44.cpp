#include <iostream>
using namespace std;

// 1 up
// 2 down
// 3 left
// 4 right



int check(int sizeX, int sizeY, char **arr, int x, int y, int prev){
	if(arr[x][y] == 'X')
		return 0;
	if(arr[x][y] != 'S')
		arr[x][y] = 'X';
	if((arr[x][y] == 'S') 	|| (x > 0) 			&& (check(sizeX, sizeY, arr, x-1, y, 2))	//from down
							|| (y > 0) 			&& (check(sizeX, sizeY, arr, x, y-1, 4))	//from right
							|| (y < sizeY-1)	&& (check(sizeX, sizeY, arr, x, y+1, 3))	//from left
							|| (x < sizeX-1)	&& (check(sizeX, sizeY, arr, x+1, y, 1))	//from up
																						){
		switch(prev){
			case 2: cout << "down ";
				break;
			case 3: cout << "left ";
				break;
			case 4: cout << "right ";
				break;
			case 1: cout << "up ";
				break;
			default:
				break;
		}
		return 1;
	}

}

int main(){

int exitX, exitY, startX, startY, i, n, m;;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;

	char **a = new char *[n];

	for (i = 0; i < n; i++)
		a[i] = new char [m];	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'F'){
				exitX = i;
				exitY = j;
			}
			else if(a[i][j] == 'S'){
				startX = i;
				startY = j;
			}
		}
	}

	cout << "Start:" << startX << ", "<< startY << endl;
	cout << "Finish:"<< exitX << ", "<< exitY << endl;;
	

	check(n, m, a, exitX, exitY, 0);
	cout << endl;

	return 0;
}