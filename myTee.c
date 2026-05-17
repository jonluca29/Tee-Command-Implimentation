#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>



int main(int argc, char **argv){
	// argument guard
	if (argc < 2){
		fprintf(stderr, "Not enough arguments.\n");
		return -1;
	}

	char ch;

	// if the -a flag is not used then the file will be opened in write mode by default
	char *mode = "w";

	// look for flags
	for (int i = 1; i < argc; i++){
		if (strncmp(argv[i], "-a", 2) == 0){
			mode = "a";
		} else if (strncmp(argv[i], "-i", 2) == 0){
			// set SIGINT to be ignored
			signal(SIGINT, SIG_IGN);	
		}
	}
	
	FILE* fptr = fopen(argv[argc-1], mode);

	if (fptr == NULL){
		perror("The file is not opened");
		return -1;
	}

	// read input from stdin one character at a time
	while (read(STDIN_FILENO, &ch, 1) > 0){
		// print to stdout	
		putchar(ch);

		// write to the specified file
		fputc(ch, fptr);
	}
	
	fclose(fptr);

	return 0;
}
