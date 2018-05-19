#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, char  *argv[]){
	char * cadena = (char *) "En un lugar de la Mancha de cuyo nombre no quiero\0";
	printf("Cadena:%s\n", cadena);
	int flag = 0, counter =0;
	char  * word = NULL;
	vector<char *> palabras;
	while(true){
		if(*(cadena+counter)== '\0'){
			word = (char *)malloc(counter-flag);
			memcpy(word, cadena+flag, counter-flag);
			printf("%s\n",word );
			palabras.push_back(word);
			break;
		}
		if(*(cadena+counter) == 32){
			int length = counter-flag+1;
			word = (char *) malloc(length);
			memcpy(word, cadena+flag, length);
			*(word+length)= '\0';
			flag = counter+1;
			palabras.push_back(word);
		}
		counter++;
	}
	for (std::vector<char *>::iterator i = palabras.begin(); i != palabras.end(); ++i){
		printf("%s\n", *i);
	}
	return 0;
}