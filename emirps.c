#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int is_prime(int num) {
	int max = 0, i = 0;

	if (num % 2 == 0) {
		return 0;
	}

	max = ((num - 1) / 2);

	for (i = 2; i < max; i++) {
		if (num % ((2 * i) + 1) == 0) {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[]) {
	int rc = 0, prime = 0, emirp = 0, start = 0, finish = 0, i = 0, l = 0;
	size_t length = 0;
	char *exec = NULL, *usage = NULL;

	if (argc < 2) {
		usage = "Usage: ";
		exec = argv[0];

		length = strlen(exec) + strlen(usage);

		printf("%s%s <finish>\n", usage, exec);
		printf("%*s <start> <finish>\n", (int)length, " ");

		rc = 1;
		goto cleanup;
	}

	finish = atoi(argv[1]);

	if (argc > 2) {
		start = finish;
		finish = atoi(argv[2]);
	}

	for (i = start, l = finish; i <= l; i++) {
		if (i < 13) {
			continue;
		}

		if (is_prime(i) == 0) {
			continue;
		}

		prime = i;
		emirp = 0;

		while (prime > 0) {
			emirp *= 10;
			emirp += (prime % 10);
			prime -= (prime % 10);
			prime /= 10;
		}

		if (i == emirp) {
			continue;
		}

		if (is_prime(emirp) == 0) {
			continue;
		}

		printf("%d\n", i);
	}

cleanup:
	return rc;
}