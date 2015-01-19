/*
 * main.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: trankien
 */

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>

void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  std::cout << m << " ";
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
            if (!isComposite[m])
                  std::cout << m << " ";
      delete [] isComposite;
}

const int SQRT_MAXN = 100000;
const int S = 10000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;

int main()
{
	int n;
	scanf("%d", &n);

//	std::vector<char> prime(n + 1, true);
//	prime[0] = prime[1] = false;
//	for (int i = 2; i <= n; ++i)
//	{
//		if (prime[i])
//		{
//			if (i * 1ll * i <= n)
//			{
//				for (int j = i * i; j <= n; j += i)
//				{
//					prime[j] = false;
//				}
//			}
//		}
//	}

	int nsqrt = (int) sqrt(n + .0);
	for (int i = 2; i <= nsqrt; ++i)
	{
		if (!nprime[i])
		{
			primes[cnt++] = i;
			if (i * 1ll * i <= nsqrt)
			{
				for (int j = i * i; j <= nsqrt; j += i)
				{
					nprime[j] = true;
				}
			}
		}
	}
	int result = 0;
	for (int k = 0, maxk = n / S; k <= maxk; ++k)
	{
		std::memset(bl, 0, sizeof bl);
		int start = k * S;
		for (int i = 0; i < cnt; ++i)
		{
			int start_idx = (start + primes[i] - 1) / primes[i];
			int j = std::max(start_idx, 2) * primes[i] - start;
			for (; j < S; j += primes[i])
			{
				bl[j] = true;
			}
		}
		if (k == 0)
		{
			bl[0] = bl[1] = true;
		}
		for (int i = 0; i < S && start + i <= n; ++i)
		{
			if (!bl[i])
			{
				++result;
			}
		}
	}
	std::cout << result;

	return 0;
}

