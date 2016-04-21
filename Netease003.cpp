//#define NETEASE3
#ifdef NETEASE3
#include <iostream>
#include <vector>
using namespace std;
vector<int> split(long long num){
	vector<int> result;
	long long T = pow(10, 0);
	while (num / T != 0){
		int mod = (num / T) % 10;
		result.push_back(mod);
		T *= 10;
	}
	return result;
}

int main(){
	int S;
	cin >> S;
	for (int l = 0; l < S; l++){
		long long  N, M;
		cin >> N >> M;
		int total = 0;
		for (long long  i = N; i <= M; i++){
			int flag1 = false;
			int flag2 = false;
			int flag3 = true;
			vector<int> num = split(i);
			if (i % 7 == 0)
				flag1 = true;
			for (int j = 0; j < num.size(); j++){
				if (num[j] == 2 || num[j] == 3 || num[j] == 5)
					flag2 = true;
				if (j + 1 < num.size()){
					if (num[j] == 8 && num[j + 1] == 1)
						flag3 = false;
				}
			}
			if (flag1 && flag2 && flag3)
				total++;
		}
		cout << total << endl;
	}
	return 0;
}
#endif