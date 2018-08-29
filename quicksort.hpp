#include <iostream>
#include <vector>

#if 0
Credit for the implementation of QuickSort here is fully owed to Brian Hays, Purdue University.
github.com/bphays/CAbuseSort
#endif

template<typename T>
void quicksort(T a, int s) {
	auto t = *a;
	for (int i = 0, w = 0; s > 1 && (i < s - 1 || (quicksort(a,w), quicksort(a + w + 1, s - w - 1), 0)); ((a[i] < a[s - 1] ? (a[i] != a[w] ? t = a[i], a[i] = a[w], a[w] = t, w++ : w++) : 1), i++), i == s - 1 ? (a[w] != a[s - 1] ? t = a[w], a[w] = a[s - 1], a[s - 1] = t, 1 : 1) : 1);
}
