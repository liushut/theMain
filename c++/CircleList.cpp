#include"CircleList.h"

//编写针对链表结构体操作的API
CircleLinkList* Init_lst()
{
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;

}
//插入函数
void Insert_lst(CircleLinkList*clist, int pos, CircleLinkNode*data)
{
	if (clist == NULL)return;
	if (data == NULL)return;
	if (pos<0 || pos>clist->size)
	{
		pos = clist->size;
	}
	//插入
	//根据位置查找结点
	//辅助指针变量
	CircleLinkNode* pCurren = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurren = pCurren->next;
	}
	//新数据入链表
	data->next = pCurren->next;
	pCurren->next = data;
	clist->size++;
}
//获得第一个元素
CircleLinkNode*Front_lst(CircleLinkList*clist)
{

	return clist->head.next;
}

//根据位置删除
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
	//根据pos找节点
	CircleLinkNode*pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;
	clist->size--;
}
//根据值去删除   里面存的都是地址   让用户自己去删除。通过回掉函数
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
	
	//循环链表  不能让一直循环
	CircleLinkNode*pPrev = &(clist->head);//从第一个结点开始，头结点没有值
	CircleLinkNode* pCurrent = pPrev->next;//先走一步
	for (int i = 0; i < clist->size; i++)
	{
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE)
		{
			pPrev->next = pCurrent->next;//找到这个值，从前一个 和后一个中间删除这个值 
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;//先走一步
	}
}
//获得链表长度
int GetSize_lst(CircleLinkList*clist)
{
	return clist->size;
}
//查找 根据值
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
//打印结点
void Print_CircleLinkList_lst(CircleLinkList*clist, PrintNode print)
{
	if (clist == NULL)
	{
		return;
	}
	//辅助指针变量
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
//释放内存
void FreeSpace_lst(CircleLinkList* clist)
{
	if (clist == NULL)
	{
		return;
	}
	free(clist);
}
//判断是否为空
int IsEmpty_lst(CircleLinkList*clist)
{
	if (clist->size == 0)
	{
		return CIRCLELINKLIST_FALSE;
	}
	return CIRCLELINKLIST_TRUE;
}
