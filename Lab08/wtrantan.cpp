#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//Used pseudocode from the textbook pg 375 
void matrixChainOrder(int p[], vector<vector<int> > &m, vector<vector<int> > &s, int size)
{
    for (int i = 1; i < size; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l < size; l++) {
        for (int i = 1; i < size - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void print(vector<vector<int>> s, int i, int j) {
    if (i == j){
        cout << "A" << (i - 1);
    } 
    else {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i <= size; i++) {
        cin >> array[i];
    }

    vector<vector<int> > m;
    vector<vector<int> > s;

    m.resize(size+1, std::vector<int>(size+1, 0));
    s.resize(size+1, std::vector<int>(size+1, 0));
    
    matrixChainOrder(array, m, s, size+1);
    cout << m[1][size] << "\n";
    print(s, 1, size);
    cout << "\n";
    return 0;
}