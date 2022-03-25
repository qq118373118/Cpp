//实现并查集
//并查集主要作用：检测图中是否有环
#include <iostream>

using namespace std;

//寻找结点x的根节点
int find_root(int x,int parent[]) {
    int root = x;
    while (parent[root] != -1) {
        root = parent[root];
    }
    return root;
}

/*
    判断两个结点是否可以合并，
    可以合并说明图中没有环，返回true,并且将两个节点合并
    不可以合并说明图中有环，返回false
    rank[i],表示节点i的深度，利用rank数组记录每个节点的深度，进行路径优化，防止出现单链影响find_root函数的搜索效率
*/
bool union_root(int x, int y, int parent[],int rank[]) {
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    
    //若两个节点的根相同，说明图中存在环
    if (x_root == y_root) {
        return false;
    }
    //若两个节点的根不同，说明图中不存在环，进行合并
    else {
        //rank[i],表示节点i的深度，判断深度，
        //将深度小的树合并到深度大的树中（深度小的树的根节点设为深度大的树的根节点）
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        //若两者深度相同，随意合并，并将被设为根节点的节点深度自增
        else {
            parent[x_root] = y_root;
            ++rank[y_root];
        }
    }
    return true;
}


int main()
{
    //测试数据假设有6个点
    int parent[6];
    int rank[6] = { 0 };

    //数据初始化
    memset(parent, -1, sizeof(parent));
    memset(rank, 0, sizeof(rank));

    //边
    int edges[5][2] = {
        {0,1},{1,2},{1,3},{2,5},{3,4}
    };

    //对每条边进行遍历
    for (int i = 0; i < 5; i++) {
        if (!union_root(edges[i][0], edges[i][1], parent,rank)) {
            cout << "存在环" << endl;
            return 0;
        }
    }
    cout << "不存在环" << endl;
    return 0;
}


