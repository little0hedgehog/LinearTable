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

//递归地删除不带头结点的单链表L中所有值为x的结点
void DelexList(LinkList &L, ElemType e)
{
	LNode *p;
	if (L == NULL)
		return;
	else
		if (L->data == e)
		{
			p = L;
			L = L->next;
			free(p);
			DelexList(L, e);
		}
		else
			DelexList(L->next, e);
}

//删除带头结点的单链表L中的所有值为x的结点，并释放空间，假设值为x的结点不唯一
void DeleZXList(LinkList &L, ElemType e)
{
	LNode *q;
	LNode *p = L->next;
	LNode *pre = L;
	while (p != NULL)
	{
		if (p->data == e)
		{
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

//设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
//注意这个函数如果直接传L会把头结点也输出来，所以在传参的时候要传L->next,也就是去掉头结点
void InvertedList(LinkList &L)
{
	if (L->next!= NULL)
	{
		InvertedList(L->next);
	}
	printf("%d ", L->data);
}

//试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）
void DeleteMin(LinkList &L)
{
	LNode *q = L->next;
	LNode *minpre=L;
	int t = q->data;
	while (q->next!= NULL)
	{
		if (q->next->data < t)
		{
			minpre = q;
			t = q->next->data;
		}
		q = q->next;
	}
	minpre->next = (minpre->next)->next;
}

//试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)
//方法一摘结点 前插
void IVList1(LinkList &L)
{
	LNode *s ;
	LNode *p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		s = p->next;
		p->next = L->next;
		L->next = p;
		p= s;
	}
}
//方法二调整指针
void IVList2(LinkList &L)
{
	LNode *p,*t,*r;
	p = L->next;
	r = p->next;
	p->next = NULL;
	while (r != NULL)
	{
		t = p;
		p = r;
		r = p->next;//一定要保留后继指针
		p->next = t;
	}
	L->next = p;
}

//有一个带头结点的单链表L，设计一个算法使其元素递增有序
//方法二
void IncList1(LinkList &L)//这个算法时间复杂度为O(n^2)
{
	LNode *r,*p,*pre;
	p = L->next;
	r = p->next;//r保持*p的后继结点指针，以保证不断链
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//方法二
void IncList2(LinkList &L)//这个算法时间复杂度为O(n*log2 n)比上边的时间复杂度低
{
	LNode *p;
	int i = 0;
	p = L->next;
	int *a = (int*)malloc(sizeof(int));
	while (p!=NULL)
	{
		a[i] = p->data;
		i++;
		p = p->next;
	}
	//然后把数组二分排序，排好序后直接后插建立链表
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
	BInsert(L, 5, 2);
	num = SizeList(L);
	PrintfList(L);
	//printf("%d", num);
	//DelexList(L, 9);
	//DeleZXList(L, 9);
	PrintfList(L);
	//DeleteMin(L);
	IVList2(L);
	PrintfList(L);
	//InvertedList(L->next);//注意这里的参数

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