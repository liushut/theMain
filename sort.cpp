#include"sort.h"
void swap_Sort(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//冒泡
void BubbleSort(int a[], int length)
{
	int flag = 0;
	for (int i = 0; i < length&&flag==0; i++)
	{
		flag = 1;
		for (int j = length-1; j > i; j--)
		{
			if (a[j-1] < a[j])//从大到小
			{
				flag = 0;
				swap_Sort(&a[j-1], &a[j]);
			}
		}
	}
}
void PrintAaary(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}

}

//选择
void ChanceSort(int arr[],int len)
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap_Sort(&arr[i], &arr[min]);
		}
	}
}
//插入排序
void InsetSort(int a[], int len)
{
	int j;
	//把0位置的元素当作有序
	for (int i = 1; i < len; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];//缓存
			for (j = i - 1; j >= 0 && temp < a[j]; j--)
			{
				a[j + 1] = a[j];//往后移动。剩下j+1元素
			}
			a[j + 1] = temp;//插入上一步j--了 所以=1
		}

	}
}
//希尔排序
void HierSort(int a[], int len)
{
	int j;
	int k;
	int incresement = len;//增量
	do
	{
		//确定分组增量
		incresement = incresement / 3 + 1;
		for (int i = 0; i < incresement; i++)//每一组最大值到incresement
		{
			for (j = i + incresement; j < len; j + incresement)
			{
				if (a[j] < a[j-incresement])
				{
					int temp = a[j];
					for (k = j - incresement; k >= 0 && temp < a[k]; k -= incresement)
					{
						a[k + incresement] = a[k];
					}
					a[k + incresement] = temp;
				}
			}
		}
	} while (incresement>1);
}
//快速排序  小->大
void QuickSort(int a[], int start,int end)
{
	int temp = a[start];//基准数
	int i = start;//开始下标
	int j = end;//结束下标
	if (i < j)
	{
		while (i < j)
		{
			//从右到左找比基准数小的。
			while (i < j&&a[j] >= temp)
			{
				j--;
			}
			//填坑
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			//从左向右找比基准数大的数
			while (i < j&&a[i] < temp)
			{
				i++;
			}
			//填坑
			if (i < j)
			{
				a[j] = a[i];
				j++;
			}
		}
		//把基准数放到i=j的位置
		a[i] = temp;
		//递归调用   对左半部分和右半部分快速排序
		QuickSort(a, start, i - 1);
		QuickSort(a, i + 1, end);
	}

}
//创建数组
int*CreateArr()
{
	srand((unsigned int)time(NULL));
	int*arr = (int*)malloc(sizeof(int)*MAX);
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}
//归并  并起来函数   合并算法  从小到大
void Merge(int a[], int start, int end, int mid, int*temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int lenth = 0;//表示辅助空间有多少个元素
	//合并两个有序序列
	while (i_start <= i_end && j_start <= j_end)
	{
		if (a[i_start] < a[j_start])
		{
			temp[lenth] = a[i_start];
			lenth++;
			i_start++;
		}
		else
		{
			temp[lenth] = a[j_start];
			j_start++;
			lenth++;
		}
	}
	//不确定谁长度大
	//i这个序列后面的元素
	while (i_start <= i_end)
	{
		temp[lenth] = a[i_start];
		i_start++;
		lenth++;
	}	//j这个序列后面的元素
	while (j_start < j_end)
	{
		temp[lenth] = a[j_start];
		lenth++;
		j_start++;
	}

	//辅助空间中的数据覆盖到原来空间
	for (int i = 0; i < lenth; i++)
	{
		a[start + i] = temp[i];
	}
}
//归并排序
void MergeSort(int a[], int start, int end, int *temp)//辅助空间
{
	//结束
	if (start >= end)
	{
		return;
	}
	//第一次分组
	int mid = (start + end) / 2;
	//继续左边分组
	MergeSort(a, start, mid, temp);
	//继续右边分组
	MergeSort(a, mid+1,end, temp);

	//合并
	Merge(a, start, end,mid,temp);
}
void MySwap(int arr[], int a,int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

}

//@param arr 待调整的数组
//@param index 待调整的结点的下标
//@param len  数组的长度
void HeadAdjust(int a[], int index, int  len)
{
	//先保存当前结点的下标
	int max = index;
	//保持当前结点的左右孩子的数组下标
	int lchild = 2 * index + 1;//   下标从0开始的
	int rchild = 2 * index + 2;
	if (lchild < len&&a[lchild] > a[max])
	{
		max = lchild;
	}
	if (rchild<len&&a[rchild]>a[max])
	{
		max = rchild;
	}
	if (max != index)//说明max变化了
	{
		//交换，得到最大的
		MySwap(a, max, index);
		HeadAdjust(a, max, len);//调整Max位置
	}
}
//堆排序
void HeapSort(int a[], int len)
{
	//初始化堆
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeadAdjust(a, i, len);
	}
	//初始化完后，现在堆顶是最大的


	//交换堆顶元素和最后一个元素
	for (int i = len - 1; i >= 0; i--)
	{
		MySwap(a,0,len);
		HeadAdjust(a, 0, i);
	}


}
