#include"stack.h"
//��ʼ��
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
//��ջ
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
//����ջ��Ԫ��
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
//��ջ
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
//�ж��Ƿ�Ϊ��
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
//����ջ��Ԫ�ظ���
int Size_Stack(SeqStack*stack)
{
	return stack->size;
}
//���ջ
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
//����
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
//��ջ
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

//��ջ
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
//����ջ��
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
//����ջ��Ԫ�ظ���
int Size_LinkStack(LinkStack*stack)
{
	return stack->size;
}
//���
void Clear_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	//����Ͳ�Ҫdelete�ڴ档�����ҹܡ�
	stack->head.next = NULL;
	stack->size = 0;
}
//����
void Free_LinkStack(LinkStack*stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
}



//��ʼ��
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
//���
void Push_SeqQueue(SeqQueue*queue, void* data)
{
	//������ߵ���ͷ  ��0λ�ÿ�ʼ
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
//���ض�ͷԪ��
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
//������
void Pop_SeqQueue(SeqQueue*queue)
{
	//��Ҫ�ƶ�Ԫ��
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
//���ض�β��Ԫ��
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
//���ش�С
int Size_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->size;
}
//��ն��С�
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
//����
void Free_SeqQueue(SeqQueue*queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
}
