/*
 * 冒泡排序：每次排序后会有一个元素到达指定位置
 * 每次遍历数组，从中挑选出最值，放到指定位置
 */

#include <iostream>
// 从小到大冒泡排序
void BubbleSort(int A[],int n)
{
	bool flag;
	for (int i = 0; i < n; ++i)
	{
		flag = false;
		for (int j = 1; j < n - i; ++j)
		{
			if (A[j - 1] > A[j])
			{
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;	
				flag = true;
			}
		}
		if(!flag)
			break;
	}
}
int main()
{
	int test[] = {3,5,1,4,9,7,6,8,2};
	BubbleSort(test, 9);
	for (int i = 0; i < 9; i++)
	{
		std::cout << test[i] << " ";
	}
	return 0;
}
/*
 * 空间效率：仅使用常数个辅助单元，O(1)
 * 时间效率：当初始序列有序时，比较次数为n-1，移动次数为0，从而最好时间复杂度为o(n)
 * 当初始序列无序时，需要进行n-1趟排序，第i趟排序要进行n-1
 * 次关键字的比较，而且每次比较都必须移动3次
 * 这种情况下：
 * 比较次数n(n-1)/2,移动次数3n(n-1)/2
 * 从而，最坏情况下时间复杂度为O(n²)，其平均时间复杂度也为O(n²).
 */