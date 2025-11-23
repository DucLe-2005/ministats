#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s file1 [file2 ...]\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		const char *filename = argv[i];
		struct Stats s;
		int rc = compute_file_stats(filename, &s);

		if (rc == -1) {
			printf("File: %s\n", filename);
			printf("Error: could not open file.\n\n");
			continue;
		} else if (rc == -2) {
			printf("File: %s\n", filename);
			printf("No valid numeric data found in file.\n\n");
			continue;
		}

		printf("File: %s\n", filename);
		printf("Count: %d\n", s.count);
		printf("Sum: %.3f\n", s.sum);
		printf("Mean: %.3f\n", s.mean);
		printf("Min: %.3f\n", s.min);
		printf("Max: %.3f\n", s.max);
		printf("Std Dev: %.3f\n\n", s.stddev);
	}

	return 0;
}
