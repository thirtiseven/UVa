#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cstring>

#define maxn 30

int fa[maxn];

void init(int size) {
	for (int i = 1; i <= size; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	int n, m;
	int T = 0;
	while(std::cin >> n >> m) {
		if(n == 0 && m == 0) break;
		std::map<std::string, int> mp;
		std::string lt[maxn];
		int g[maxn][maxn];
		memset(g, 0, sizeof(g));
		int cnt = 0;
		for(int i = 0; i < m; i++) {
			std::string temp_name1, temp_name2;
			std::cin >> temp_name1 >> temp_name2;
			if(mp.find(temp_name1) == mp.end()) {
				mp[temp_name1] = cnt;
				lt[cnt] = temp_name1;
				cnt++;
			}
			if(mp.find(temp_name2) == mp.end()) {
				mp[temp_name2] = cnt;
				lt[cnt] = temp_name2;
				cnt++;
			}
			g[mp[temp_name1]][mp[temp_name2]] = 1;
		}
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					g[i][j] = g[i][j]||(g[i][k]&&g[k][j]);
				}
			}
		}
		init(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(g[i][j] == 1 && g[j][i] == 1) {
					unin(i, j);
				}
			}
		}
		if(T) std::cout << '\n';
		std::cout << "Calling circles for data set " << T+1 << ":\n";
		T++;
		for(int i = 0; i < n; i++) {
			if(fa[i] != i) {
				continue;
			}
			std::cout << lt[i];
			for(int j = 0; j < n; j++) {
				if(fa[j] == i && i != j) {
					std::cout << ", " << lt[j];
				}
			}
			std::cout << '\n';
		}
	}
	return 0;
}