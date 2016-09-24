#define MS4T1002
#ifdef MS4T1002
#include <iostream>
#include<string>
#include<vector>
using namespace std;
#define base 2
#define MAX 50
int* change(long num)
{
	int a[8], i = 0;
	for (int k = 0; k < 8; k++)
		a[k] = 0;
	while (num != 0)
	{
		a[i] = num % base;
		num /= base;
		i++;
	}
	int ret[8];
	for (int j = 0; j < 8; j++){
		ret[j] = a[7 - j];
	}
	return ret;
}
int main()
{
	int n, m;
	vector<int*> allowList;
	vector<int> allowMask;
	vector<int> result;
	cin >> n >> m;

	for (int l = 0; l < n; l++)
	{
		string mark;
		char str[MAX];
		cin >> mark;
		cin >> str;
		int count = 0, sum = 0, mask = 0;
		int flag = 0, maskflag = 0;;
		int len = strlen(str);
		int *addr = new int[33];
		if (mark == "allow")
			addr[32] = 1;
		else if (mark == "deny")
			addr[32] = 0;
		for (int i = 0; i <= len; i++)
		{
			if (str[i] != '.' && i != len && maskflag == 0 && str[i] != '/')
				sum = sum * 10 + str[i] - '0';
			else if (maskflag == 0 && ((str[i] == '.' || str[i] == '/') || i == len))
			{
				if (str[i] == '/')
					maskflag = 1;
				int* tmp = change(sum);
				for (int j = count * 8; j < (count + 1) * 8; j++){
					addr[j] = tmp[j - count*8];
				}
				count++;
				sum = 0;
			}
			else if (maskflag == 1 && i != len)
			{
				mask = mask * 10 + str[i] - '0';
			}
		}
		if (maskflag == 0)
			mask = -1;
		allowList.push_back(addr);
		allowMask.push_back(mask);
	}
	for (int l = 0; l < m; l++){
		char str[MAX];
		cin >> str;
		int addr[32];
		int count = 0, sum = 0;
		int len = strlen(str);
		int flag = 0;
		for (int i = 0; i <= len; i++)
		{
			if (str[i] != '.' && i != len)
				sum = sum * 10 + str[i] - '0';
			else
			{
				int* tmp = change(sum);
				for (int i = count * 8; i < (count + 1) * 8; i++){
					addr[i] = tmp[i - count * 8];
				}
				count++;
				sum = 0;
			}
		}
		for (int j = 0; j < allowList.size(); j++){
			int length;
			if (allowMask[j] != -1)
				length = allowMask[j];
			else
				length = 32;
			int k;
			for (k = 0; k < length; k++){
				if (addr[k] != allowList[j][k])
					break;
			}
			if (k == length){
				if (allowList[j][32] == 1)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
				flag = 1;
			}
			if (flag == 1){
				break;
			}
		}
		if (flag == 0)
			cout << "YES" << endl;
	}
	return 0;
}

#endif