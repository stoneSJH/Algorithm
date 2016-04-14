#define SORTS
#ifdef SORTS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int sedgewick[] = {  // Sedgewick增量
	1073643521, 603906049, 268386305, 150958081, 67084289,
	37730305, 16764929, 9427969, 4188161, 2354689,
	1045505, 587521, 260609, 146305, 64769,
	36289, 16001, 8929, 3905, 2161,
	929, 505, 209, 109, 41,
	19, 5, 1, 0 };
int hibbard[] = { // Hibbard增量
	134217727, 67108863, 33554431, 16777215, 8388607,
	4194303, 2097151, 1048575, 524287, 262143, 131071,
	65535, 32767, 16383, 8191, 4095, 2047, 1023, 511,
	255, 127, 63, 31, 15, 7, 3, 1, 0 };

void SelectSort(int* _a, int size){
	for (int i = 0; i < size; i++){
		int min = _a[i];
		int index = i;
		for (int j = i + 1; j < size; j++){
			if (_a[j] < min){
				min = _a[j];
				index = j;
			}
		}
		if (index != i){
			_a[index] = _a[i];
			_a[i] = min;
		}
	}
}

void BubbleSort(int* _a, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = i + 1; j < size; j++){
			if (_a[i] > _a[j]){
				int temp = _a[i];
				_a[i] = _a[j];
				_a[j] = temp;
			}
		}
	}
}

void InsertSort(int* _a, int size){
	for (int i = 1; i < size; i++){
		int j = i - 1;
		int key = _a[i];
		while (j >= 0 && _a[j] > key){
			_a[j + 1] = _a[j];
			j--;
		}
		_a[j + 1] = key;
	}
}

void ShellSort(int* _a, int size){
	int d = size;
	while (true){
		d = d / 2;//Shell增量
		for (int pos = 0; pos < d; pos++){
			for (int i = pos + d; i < size; i += d){
				int j = i - d;
				int key = _a[i];
				while (j >= 0 && _a[j] > key){
					_a[j + d] = _a[j];
					j -= d;
				}
				_a[j + d] = key;
			}
		}
		if (d == 1)
			break;
	}
}

void _Qsort(int* _a, int _low, int _high){
	int low = _low;
	int high = _high;
	int mid = _a[(_low + _high) / 2];
	while (low < high){
		while (_a[low] < mid)
			low++;
		while (_a[high] > mid)
			high--;
		if (low <= high){
			int temp = _a[low];
			_a[low] = _a[high];
			_a[high] = temp;
			low++;
			high--;
		}
	}
	if (high > _low)
		_Qsort(_a, _low, high);
	if (_high > low)
		_Qsort(_a, low, _high);
}
void QuickSort(int* _a, int size){
	_Qsort(_a, 0, size - 1);
}

void Merge(int* _a, int* _b, int _low, int _mid, int _high){
	int pos = _low;
	int i = _low;
	int j = _mid;
	while (i < _mid && j < _high){
		if (_a[i] < _a[j]){
			_b[pos] = _a[i];
			i++;
			pos++;
		}
		else{
			_b[pos] = _a[j];
			j++;
			pos++;
		}

	}
	while (i < _mid){
		_b[pos] = _a[i];
		pos++;
		i++;
	}
	while (j < _high){
		_b[pos] = _a[j];
		pos++;
		j++;
	}
	for (i = _low; i < pos; i++){
		_a[i] = _b[i];
	}
}
void _Msort(int* _a, int* _b, int _low, int _high){
	if (_high > _low + 1){
		int mid = (_low + _high) / 2;
		_Msort(_a, _b, _low, mid);
		_Msort(_a, _b, mid, _high);
		Merge(_a, _b, _low, mid, _high);
	}
}
void MergeSort(int* _a, int size){
	int low = 0;
	int high = size;
	int* _b = new int[size];
	for (int i = 0; i < size; i++)
		_b[i] = 0;
	_Msort(_a, _b, low, high);
}


void Adjust(int* _a, int _start, int _end){
	//i --> 2 * i + 1, 2 * i + 2
	int i = _start;
	int temp = _a[i];
	int j = 2 * _start + 1;
	while (j < _end){
		if (j + 1 < _end && _a[j + 1] > _a[j])
			j++;
		if (_a[j] < temp)
			break;
		_a[i] = _a[j];
		i = j;
		j = 2 * i + 1;
	}
	_a[i] = temp;
}
void HeapSort(int* _a, int size){
	for (int i = size / 2; i >= 0; i--)
		Adjust(_a, i, size);
	for (int i = size - 1; i >= 0; i--){
		int temp = _a[i];
		_a[i] = _a[0];
		_a[0] = temp;
		Adjust(_a, 0, i);
	}
}

void RadixSort(int* _a, int size){
	int d = 0;
	while (true){
		int degree = pow(10, d);
		bool flag = false;
		for (int i = 0; i < size; i++){
			if (_a[i] / degree != 0){
				flag = true;
				break;
			}
		}
		if (flag)
			d++;
		else
			break;
	}
	d--;
	int **bucket = new int*[19];
	for (int i = 0; i < 19; i++)
		bucket[i] = new int[size];
	int *index = new int[19];

	int _d = 0;
	while (_d <= d){
		for (int i = 0; i < 19; i++)
			index[i] = 0;
		for (int i = 0; i < 19; i++)
		for (int j = 0; j < size; j++)
			bucket[i][j] = 0;
		int degree = pow(10, _d);
		for (int i = 0; i < size; i++){
			int mod = (_a[i] / degree) % 10;
			mod += 9;
			bucket[mod][index[mod]] = _a[i];
			index[mod]++;
		}
		int pos = 0;
		for (int i = 0; i < 19; i++){
			if (index[i] != 0){
				for (int j = 0; j < index[i]; j++){
					_a[pos] = bucket[i][j];
					pos++;
				}
			}
		}
		_d++;
	}
}

int main(){
	int a[] = { 9, 2, 11, -7, 0, 6, 3, 2, 5000, -10 };
	int n =	sizeof(a) / sizeof(a[0]);
	//QuickSort(a, n);
	//SelectSort(a, n);
	//BubbleSort(a, n);
	//InsertSort(a, n);
	//ShellSort(a, n);
	//MergeSort(a, n);
	//HeapSort(a, n);
	RadixSort(a, n);
	//cout << -17 % 10 << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;

}

#endif