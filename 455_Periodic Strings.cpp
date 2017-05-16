#include <iostream> 
#include <cstring> 

int main(int argc, char *argv[]) {  
	char word[100]; 
	int n;
	std::cin >> n;
	while(n--) { 
		std::cin >> word;  
		int nLen=strlen(word);  
		for (int i=1; i<=nLen; ++i) {  
			if (nLen%i==0) {  
				int ok=1;  
				for (int j=i; j<nLen; ++j) {  
					if (word[j%i]!=word[j]) {  
						ok=0;  
						break;  
					}  
				}  
				if (ok) {  
					std::cout << i <<std::endl; 
					break;
				}  
			}  
		} 
		if(n) {
			std::cout << std::endl;
		}
	} 
	return 0;  
} 