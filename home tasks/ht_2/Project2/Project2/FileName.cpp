#include <iostream>
using namespace std;

struct rectangle {

	int length, width;

	void sum(rectangle other) {
		float perym1 = 2 * (this->length + this->width);
		float perym2 = 2 * (other.length + other.width);
		cout << "Sum of rectangles' perimeters: " << perym1 + perym2;
	}
};

int main() {
	rectangle first = { 2, 5 };
	rectangle second = { 4, 6 };

	first.sum(second);






	return 0;
}