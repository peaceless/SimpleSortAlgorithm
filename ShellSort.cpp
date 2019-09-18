#include <iostream>
#include <cstdlib>
#include <ctime>
typedef int ElemType;
void ShellSort(ElemType A[],int n)
{
	//对顺序表作希尔插入排序，本算法和直接插入排序相比，作了以下修改
	//1.前后记录位置的增量是dk，不是1
	//2.r[0]只是暂存单元，不是哨兵，当j<=0,插入位置已到
	int j = 1;
	int temp;
	for(int dk = n/2;dk >= 1;dk /= 2) {		//步长变化
		for(int i = dk; i <= n; ++i){
			if(A[i] < A[i-dk]){	//需将A【i】插入有序增量字表
				temp = A[i];			//暂存在A【0】
				for(j = i-dk;j >= 0 && temp < A[j];j -= dk)
					A[j+dk] = A[j];		//记录后移，查找插入位置
				A[j+dk] = temp;			//插入
			}
		}
	}
}
//void p(int arr[], int bgn, int end)
// //{
// 	    for (int step = (end - bgn) / 2; step > 0; step /= 2)
//     {
//         for (int i = bgn; i < step; ++i)
//         {
//             /*
//             * 以下，insertSort的变异
//             */
//             for (int j = i + step; j < end; j += step)
//             {
//                 int k = j - step;
//                 for ( ; k >= i; k -= step)
//                     if (arr[k] <= arr[j])
//                         break;
//                 if (k != j - step)
//                 {
//                     int tmp = arr[j];
//                     for (int m = j; m > k + step; m -= step)
//                         arr[m] = arr[m - step];
//                     arr[k + step] = tmp;
//                 }
//             }
//         }
//     }
// }
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int test[10];
	std::cout << "get a queue: \n";
	for (int i = 0; i < 10; ++i)
	{
		test[i] = rand()%10;
		std::cout << test[i] << " ";
	}
	std::cout << "after sort" << std::endl;
	ShellSort(test,10);
	for (int i = 0; i < 10; ++i)
	{
		std::cout << test[i] << " ";
	}
	return 0;
}
/*
 * 空间效率：仅使用常数个辅助单元，故空间复杂度为O(1)；
 * 时间效率：依赖于增量序列的函数，当n在某个特定范围时，希尔排序的时间复杂度约为O(n1.3)，
 * 最坏情况是O(n²)
 */