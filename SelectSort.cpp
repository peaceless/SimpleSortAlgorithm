/*
 * 选择排序：每次排序过程中，选出最小(大)值放到指定位置
 * 不稳定，如果排序队列中有相同元素，会改变它们相对位置
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>

void SelectSort(int A[], int n){
	//对表A做简单选择排序，A【】从0开始存放元素
	int min;
	for(int i = 0; i < n - 1; i++) //一共进行n-1趟
	{
		min = i;	//记录最小位置
		for(int j = i + 1; j < n; j++)	//在A【i。。。n-1】中选择最小元素
			if(A[j] < A[min]) min = j;//更新最小元素位置
		if (min != i)
		{
			int temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
}
int main()
{
	srand((unsigned)time(0));
	int test[10];
	std::cout << "get queue:\n";
	for (int i = 0; i < 10; ++i)
	{
		test[i] = rand()%10;
		std::cout << test[i] << " ";
	}
	SelectSort(test,10);
	std::cout << "\nafter sort :\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << test[i] << " ";
	}
	return 0;
}
/*
 * 空间效率：常数辅助单元，O(1);
 * 时间效率：元素移动次数不超过3（n-1）次，最好情况时0次，此时表已有序；
 * 但元素间比较次数与序列的初始状态有关，始终是n(n-1)/2次，所以时间复杂度为O(n²)；
*/