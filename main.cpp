#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElemType;//表内元素类型

typedef struct LNode {//定义单链表结点类型
	ElemType data;//数据域
	struct LNode *next;//指针域
}LNode,*LinkList;

//头插法初始化链表
LinkList CreatList1(LinkList &L)
{
	LNode *l;
	int x = 0;
	//int i = 0;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	//scanf("%d", &x);
	while (x != 10)
	{
		l = (LinkList)malloc(sizeof(LNode));
		l->data = x;
		l->next = L->next;
		L->next = l;
		x++;
		//scanf("%d", &x);
	}
	return L;
}

//尾插法初始化链表
LinkList CreatList2(LinkList &L)
{
	LNode *s,*r;
	int x = 0;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	//scanf("%d", &x);
	while (x != 10)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		x++;
		//scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//按序号查找结点值（注意单链表中的数据结点的个数不包含头结点）
LNode *GetElem(LinkList &L, int i)
{
	int j = 1;
	LNode *p = L->next;
	LNode *t = NULL;
	if (i < 0)
		return t;
	if (i == 0)
		return L;
	while (j != i)
	{
		p = p->next;
		j++;
		if (p->next == NULL&&(j!=i))
		{
			return t;
		}
	}
	return p;
}

//按值查找表结点
LNode *LocateElem(LinkList &L, ElemType e)
{
	LNode *p=L->next;
	LNode *temp = NULL;
	while (p!=NULL)
	{
		if (p->data == e)
			return p;
		else
			p = p->next;
	}
	return temp;
}

//后插结点,把值为e的新结点插入到单链表的第i个位置上
void BInsert(LinkList &L, ElemType e,int i)
{
	LNode *p;
	LNode *s;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = NULL;
	p = GetElem(L, i - 1);
	s->next = p->next;
	p->next = s;
}

//将单链表的第i个结点删除
void DeleList(LinkList &L,int i)
{
	LNode *p;
	p = GetElem(L, i - 1);
	if (p == NULL)
		printf("没有这个结点\n");
	else
		p->next = (p->next)->next;
}
//求表长操作
int SizeList(LinkList &L)
{
	int i=0;
	LNode *s = L->next;
	while (s!=NULL)
	{
		i++;
		s = s->next;
	}
	return i;
}



//按从头到尾的顺序输出链表
void PrintfList(LinkList &L)
{
	LinkList temp = L->next;
	while (temp!= NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int num;
	LinkList L;
	//LNode *temp,*test;
	CreatList2(L);
	PrintfList(L);
	DeleList(L, 15);
	BInsert(L, 10, 2);
	num = SizeList(L);
	PrintfList(L);
	printf("%d", num);

	//----测试GetElem(LinkList &L, int i)----//
	//temp = GetElem(L, 11);
	//if (temp == NULL)
	//	printf("\n不存在此节点!\n");
	//else
	//	printf("\n%d", temp->data);

	//----测试LocateElem(LinkList &L, ElemType e)----//
	/*test = LocateElem(L, 8);
	if (test == NULL)
		printf("\n不存在此节点!\n");
	else
		printf("\n找到啦!");*/

	system("pause");
	return 0;
}