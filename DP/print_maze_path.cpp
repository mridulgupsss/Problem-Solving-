#include <bits/stdc++.h>
using namespace std;

void printpath(vector<vector<int>> &dp, string psf, int i, int j)
{
    if (i == 4 && j == 4) // base case
    {
        cout << psf << endl;
        return;
    }

    if (i == 4)
    {
        printpath(dp, psf + "h", i, j + 1);
    }
    else if (j == 4)
    {
        printpath(dp, psf + "v", i + 1, j);
    }
    else
    {
        if (dp[i + 1][j] > dp[i][j + 1])
        {
            printpath(dp, psf + "h", i, j + 1);
        }
        else if (dp[i + 1][j] < dp[i][j + 1])
        {
            printpath(dp, psf + "v", i + 1, j);
        }
        else
        {
            printpath(dp, psf + "h", i, j + 1);
            printpath(dp, psf + "v", i + 1, j);
        }
    }
}
int main()
{
    // input dp  (basically fomed dp after solving min cost maze path problem)
    vector<vector<int>> dp(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            cin >> dp[i][j];
        }
    }

    // reverse engineering to print paths

    printpath(dp, "", 0, 0);
}