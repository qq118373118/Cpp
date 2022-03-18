
//学习使用Heap,并解决《小红戴口罩》


#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;


//arr,表示口罩初始忍耐度数组，maxvalue表示小红最大忍耐度。
int func(vector<int> & arr,int maxvalue) {
    int res = 0;

    //创建小顶堆，如果传入的是less<int>，则创建的就是大顶堆
    make_heap(arr.begin(), arr.end(), greater<int>());
    while (maxvalue>arr[0]) {
        res++;
        for (auto c : arr)
            cout << c << ' ';
        cout << endl;
        maxvalue -= arr[0];
        int temp = arr[0] *= 2;

        //将根与二叉堆最后的数字交换，弹出，重新添加更新二叉堆
        pop_heap(arr.begin(), arr.end());
        arr.pop_back();
        arr.push_back(temp);
        push_heap(arr.begin(), arr.end(), greater<int>());
    }
    return res;
}



int main(){
    //第一行数据，输入口罩数量 和最大忍耐限度
    //第二行数据,输入每个口罩的初始忍耐度
    //每个口罩用完之后，忍耐度翻倍
    //问，输出最多忍耐几天
    int count = 0, maxvalue;
    cin >> count >> maxvalue;

    vector<int> arr(count);

    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    int ans = func(arr, maxvalue);
    cout << ans << endl;
    return 0;
}

