#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <memory>
#include <cstdio>
#include <assert.h>
#include <iostream>
const int MAXN = 300005;
int numbers[MAXN];
int main() {
	int t;
	int n, x;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &numbers[i]);
		}
		int num_min = numbers[1];
		int num_max = numbers[1];
		int res = 0;
		for (int i = 2; i <= n; i++) {
			if (numbers[i] > num_max) {
				num_max = numbers[i];
			}
			if (numbers[i] < num_min) {
				num_min = numbers[i];
			}
			if (num_max - num_min > 2 * x) {
				res++;
				num_min = num_max = numbers[i];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
