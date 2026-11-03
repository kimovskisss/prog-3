#include <iostream>
#include <vector>
using namespace std;

// функција која проверува дали е безбедно да се постави кралица на позиција
int isSafe(vector<vector<int>>& mat,
    int row, int col) {
    int n = mat.size();
    int i, j;

    // проверка на колоната од горе
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    // проверка на горната дијагонала во лево нагоре
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    // проверка на горната дијагонала во десно 
    for (i = row - 1, j = col + 1; j < n && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

//функција за поставување кралици
void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>& result) {
    int n = mat.size();

    // ако сите се поставени
    if (row == n) {

        // го чува моменталното решение
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    ans.push_back(j + 1);
                }
            }
        }
        result.push_back(ans);
        return;
    }

    // ги поставува кралицире една по една
    for (int i = 0; i < n; i++) {

        // проверка дали може кралици да се постават
        if (isSafe(mat, row, i)) {
            mat[row][i] = 1;
            placeQueens(row + 1, mat, result);

            // backtrack
            mat[row][i] = 0;
        }
    }
}

// функција за барање на сите решенија
vector<vector<int>> nQueen(int n) {

    // иницијализација на таблата
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> result;

    // поставување кралици
    placeQueens(0, mat, result);

    return result;
}

int main() {
    int n = 4;
    vector<vector<int>> result = nQueen(n);
    for (auto& ans : result) {
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
