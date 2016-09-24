//AC
//#define T1051
#ifdef T1051
#include <iostream>
using namespace std;

int getmax(int* a, int n){
	int max = 0;
	int last = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != -1){
			int tmp = a[i] - last - 1;
			last = a[i];
			if (tmp > max)
				max = tmp;
		}
		else continue;
	}
	return max;
}

int solve(int* a, int n, int m){
	if (m >= n)
		return 100;
	int result = 0;
	for (int i = 0; i < n - m; i++){
		int *temp = new int[n];
		for (int k = 0; k < n; k++)
			temp[k] = a[k];
		for (int j = 0; j < m; j++)
			temp[i + j] = -1;
		int tmp = getmax(temp, n);
		if (tmp > result)
			result = tmp;
	}
	return result;
}

int main(){
	int t;
	cin >> t;
	for (int k = 0; k < t; k++){
		int n, m;
		cin >> n >> m;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int result = solve(a, n, m);
		cout << result << endl;
	}
	return 0;
}
#endif