//#define MS4T1001
#ifdef MS4T1001
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int emulate(int n, int w, int h, int p, int* a){
	int totChar = 0;
	for (int i = 0; i < n; i++){
		totChar += a[i];
	}
	long result = w * p * h / totChar;
	if (w < result)
		result = w;
	if (h < result)
		result = h;
	return (int)result;
}

int main(){
	int testNum;
	while (cin >> testNum){
		vector<int> answer;
		for (int k = 0; k < testNum; k++){
			int n, w, h, p;
			cin >> n >> p >> w >> h;
			int* a = new int[n];
			for (int i = 0; i < n; i++)
				cin >> a[i];
			int s = emulate(n, w, h, p, a);
			while (s > 1){
				int cil = floor(w / s);
				int totLine = 0;
				for (int i = 0; i < n; i++){
					totLine += ceil((double)a[i] / cil);
					cout << cil <<"  "<< totLine << endl;
				}
				int lip = floor(h / s) * p;
				if (lip >= totLine)
					break;
				else
					s--;
			}
			answer.push_back(s);
		}
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << endl;
	}
	return 0;
}

#endif