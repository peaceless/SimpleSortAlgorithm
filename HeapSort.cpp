//建立大根堆
void BuildMaxHeap(ElemType A[],int len)
{
	for(int i = len/2;i > 0;i--)	//从i=[n/2]~1，反复调整堆
		AdjustDown(A,i,len);
}
void AdjustDown(ElemType A[],int k,int len){
//函数AdjustDown将元素k向下进行调整
	A[0] = A[k];	//A[0]暂存
	for(i = 2*k;i <= len;i *= 2) {	//沿key较大的子节点向下筛选
		if(i < len && A[i] < A[i+1])
			i++;	//取key较大的子节点的下标
		if(A[0] > A[i]) break;	//筛选结束
		else {
			A[k] = A[i];	//将A【i】调整到双亲结点上
			k = i;	//修改k值，以便继续向下筛选
		}
	}
	A[k] = A[0]; 	//被筛选节点的值放入最终位置
}
//堆排序算法
void HeapSort(ElemType A[],int len)
{
	BuildMaxHeap(A,len);	//初始建堆
	for(i = len;i > 1;i--)	//n-1趟的交换和建堆过程
	{
		swap(A[i],A[j]);	//输出堆顶元素（和堆底元素交换）
		AdjustDown(A,1,i-1);//整理，把剩余i-1个元素整理成堆
	}
}
//向上调整堆的算法
void AdjustUp(ElemType A[],int k)
//参数k为向上调整的节点，也为堆的元素个数
{
	A[0] = A[k];
	int i = k/2;//若结点值大于双亲结点，则将双亲结点向下调，并继续向上比较
	while(i > 0 && A[i] < A[0])
	{
		A[k] = A[i];
		k = i;
		i = k/2;	//继续向上比较
	}
	A[k] = A[0];	//复制到最终位置
}
/*
 * 空间效率：常数辅助单元，O(1)
 * 时间效率：建堆时间为O(n),之后有n-1次向下调整操作，每次调整时间复杂度为O(h)
 * O(nlog2n)
 */