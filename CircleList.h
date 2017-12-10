#pragma once
#include<iostream>
using namespace std;

//����С���
#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0
typedef struct CircleLinkNode {
	struct CircleLinkNode* next;
}CircleLinkNode;

//����ṹ��
typedef struct CircleLinkList
{
	CircleLinkNode head;//Ϊʲô����ָ��?  ����new���
	int size;
	//�����Լ�һ��βָ�롣ֱ�ӻ�þͿ��ԡ�
}CircleLinkList;
typedef void(*PrintNode)(CircleLinkNode*);
typedef int(*ComaraNode)(CircleLinkNode*, CircleLinkNode*);
//��д�������ṹ�������API
CircleLinkList* Init_lst();
//���뺯��
void Insert_lst(CircleLinkList*clist, int pos, CircleLinkNode*data);
//��õ�һ��Ԫ��
CircleLinkNode*Front_lst(CircleLinkList*clist);
//����λ��ɾ��
void Remove_pos_lst(CircleLinkList*, int pos);
//����ֵȥɾ��   �����Ķ��ǵ�ַ   ���û��Լ�ȥɾ����ͨ���ص�����
void Remove_value_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare);
//���������
int GetSize_lst(CircleLinkList*clist);
//���� ����ֵ
int Find_CircleList_lst(CircleLinkList*clist, CircleLinkNode*data, ComaraNode compare);
//��ӡ���
void Print_CircleLinkList_lst(CircleLinkList*clist,PrintNode print);
//�ͷ��ڴ�
void FreeSpace_lst(CircleLinkList* clist);
//�ж��Ƿ�Ϊ��
int IsEmpty();





