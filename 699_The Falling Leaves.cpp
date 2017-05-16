#include <iostream>
#include <cstring>

#define maxn 300

int sum[maxn];

void build(int p) {
	int v;
	std::cin >> v;
	if(v == -1) {
		return;
	}
	sum[p] += v;
	build(p - 1);
	build(p + 1);
}

bool init(){
	int v;
	std::cin >> v;
	if(v == -1) {
		return false;
	}
	memset(sum, 0, sizeof(sum));
	int pos = maxn / 2;
	sum[pos] = v;
	build(pos - 1);
	build(pos + 1);
}

int main(int argc, char *argv[]) {  
	int kase = 0;
	while(init()) {
		int p = 0;
		while(sum[p] == 0) {
			p++;
		}
		std::cout << "Case " << ++kase << ":\n" << sum[p++];
		while(sum[p] != 0) {
			std::cout << "\n\n";
		}
	}
	return 0;
}