#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stats.h"

#define MAX_VALUES 100000

int compute_file_stats(const char *filename, struct Stats *out_stats) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}

	double values[MAX_VALUES];
	int count = 0;
	double num;
	double sum = 0.0;
	double min = values[0];
	double max = values[0];

	// Check if file is empty
	if (fscanf(fp, "%lf", &num) == 1) {
		count = 1;
		sum = num;
		min = num;
		max = num;
	} else {
		// No valid numbers at all
		return -2;
	}


	// Read numbers
	while (count < MAX_VALUES && fscanf(fp, "%lf", &num) == 1) {
		values[count] = num;
		count++;
	}

	fclose(fp);

	// Compute sum, min, max
	for (int i = 0; i < count; i++) {
		double x = values[i];
		sum += x;
		if (x < min) min = x;
		if (x > max) max = x;
	}

	double mean = sum / count;

	// Compute variance
	double sq_diff_sum = 0.0;
	for (int i = 0; i < count; i++) {
		double diff = values[i] - mean;
		sq_diff_sum += diff * diff;
	}

	double variance = sq_diff_sum / count;
	double stddev = sqrt(variance);

	out_stats->count = count;
	out_stats->sum = sum;
	out_stats->mean = mean;
	out_stats->min = min;
	out_stats->max = max;
	out_stats->stddev = stddev;

	return 0;
}
