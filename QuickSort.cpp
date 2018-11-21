void QuickSort(ElemType A[],int low,int high) {
	if(low < high)	//递归跳出的条件
	//Partition() 是划分操作，将表A[low...high] 划分为满足上述条件的两个字表
	{
		int pivotpos = Partition(A,low,high);//划分
		QuickSort(A,low,pivotpos-1);	//依次对两个子表进行递归排序
		QuickSort(A,pivotpos+1,high);
	}
}

int Partition(ElemType A[],int low,int high)
{
	//严版教材的划分算法(一趟排序过程)
	ElemType pivot = A[low];	//将当前表中第一个元素设为枢轴值，对表进行划分
	while(low < high) {			//循环跳出条件
		while(low < high && A[high] >= pivot) --high;
		A[low] = A[high];		//将比枢轴值小的元素移动到左端
		while(low < high && A[low] <= pivot) ++low;
		A[high] = A[low];		//将比枢轴值大的元素移动到右端
	}
	A[low] = pivot;				//枢轴元素存放到最终位置
	return low;					//返回存放枢轴的最终位置
}
/*
 * 空间效率：快速排序是递归的，需要借助工作栈来保存每一层递归调用的必要信息，其
 * 容量应与递归调用的最大深度一致。最好情况下为log2(n+1)向上取整；最坏情况下，
 * 因为要进行n-1次递归调用，所以栈的深度为O(n),平均情况下，栈的深度为O(log2n).
 * 因此空间复杂度在最坏情况下O(n),平均情况下为O(log2n).
 * 时间效率：快速排序的运行时间与划分是否对称有关，而后者又与具体使用的划分算法有关，
 * 快排的最坏情况发生在两个领域分别包含n-1个元素和0个元素，这种最大程度的不对称若发生在
 * 每一层递归上，即对应初始排序表基本有序或基本逆序时，就得到最坏情况下的时间复杂度为O(n²)
 */