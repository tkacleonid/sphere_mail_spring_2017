#include <stdio.h>
#include <stdlib.h>


int main()
{
	unsigned int n, k, m, l;
	int i,j;

	scanf("%d %d %d %d", &n,&k,&m,&l);

	unsigned int *ar = new unsigned int[n]();
	unsigned int *ar_sort = new unsigned int[n]();
	unsigned int *tmp;

	unsigned int cnt[4][257] = {0};

	ar[0] = k;
	cnt[0][1 + (ar[0] & 0xff)]++;
	cnt[1][1 + ((ar[0] >> 8) & 0xff)]++;
	cnt[2][1 + ((ar[0] >> 16) & 0xff)]++;
	cnt[3][1 + ((ar[0] >> 24) & 0xff)]++;
	for(i = 1; i < n; i++) {
		ar[i] = (unsigned int)((ar[i-1]*(unsigned long long)m)&0xFFFFFFFFU)%l;
		cnt[0][1 + (ar[i] & 0xff)]++;
		cnt[1][1 + ((ar[i] >> 8) & 0xff)]++;
		cnt[2][1 + ((ar[i] >> 16) & 0xff)]++;
		cnt[3][1 + ((ar[i] >> 24) & 0xff)]++;
	}

	long long res = 0;
	for (j = 0; j < 4; j++) {
		for (i = 1; i < 257; i++) cnt[j][i] += cnt[j][i - 1];
		for (i = 0; i < n; i++) {
			ar_sort[cnt[j][(ar[i] >> (8 * j)) & 0xff]++] = ar[i];
		}
		tmp = ar_sort;
		ar_sort = ar;
		ar = tmp;
	}

	for(i = 0; i < n; i+=2) {res += ar[i]%l;res%=l;}

	printf("%d",res);


	return 0;
}