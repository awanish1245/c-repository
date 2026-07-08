#include <iostream>
using namespace std;
int gridway(int r, int c, int n, int m)
{
    if (r == n - 1 && c == m - 1)
    {
        return 1;
    }
    if (r >= n || c >= m)
    {
        return 0;
    }
    int val1 = gridway(r, c + 1, n, m);
    int val2 = gridway(r + 1, c, n, m);
    return val1 + val2;
}
int main()
{
    int n = 3;
    int m = 3;
    cout << gridway(0, 0, n, m);
    return 0;
}