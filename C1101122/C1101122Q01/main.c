#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include "util.h"

int main(int argc, char* argv[])
{
	int seq1[20] = { 1, 2, 3, 4, 5 };
	int seq2[20] = { 6, 7, 8, 9, 10 };
	int seq_out[40] = { 0 };
	int n1 = 5, n2 = 5, n_total, p = 2;

	/**
	* Hint
	* positon : 0 1 2 3 4 5 6 7 8 9
	* seq1    : 1 2           3 4 5
	* seq2    :     6 7 8 9 10
	*/
	insert_sequence(seq1, n1, seq2, n2, seq_out, &n_total, p);
	// printf("%d\n", n_total);

	// in this example result should be: 1 2 6 7 8 9 10 3 4 5
	print_data(seq_out, n_total);

	return 0;
}