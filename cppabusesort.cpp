#include <algorithm>
#include <iomanip>
#include <iostream>

#if 0
Credit for the implementation of QuickSort here is fully owed to Brian Hays, Purdue University.
github.com/bphays/CAbuseSort
#endif

template<typename T>
void qs(T a, int s) {
	for (int i = 0, w = 0; s > 1 && (i < s - 1 || (qs(a, w), qs(a + w+ 1, s - w - 1), 0)); ((a[i] < a[s - 1] ? (a[i] != a[w] ? a[w] ^= a[i], a[i] ^= a[w], a[w] ^= a[i], w++ : w++) : 1), i++), i == s - 1 ? (a[w] != a[s - 1] ? a[s - 1] ^= a[w], a[w] ^= a[s - 1], a[s - 1] ^= a[w], 1 : 1) : 1);
}

int main() {
	std::vector<char> a = {'f','a','c','k','e','m','i','n','e','m','g','e','r','b','i','l','s'};
	std::vector<char>::iterator it = a.begin();
	qs(it, a.size());
	for (auto i : a) std::cout << i << std::endl;
}
