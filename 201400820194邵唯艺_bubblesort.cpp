#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <math.h>
#include<conio.h>
#include<string.h>
using namespace std;
int bubblesort(int *a, int n)
{

	int number_of_changes = 0;
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j <= i - 1; ++j)
		{

		if (a[j]>a[j + 1])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			number_of_changes++;
		}
		}

	return number_of_changes;

}

int main()
{
	char b[100];
	int a[100];
	printf("请输入数组: ");
	int k = 0;
	while (1)
	{
		cin >> b[k];
		a[k]=(int)b[k]-'0';
		k++;
		if (getchar() == '\n') break;
	}


	int n;
	cout << "请输入需要排序的长度:"; cin >> n;

	if (n>k) { cout << "输入排序数过长,自动修正为数组长度" << endl; n = k; }

	int number_of_changes = bubblesort(a, n);
	cout << "排序后的数组: ";
	for (int i = 0; i<n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "交换次数" << number_of_changes << endl;
	_getch();
	return 0;

}

///int a[10]={5,7,1,2,9,8,6,3,4,0};
///int n=10;
/// 5 7 1 2 9 8 6 3 4 0
///10
