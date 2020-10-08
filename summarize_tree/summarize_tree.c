#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
  struct stat buf;

  if(stat(path, &buf) == 0) {
	  if(S_ISDIR(buf.st_mode) > 0) {
		  return true;
	  } else {
		  return false;
	  }
  } else {
	  printf("Error in stat call: %s", path);
	  return 0;
  }
}

void process_path(const char*);

void process_directory(const char* path) {
  DIR *newDir;
  struct dirent *dirEntry;
  
  if((newDir = opendir(path)) == NULL) {
	  printf("Error, null directory path");
	  exit(0);
  }

  chdir(path);

  while (dirEntry = readdir(newDir)) {
	  if (strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0) {
		  process_path(dirEntry->d_name);
	  }
  }
  
  num_dirs++;
  
  chdir("..");
  closedir(newDir);
}

void process_file(const char* path) {
	++num_regular;
}

void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
