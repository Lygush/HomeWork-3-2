#include <iostream>

void PrintMass(int* mass, int size) {
	for (int i{}; i < size; ++i) {
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;
}

int Pivoting(int* arr, int left, int right) {
	int pivot{ arr[right] };
	int pIndex{ left };
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
		{
			std::swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	std::swap(arr[pIndex], arr[right]);
	return pIndex;
}

void QuickSort(int* arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int pivot{ Pivoting(arr,left,right) };
	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);
}
					

int main() {

	setlocale(LC_ALL, "Russian");

	int arrFirst[10] {3, 43, 3, 29, 18, 72, 57, 61, 2, 33};
	int n{ sizeof(arrFirst) / sizeof(arrFirst[0]) };
	std::cout << "Исходный массив: ";
	PrintMass(arrFirst, 10);
	QuickSort(arrFirst, 0, n - 1);
	std::cout << "Отсортированный массив: ";
	PrintMass(arrFirst, 10);
	std::cout << std::endl;

	int arrSecond[15] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	n = sizeof(arrSecond) / sizeof(arrSecond[0]);
	std::cout << "Исходный массив: ";
	PrintMass(arrSecond, 15);
	QuickSort(arrSecond, 0, n - 1);
	std::cout << "Отсортированный массив: ";
	PrintMass(arrSecond, 15);
	std::cout << std::endl;

	int arrThird[18] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
	n = sizeof(arrThird) / sizeof(arrThird[0]);
	std::cout << "Исходный массив: ";
	PrintMass(arrThird, 18);
	QuickSort(arrThird, 0, n - 1);
	std::cout << "Отсортированный массив: ";
	PrintMass(arrThird, 18);
	std::cout << std::endl;

	return 0;
}