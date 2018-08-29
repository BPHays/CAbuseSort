#include <iostream>
#include <vector>
#include "quicksort.hpp"

int main() {
	/* Since this version of quicksort can sort any data type with the '<' operator, this is a demo of three examples of cases that work by default */
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
	quicksort(it2, s.size());
	for (auto i : s) std::cout << i <<  std::endl;
	std::vector<std::vector<std::string>>::iterator it3 = v.begin();
	quicksort(it3, v.size());
	for (auto i : v) {
		for (auto c : i) {
			std::cout << c << std::endl;
		}
	}
	std::vector<int>::iterator it4 = k.begin();
	quicksort(it4, k.size());
	for (auto i : k) std::cout << i << std::endl;

}
