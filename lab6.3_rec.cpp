#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(int* a, int Low, int Max, int N, int i);
void print(int* a, int N, int i);
template <typename T>
T count1(T* a, T N, int i, T j);
int count2(int* a, int N, int i, int j);

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
	print(a, N, 0);
	cout << endl;
	cout << "Кількіть парних(cпосіб з шаблоном): " << count1(a, N, 0, 0) << endl;
	cout << "Кількіть парних(спосіб без шаблону): " << count2(a, N, 0, 0) << endl;
	delete[] a;
}
void create(int* a, int Low, int Max, int N, int i)
{
	if (i < N)
	{
		a[i] = Low + rand() % (Max - Low + 1);
		create(a, Low, Max, N, ++i);
	}
}
void print(int* a, int N, int i)
{
	if (i < N)
	{
		cout << setw(3) << a[i] << " ";
		print(a, N, ++i);
	}
}
template <typename T>
T count1(T* a, T N, int i, T j)          // <- спосіб з шаблоном
{
	if (i < N)
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
int count2(int* a, int N, int i, int j)                    // <- спосіб без шаблону
{												
	if (i < N)
	{
		if (a[i] % 2 == 0)
		{
			++j;
		}
		count2(a, N, ++i, j);
	}
	else
		return j;
}