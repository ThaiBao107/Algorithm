#include<iostream>
using namespace std;
#define MAX 100
void nhapmang(int a[], int& n)
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


int main()
{
	int a[MAX];
	int n = 0;
	nhapmang(a, n);
	system("cls");
	show_table(a, n);
	return 0;
}