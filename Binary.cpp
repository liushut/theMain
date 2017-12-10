#include<iostream>
using namespace std;
int num = 0;

typedef struct LinkStackNode
{
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct BinaryNode
{
	char data;
	struct BinaryNode* lchilde;
	struct BinaryNode* rchilde;
}BinaryNode;
//往栈中放的节点
typedef struct StackNode
{
	LinkStackNode node;
	BinaryNode*root;
	int flag;

}StackNode;
typedef struct LinkStack
{
	LinkStackNode head;
	int size;
}LinkStack;

//递归遍历
void Recursion_TT(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//先访问根节点
	cout << root->data;
	//在遍历左
	Recursion_TT(root->lchilde);
	//在遍历右
	Recursion_TT(root->rchilde);
}
void FreeTree(BinaryNode*root)
{
	if (root != NULL)
	{
		return;
	}
	FreeTree(root->lchilde);
	FreeTree(root->rchilde);

	//释放当前
	free(root);
}
void Caculata(BinaryNode* root)
{
	if (root == NULL)return;
	if (root->lchilde == NULL && root->rchilde == NULL)
	{
		num++;
	}
	//左
	Caculata(root->lchilde);

	Caculata(root->rchilde);

}
BinaryNode* Copy_BinaryTree(BinaryNode* root)
{
	if (root == NULL)return NULL;

	BinaryNode* lchidl = Copy_BinaryTree(root->lchilde);
	BinaryNode* rchidl = Copy_BinaryTree(root->rchilde);
	//创建节点
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->data = root->data;
	newnode->lchilde = lchidl;
	newnode->rchilde = rchidl;
	return newnode;

}
void  Create_BinaryTree()
{
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	
	//建立节点关系
	node1.lchilde = &node2;
	node1.rchilde = &node6;

	node2.rchilde = &node3;

	node3.lchilde = &node4;
	node3.rchilde = &node5;

	node6.rchilde = &node7;
	node7.lchilde = &node8;
	/*cout << &node1 << endl;
	
	Recursion_TT(&node1);
	
	Caculata(&node1);
	cout << "num" <<  &node1 << endl;
	BinaryNode*root= Copy_BinaryTree(&node1);
	Recursion_TT(root);

	FreeTree(root);
*/
	
}
void Recursion(BinaryNode*root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << endl;
	Recursion(root->lchilde);
	Recursion(root->rchilde);
}
BinaryNode* CreateTree()
{
	char ch;
	cin >> ch;
	BinaryNode* node;
	BinaryNode* lchild;
	BinaryNode* rchild;
	if (ch == '#')
	{
		node = NULL;
	}
	else
	{

		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->data = ch;
		node->lchilde = CreateTree();
		node->rchilde = CreateTree();
		
	}
	return node;
}
int main()
{
	BinaryNode* root = CreateTree();
	Recursion(root);

	return 0;
}