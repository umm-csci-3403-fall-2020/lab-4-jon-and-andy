#include <ftw.h>
#include <stdio.h>

#define MAX_FTW_DEPTH 16
static int dirCount;
static int files;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
	if(typeflag == FTW_F) {
		files++;
	} else if(typeflag == FTW_D) {
		dirCount++;
	}
	return 0;
}

int main(int argc, char** argv) {

	ftw(argv[1], callback, MAX_FTW_DEPTH);

	printf("There were %d directories.", dirCount);
	printf("\n");
	printf("There were %d regular files.", files);

	return 0;
}
