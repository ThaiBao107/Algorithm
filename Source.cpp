#include<iostream>
#include<fstream>
#define MAX 100

using namespace std;

void read_file(int a[][MAX], int& n)
{
	ifstream inF;
	inF.open("data.txt", ios_base::in);
	if (inF.is_open())
	{
		int b;
		inF >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				inF >> b;
				a[i][j] = b;
			}
		inF.close();
	}
	else
		cout << "Khong mo duoc file" << endl;

}



void duyet_mang(int a[][MAX], int n)
{
	cout << "Danh sach" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}




void TaoE(int E1[], int E2[], int wE[], int& nE, int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
		}
}




void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}




void sapxep(int E1[], int E2[], int wE[], int nE)
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
				swap(wE[i], wE[j]);
			}
}

int TonTai(int D[], int nT, int k)
{
	for (int i = 0; i < nT; i++)
		if (D[i] == k) return 1;
	return 0;
}


void Kruskal(int E1[], int E2[], int wE[], int& nE, int T1[], int T2[], int wT[], int& nT, int a[][MAX], int& n)
{
	TaoE(E1, E2, wE, nE, a, n);
	sapxep(E1, E2, wE, nE);
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(T1, nT, E1[i]) == 1 && TonTai(T2, nT, E2[i]) == 1) continue;
		if (TonTai(T1, nT, E2[i]) == 1 && TonTai(T2, nT, E1[i]) == 1) continue;
		T1[nT] = E1[i];		
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1) break;
	}
}


void duyet_Kruskal(int T1[], int T2[], int wT[], int nT)
{
	int tong = 0;
	cout << "Kruskal" << endl;
	for (int i = 0; i < nT; i++)
	{
		cout << "(" << T1[i] << "," << T2[i] << "): " << wT[i] << endl;
		tong += wT[i];
	}
	cout << "Tong: " << tong << endl;
}



int main()
{
	int choose;
	int a[MAX][MAX];
	int n = 0;
	do
	{
		cout << "---------------MENU----------------------" << endl;
		cout << "1. Doc file                               " << endl;
		cout << "2. Show mang                               " << endl;
		cout << "3. Kruskal                                " << endl;
		cout << "4. EXIT                                   " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 4) break;
			else
				cout << "Nhap sai yeu cua, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			read_file(a, n);
			cout << "Doc file thanh cong" << endl;
			break;
		}
		case 2:
		{
			if (n == 0) cout << "Chua co du lieu" << endl;
			else
			{
				duyet_mang(a, n);
			}
			break;
		}
		case 3:
		{
			if (n == 0) cout << "Chua co du lieu" << endl;
			else
			{
				int E1[MAX];        int T1[MAX];
				int E2[MAX];        int T2[MAX];
				int wE[MAX];        int wT[MAX];
				int nE = 0;			int nT = 0;
				Kruskal(E1, E2, wE, nE, T1, T2, wT, nT, a, n);
				duyet_Kruskal(T1, T2, wT, nT);
			}
			break;
		}
		case 4:
		{
			return 0;
		}
		}
		system("pause");
		system("cls");
	} while (true);
}