#include <iostream>
#include <iomanip>
#include <cstring>
#define sMax 100

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	while(n--){
		char s[sMax];
		std::cin >> s;
		double mass = 0;
		double alice;
		int len = strlen(s);
		for(int i = 0;i < len;i++){
			if(s[i] == 'C' && s[i+1] >= '0' && s[i+1] <= '9'){
				alice = s[i+1] - 48;
				if(s[i+2] >= '0' && s[i+2] <= '9'){
					alice *= 10;
					alice += (int)(s[i+2]) - 48;
				}
				mass += alice * 12.01;
				//cout << mass << " " << alice << endl;
			}else if(s[i] == 'H' && s[i+1] >= '0' && s[i+1] <= '9'){
				alice = s[i+1];
				alice = alice - 48;
				if(s[i+2] >= '0' && s[i+2] <= '9'){
					alice *= 10;
					alice += (int)(s[i+2]) - 48;
				}
				mass += alice * 1.008;
				//cout << mass << " " << alice << endl;
			}else if(s[i] == 'O' && s[i+1] >= '0' && s[i+1] <= '9'){
				alice = s[i+1];
				alice = alice - 48;
				if(s[i+2] >= '0' && s[i+2] <= '9'){
					alice *= 10;
					alice += (int)(s[i+2]) - 48;
				}
				mass += alice * 16.00;
				//cout << mass << " " << alice << endl;
			}else if(s[i] == 'N' && s[i+1] >= '0' && s[i+1] <= '9'){
				alice = s[i+1];
				alice = alice - 48;
				if(s[i+2] >= '0' && s[i+2] <= '9'){
					alice *= 10;
					alice += (int)(s[i+2]) - 48;
				}
				mass += alice * 14.01;
				//cout << mass << " " << alice << endl;
			}else if(s[i] == 'C'){
				mass += 12.01;
			}else if(s[i] == 'H'){
				mass += 1.008;
			}else if(s[i] == 'O'){
				mass += 16.00;
			}else if(s[i] == 'N'){
				mass += 14.01;
			}
			else{
				continue;
			}		
		}
		std::cout << fixed << setprecision(3) << mass << std::endl;
		}
		return 0;
}