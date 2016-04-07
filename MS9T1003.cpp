//#define MS9T1003
#ifdef MS9T1003

#include <iostream>
using namespace std;
int main(){
	/*int a1 = 1, a2 = 1;
	cout << a1 << " " << a2 << " ";
	while (true){
		int tmp = a1 + a2;
		a1 = a2;
		a2 = tmp;
		cout << a2 << " ";
		if (a2 > 100000)
			break;
	}*/
	//100000 max 25;
	int fib[25];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 25; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	int n;
	cin >> n;
	int* a = new int [n];
	int** dp = new int* [n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[25];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < 25; j++)
		dp[i][j] = 0;
	if (a[0] == 1)
		dp[0][0] = 1;
	for (int i = 1; i < n; i++){
		if (a[i] == 1)
			dp[i][0] = dp[i - 1][0] + 1;
		else
			dp[i][0] = dp[i - 1][0];
		for (int j = 1; j < 25; j++){
			if (fib[j] == a[i])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	int result = 0;
	for (int i = 0; i < 25; i++)
		result += dp[n - 1][i];
	cout << result << endl;
	return 0;
}


#endif