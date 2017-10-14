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
//����һ
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

//������������Ԫ��ֵ����������������Ա����Ե�������ʽ�洢
//���д�㷨��������������鲢Ϊһ����Ԫ��ֵ�ݼ��������еĵ�����
//��Ҫ������ԭ������������Ľ���Ź鲢��ĵ�����
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

// ��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
//��дһ����������A��B�Ĳ������������A������
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

//��һ������ͷ���ĵ������ڲ��ı������ǰ���£����һ�������ܸ�Ч���㷨
//���������е�����K��λ���ϵĽ�㣬�����ҳɹ�������ý���data�򲢷���1������ֻ����0
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
			printf("û�����λ��\n");
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

//��str1��str2�Ƿֱ�ָ�������������ڵ������ͷ��㣬����ṹ��data|next
//���һ����ʱ���Ͼ����ܸ�Ч���㷨���ҳ���str1��str2��ָ����������ͬ��׺����ʼλ��
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
				printf("��ͬ��׺����ʼλ���ڵ�һ�����еĵ�%dλ���ڶ������еĵ�%dλ",i-j+a,a);
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
				printf("��ͬ��׺����ʼλ���ڵ�һ�����еĵ�%dλ���ڶ������еĵ�%dλ",a , i - j + a);
				return 1;
			}
			l = l->next;
			m = m->next;
			a++;
		}
	}
	printf("û�й�����׺\n");
	return 0;
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