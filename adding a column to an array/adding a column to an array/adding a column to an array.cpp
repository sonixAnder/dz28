#include <iostream>
#include <vector>
using namespace std;

void addColumn(vector<vector<int>>& matrix, int position)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].insert(matrix[i].begin() + position, 5); //менять число в конце на то, которое хотите
	}
}

int main()
{
	vector<vector<int>>matrix ={{ 1,2,3 },
								{ 4,5,6 },
								{ 7,8,9 }};


	int position = 1; //менять расположение на то, которое хотите
	addColumn(matrix, position);

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}