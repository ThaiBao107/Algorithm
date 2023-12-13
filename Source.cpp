#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20

struct NODE
{
	int data;
	NODE* link;
};


struct Queue
{
	NODE* first;
	NODE* last;
};


NODE* init_NODE(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->link = NULL;
	return p;
}


void init_Queue(Queue &q)
{
	q.first = NULL;
	q.last = NULL;
}


void Push(Queue& q, NODE* p)
{
	if (q.first == NULL)
		q.first = q.last = p;
	else
	{
		q.last->link = p;
		q.last = p;
	}
}


void Pop(Queue& q, int& x)
{
	if (q.first == NULL)
		return;
	else
	{
		x = q.first->data;
		NODE* h = q.first;
		q.first = q.first->link;
		delete h;
	}
}


int read_file_SL()
{
	int n = 0;
	ifstream inF;
	inF.open("MTK.txt", ios_base::in);
	if (inF.is_open())
	{
		char b;
		do
		{
			inF >> b;
			n++;
		} while (b != '0' && b != '1');
		inF.close();
	}
	else
		cout << "khong mo duoc file" << endl;
	return n - 1;
}


void read_file(int a[][MAX], int& n)
{
	ifstream inF;
	inF.open("MTK.txt", ios_base::in);
	if (inF.is_open())
	{
		char c; int b;
		n = read_file_SL();
		for (int i = 0; i < n; i++)
			inF >> c;

		while (!inF.eof())
		{
			for(int i = 0;i<n;i++)
				for (int j = 0; j < n; j++)
				{
					inF >> b;
					a[i][j] = b;
				}
		}
		inF.close();
		cout << "Doc file thanh cong" << endl;
	}
	else
		cout << "khong doc duoc file" << endl;
}


void show_graph(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}		
}


void init_dinhchuaxet(int C[], int n)
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

int bfs[MAX];

void Browse_BFS(int a[][MAX], int n, int k)
{
	int C[MAX];
	int count_bfs = 0;
	Queue q;
	init_Queue(q);
	init_dinhchuaxet(C, n);
	NODE* p = init_NODE(k);
	Push(q, p);
	C[k] = 0;
	while (q.first != NULL)
	{
		int x;
		Pop(q, x);
		bfs[count_bfs++] = x;
		for (int i = 0; i< n; i++)
			if (C[i] == 1 && a[x][i] == 1)
			{
				NODE* b = init_NODE(i);
				Push(q, b);
				C[i] = 0;
			}
	}
}


void browse_graph(int n)
{
	for (int i = 0; i < n; i++)
		cout << bfs[i] << " ";
}


int main()
{
	int n = 0;
	int a[MAX][MAX];
	int choose;
	do
	{
		cout << "--------MENU--------------" << endl;
		cout << "1. Read file                " << endl;
		cout << "2. Browse by array             " << endl;
		cout << "3. Browse by BFS                 " << endl;
		cout << "4. EXIT                           " << endl;
		cout << "--------------------------" << endl;
		cout << "Choose: ";
		while (true)
		{
			cin >> choose;
			if (choose > 0 && choose <= 4) break;
			else
				cout << "Nhap sai, nhap lai: ";
		}
		system("cls");
		switch (choose)
		{
		case 1:
		{
			read_file(a, n);
			break;
		}
		case 2:
		{
			if (n == 0)
				cout << "Chua co do thi" << endl;
			else
			{
				show_graph(a, n);
			}
			break;
		}
		case 3:
		{
			if (n == 0)
				cout << "Chua co do thi" << endl;
			else
			{
				int l;
				cout << "Nhap dinh nat dau duyet: ";
				while (true)
				{
					cin >> l;
					if (l >= 0 && l <= n) break;
					else
						cout << "Khong co dinh da nhap" << endl;
				}
				system("cls");
				Browse_BFS(a, n, l);
				cout << "Duyet thanh cong" << endl;
				system("pause");
				system("cls");
				browse_graph(n);
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

