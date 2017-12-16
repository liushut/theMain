#pragma once
#include<iostream>
using namespace std;

//链表小结点
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
typedef struct CircleLinkNode {
	struct CircleLinkNode* next;
}CircleLinkNode;

//链表结构体
typedef struct CircleLinkList
{
	CircleLinkNode head;//为什么不用指针?  不用new结点
	int size;
	//还可以加一个尾指针。直接获得就可以。
}CircleLinkList;
typedef void(*PrintNode)(CircleLinkNode*);
typedef int(*ComaraNode)(CircleLinkNode*, CircleLinkNode*);
//编写针对链表结构体操作的API
CircleLinkList* Init_lst();
//插入函数
void Insert_lst(CircleLinkList*clist, int pos, CircleLinkNode*data);
//获得第一个元素
CircleLinkNode*Front_lst(CircleLinkList*clist);
//根据位置删除
void Remove_pos_lst(CircleLinkList*, int pos);
//根据值去删除   里面存的都是地址   让用户自己去删除。通过回掉函数
void Remove_value_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare);
//获得链表长度
int GetSize_lst(CircleLinkList*clist);
//查找 根据值
int Find_CircleList_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare);
//打印结点
void Print_CircleLinkList_lst(CircleLinkList*clist,PrintNode print);
//释放内存
void FreeSpace_lst(CircleLinkList* clist);
//判断是否为空
int IsEmpty();





