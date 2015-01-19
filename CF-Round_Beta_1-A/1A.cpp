/*
 * 1A.cpp
 *
 *  Created on: Dec 12, 2014
 *      Author: trankien
 */

//http://codeforces.com/problemset/problem/1/A

#include <stdio.h>
#include <limits.h>

int main() {
	unsigned long long m, n, a, i, j;
	scanf("%I64d%I64d%I64d", &m, &n, &a);
	i = m / a;
	j = n / a;
	if (a * i != m) {
		i++;
	}
	if (a * j != n) {
		j++;
	}
	printf("%I64d", i * j);
	return 0;
}

