// DFS_N_Queen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<vector>
#include <iostream>

using namespace std;

const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {-1,-1,-1,0,0,1,1,1 };

void dfs(int n, int k, vector<vector<int>>& attack, vector<string>& current, vector<vector<string>>& res);
void put_in(int n, int i, int k, vector<vector<int>>& attack);


vector<vector<string>>  SolveNQueen(int n) {

    vector<vector<string>>res;
    vector<vector<int>> attack(n,vector<int>(n,0));
    vector<string>current(n,"");
    for (int i = 0; i < n; i++) {
        current[i].append(n, '.');
    }
    dfs(n, 0, attack, current, res);
    return res;
}

void dfs(int n,int k, vector<vector<int>>& attack, vector<string>& current, vector<vector<string>> & res) {

    if (k == n) {
        res.push_back(current);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (attack[k][i] == 0) {
            vector<vector<int>> temp = attack;
            current[k][i] = 'Q';
            put_in(n, k, i, attack);
            dfs(n, k + 1, attack, current, res);
            attack = temp;
            current[k][i] = '.';
        }
    }
}

void put_in(int n,int x,int y, vector<vector<int>>& attack) {
    attack[x][y] = 1;
    for (int i = 1; i < attack.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                attack[nx][ny] = 1;
        }
   }
}



int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans = SolveNQueen(n);
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

