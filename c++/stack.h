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
//初始化
SqeStack*Init_Stack();
//入栈
void Push_Stack(SeqStack*stack,void* data);
//返回栈顶元素
void*Top_Stack(SeqStack*stack);
//出栈
void Pop_Stack(SeqStack*stack);
//判断是否为空
int IsEmpty(SeqStack*stack);
//返回栈中元素个数
int Size_Stack(SeqStack*stack);
//销毁
void Free_Stack(SeqStack*stack);
//清空栈
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
//初始化
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack*stack,LinkStackNode*data);

//出栈
void Pop_LinkStack(LinkStack*stack);
//返回栈顶
LinkStackNode* Top_LinkStack(LinkStack*stack);
//返回栈顶元素
int Size_LinkStack(LinkStack*stack);
//清空
void Clear_LinkStack(LinkStack*stack);
//销毁
void Free_LinkStack(LinkStack*stack);


typedef struct SeqQueue
{
	void* data[MAX_SIZE];
	int size;
}SeqQueue;
//初始化
SeqQueue* Init_SeqQueue();
//入队
void Push_SeqQueue(SeqQueue*quueu,void*data);
//返回对头元素
void* Front_SeqQueue(SeqQueue*queue);
//出队列
void Pop_SeqQueue(SeqQueue*queue);
//返回队尾的元素
void*Back_SeqQueue(SeqQueue*queue);
//返回大小
int Size_SeqQueue(SeqQueue*queue);
//清空队列。
void Clear_SeqQueue(SeqQueue*queue);
//销毁
void Free_SeqQueue(SeqQueue*queue);



