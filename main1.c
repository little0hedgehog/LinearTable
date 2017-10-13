//2017.10.07 学习顺序表的程序
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>//也可以用malloc.h替换 包含malloc函数
#define InitSize 50//表长度的初始定义
typedef int ElemType;//表内元素类型
typedef struct {
	ElemType *data;//指示动态分配数组的指针
	int MaxSize;//数组的最大容量
	int length;//数组当前元素个数
}SeqList;//动态分配数组顺序表的类型定义

//把元素e插入表中第i个位置
int ListInsert(SeqList *l, int i, ElemType e)//这个地方主要是利用指针传递length
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

//删除顺序表中第i个位置的元素
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

//查找顺序表中第一个元素值等于e的元素，并返回其序位
int LocateElem(SeqList *l, ElemType e)
{
	int i = 0;
	for (i = 0; i <= l->length - 1; i++)
	{
		if (l->data[i] == e)
		{
			printf("找到啦，在第%d位", i + 1);
			return 1;
		}
	}
	return -1;
}

//输出测试,输出当前序列中的所有有效元素
void PrintList(SeqList *l)
{
	int i;
	printf("当前序列为:");
	for (i = 0; i<l->length; i++)
	{
		printf("%d ", l->data[i]);//数字型用
	  //printf("%c",l->data[i]);//字符型用
	}
	printf("\n");
}

//从顺序表中删除具有最小值得元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，
//若顺序表为空则显示出错信息并退出运行
int test1(SeqList *l)
{
	int i, temp, pos;
	if (l->length == 0)
	{
		printf("错误!");
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

//设计一个高效的算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O(1)
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

//长度为n的序列表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法
//该算法删除线性表中所有值为X的数据元素
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

//从顺序表中删除其值在给定值S与T之间(要求S<T)的所有元素，如果S或T不合理或者
//顺序表为空则显示出错信息并退出运行
int test4(SeqList *l, ElemType s, ElemType t)
{
	int i;
	int j = 0;
	if (l->length == 0 || s >= t)
	{
		printf("失败啦!\n");
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

//从有序顺序表中删除所有其值重复的元素，使表中的所有元素的值均不同
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

//将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表
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

//将一个顺序表以第m位元素为界限，把第1到M-1位元素与第M到最后一位元素交换位置
void test7(SeqList *l, int m)
{
	int i;
	ElemType temp;
	for (i = 0; i<l->length / 2; i++)//先把元素全都逆置
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

//线性表中元素递增有序且按顺序存储于计算机内。要求设计一个算法完成用最少时间在表中查找数值为X的元素
//若找到将其与后继元素位置互换，若找不到将其插入到表中且使表中元素仍递增有序
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

//一个长度为L的升序序列S，处于第L/2（向上取整）个位置的数称为S的中位数。现有两个升序序列A、B
//设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数
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
				if ((sa + da) % 2 == 0)//元素个数为奇数
				{
					sa = ma;//舍弃A中间点以前的部分并且保留中间点
					db = mb;//舍弃B中间点以后的部分并且保留中间点
				}
				else//元素个数为偶数
				{
					sa = ma + 1;//舍弃A中间点及中间点以前的部分
					db = mb;//舍弃B中间点以后的部分并且保留中间点
				}
			}
			else
			{
				if ((sb + db) % 2 == 0)//元素个数为奇数
				{
					sb = mb;
					da = ma;
				}
				else//元素个数为偶数
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

//设序列有n个元素，若一个元素在序列中出现的次数>n/2，则称这个元素为此序列的主元素。假设有一个序列A
//设计一个尽可能高效的算法，找出A的主元素。若存在则输出主元素；否则输出-1
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
	//-----初始化一个顺序表------//
	int i, j, k, m;
	SeqList L;
	L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
	L.length = 0;
	L.MaxSize = InitSize;
	for (i = 0; i <= 4; i++)
	{
		L.data[i] = i;//数字用
		//L.data[i]=97+i;//字符型用
		L.length++;
	}
	PrintList(&L);
	/*
	//----测试test1-----
	m=test1(&L);
	printf("被删元素的值为%d\n",m);
	PrintList(&L);
	//----测试test2-----
	test2(&L);
	PrintList(&L);
	//----测试test3-----
	test3(&L,6);
	PrintList(&L);
	printf("当前序列长度为%d",L.length);
	//----测试test4-----
	test4(&L,3,2);
	PrintList(&L);
	//----测试test5-----
	test5(&L);
	PrintList(&L);
	//----测试test6-----
	P=test6(&L,&N,&P);
	PrintList(&P);
	//----7 8 9 10的测试用例写上去好乱 用的时候再写吧----
	//----测试ListInsert-----
	j=ListInsert(&L,2,'w');//要注意是&L，因为传的是指针
	printf("\n%d,%d\n",j,L.length);
	PrintList(&L);
	//---测试DeleteList-----
	k=DeleteList(&L,2);
	printf("\n%d,%d\n",k,L.length);
	PrintList(&L);
	//---测试LocateElem-----
	printf("\n");
	LocateElem(&L,'j');
	*/

	system("pause");
	return 0;
}
