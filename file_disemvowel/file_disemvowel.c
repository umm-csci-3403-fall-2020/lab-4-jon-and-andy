#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define BUF_SIZE 1024

//Checks if character is vowel
bool check_Vowel(char C) {
	char c = tolower(c);
	if (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

//Grabs all non vowels
int get_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	int i;
	int length = 0;
	for (i = 0; i < num_chars; i++) {
		if (!check_Vowel(in_buf[i]) == false) {
			out_buf[length] = in_buf[i];
			length++;
		}
	}
	return length;
}

//Grabs all the non vowels and sends them to outputFile
void file_disemvowel(FILE* inputFile, FILE* outputFile) {

	char *in_buf = (char*) calloc(BUF_SIZE, sizeof(char));
	char *out_buf = (char*) calloc(BUF_SIZE, sizeof(char));

	int j = 0;
	int i = BUF_SIZE;

	while (i == BUF_SIZE) {
		i = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
		j = get_non_vowels(i, in_buf, out_buf);

		fwrite(out_buf, sizeof(char), j, outputFile);
	}
	free(in_buf);
	free(out_buf);

	fclose(inputFile);
	fclose(outputFile);
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
		outputFile = stdout;
	}
	else if(argc == 3){
		inputFile = fopen(argv[1], "r");
		outputFile = fopen(argv[2], "w+");
	}

	file_disemvowel(inputFile, outputFile);
	fclose(outputFile);
	return 0;
}
