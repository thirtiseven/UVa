#include <iostream>

bool solve(int &w) {
	int w1, d1, w2, d2;
	bool b1 = true, b2 = true;
	std::cin >> w1 >> d1 >> w2 >> d2;
	if(w1 == 0){
		b1 = solve(w1);
	}
	if(w2 == 0){
		b2 = solve(w2);
	}
	w = w1 + w2;
	return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main(int argc, char *argv[]) {  
	int t, w;
	std::cin >> t;
	while(t--) {
		if(solve(w)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
		if(t) {
			std::cout << "\n";
		}
	}
	return 0;
}