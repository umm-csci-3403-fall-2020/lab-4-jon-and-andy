#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool checkVowel(char C) {
	char c = tolower(C);
	if (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

int countConsonant (char *str) {
	int count = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (!checkVowel(str[i])) {
			count++;
		}
	}
	return count;
}

char *file_disemvowel(char *str) {
	int length = strlen(str);
	int numConsonants = countConsonant(str);
	char *newStr = (char*) calloc(numConsonants + 1, sizeof(char));

	int newIndex = 0;
	for (int old = 0; old < length; old++) {
		if(!checkVowel(str[old])) {
			newStr[newIndex] = str[old];
			newIndex++;
		}
	}
	newStr[newIndex] = '\0';
	return newStr;
	
	free(newStr);
}


int main(int argc, char*argv[]) {

	FILE *inputFile;
	FILE *outputFile;

	if(argc == 1){
		inputFile = stdin;
		outputFile = stdout;
	}
	else if(argc == 2){
		inputFile = fopen(argv[1], "r");
		outputFIle = stdout;
	}
	else if(argc == 3){
		inputFile = fopen(argv[1], "r");
		outputFile = fopen(argv[2], "w+");
	}

	file_disemvowel(inputFile, outputFile);
	fclose(outputFile);
	return 0;
}
