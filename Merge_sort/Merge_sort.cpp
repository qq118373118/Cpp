//归并排序
//将数组划分为若干个有序子数组，再将若干有序子数组合并

#include <iostream>

using namespace std;

//归并排序的核心函数，即合并和排序
void merge_sort(int arr[], int temp[], int left, int mid, int right) {

	//将待排序数据临时存放至临时数组，排序范围是[left,right]
	for (int i = left; i <= right;i++) {
		temp[i] = arr[i];
	}

	//获取划分的两个子数组的头部
	int i = left;
	int j = mid + 1;

	//将排序后的归并结果放入原数组中，排序范围是[left,right]
	for(int k = left;k<=right;k++){

		//当左半子数组下标越界，右半数组直接将数据放入原数组
		if (i == mid + 1) {
			arr[k] = temp[j];
			++j;
		}
		//当右半子数组下标越界，左半数组直接将数据放入原数组
		else if (j == right + 1) {
			arr[k] = temp[i];
			++i;
		}
		//归并和排序，把两个子数组头部较小的数放回原数组
		else if (temp[i] <= temp[j]) {
			arr[k] = temp[i];
			i++;
		}
		else{
			arr[k] = temp[j];
			j++;
		}
	}
}


//该函数用于划分数组，范围是[left,right]
void reverse(int arr[],int temp[],int left,int right) {

	//当left>=right，停止递归
	if (left >= right)
		return;

	//获取中间元素下标，为防止（left+right）数据过大，用下述公式求中间元素下标
	int mid = left + (right - left) / 2;

	//递归，进一步划分和排序[left,mid]范围内的数组
	reverse(arr, temp, left, mid);

	//递归，进一步划分和排序[mid+1,right]范围内的数组
	reverse(arr, temp, mid + 1, right);

	//合并并排序范围[left,right]数组
	merge_sort(arr, temp, left, mid, right);
}





int main()
{
	//待排序数组大小
	int n = 8;
	//待排序数组
	int arr[] = { 9,5,7,3,2,4,6,1 };
	//临时数组，用于临时存放数据
	int* temp = new int[n];


	//输出排序前数据结果
	cout << "排序前：" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;


	//调用函数，划分数组
	reverse(arr, temp, 0, n - 1);



	//输出排序后数据结果
	cout << "排序后：" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;


	//释放内存
	delete[] temp;
	return 0;
}

