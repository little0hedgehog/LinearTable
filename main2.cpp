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
//方法一
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

//假设有两个按元素值递增次序排序的线性表，均以单链表形式存储
//请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表
//并要求利用原来两个单链表的结点存放归并后的单链表
void MergeList(LinkList &L, LinkList &M)
{
	LNode *l,*m,*rl,*rm;
	l = L->next;
	m = M->next;
	L->next = NULL;
	while (l != NULL && m != NULL)
	{
		if (l->data <= m->data)
		{
			rl = l->next;
			l->next = L->next;
			L->next = l;
			l = rl;
		}
		else
		{
			rm = m->next;
			m->next = L->next;
			L->next = m;
			m = rm;
		}
	}
	if (l != NULL)
		m = l;
	while (m != NULL)
	{
		rm = m->next;
		m->next = L->next;
		L->next = m;
		m = rm;
	}
	free(M);
}

// 已知两个链表A和B分别表示两个集合，其元素递增排列。
//编写一个函数，求A和B的并集，并存放在A链表中
void UList(LinkList &L, LinkList &M)
{
	LNode *l, *m, *rl, *rm,*u;
	l = L->next;
	m = M->next;
	L->next = NULL;
	while (l != NULL && m != NULL)
	{
		if (l->data == m->data)
		{
			rl = l->next;
			l->next = L->next;
			L->next = l;
			//printf("%d ", L->next->data);
			l = rl;
			u = m;
			rm = m->next;
			m = rm;
			free(u);
		}
		else if (l->data < m->data)
		{
			u = l;
			rl = l->next;
			l = rl;
			free(u);
		}
		else if (l->data > m->data)
		{
			u = m;
			rm = m->next;
			m = rm;
			free(u);
		}
	}
	if (l != m)
		m = l;
	while (m != 0)
	{
		u = m;
		m = m->next;
		free(u);
	}
	//L->next = NULL;
	free(M);
}

//有一个代表头结点的单链表，在不改变链表的前提下，设计一个尽可能高效的算法
//查找链表中倒数第K个位置上的结点，若查找成功，输出该结点的data域并返回1；否则只返回0
int SearchList(LinkList &L, int k)
{
	LNode *s,*p;
	int i=1;
	s = L->next;
	p = L->next;
	while (i <= k)
	{
		if (p == NULL)
		{
			printf("没有这个位置\n");
			return 0;
		}
		else
		{
			s = s->next;
			i++;
		}
	}
	while (s != NULL)
	{
		s = s->next;
		p = p->next;
	}
	printf("%d", p->data);
	return 1;
}

//设str1和str2是分别指向两个单词所在单链表的头结点，链表结构是data|next
//设计一个在时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置
int PosList(LinkList &L, LinkList &M)
{
	int i = 0;
	int j = 0;
	int a = 0;
	LNode *l, *m;
	l = L->next;
	m = M->next;
	while (l != 0)
	{
		l = l->next;
		i++;
	}
	while (m != 0)
	{
		m = m->next;
		j++;
	}
	if (i > j)
	{
		l = L->next;
		m = M->next;
		a = i - j;
		for (a; a > 0; a--)
			l = l->next;
		a = 1;
		while (m != NULL)
		{
			if (l == m)
			{
				printf("共同后缀的起始位置在第一个序列的第%d位，第二个序列的第%d位",i-j+a,a);
				return 1;
			}
			l = l->next;
			m = m->next;
			a++;
		}
	}
	else
	{
		l = L->next;
		m = M->next;
		a = j - i;
		for (a; a > 0; a--)
			m = m->next;
		a = 1;
		while (l != NULL)
		{
			if (l->data == m->data)
			{
				printf("共同后缀的起始位置在第一个序列的第%d位，第二个序列的第%d位",a , i - j + a);
				return 1;
			}
			l = l->next;
			m = m->next;
			a++;
		}
	}
	printf("没有公共后缀\n");
	return 0;
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
	LinkList L,M;
	//LNode *temp,*test;
	CreatList2(L);
	CreatList1(M);
	//DeleList(L, 15);
	//BInsert(L, 10, 11);
	PrintfList(L);
	//SearchList(L, 4);
	//num = SizeList(L);
	PrintfList(M);
	PosList(L, M);
	//UList(L, M);
	//printf("%d", num);
	//DelexList(L, 9);
	//DeleZXList(L, 9);
	//PrintfList(L);
	//DeleteMin(L);
	//IVList2(L);
	//PrintfList(L);
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