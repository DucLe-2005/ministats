#ifndef STATS_H
#define STATS_H

struct Stats {
	int count;
	double sum;
	double mean;
	double min;
	double max;
	double stddev;
};

/**
 *  Analyze one file.
 *  Returns:
 *  	0 on success
 *  	-1 if file could not be opened
 *  	-2 if no valid numbers in file
 */
int compute_file_stats(const char *filename, struct Stats *out_stats);

#endif
