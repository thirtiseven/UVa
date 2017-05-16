#include <iostream>
#include <cstring>
	
int main(int argc, char *argv[]) {
	int Dcount[11000][12];
	int alice = 0, bob = 0, clare = 0, dave = 0;
	for(int j = 1;j < 10000; j++){
		for(int i = 1; i <= j; i++){
			alice = i / 1000;
			bob   = i / 100 - alice * 10;
			clare = i / 10 - bob * 10 - alice * 100;
			dave  = i % 10;
			Dcount[j][alice]++;
			Dcount[j][bob]++;
			Dcount[j][clare]++;
			Dcount[j][dave]++;	
		}
		Dcount[j][0] = j / 1000 * 100 + j / 100 * 10 + j / 10;	
		//memset(Dcount, 0, sizeof(Dcount));
	}
	int n, m;
	std::cin >> n;
	while(n--){
		std::cin >> m;
		for(int i = 0; i <= 9; i++) {
			if(i != 0){
				std::cout << " ";
			}
			std::cout << Dcount[m][i];
		}
		std::cout << std::endl;
	}
	return 0;
}