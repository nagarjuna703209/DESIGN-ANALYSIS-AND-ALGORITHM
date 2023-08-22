#include <bits/stdc++.h>
using namespace std;

double cont[1000][1000];


void num_of_containers(int n,
					double x)
{
	int count = 0;


	cont[1][1] = x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {


			if (cont[i][j] >= (double)1) {
				count++;

			
				cont[i + 1][j]
					+= (cont[i][j]
						- (double)1)
					/ (double)2;

				cont[i + 1][j + 1]
					+= (cont[i][j]
						- (double)1)
					/ (double)2;
			}
		}
	}
	cout << count;
}

int main()
{
	int n = 3;
	double x = 5;
	num_of_containers(n, x);
	return 0;
}

