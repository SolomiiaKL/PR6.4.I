#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(double* a, const int size, const double Low, const double High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + (High - Low) * rand() / RAND_MAX;
}

void Print(const double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(8) << fixed << setprecision(2) << a[i];
	cout << endl;
}

// 1.1. Кількість елементів масиву, рівних нулю
int CountZero(const double* a, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 0)
			count++;
	return count;
}

// Пошук індексу мінімального елемента
int IndexMin(const double* a, const int size)
{
	int imin = 0;
	for (int i = 1; i < size; i++)
		if (a[i] < a[imin])
			imin = i;
	return imin;
}

// 1.2. Сума елементів масиву, розташованих після мінімального елемента
double SumAfterMin(const double* a, const int size)
{
	int imin = IndexMin(a, size);
	double s = 0;
	for (int i = imin + 1; i < size; i++)
		s += a[i];
	return s;
}

void Swap(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}

// 2. Впорядкувати непарні елементи масиву (елементи з непарними індексами) за зростанням модулів
void SortOddAscendingAbs(double* a, const int size)
{
	for (int i = 1; i < size; i += 2)
		for (int j = i + 2; j < size; j += 2)
			if (fabs(a[j]) < fabs(a[i]))
				Swap(a[i], a[j]);
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	if (n <= 0)
	{
		cout << "n must be > 0" << endl;
		return 0;
	}

	double* a = new double[n];
	Create(a, n, -10, 10);

	cout << "Array:" << endl;
	Print(a, n);

	cout << "Count of zero elements = " << CountZero(a, n) << endl;

	int iMin = IndexMin(a, n);
	if (iMin < n - 1)
		cout << "Sum of elements after minimum = " << SumAfterMin(a, n) << endl;
	else
		cout << "There are no elements after the minimum element" << endl;

	SortOddAscendingAbs(a, n);

	cout << "Modified array:" << endl;
	Print(a, n);

	delete[] a;
	return 0;
}