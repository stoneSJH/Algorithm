//WA
//#define T1284
#ifdef T1284
#include <iostream>
using namespace std;

void yf(int &a, int &b){
	if (b % a == 0){
		b = b / a;
		a = 1;
		return;
	}
	int flag = 0;
	for (int i = 2; i <= a / 2; i++){
		if (a % i == 0 && b % i == 0){
			a /= i;
			b /= i;
			flag = 1;
			break;
		}
	}
	if (a == 1 || flag == 0)
		return;
	else
		yf(a, b);
}

int main(){
	long long n, m;
	cin >> n >> m;
	int tmp = n;
	if (m > n)
		tmp = m;
	int count1 = 1, count2 = 1;
	int same = 1;
	int flag1 = 0, flag2 = 0;
	for (long long i = 2; i <= tmp / 2; i++)
	{
		if (n % i == 0)
			count1++;
		if (m % i == 0)
			count2++;
		if (n % i == 0 && m % i == 0)
			same++;
		if (n == i)
			flag1 = 1;
		if (m == i)
			flag2 = 1;
	}
	if (flag1 == 0)
		count1++;
	if (flag2 == 0)
		count2++;
	if (n == m)
		same++;
	int total = count1 * count2;
	yf(same, total);
	cout << total << " " << same << endl;
	return 0;
}
#endif