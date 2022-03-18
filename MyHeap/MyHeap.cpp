// 这里实现了一个大顶堆

#include <iostream>

using namespace std;

//函数声明
void heapify(int arr[], int i, int n);
void build_heap(int arr[], int n);


int main()
{

    //输入要创建的大顶堆的节点数量
    int n;
    cin >> n;

    //利用数组模拟一个平衡二叉树来创建大顶堆
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //调用创建大顶堆函数
    build_heap(arr, n);


    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    delete[] arr;
}


//该函数的功能是，在当前结点 arr[i]与该节点的左右孩子中找出最大值，如果最大值是节点本身不做操作；
//如果最大值是孩子节点，将该节点与孩子结点的值进行交换，并且交换后以孩子结点为根的树可能不再满足大顶堆，所以需要以交换后的结点为根节点进行递归，重复该操作。
void heapify(int arr[], int i, int n) {

    //当前结点的下标为i,按照下面公式可以算出左孩子和右孩子的下标。
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    //用来记录当前节点和左右孩子中最大值的下标，默认为当前结点的下标。
    int max_index = i;

    //递归结束条件
    //（不写也可以，因为如果当前结点与左右孩子结点比较就是最大值的话，不会进行任何操作，递归自然就结束了）
    if (i >= n) {
        return;
    }

    //如果左孩子下标不越界，并且比记录的最大值还大，更新最大值下标。
    if (left < n && arr[left] > arr[max_index]) {
        max_index = left;
    }

    //如果右孩子下标不越界，并且比记录的最大值还大，更新最大值下标。
    if (right < n && arr[right] > arr[max_index]) {
        max_index = right;
    }

    //如果最大值下标不是当前结点下标，说明左右孩子中有最大值，与其交换，并进行递归操作。
    if (max_index != i) {

        //值交换
        int temp = arr[max_index];
        arr[max_index] = arr[i];
        arr[i] = temp;

        //递归，因为交换后，以当前结点交换的孩子结点为根的树可能不再满足大顶堆的特点，需要进行再一次的heapify操作
        heapify(arr, max_index, n);
    }
}


//创建大顶堆的接口
void build_heap(int arr[], int n) {

    //通过最后一个结点的下标找出第一个有孩子结点的结点。
    int last = n - 1;
    int parent = (last - 1) / 2;

    //从第一个有孩子的结点往根节点进行heapify操作，可以完成大顶堆的创建。
    for (int i = parent; i >= 0; i--) {
        heapify(arr, i, n);
    }
}