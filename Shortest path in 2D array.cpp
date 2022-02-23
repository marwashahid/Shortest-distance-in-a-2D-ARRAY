#include<iostream>
#include<array>
using namespace std;
int shortest_Distance(char arrayGrid[][4]);
int main()
{
	char arrayGrid[4][4] = { { 'S','0','1','1' },{ '1','1','0','1' },{ '0','1','1','1' },{ '1','0','D','1' } };

	cout<<shortest_Distance(arrayGrid);


	system("pause");
	return 0;
}
int shortest_Distance(char arrayGrid[][4])
{
	int no_row = 4, no_col = 4;
	int row, col;
	bool visited[4][4];
	int stack_row[4];
	int stack_col[4];
	int distance;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arrayGrid[i][j] == '0')
				visited[i][j] = true;
			else
				visited[i][j] = false;
			if (arrayGrid[i][j] == 'S')
			{
				row = i;
				col = j;
			}

		}
	}
	visited[row][col] = true;
	stack_row[0] = { row };
	stack_col[0] = { col };
	int i = 0;
	while ( *(stack_row) != 0 || *(stack_col) != 0)
	{
		if (stack_row[i] != 0 || stack_col[i] != 0)
		{
			stack_row[i] = 0;
			stack_col[i] = 0;

		}
		if (arrayGrid[row][col] == 'D')
			return distance;
		//moving up 
		if (row - 1 >= 0 && visited[row - 1][col] == false)
		{
			stack_row[1] = row - 1;
			stack_col[1] = col;
			distance++;
			visited[row - 1][col] = true;
		}
		//moving down 
		if (row + 1 < no_row && visited[row + 1][col] == false)
		{
			stack_row[2] = row + 1;
			stack_col[2] = col;
			distance++;
			visited[row - 1][col] = true;
		}
		//moving left 
		if (col - 1 >= 0 && visited[row][col - 1] == false)
		{
			stack_row[3] = row;
			stack_col[3] = col - 1;
			distance++;
			visited[row][col - 1] = true;
		}
		//moving right 
		if (col + 1 < no_col && visited[row][col + 1] == false)
		{
			stack_row[4] = row;
			stack_col[4] = col + 1;
			distance++;
			visited[row][col + 1] = true;
		}
		i++;
	}

	return -1;
}