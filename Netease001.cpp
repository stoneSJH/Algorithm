//#define NETEASE1
#ifdef NETEASE1
#include <iostream>
#include <vector>
using namespace std;

void Opt1(vector<vector<int> >& matrix, int& N, int& M){
	vector<vector<int> > result;
	for (int i = 0; i < M; i++){
		vector<int> tmp;
		for (int j = N - 1; j >= 0; j--){
			tmp.push_back(matrix[j][i]);
		}
		result.push_back(tmp);
	}
	matrix = result;
	N = matrix.size();
	M = matrix[0].size();
}
void Opt2(vector<vector<int> >& matrix, int& N, int& M){
	vector<vector<int> > result;
	for (int i = M - 1; i >= 0; i--){
		vector<int> tmp;
		for (int j = 0; j < N; j++){
			tmp.push_back(matrix[j][i]);
		}
		result.push_back(tmp);
	}
	matrix = result;
	N = matrix.size();
	M = matrix[0].size();
}
void Opt3(vector<vector<int> >& matrix, int& N, int& M){
	vector<vector<int> > result;
	for (int i = N - 1; i >= 0; i--){
		vector<int> tmp;
		for (int j = 0; j < M; j++){
			tmp.push_back(matrix[i][j]);
		}
		result.push_back(tmp);
	}
	matrix = result;
}
void Opt4(vector<vector<int> >& matrix, int& N, int& M){
	vector<vector<int> > result;
	for (int i = 0; i < N; i++){
		vector<int> tmp;
		for (int j = M - 1; j >= 0; j--){
			tmp.push_back(matrix[i][j]);
		}
		result.push_back(tmp);
	}
	matrix = result;
}
void Opt5(vector<vector<int> >& matrix, int x0, int y0, int x1, int y1, int value){
	for (int i = x0; i <= x1; i++){
		for (int j = y0; j <= y1; j++){
			matrix[i][j] += value;
			if (matrix[i][j] >= 255)
				matrix[i][j] = 255;
		}
	}
}
void Opt6(vector<vector<int> >& matrix, int x0, int y0, int x1, int y1, int value){
	for (int i = x0; i <= x1; i++){
		for (int j = y0; j <= y1; j++){
			matrix[i][j] -= value;
			if (matrix[i][j] <= 0)
				matrix[i][j] = 0;
		}
	}
}
void Opt7(vector<vector<int> >& matrix, int& N, int& M, int x0, int y0, int x1, int y1){
	vector<vector<int> > result;
	for (int i = x0; i <= x1; i++){
		vector<int> tmp;
		for (int j = y0; j <= y1; j++){
			tmp.push_back(matrix[i][j]);
		}
		result.push_back(tmp);
	}
	matrix = result;
	N = matrix.size();
	M = matrix[0].size();
}
int main(){
	int S;
	cin >> S;
	for (int l = 0; l < S; l++){
		int N, M, T;
		vector<int> result;
		vector<vector<int> > matrix;
		cin >> N >> M;
		for (int i = 0; i < N; i++){
			vector<int> tmp;
			for (int j = 0; j < M; j++){
				int pixel;
				cin >> pixel;
				tmp.push_back(pixel);
			}
			matrix.push_back(tmp);
		}
		cin >> T;
		for (int k = 0; k < T; k++){
			int op;
			cin >> op;
			switch (op){
			case 1:
			{
					  Opt1(matrix, N, M);
					  break;
			}
			case 2:
			{
					  Opt2(matrix, N, M);
					  break;
			}
			case 3:
			{
					  Opt3(matrix, N, M);
					  break;
			}
			case 4:
			{
					  Opt4(matrix, N, M);
					  break;
			}
			case 5:
			{
					  int x0, y0, x1, y1, value;
					  cin >> x0 >> y0 >> x1 >> y1 >> value;
					  Opt5(matrix, x0, y0, x1, y1, value);
					  break;
			}
			case 6:
			{
					  int x0, y0, x1, y1, value;
					  cin >> x0 >> y0 >> x1 >> y1 >> value;
					  Opt6(matrix, x0, y0, x1, y1, value);
					  break;
			}
			case 7:
			{
					  int x0, y0, x1, y1;
					  cin >> x0 >> y0 >> x1 >> y1;
					  Opt7(matrix, N, M, x0, y0, x1, y1);
					  break;
			}
			default:
				break;
			}
			for (int i = 0; i < matrix.size(); i++){
				for (int j = 0; j < matrix[i].size(); j++){
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		int totalPixel = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				totalPixel += matrix[i][j];
		cout << N << " " << M << " " << matrix[0][0] << " " << totalPixel << endl;
	}
	return 0;
}

#endif