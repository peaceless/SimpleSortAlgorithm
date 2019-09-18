/*
 * 插入排序认为已存在一个已经排序好的序列，将一系列元素插入到这个已排序序列中去
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
typedef int ElemType;
void InsertSort(ElemType A[], int n) {
	int i,j = 1;
	int temp;
	for(i = 2; i < n; i++) {	//依次将A【2】~A【n】插入到前面已排序序列
		if(A[i] < A[i-1]) {		//若A【i】的关键码小于其前驱，需将A【i】插入有序表
			temp = A[i]	;	//复制为哨兵，A【0】不存放元素
			for(j = i-1; temp < A[j]; --j)	//从后往前查找带插入位置
				A[j+1] = A[j];	//向后挪位置
		}
		A[j+1] = temp;	//复制到插入位置
	}
}
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int test[10];
	std::cout << "get a queue:\n";
	for (int i = 0; i < 10; ++i)
	{
		test[i] = rand()%10;
		std::cout << test[i] << " ";
	}
	std::cout << "\nafter sort\n";
	InsertSort(test,10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << test[i] << " ";
	}
	return 0;
}
/*
	空间效率：使用常数单元，空间复杂度为O（1）
	时间效率：最好情况下，即表中元素已有序，时间复杂度为O（n）
			 最坏情况下，即表中元素逆序，总的移动次数为Σ（i = 2~n）（i+1）
			 平均比较次数和总的移动次数为n²/4
 */