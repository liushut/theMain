#include"stack.h"
//初始化
SqeStack*Init_Stack()
{
	SqeStack* stack = (SqeStack*)malloc(sizeof(SqeStack));
	for (int i = 0; i < 1024; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//入栈
void Push_Stack(SeqStack*stack, void* data)
{
	if (data == NULL)
	{
		return;
	}
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 1024)
	{
		return;
	}
	stack->data[stack->size] = data;
	stack->size++;
}
//返回栈顶元素
void*Top_Stack(SeqStack*stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size-1];
}
//出栈
void Pop_Stack(SeqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	stack->data[stack->size - 1] = NULL;
	stack->size--;
}
//判断是否为空
int IsEmpty(SeqStack*stack)
{
	if (stack == NULL)
	{
		return 1;
	}
	if (stack->size == 0)
	{
		return 1;
	}
	return 0;
}
//返回栈中元素个数
int Size_Stack(SeqStack*stack)
{
	return stack->size;
}
//清空栈
void Clear_Stack(SeqStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	for (int i = 0; i < stack->size; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
}
//销毁
void Free_Stack(SeqStack*stack)
{
	if (stack != NULL)
	{
		return;
	}
	free(stack);
	
}

LinkStack* Init_LinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next = NULL;
	stack->size = 0;
	return stack;
}
//入栈
void Push_LinkStack(LinkStack*stack,LinkStackNode*data)
{
	if (data == NULL)
	{
		return;
	}
	if (stack == NULL)
	{
		return; 
	}
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;

}

//出栈
void Pop_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	LinkStackNode*pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}
//返回栈顶
LinkStackNode* Top_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->head.next;
}
//返回栈中元素个数
int Size_LinkStack(LinkStack*stack)
{
	return stack->size;
}
//清空
void Clear_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	//这里就不要delete内存。不归我管。
	stack->head.next = NULL;
	stack->size = 0;
}
//销毁
void Free_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}



//初始化
SeqQueue* Init_SeqQueue()
{
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;
	return queue;
}
//入队
void Push_SeqQueue(SeqQueue*queue, void* data)
{
	//数组左边当对头  从0位置开始
	if (queue == NULL)
	{
		return;
	}
	if (queue->size > MAX_SIZE)
	{
		return;
	}
	if (data = NULL)
	{
		return;
	}
	queue->data[queue->size] = data;
	queue->size++;
}
//返回对头元素
void* Front_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	if (queue->size == 0)
	{
		return NULL;
	}
	return queue->data[0];
}
//出队列
void Pop_SeqQueue(SeqQueue*queue)
{
	//需要移动元素
	if (queue == NULL)
	{
		return;
	}
	if (queue->size == 0)
	{
		return;
	}
	for (int i = 0; i < queue->size - 1; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}
//返回队尾的元素
void* Back_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	if (queue->size == NULL)
	{
		return NULL; 
	}

	return queue->data[queue->size-1];

}
//返回大小
int Size_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->size;
}
//清空队列。
void Clear_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return;
	}
	for (int i = 0; i < queue->size; i++)
	{
		queue->data[i] = NULL;
	}
	queue->size = 0;

}
//销毁
void Free_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
}
