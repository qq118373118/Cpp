// Knapsack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    int cap, n;
    cin >> n >> cap;
    vector<vector<int>> B(n + 1, vector<int>(cap + 1, 0));
    vector<int> value(n+1,0);
    vector<int> wigth(n+1,0);
    cout << value.size() << endl;
    for (int i = 1; i <= n; i++) {
        cin >> wigth[i] >> value[i];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            if (j >= wigth[i]) {
                B[i][j] = max(value[i] + B[i - 1][j - wigth[i]], B[i - 1][j]);
            }
            else
                B[i][j] = B[i - 1][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}

