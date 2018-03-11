#include <stdio.h>

void pA(int *, int);
void qs(int *, int);

int main() {
	int a [] = {3, 4, 2, 6, 7, 3, 6, 1, 2, 15, 4, 9, 7, 4, 2, 5};
	puts("Before sort:");
	pA(a, 16);
	qs(a, 16);
	puts("After sort:");
	pA(a, 16);
}

void pA(int * a, int s) {
	for (int i = 0; i < s || puts("") && 0; printf("%d, ", a[i++]));
}

void qs(int * a, int s) {
	for (int i = 0, w = 0; s > 1 && (i < s-1 || (qs(a,w), qs(a+w+1,s-w-1), 0)); ((a[i] < a[s-1] ? (a[i] != a[w] ? a[w] ^= a[i], a[i] ^= a[w], a[w] ^= a[i], w++ : w++): 1), i++), i == s-1 ? (a[w] != a[s-1] ? a[s-1] ^= a[w], a[w] ^= a[s-1], a[s-1] ^= a[w], 1 : 1) : 1);
}
