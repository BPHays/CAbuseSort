#include <iostream>
#include <vector>

#if 0
Credit for the implementation of QuickSort here is fully owed to Brian Hays, Purdue University.
github.com/bphays/CAbuseSort
#endif

template<typename T>
void qs2(T a, int s) {
	auto t = *a;
	for (int i = 0, w = 0; s > 1 && (i < s - 1 || (qs2(a,w), qs2(a + w + 1, s - w - 1), 0)); ((a[i] < a[s - 1] ? (a[i] != a[w] ? t = a[i], a[i] = a[w], a[w] = t, w++ : w++) : 1), i++), i == s - 1 ? (a[w] != a[s - 1] ? t = a[w], a[w] = a[s - 1], a[s - 1] = t, 1 : 1) : 1);
}

int main() {
	std::vector<std::string> s = {
			"Sophia","Jackson"
			,"Emma","Aiden"
			,"Olivia","Lucas"
			,"Ava","Liam"
			,"Mia","Noah"
			,"Isabella","Ethan"
			,"Riley","Mason"
			,"Aria","Caden"
			,"Zoe","Oliver"
			,"Charlotte","Elijah"
			,"Lily","Grayson"
			,"Layla","Jacob"
			,"Amelia","Michael"
			,"Emily","Benjamin"
			,"Madelyn","Carter"
			,"Aubrey","James"
			,"Adalyn","Jayden"
			,"Madison","Logan"
			,"Chloe","Alexander"
	};
	std::vector<std::vector<std::string>> v = {{"hello", "I", "am", "a", "vector"}, {"And", "I", "am", "one", "too"}, {"Vector", "number", "three", "here"}};

	std::vector<int> k = {5, 32, 9, 29, 1, 9, 3, 1, 9, 14, 2, 6, 2, 7, 8, 8 ,291, 38, 48, 2834,325,3465346,32542,4,21342,353,6,457,456345,-40};
	
	std::vector<std::string>::iterator it2 = s.begin();
	qs2(it2, s.size());
	for (auto i : s) std::cout << i <<  std::endl;
	std::vector<std::vector<std::string>>::iterator it3 = v.begin();
	qs2(it3, v.size());
	for (auto i : v) {
		for (auto c : i) {
			std::cout << c << std::endl;
		}
	}
	std::vector<int>::iterator it4 = k.begin();
	qs2(it4, k.size());
	for (auto i : k) std::cout << i << std::endl;

}
