#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(int* a, int Low, int Max, int N, int i);
void print(int* a, int N, int i);
template <typename T>
T count1(T* a, T N, T i, T j);

int main()
{
	int N, Low, Max;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand((unsigned)time(NULL));
	cout << "�����������" << endl;
	cout << "������ ������� �������� ������: "; cin >> N;
	cout << "������ �������� �������� �������� ������: "; cin >> Low;
	cout << "������ ����������� �������� �������� ������: "; cin >> Max;
	int* a = new int[N];
	create(a, Low, Max, N, 0);
	print(a, N, 0);
	cout << endl;
	cout << "ʳ����� ������: " << count1(a, N, 0, 0) << endl;
	delete[] a;
}
void create(int* a, int Low, int Max, int N, int i)
{
	if (i <= N - 1)
	{
		a[i] = Low + rand() % (Max - Low + 1);
		create(a, Low, Max, N, ++i);
	}
}
void print(int* a, int N, int i)
{
	if (i <= N - 1)
	{
		cout << setw(3) << a[i] << " ";
		print(a, N, ++i);
	}
}
template <typename T>
T count1(T* a, T N, T i, T j)
{
	if (i <= N - 1)
	{
		if (a[i] % 2 == 0)
		{
			++j;
		}
		count1(a, N, ++i, j);
	}
	else
		return j;
}