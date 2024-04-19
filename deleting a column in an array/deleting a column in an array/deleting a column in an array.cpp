#include <iostream>
#include <vector>
using namespace std;

void deleteColumn(vector<vector<int>>& arr, int column)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].erase(arr[i].begin() + column);
    }
}

int main()
{
    vector<vector<int>> arr =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int columnToDelete = 0; //менять по своему усмотрению
    deleteColumn(arr, columnToDelete);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}