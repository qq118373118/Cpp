
//利用DFS+回溯解决N皇后问题

#include<vector>
#include <iostream>

using namespace std;

//方向数组
const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {-1,-1,-1,0,0,1,1,1 };

//函数声明
void dfs(int n, int k, vector<vector<int>>& attack, vector<string>& current, vector<vector<string>>& res);
void put_in(int n, int i, int k, vector<vector<int>>& attack);

//N皇后问题接口
vector<vector<string>>  SolveNQueen(int n) {

    //初始化
    //attack:用于记录将皇后放入棋盘后的攻击范围（0表示可以放置，即不在其他皇后的攻击范围里；1表示不可放置，即在其他皇后的攻击范围里）
    //current：用于记录当前皇后摆放位置
    //res:用于记录每一种解法的摆放情况
    vector<vector<string>>res;
    vector<vector<int>> attack(n,vector<int>(n,0));
    vector<string>current(n,"");
    for (int i = 0; i < n; i++) {
        current[i].append(n, '.');
    }

    //递归解N皇后问题
    dfs(n, 0, attack, current, res);
    return res;
}


void dfs(int n,int k, vector<vector<int>>& attack, vector<string>& current, vector<vector<string>> & res) {

    //k表示行数，若k==n,表示已经求得一种解法，将解法放入res
    if (k == n) {
        res.push_back(current);
        return;
    }

    //对列进行遍历，
    for (int i = 0; i < n; i++) {
        //如果attack[k][i]==0，表示该位置可以放皇后
        if (attack[k][i] == 0) {

            //记录当前攻击范围，之后用于回溯
            vector<vector<int>> temp = attack;

            //将该位置更新，放入皇后
            current[k][i] = 'Q';

            //更新攻击范围
            put_in(n, k, i, attack);

            //进入下一行的递归
            dfs(n, k + 1, attack, current, res);

            //回溯至放入前的状态
            attack = temp;
            current[k][i] = '.';
        }
    }
}

//用于更新放入皇后之后的攻击范围
void put_in(int n,int x,int y, vector<vector<int>>& attack) {

    //更新皇后放入的位置
    attack[x][y] = 1;

    //以当前位置为中心，向外扩散攻击范围
    for (int i = 1; i < attack.size(); i++) {

        //皇后的攻击方为有八个方向，呈"米"字型,在攻击范围内的元素置1
        for (int j = 0; j < 8; j++) {
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];

            //坐标有效，置疑
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                attack[nx][ny] = 1;
        }
   }
}



int main()
{
    int n;

    //输入n，表示求解N皇后问题
    cin >> n;

    //调用并接收N皇后问题的结果
    vector<vector<string>> ans = SolveNQueen(n);

    //遍历输出各种解法
    int count = 1;
    for (auto res : ans) {
        cout << "这是第:" << count << "解法" << endl;
        count++;
        for (auto s : res) {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}

