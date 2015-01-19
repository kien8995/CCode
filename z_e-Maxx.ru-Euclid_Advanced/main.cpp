/*
 * main.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: trankien
 */

//a*x + b*y = gcd(a,b)
int gcd(int a, int b, int & x, int & y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{

	return 0;
}

