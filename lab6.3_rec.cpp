#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

template <typename T>
T count1(T* a, T N, T i, T j)
{
	if (i <= N - 1)
	{
		if (a[i] % 2 == 0)
		{
			++j;
		}
		return count1(a, N, ++i, j);
	}
	else
		return j;
}
void print(int* a, int N, int i)
{
	if (i <= N - 1)
	{
		cout << setw(3) << a[i] << " ";
		return print(a, N, ++i);
	}
}
void create(int* a, int Low, int Max, int N, int i)
{
	if (i <= N - 1)
	{
		a[i] = Low + rand() % (Max - Low + 1);
		return create(a, Low, Max, N, ++i);
	}
	else
		print(a, N, 0);
}
int main()
{
	int N, Low, Max;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand((unsigned)time(NULL));
	cout << "Рекурсивний" << endl;
	cout << "Введіть кількість елементів масиву: "; cin >> N;
	cout << "Введіть мінімальне значення елементу масиву: "; cin >> Low;
	cout << "Введіть максимальне значення елементу масиву: "; cin >> Max;
	int* a = new int[N];
	create(a, Low, Max, N, 0);
	cout << endl;
	cout << "Кількіть парних: " << count1(a, N, 0, 0) << endl;
	delete[] a;
}