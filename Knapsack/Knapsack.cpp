// 0/1背包问题
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    
    int cap, n;
    //输入物品数量和背包容量
    cin >> n >> cap;

    //创建dp数组，B(n,cap)表示第n个物品时，在cap容量下，最大价值，因为数组大小时B(n+1,cap+1),最后结果应查看B[n][cap]
    vector<vector<int>> B(n + 1, vector<int>(cap + 1, 0));

    //用于存储物品价值的数组，因为数组大小是n+1，所以下标从1开始表示第一个物品
    vector<int> value(n+1,0);

    //用于存储物品重量的数组，因为数组大小是n+1，所以下标从1开始表示第一个物品
    vector<int> wigth(n+1,0);

    //输入第i个物品的重量和价值
    for (int i = 1; i <= n; i++) {
        cin >> wigth[i] >> value[i];
    }


    //从第1个物品和背包容量为1开始
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {

            //解决0/1背包问题的核心，若当前背包容量可以放下第i个物品时，求是放入背包内价值多还是不放入时价值多。
            if (j >= wigth[i]) {
                B[i][j] = max(value[i] + B[i - 1][j - wigth[i]], B[i - 1][j]);
            }
            //若无法放入，将放入第i-1个物品的结果保存
            else
                B[i][j] = B[i - 1][j];
        }
    }
    //将B(n,cap）所有情况遍历出来，最后结果是B[n][cap]
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}

