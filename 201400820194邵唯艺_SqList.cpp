///#include<stdafx.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <math.h>
#include<conio.h>
#include<string.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define  ERROR 0
#define OVERLOAD -2
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;

}SqList;

Status ListInit_Sq(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem) exit(OVERLOAD);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	cout << "Initialize sqlist\n";
	return OK;
};
Status  ListInsert_Sq(SqList &L, int i, ElemType e)///表示插在ai的位置
{
	ElemType *newbase, *p, *q;
	if (i<1 || i>L.length + 1) return ERROR;///注意此处的指标是从0开始的
	if (L.length >= L.listsize)
	{
		newbase = (ElemType *)malloc((L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if (!newbase) exit(OVERLOAD);
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	p = L.elem + i - 1;
	q = L.elem + L.length - 1;
	for (q; q >= p; --q) { *(q + 1) = *q; }
	*p = e;
	++L.length;
	cout << "Insert elem " << e << " before a" << i << ".\n";
	return OK;
};
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	if (i<1 || i>L.length) return ERROR;
	ElemType *p, *q;
	q = L.elem + L.length - 1;
	p = L.elem + i - 1;
	e = *p++;
	for (p; p <= q; ++p) *(p - 1) = *p;
	L.length--;
	cout << "Delete elem a" << i << ".\n";
	return OK;
};
Status ShowList(SqList &L)
{
	cout << "L : ";
	for (int i = 0; i<L.length; ++i)
	{
		if (i<L.length - 1)
			cout << L.elem[i] << " ->";
		else
			cout << L.elem[i] << " ";
	}

	cout << endl;
	return OK;
};

int LocateElem(SqList L,ElemType e,Status(* compare)(ElemType,ElemType))
{
    int i=1;
   ElemType *p=L.elem;
   while(i<=L.length&&(!compare(*(p+i-1),e)) i++;
   if(i>=L.length) return 0;
   else return i;

};

Status MergeList(SqList La,SqList Lb,SqList &Lc)///就地合并，按顺序
{
    ElemType*p,*q,*plast,*qlast,*newbase;
    Lc.listsize=La.listsize+Lb.listsize;
    newbase=(ElemType *) malloc((La.listsize+Lb.listsize)*sizeof(ElemType));
    if(!newbase) exit(-2);
    Lc.elem=newbase;
    p=La.elem;q=Lb.elem;
    plast=La.elem+L.length-1;
    qlast=Lb.elem+L.length-1;
    int i=0;
    while(p<=plast&&q<=qlast)
    {
        if(*p<=*q)
        { newbase[i++]=*p;p++;}
        else
        { newbase[i++]=*q;q++;}
    }

    while(p<=plast){newbase[i++]=*p;p++;}
    while(q<=qlast){newbase[i++]=*q;q++;}
    Lc.length=La.length+Lb.length;
    return OK;
};

int compare(ElemType a,ElemType b)
{ if(a==b) return 1;
  else return 0;
}

int main()
{
	SqList L;
	ElemType e;
	ListInit_Sq(L);
	ListInsert_Sq(L, 1, 1);
	ShowList(L);
	ListInsert_Sq(L, 1, 2);
	ShowList(L);
	ListInsert_Sq(L, 3, 3);
	ShowList(L);
	ListDelete_Sq(L, 1, e);
	ShowList(L);
	_getch();
	return 0;
}
