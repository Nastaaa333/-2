#include <iostream>
#include<cstdlib>
#include<chrono>
using namespace std;

void quicksort(int* arr, int end, int begin)   //сортировка quicksort
{

	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l) 
	{
		while (arr[f] < mid) {
			f++;
		}

		while (arr[l] > mid) {
			l--;
		}

		if (f <= l) {
			swap(arr[f], arr[l]);
			f++;
			l--;
		}

		if (begin < l) {
			quicksort(arr, l, begin);
		}
		if (f < end) {
			quicksort(arr, end, f);
		}

	}

}

int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}

		return binarySearch(arr, value, mid + 1, end);
	}

	return -1;
}

int main()
{
	setlocale(0, "");

	// Задание 1
	cout << "Задание 1" << endl;
	const int N = 100;                              // заполнили массив случайными числами в диапозоне от -99 до 99
	int randomNum[N] = {};
	cout << "Наш массив: " << endl;
	for (int i = 0; i < N; i++) 
	{
		randomNum[i] = rand() % 199 - 99;       
		cout << randomNum[i] << " ";
	}
	cout << endl << endl;



	// Задание 2
	cout << "Задание 2" << endl;
	int end = N - 1;
	int begin = 0;

	auto t1 = chrono::steady_clock::now();
	quicksort(randomNum, end, begin);
	auto t2 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration1 = t2 - t1;
	cout << "Время сортировки массива: " << duration1.count() << "" << endl;

	cout << "Отсортированный массив: " << endl;

	for (int i = 0; i < N; i++)
	{
		cout << randomNum[i] << " ";
	}
	cout << endl << endl;;




	// Задание 3
	cout << "Задание 3" << endl;
	cout << "Новый массив: " << endl;

	int randomNum2[N] = {};                   // новый массив
	for (int i = 0; i < N; i++)
	{
		randomNum2[i] = rand() % 199 - 99;
		cout << randomNum2[i] << " ";
	}
	cout << endl;

	auto start2 = chrono::steady_clock::now();
	int minValue = randomNum2[0];
	int maxValue = randomNum2[0];
	for (int j = 1; j < N; ++j) {
		if (randomNum2[j] < minValue) {
			minValue = randomNum2[j];
		}
		if (randomNum2[j] > maxValue) {
			maxValue = randomNum2[j];
		}
	}
	auto end2 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration2 = end2 - start2;
	cout << "Минимальное значение: " << minValue << endl <<"Максимальное: " << maxValue << endl << "Время нахождения мин и макс значения в неотсортированом массиве: " << duration2.count() << "" << endl;

	cout << endl << "Теперь в отсортированном массиве: " << endl;
	quicksort(randomNum2, end, begin);
	auto start3 = chrono::steady_clock::now();
	int minValue2 = randomNum2[0];
	int maxValue2 = randomNum2[N-1];
	auto end3 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration3 = end3 - start3;
	cout << "Минимальное значение: " << minValue2 << endl << "Максимальное: " << maxValue2 << endl << "Время нахождения мин и макс значения в отсортированом массиве: " << duration3.count() << "" << endl;
	cout << "Отсортированный массив: " << endl;

	for (int i = 0; i < N; i++)
	{
		cout << randomNum2[i] << " ";
	}
	cout << endl << endl;;

	cout << endl << endl;;

	// Задание 4
	cout << "Задание 4" << endl;

	int middle1 = (minValue + maxValue) / 2;
	int middle2 = (minValue2 + maxValue2) / 2;
	cout << "Среднее значение в неотсортированном массиве: " << middle1<< endl << "Среднее значение в отсортированом массиве: " << middle2 << endl;
	cout << "Индексы всех элементов которые равны " << middle1 << ": ";
	for (int k = 0; k < N; ++k) {
		if (randomNum2[k] == middle1) {
			cout << k << " ";
		}
	}
	auto start4 = chrono::steady_clock::now();
	int counter = 0;
	for (int k = 0; k < N; ++k) {
		if (randomNum2[k] == middle1) {
			counter++;
		}
	}
	auto end4 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration4 = end4 - start4;
	cout << endl;
	cout << "Количество элементов которые равны " << middle1 <<": " << counter << endl << "Время поиска: " << duration4.count()<< endl<<endl;


	//Задание 5
	cout << "Задание 5" << endl;
	int a;
	int counterNew = 0;
	cout << "Введите число a ";
	cin >> a;
	for (int g = 0; g < N; g++) {
		if (randomNum2[g] < a) {
			counterNew++;
		}
	}
	cout << "Количество элементов в отсортированном массиве, которые меньше числа " << a << ": "<< counterNew << endl << endl;



	//Задание 6
	cout << "Задание 6" << endl;
	int b;
	int counterNew2 = 0;
	cout << "Введите число b ";
	cin >> b;
	for (int g = 0; g < N; g++) {
		if (randomNum2[g] > b) {
			counterNew2++;
		}
	}
	cout << "Количество элементов в отсортированном массиве, которые больше числа " << b << ": " << counterNew2 << endl << endl;


	//Задание 7
	cout << "Задание 7" << endl;
	int randomNum3[N] = {};
	bool arg = false;
	cout << "Введите число, которое нужно найти: ";
	int Num;
	cin >> Num;
	cout << endl;
	cout << "Новый массив: " << endl;
	for (int i = 0; i < N; i++)
	{
		randomNum3[i] = rand() % 199 - 99;
		cout << randomNum3[i] << " ";
	}
	cout << endl << endl;
	
	auto start5 = chrono::steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (randomNum3[i] == Num) {
			arg = true;
			break;
		}
	}
	auto end5 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration5 = end5 - start5;
	if (arg) {
		cout << "Число " << Num << " существует" << endl;
	}
	else {
		cout << "Элемент " << Num << " не найден" << endl;
	}
	cout << "Время затраченное на перебор массива: " << duration5.count() << endl;

	quicksort(randomNum3,end, begin);

	auto start6 = chrono::steady_clock::now();
	int size = sizeof(randomNum3) / sizeof(randomNum3[0]);
	int result = binarySearch(randomNum3, Num, 0, size - 1);
	auto end6 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration6 = end6 - start6;
	cout << endl;
	if (result == -1) {
		cout << "Элемент " << Num << " не найден" << endl;
	}
	else {
		cout << "Число " << Num << " существует" << endl;
	}
	cout << "Время затраченное на бинарный поиск: " << duration6.count() << endl;
	cout << endl;

	//Задание 8

	int index1, index2;
	cout << "Введите первый индекс: ";
	cin >> index1;
	cout << endl;
	cout << "Введите второй индекс: ";
	cin >> index2;
	cout << endl;
	cout << "Массив был таким: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << randomNum3[i] << " ";
	}
	cout << endl;

	auto start7 = chrono::steady_clock::now();
	swap(randomNum3[index1], randomNum3[index2]);
	auto end7 = chrono::steady_clock::now();
	chrono::duration<double, milli>duration7 = end7 - start7;

	cout << endl;
	cout << "Массив стал таким: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << randomNum3[i] << " ";
	}
	cout << endl;
	cout << "Время, за которое переставили элементы: " << duration7.count() << endl<< endl<<endl;




	//ИДЗ2
	cout << "ИДЗ2" << endl;
	int Part1[50] = {};
	int Part2[50] = {};
	for (int i1 = 0; i1 < N / 2; i1++) {
		Part1[i1] = randomNum[i1];
		Part2[i1] = randomNum[50 + i1];
	}

	cout << "Первая часть массива: " << endl;
	for (int i = 0; i < N/2; i++)
	{
		cout << Part1[i] << " ";
	}
	cout << endl;

	cout << "Вторая часть массива: " << endl;
	for (int i = 0; i < N/2; i++)
	{
		cout << Part2[i] << " ";
	}
	cout << endl << endl;
	cout << "Первый и второй массив после того, как поменяли значения нечетных элементов 1-го массива с четными элементами 2-го массива" << endl << endl;

	int n;
	for (int t=0; t<N/2; t+=2){
		n = Part1[t+1];
		Part1[t+1] = Part2[t];
		Part2[t] = n;
	}
	cout << "Первый массив: " << endl;
	for (int i = 0; i < N / 2; i++)
	{
		cout << Part1[i] << " ";
	}
	cout << endl;

	cout << "Второй массив: " << endl;
	for (int i = 0; i < N / 2; i++)
	{
		cout << Part2[i] << " ";
	}
	cout << endl << endl;
	cout << "Второй массив, в котором все значения стали четными: " << endl;

	for (int h = 0; h < N / 2; h++) {
		if (Part2[h] % 2 !=0 && Part2[h]<99) {
			Part2[h]++;
		}
		else if (Part2[h] % 2 != 0 && Part2[h] == 99) {
			Part2[h]--;
		}
	}
	for (int i = 0; i < N / 2; i++)
	{
		cout << Part2[i] << " ";
	}

	int counter5 = 0;
	for (int r = 0; r < N / 2; r++) {
		if (Part1[r] > Part2[r]) {
			counter5++;
		}
	}
	cout << endl << endl << "Количество элементов, которые больше в 1-м массиве, чем во 2-м: " << counter5 << endl;

}


