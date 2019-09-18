/*桶排序*/
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
void bucketSort(int arr[])
{
	int max = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (i > max)
			max = i;
	}
	int *pBuf = new int[max + 1];
	memset(pBuf, 0, (max + 1)*sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		int temp = arr[i];
		++pBuf[temp];
	}
	for (int i = 0, j = 0; i <= max; ++i)
	{
		while (pBuf[i]--)
			arr[j++] = i;
	}
	delete []pBuf;
}
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int test[10];
	std::cout << "get a queue:\n";
	for (int i = 0; i < 10; ++i)
	{
		test[i] = rand() % 10;
		std::cout << test[i] << " ";
	}
	std::cout << "\nBucketSort:\n";
	bucketSort(test);
	for (int i = 0; i < 10; i++)
	{
		std::cout << test[i] << " ";
	}
	return 0;
}
// 桶排序是将待排序集合分为一定数量的子集合(桶bucket)
// 再对桶内的集合使用某种排序方式，获得分段有序集合
// 将各桶内集合依次取出，即得到有序集合
// 空间复杂度：使用空间M存储元素，空间使用为o(N+M)
// 时间复杂度：移动元素入桶时间为o(N),后序排序时间复杂度取决于使用的排序算法
// 即总时间复杂度为o(N + x);