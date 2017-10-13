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
	BInsert(L, 10, 2);
	num = SizeList(L);
	PrintfList(L);
	printf("%d", num);

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