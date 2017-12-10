#include"CircleList.h"

//��д�������ṹ�������API
CircleLinkList* Init_lst()
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;

}
//���뺯��
void Insert_lst(CircleLinkList*clist, int pos, CircleLinkNode*data)
{
	if (clist == NULL)return;
	if (data == NULL)return;
	if (pos<0 || pos>clist->size)
	{
		pos = clist->size;
	}
	//����
	//����λ�ò��ҽ��
	//����ָ�����
	CircleLinkNode* pCurren = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}
	//������������
	data->next = pCurren->next;
	pCurren->next = data;
	clist->size++;
}
//��õ�һ��Ԫ��
CircleLinkNode*Front_lst(CircleLinkList*clist)
{

	return clist->head.next;
}

//����λ��ɾ��
void Remove_pos_lst(CircleLinkList*clist, int pos)
{
	if (clist == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= clist->size)
	{
		return;
	}
	//����pos�ҽڵ�
	CircleLinkNode*pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	clist->size--;
}
//����ֵȥɾ��   �����Ķ��ǵ�ַ   ���û��Լ�ȥɾ����ͨ���ص�����
void Remove_value_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare)
{

	if (clist == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return; 
	}
	
	//ѭ������  ������һֱѭ��
	CircleLinkNode*pPrev = &(clist->head);//�ӵ�һ����㿪ʼ��ͷ���û��ֵ
	CircleLinkNode* pCurrent = pPrev->next;//����һ��
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;//�ҵ����ֵ����ǰһ�� �ͺ�һ���м�ɾ�����ֵ 
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;//����һ��
	}
}
//���������
int GetSize_lst(CircleLinkList*clist)
{
	return clist->size;
}
//���� ����ֵ
int Find_CircleList_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare)
{
	if (clist == NULL)
	{
		return -1;
	}

	if (data == NULL)
	{
		return -1;
	}
	int flag = -1;
	CircleLinkNode*pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}

	return flag;
}
//��ӡ���
void Print_CircleLinkList_lst(CircleLinkList*clist, PrintNode print)
{
	if (clist == NULL)
	{
		return;
	}
	//����ָ�����
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++)
	{
		if (pCurrent == &(clist->head))
		{
			pCurrent = pCurrent->next;
			cout << "--------------" << endl;
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}

}
//�ͷ��ڴ�
void FreeSpace_lst(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}
//�ж��Ƿ�Ϊ��
int IsEmpty_lst(CircleLinkList*clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_FALSE;
	}
	return CIRCLELINKLIST_TRUE;
}
