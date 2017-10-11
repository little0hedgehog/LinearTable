//2017.10.07 ѧϰ˳���ĳ���
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>//Ҳ������malloc.h�滻 ����malloc����
#define InitSize 50//���ȵĳ�ʼ����
typedef int ElemType;//����Ԫ������
typedef struct {
	ElemType *data;//ָʾ��̬���������ָ��
	int MaxSize;//������������
	int length;//���鵱ǰԪ�ظ���
}SeqList;//��̬��������˳�������Ͷ���

//��Ԫ��e������е�i��λ��
int ListInsert(SeqList *l, int i, ElemType e)//����ط���Ҫ������ָ�봫��length
{
	int j;
	if (i<1 || i>l->MaxSize + 1 || l->length>l->MaxSize)
		return -1;
	else
	{
		for (j = l->length; j >= i; j--)
		{
			l->data[j] = l->data[j - 1];
		}
		l->data[i - 1] = e;
		l->length++;
		return 1;
	}
}

//ɾ��˳����е�i��λ�õ�Ԫ��
int DeleteList(SeqList *l, int i)
{
	int j;
	if (i<1 || i>l->MaxSize || l->length<1)
		return -1;
	else
	{
		for (j = i; j <= l->length; j++)
		{
			l->data[j - 1] = l->data[j];
		}
		l->length--;
		return 1;
	}
}

//����˳����е�һ��Ԫ��ֵ����e��Ԫ�أ�����������λ
int LocateElem(SeqList *l, ElemType e)
{
	int i = 0;
	for (i = 0; i <= l->length - 1; i++)
	{
		if (l->data[i] == e)
		{
			printf("�ҵ������ڵ�%dλ", i + 1);
			return 1;
		}
	}
	return -1;
}

//�������,�����ǰ�����е�������ЧԪ��
void PrintList(SeqList *l)
{
	int i;
	printf("��ǰ����Ϊ:");
	for (i = 0; i<l->length; i++)
	{
		printf("%d ", l->data[i]);//��������
	  //printf("%c",l->data[i]);//�ַ�����
	}
	printf("\n");
}

//��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ�����
//��˳���Ϊ������ʾ������Ϣ���˳�����
int test1(SeqList *l)
{
	int i, temp, pos;
	if (l->length == 0)
	{
		printf("����!");
		return -1;
	}
	else
	{
		temp = l->data[0];
		pos = 0;
		for (i = 1; i<l->length; i++)
		{
			if (temp>l->data[i])
			{
				temp = l->data[i];
				pos = i;
			}
		}
		DeleteList(l, pos + 1);
		ListInsert(l, l->length + 1, l->data[l->length - 1]);
		return temp;
	}
}

//���һ����Ч���㷨����˳��������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
void test2(SeqList *l)
{
	int i;
	ElemType temp;
	for (i = 0; i<l->length / 2; i++)
	{
		temp = l->data[i];
		l->data[i] = l->data[l->length - 1 - i];
		l->data[l->length - 1 - i] = temp;
	}
}

//����Ϊn�����б�L����дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨
//���㷨ɾ�����Ա�������ֵΪX������Ԫ��
void test3(SeqList *l, ElemType e)
{
	int i;
	int j = 0;
	for (i = 0; i<l->length; i++)
	{
		if (l->data[i] != e)
		{
			l->data[j] = l->data[i];
			j++;
		}
	}
	l->length = j;
}

//��˳�����ɾ����ֵ�ڸ���ֵS��T֮��(Ҫ��S<T)������Ԫ�أ����S��T���������
//˳���Ϊ������ʾ������Ϣ���˳�����
int test4(SeqList *l, ElemType s, ElemType t)
{
	int i;
	int j = 0;
	if (l->length == 0 || s >= t)
	{
		printf("ʧ����!\n");
		return -1;
	}
	else
	{
		for (i = 0; i<l->length; i++)
		{
			if (l->data[i]<s || l->data[i]>t)
			{
				l->data[j] = l->data[i];
				j++;
			}
		}
		l->length = j;
		return 1;
	}
}

//������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ���е�����Ԫ�ص�ֵ����ͬ
void test5(SeqList *l)
{
	int i;
	int j = 1;
	for (i = 1; i<l->length; i++)
	{
		if (l->data[i] != l->data[i - 1])
		{
			l->data[j] = l->data[i];
			j++;
		}
	}
	l->length = j;
}

//����������˳���ϲ���һ���µ�����˳������ɺ������ؽ��˳���
SeqList test6(SeqList *l, SeqList *m, SeqList *k)
{
	int i = 0;//l
	int j = 0;//m
	int t;
	for (t = 0;; t++)
	{
		if (i != l->length && j != m->length)
		{
			if (l->data[i]<m->data[j])
			{
				k->data[t] = l->data[i];
				i++;
			}
			else
			{
				k->data[t] = m->data[j];
				j++;
			}
		}
		else
			break;
	}
	if (i == l->length)
	{
		for (; j<m->length; t++, j++)
			k->data[t] = m->data[j];
	}
	if (j == m->length)
	{
		for (; i<l->length; t++, i++)
			k->data[t] = l->data[i];
	}
	k->length = t;

	return *k;
}

//��һ��˳����Ե�mλԪ��Ϊ���ޣ��ѵ�1��M-1λԪ�����M�����һλԪ�ؽ���λ��
void test7(SeqList *l, int m)
{
	int i;
	ElemType temp;
	for (i = 0; i<l->length / 2; i++)//�Ȱ�Ԫ��ȫ������
	{
		temp = l->data[i];
		l->data[i] = l->data[l->length - 1 - i];
		l->data[l->length - 1 - i] = temp;
	}
	for (i = 0; i<(l->length - m) / 2; i++)
	{
		temp = l->data[i];
		l->data[i] = l->data[l->length - m - i];
		l->data[l->length - m - i] = temp;
	}
	for (i = l->length - m + 1; i<(2 * l->length - m + 1) / 2; i++)
	{
		temp = l->data[i];
		l->data[i] = l->data[l->length - 1 - i + l->length - m + 1];
		l->data[l->length - 1 - i + l->length - m + 1] = temp;
	}
}

//���Ա���Ԫ�ص��������Ұ�˳��洢�ڼ�����ڡ�Ҫ�����һ���㷨���������ʱ���ڱ��в�����ֵΪX��Ԫ��
//���ҵ���������Ԫ��λ�û��������Ҳ���������뵽������ʹ����Ԫ���Ե�������
void test8(SeqList *l, ElemType e)
{
	int left = 0;
	int right = l->length - 1;
	int mid, t, i;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (l->data[mid] == e)
		{
			t = l->data[mid + 1];
			l->data[mid + 1] = e;
			l->data[mid] = t;
			break;
		}
		else if (l->data[mid]<e)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (right<left)
	{
		for (i = l->length - 1; i>right; i--)
		{
			l->data[i + 1] = l->data[i];
		}
		l->data[i + 1] = e;
		l->length++;
	}
}

//һ������ΪL����������S�����ڵ�L/2������ȡ������λ�õ�����ΪS����λ��������������������A��B
//���һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨���ҳ���������A��B����λ��
int test9(SeqList *l, SeqList *m)
{
	int sa = 0, ma, da = l->length - 1, sb = 0, mb, db = m->length - 1;
	if (l->length == 1 && m->length == 1)
		return l->data[0] < m->data[0] ? l->data[0] : m->data[0];
	else
	{
		ma = (sa + da) / 2;
		mb = (sb + db) / 2;
	}
	while (sa != da || sb != db)
	{
		if (l->data[ma] == m->data[mb])
			return l->data[ma];
		else
		{
			if (l->data[ma]<m->data[mb])
			{
				if ((sa + da) % 2 == 0)//Ԫ�ظ���Ϊ����
				{
					sa = ma;//����A�м����ǰ�Ĳ��ֲ��ұ����м��
					db = mb;//����B�м���Ժ�Ĳ��ֲ��ұ����м��
				}
				else//Ԫ�ظ���Ϊż��
				{
					sa = ma + 1;//����A�м�㼰�м����ǰ�Ĳ���
					db = mb;//����B�м���Ժ�Ĳ��ֲ��ұ����м��
				}
			}
			else
			{
				if ((sb + db) % 2 == 0)//Ԫ�ظ���Ϊ����
				{
					sb = mb;
					da = ma;
				}
				else//Ԫ�ظ���Ϊż��
				{
					sb = mb + 1;
					da = ma;
				}
			}
		}
		ma = (sa + da) / 2;
		mb = (sb + db) / 2;
	}
	return l->data[ma]<m->data[mb] ? l->data[ma] : m->data[mb];
}

//��������n��Ԫ�أ���һ��Ԫ���������г��ֵĴ���>n/2��������Ԫ��Ϊ�����е���Ԫ�ء�������һ������A
//���һ�������ܸ�Ч���㷨���ҳ�A����Ԫ�ء��������������Ԫ�أ��������-1
int test10(SeqList *l)
{
	int i,n;
	int e;
	e = l->data[0];
	n = 1;
	for (i = 1; i < l->length; i++)
	{
		if (l->data[i] == e)
			n++;
		else
		{
			if (n > 0)
				n--;
			else
			{
				if (n == 0)
				{
					e = l->data[i];
					n++;
				}
			}
		}
	}
	if (n > 0)
	{
		n = 0;
		for (i = 0; i < l->length; i++)
		{
			if (l->data[i] == e)
				n++;
		}
	}
	if (n > l->length / 2)
		return e;
	return -1;
}

int main()
{
	//-----��ʼ��һ��˳���------//
	int i, j, k, m;
	SeqList L;
	L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
	L.length = 0;
	L.MaxSize = InitSize;
	for (i = 0; i <= 4; i++)
	{
		L.data[i] = i;//������
		//L.data[i]=97+i;//�ַ�����
		L.length++;
	}
	PrintList(&L);
	/*
	//----����test1-----
	m=test1(&L);
	printf("��ɾԪ�ص�ֵΪ%d\n",m);
	PrintList(&L);
	//----����test2-----
	test2(&L);
	PrintList(&L);
	//----����test3-----
	test3(&L,6);
	PrintList(&L);
	printf("��ǰ���г���Ϊ%d",L.length);
	//----����test4-----
	test4(&L,3,2);
	PrintList(&L);
	//----����test5-----
	test5(&L);
	PrintList(&L);
	//----����test6-----
	P=test6(&L,&N,&P);
	PrintList(&P);
	//----7 8 9 10�Ĳ�������д��ȥ���� �õ�ʱ����д��----
	//----����ListInsert-----
	j=ListInsert(&L,2,'w');//Ҫע����&L����Ϊ������ָ��
	printf("\n%d,%d\n",j,L.length);
	PrintList(&L);
	//---����DeleteList-----
	k=DeleteList(&L,2);
	printf("\n%d,%d\n",k,L.length);
	PrintList(&L);
	//---����LocateElem-----
	printf("\n");
	LocateElem(&L,'j');
	*/

	system("pause");
	return 0;
}
