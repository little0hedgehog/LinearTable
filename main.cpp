#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElemType;//����Ԫ������

typedef struct LNode {//���嵥����������
	ElemType data;//������
	struct LNode *next;//ָ����
}LNode,*LinkList;

//ͷ�巨��ʼ������
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

//β�巨��ʼ������
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

//����Ų��ҽ��ֵ��ע�ⵥ�����е����ݽ��ĸ���������ͷ��㣩
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

//��ֵ���ұ���
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

//�����,��ֵΪe���½����뵽������ĵ�i��λ����
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

//��������ĵ�i�����ɾ��
void DeleList(LinkList &L,int i)
{
	LNode *p;
	p = GetElem(L, i - 1);
	if (p == NULL)
		printf("û��������\n");
	else
		p->next = (p->next)->next;
}
//�������
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

//�ݹ��ɾ������ͷ���ĵ�����L������ֵΪx�Ľ��
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

//ɾ����ͷ���ĵ�����L�е�����ֵΪx�Ľ�㣬���ͷſռ䣬����ֵΪx�Ľ�㲻Ψһ
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

//��LΪ��ͷ���ĵ�������д�㷨ʵ�ִ�β��ͷ�������ÿ������ֵ
//ע������������ֱ�Ӵ�L���ͷ���Ҳ������������ڴ��ε�ʱ��Ҫ��L->next,Ҳ����ȥ��ͷ���
void InvertedList(LinkList &L)
{
	if (L->next!= NULL)
	{
		InvertedList(L->next);
	}
	printf("%d ", L->data);
}

//�Ա�д�ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ���ĸ�Ч�㷨��������Сֵ�����Ψһ�ģ�
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

//�Ա�д�㷨����ͷ���ĵ�����͵����ã���ν���͵ء���ָ�����ռ临�Ӷ�ΪO(1)
//����һժ��� ǰ��
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
//����������ָ��
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
		r = p->next;//һ��Ҫ�������ָ��
		p->next = t;
	}
	L->next = p;
}

//��һ����ͷ���ĵ�����L�����һ���㷨ʹ��Ԫ�ص�������
//������
void IncList1(LinkList &L)//����㷨ʱ�临�Ӷ�ΪO(n^2)
{
	LNode *r,*p,*pre;
	p = L->next;
	r = p->next;//r����*p�ĺ�̽��ָ�룬�Ա�֤������
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
//������
void IncList2(LinkList &L)//����㷨ʱ�临�Ӷ�ΪO(n*log2 n)���ϱߵ�ʱ�临�Ӷȵ�
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
	//Ȼ���������������ź����ֱ�Ӻ�彨������
}

//����ͷ��β��˳���������
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
	//InvertedList(L->next);//ע������Ĳ���

	//----����GetElem(LinkList &L, int i)----//
	//temp = GetElem(L, 11);
	//if (temp == NULL)
	//	printf("\n�����ڴ˽ڵ�!\n");
	//else
	//	printf("\n%d", temp->data);

	//----����LocateElem(LinkList &L, ElemType e)----//
	/*test = LocateElem(L, 8);
	if (test == NULL)
		printf("\n�����ڴ˽ڵ�!\n");
	else
		printf("\n�ҵ���!");*/

	system("pause");
	return 0;
}