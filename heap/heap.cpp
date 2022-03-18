// heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;


int func(vector<int> & arr,int maxvalue) {
    int res = 0;
    make_heap(arr.begin(), arr.end(), greater<int>());
    while (maxvalue>arr[0]) {
        res++;
        for (auto c : arr)
            cout << c << ' ';
        cout << endl;
        maxvalue -= arr[0];
        int temp = arr[0] *= 2;
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


// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
