#include <iostream>
#include <queue>
using namespace std;
#define MAX 403 

int tab[MAX][MAX];
int dis[MAX];
int source, sink;
int total;

void build(){
	int n, f, d;
	cin >> n >> f >> d;
	memset(tab, 0, sizeof(tab));
	source = 0;
	sink = 2 * n + f + d + 1;
	total = sink + 1;
	for (int i = 1; i <= f; i++)
		tab[source][i] = 1;
	for (int i = 1; i <= n; i++)
		tab[f + i][f + n + i] = 1;
	for (int i = 1; i <= d; i++)
		tab[f + 2 * n + i][sink] = 1;
	int fs, ds, fi, di;
	for (int i = 1; i <= n; i++){
		cin >> fs >> ds;
		for (int j = 1; j <= fs; j++){
			cin >> fi;
			tab[fi][f + i] = 1;
		}
		for (int j = 1; j <= ds; j++){
			cin >> di;
			tab[f + i + n][f + 2 * n + di] = 1;
		}
	}
}
int bfs(){
	int cur;
	queue<int> q;
	memset(dis, -1, sizeof(dis));
	dis[sink] = 0;
	q.push(sink);
	while (!q.empty()){
		cur = q.front();
		q.pop();
		for (int i = 0; i < total; i++){
			if (dis[i] == -1 && tab[i][cur] != 0){
				dis[i] = dis[cur] + 1;
				q.push(i);
			}
		}
		if (cur == source) return 1;
	}
	return 0;
}
int find(int cur, int maxflow){
	if (cur == sink) return maxflow;
	int curflow, upper = maxflow;
	for (int i = 0; i < total && upper; i++){
		if (dis[i] + 1 == dis[cur] && tab[cur][i] != 0){
			curflow = find(i, min(upper, tab[cur][i]));
			tab[i][cur] += curflow;
			tab[cur][i] -= curflow;
			upper -= curflow;
		}
	}
	return maxflow - upper;
}
int dinic(){
	int result = 0;
	while (bfs()){
		result += find(source, 0x7fffffff);
	}
	return result;
}
int main(){
	build();
	cout << dinic() << endl;
	return 0;
}