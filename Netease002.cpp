//#define NETEASE2
#ifdef NETEASE2
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(vector<vector<char> >&matrix, int& result){
	vector<vector<int> > tag;
	for (int i = 0; i < matrix.size(); i++){
		vector<int> tmp;
		for (int j = 0; j < matrix[0].size(); j++){
			tmp.push_back(0);
		}
		tag.push_back(tmp);
	}
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++){
			if (matrix[i][j] == '.')
				continue;
			int tmpi = i + 1;
			int tmpj = j + 1;
			int count = 1;
			while (tmpj < matrix[0].size()){
				if (matrix[i][j] == matrix[i][tmpj]){
					count++;
					tmpj++;
				}
				else
					break;
			}
			if (count >= 3){
				for (int k = j; k < tmpj; k++)
					tag[i][k] = 1;
			}
			count = 1;
			while (tmpi < matrix.size()){
				if (matrix[i][j] == matrix[tmpi][j]){
					count++;
					tmpi++;
				}
				else
					break;
			}
			if (count >= 3){
				for (int k = i; k < tmpi; k++)
					tag[k][j] = 1;
			}
		}
	}
	bool changeflag = false;
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++){
			if (tag[i][j] == 1){
				matrix[i][j] = '.';
				result++;
				changeflag = true;
			}
		}
	}
	if (changeflag){
		for (int i = matrix.size() - 1; i >= 0; i--){
			for (int j = 0; j < matrix[0].size(); j++){
				int pos = i + 1;
				while (pos < matrix.size()){
					if (matrix[pos][j] == '.')
						pos++;
					else break;
				}
				if (pos != i + 1){
					matrix[pos - 1][j] = matrix[i][j];
					matrix[i][j] = '.';
				}
			}
		}
		check(matrix, result);
	}
}

int main(){
	int S;
	cin >> S;
	for (int i = 0; i < S; i++){
		vector<vector<char> > matrix;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++){
			vector<char> tmp;
			for (int j = 0; j < M; j++){
				char c;
				cin >> c;
				tmp.push_back(c);
			}
			matrix.push_back(tmp);
		}
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		char tmp = matrix[x0][y0];
		matrix[x0][y0] = matrix[x1][y1];
		matrix[x1][y1] = tmp;
		int total = 0;
		check(matrix, total);
		cout << total << endl;
	}
}
#endif