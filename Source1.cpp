#include<iostream>
using namespace std;
#define MAX 100

void nhap_mang(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ":";
		cin >> a[i];
	}
}

void show_table(int a[], int n)
{
	cout << "Danh sach" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void selection_sort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min_pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[min_pos] > a[j])
			{
				min_pos = j;
			}
		}
		swap(a[min_pos], a[i]);
	}
}


int main()
{
	int a[MAX];
	int n = 0;
	int choose;
	do
	{
		cout << "---------------------MENU--------------------------" << endl;
		cout << "1. Nhap mang                                        " << endl;
		cout << "2. Xuat bang                                        " << endl;
		cout << "3. Sap xep theo tuan toan selection sort             " << endl;
		cout << "4. EXIT                                              " << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Choose: ";
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
		{
			nhap_mang(a, n);
			break;
		}
		case 2:
		{
			if (n != 0)
			{
				show_table(a, n);
			}
			else
				cout << "Chua co dnah sach" << endl;
			break;
		}
		case 3:
		{
			if (n != 0)
			{
				selection_sort(a, n);
				cout << "Sap xep thanh cong" << endl;
				system("cls");
				show_table(a, n);
			}
			else
				cout << "Chua co danh sach" << endl;
			break;
		}
		case 4:
		{
			cout << "EXIT" << endl;
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);
	return 0;
}