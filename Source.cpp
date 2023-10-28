#include <iostream>
#include <random>
using namespace std;

void ArrayInit(int arr[],int);
void Array(int arr[], int);
int MaxElement(int arr[],int,int);
void FuncMaxElem();
void HanoiTowers(int,int,int,int);
void FuncHanoiTowers();
void CheassBoard(int** ,int);
int KnightMoves(int, int, int** , int, int, int knight_x[], int knight_y[]);
void FuncKnightMove();
void SetQueen(int, int, int** , int);
void ResetQueen(int, int, int** , int);
bool TryQueen(int, int** , int);
void FuncQueenPlacement();

int main()
{
	FuncMaxElem();
	FuncHanoiTowers();
	FuncKnightMove();
	FuncQueenPlacement();
}
void ArrayInit(int arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		int x = rand() % 100;
		while (find(arr, arr + i, x) != arr + i)
		{
			x = rand() % 200;
		}
		arr[i] = x;
	}
}
void Array(int arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int MaxElement(int arr[], int l, int r)
{
	int mid, one_subarr, two_subarr;
	if (l == r) 
		return arr[l];
	mid = (l+r) / 2;
	one_subarr = MaxElement(arr,l, mid);
	two_subarr = MaxElement(arr,mid+1,r);
	cout << one_subarr << " " << two_subarr << " " << endl;
	if (one_subarr > two_subarr)
	{ 
		cout << "maximum element  =  " << one_subarr << endl;
		return one_subarr;
	}
	else
	{
		cout << "maximum element =  " << two_subarr << endl;
		return two_subarr;	
	}
}
void FuncMaxElem()
{
	cout << "Finding the maximum of an array: " << endl;
	int n;
	cout << "Enter the number of array elements: ";
	cin >> n;
	int* arr = new int[n];
	ArrayInit(arr, n);
	Array(arr, n);
	int max_elem = MaxElement(arr, 0, n - 1);
	cout  << "Max array element = " << max_elem << endl;
	cout << endl;
}
void HanoiTowers(int n, int st1,int st2,int st3)
{
	if (n == 1)
	{
		cout << "disk " << n << " " << st1 << "->" << st3 << endl;
	}
	else
	{
		HanoiTowers(n - 1, st1, st3, st2);
		cout << "disk " << n << " " << st1 << "->" << st3 << endl;
		HanoiTowers(n-1,st2,st1,st3);
	}
}
void FuncHanoiTowers()
{
	cout << "Hanoi Towers: " << endl;
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;
	HanoiTowers(n, 1, 2, 3);
	cout << endl;
}
void CheassBoard(int** cheass_board, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << cheass_board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int KnightMoves(int x_pos,int y_pos, int** cheass_board, int n, int next_pos, int knight_x[], int knight_y[])
{
	if (x_pos < 0 || y_pos < 0 || x_pos >= n || y_pos >= n)
		return false;
	if (cheass_board[x_pos][y_pos] != 0)
		return false;
	next_pos++;
	cheass_board[x_pos][y_pos] = next_pos;
	if (next_pos == n * n )
		return true;
	cout << "number of moves = " << next_pos << endl;
	CheassBoard(cheass_board, n);
	for (int i = 0;i < 8;i++)
	{
		if (KnightMoves(x_pos + knight_x[i], y_pos + knight_y[i], cheass_board, n, next_pos, knight_x, knight_y))
			return true;
	}
	next_pos--;
	cheass_board[x_pos][y_pos] = 0;
	return false;
	
}
void FuncKnightMove()
{
	cout << "Knight's Move: " << endl;
	int x_pos, y_pos,n,next_pos = 0;
	int knight_x[8] = {2,1,-1,-2,-2,-1,1,2};
	int knight_y[8] = {1,2,2,1,-1,-2,-2,-1};
	cout << "Enter the coordinates of the horse(x): ";
	cin >> x_pos;
	cout << "Enter the coordinates of the horse(y): ";
	cin >> y_pos;
	cout << "Enter the board size(1-6): " ;
	cin >> n;
	if (n > 8 || n < 1 || x_pos > n || y_pos > n )
	{
		cout << "Incorrect input " << endl;
		return;
	}
	int** cheass_board = new int* [n];
	for (int i = 0; i < n; i++)
		cheass_board[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cheass_board[i][j] = 0;
	}
	if (KnightMoves(x_pos, y_pos, cheass_board, n, next_pos, knight_x, knight_y))
		CheassBoard(cheass_board, n);
	else
		cout << "No solutions: " << endl;
}
void SetQueen(int i,int j,int** cheass_board,int n)
{
	for (int x = 0;x < n;x++)
	{
		++cheass_board[x][j];
		++cheass_board[i][x];
		int foo;
		foo = j - i + x;
		if (foo >=0 && foo < n)
			++cheass_board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < n)
			++cheass_board[x][foo];
	}
	cheass_board[i][j] = -1;
	
}
void ResetQueen(int i, int j, int** cheass_board, int n)
{
	for (int x = 0;x < n;x++)
	{
		-- cheass_board[x][j];
		--cheass_board[i][x];
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < n)
			--cheass_board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < n)
			--cheass_board[x][foo];
	}
	cheass_board[i][j] = 0;
	
}
bool TryQueen(int i, int** cheass_board, int n)
{
	bool result = false;
	for (int j = 0;j < n;j++)
	{
		if (cheass_board[i][j] == 0)
		{
			SetQueen(i, j, cheass_board, n);
			if (i == n-1)
				result = true;
			else
			{
				if (!(result = TryQueen(i + 1, cheass_board, n)))
					ResetQueen(i, j, cheass_board, n);
			}
		}
		if (result)
			break;
	}
	return result;
}
void FuncQueenPlacement()
{
	cout << "Queen Placement: " << endl;
	int n;
	cout << "Enter the board size(4-8): ";
	cin >> n;
	if (n < 4 || n > 8)
	{
		cout << "Incorrect input " << endl;
		return;
	}
	int** cheass_board = new int* [n];
	for (int i = 0; i < n; i++)
		cheass_board[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cheass_board[i][j] = 0;
	}
	TryQueen(0,cheass_board, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cheass_board[i][j] == -1)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout <<  endl;
	}
	
}

