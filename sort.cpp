#include"sort.h"
void swap_Sort(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//ð��
void BubbleSort(int a[], int length)
{
	int flag = 0;
	for (int i = 0; i < length&&flag==0; i++)
	{
		flag = 1;
		for (int j = length-1; j > i; j--)
		{
			if (a[j-1] < a[j])//�Ӵ�С
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

//ѡ��
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
//��������
void InsetSort(int a[], int len)
{
	int j;
	//��0λ�õ�Ԫ�ص�������
	for (int i = 1; i < len; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];//����
			for (j = i - 1; j >= 0 && temp < a[j]; j--)
			{
				a[j + 1] = a[j];//�����ƶ���ʣ��j+1Ԫ��
			}
			a[j + 1] = temp;//������һ��j--�� ����=1
		}

	}
}
//ϣ������
void HierSort(int a[], int len)
{
	int j;
	int k;
	int incresement = len;//����
	do
	{
		//ȷ����������
		incresement = incresement / 3 + 1;
		for (int i = 0; i < incresement; i++)//ÿһ�����ֵ��incresement
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
//��������  С->��
void QuickSort(int a[], int start,int end)
{
	int temp = a[start];//��׼��
	int i = start;//��ʼ�±�
	int j = end;//�����±�
	if (i < j)
	{
		while (i < j)
		{
			//���ҵ����ұȻ�׼��С�ġ�
			while (i < j&&a[j] >= temp)
			{
				j--;
			}
			//���
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			//���������ұȻ�׼�������
			while (i < j&&a[i] < temp)
			{
				i++;
			}
			//���
			if (i < j)
			{
				a[j] = a[i];
				j++;
			}
		}
		//�ѻ�׼���ŵ�i=j��λ��
		a[i] = temp;
		//�ݹ����   ����벿�ֺ��Ұ벿�ֿ�������
		QuickSort(a, start, i - 1);
		QuickSort(a, i + 1, end);
	}

}
//��������
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
//�鲢  ����������   �ϲ��㷨  ��С����
void Merge(int a[], int start, int end, int mid, int*temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int lenth = 0;//��ʾ�����ռ��ж��ٸ�Ԫ��
	//�ϲ�������������
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
	//��ȷ��˭���ȴ�
	//i������к����Ԫ��
	while (i_start <= i_end)
	{
		temp[lenth] = a[i_start];
		i_start++;
		lenth++;
	}	//j������к����Ԫ��
	while (j_start < j_end)
	{
		temp[lenth] = a[j_start];
		lenth++;
		j_start++;
	}

	//�����ռ��е����ݸ��ǵ�ԭ���ռ�
	for (int i = 0; i < lenth; i++)
	{
		a[start + i] = temp[i];
	}
}
//�鲢����
void MergeSort(int a[], int start, int end, int *temp)//�����ռ�
{
	//����
	if (start >= end)
	{
		return;
	}
	//��һ�η���
	int mid = (start + end) / 2;
	//������߷���
	MergeSort(a, start, mid, temp);
	//�����ұ߷���
	MergeSort(a, mid+1,end, temp);

	//�ϲ�
	Merge(a, start, end,mid,temp);
}
void MySwap(int arr[], int a,int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

}

//@param arr ������������
//@param index �������Ľ����±�
//@param len  ����ĳ���
void HeadAdjust(int a[], int index, int  len)
{
	//�ȱ��浱ǰ�����±�
	int max = index;
	//���ֵ�ǰ�������Һ��ӵ������±�
	int lchild = 2 * index + 1;//   �±��0��ʼ��
	int rchild = 2 * index + 2;
	if (lchild < len&&a[lchild] > a[max])
	{
		max = lchild;
	}
	if (rchild<len&&a[rchild]>a[max])
	{
		max = rchild;
	}
	if (max != index)//˵��max�仯��
	{
		//�������õ�����
		MySwap(a, max, index);
		HeadAdjust(a, max, len);//����Maxλ��
	}
}
//������
void HeapSort(int a[], int len)
{
	//��ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		HeadAdjust(a, i, len);
	}
	//��ʼ��������ڶѶ�������


	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	for (int i = len - 1; i >= 0; i--)
	{
		MySwap(a,0,len);
		HeadAdjust(a, 0, i);
	}


}
