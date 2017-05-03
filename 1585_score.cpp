#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
	char s[85];
	int n,sum,comb,len;
	std::cin >> n;
	while(n--){
		std::cin >> s;
		sum = 0;
		comb = 0;
		len = strlen(s);
		for(int i = 0;i < len;i++){
			if(s[i] == 'X'){
				comb = 0;
			}
			if(s[i] == 'O'){
				comb++;
				sum += comb;
			}
		}
		std::cout << sum << std::endl;
	}
}