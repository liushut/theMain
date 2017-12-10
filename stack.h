#pragma once
#include<iostream>
using namespace std;
#define MAX_SIZE 1024
#define MY_FLASE 0
#define MY_TRUE  1
typedef struct SqeStack {
	void* data[1024];
	int size;
}SeqStack;
//��ʼ��
SqeStack*Init_Stack();
//��ջ
void Push_Stack(SeqStack*stack,void* data);
//����ջ��Ԫ��
void*Top_Stack(SeqStack*stack);
//��ջ
void Pop_Stack(SeqStack*stack);
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack*stack);
//����ջ��Ԫ�ظ���
int Size_Stack(SeqStack*stack);
//����
void Free_Stack(SeqStack*stack);
//���ջ
void Clear_Stack(SeqStack*stack);

typedef struct LinkStackNode
{
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode head;
	int size;
}LinkStack;
//��ʼ��
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack*stack,LinkStackNode*data);

//��ջ
void Pop_LinkStack(LinkStack*stack);
//����ջ��
LinkStackNode* Top_LinkStack(LinkStack*stack);
//����ջ��Ԫ��
int Size_LinkStack(LinkStack*stack);
//���
void Clear_LinkStack(LinkStack*stack);
//����
void Free_LinkStack(LinkStack*stack);


typedef struct SeqQueue
{
	void* data[MAX_SIZE];
	int size;
}SeqQueue;
//��ʼ��
SeqQueue* Init_SeqQueue();
//���
void Push_SeqQueue(SeqQueue*quueu,void*data);
//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue*queue);
//������
void Pop_SeqQueue(SeqQueue*queue);
//���ض�β��Ԫ��
void*Back_SeqQueue(SeqQueue*queue);
//���ش�С
int Size_SeqQueue(SeqQueue*queue);
//��ն��С�
void Clear_SeqQueue(SeqQueue*queue);
//����
void Free_SeqQueue(SeqQueue*queue);



