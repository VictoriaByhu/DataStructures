#include <iostream>
using namespace std;
struct triangle
	{
		int side1;
		int side2;
		int side3;

		bool isValid()
		{
			return (side1 + side2 > side3) &&
				(side1 + side3 > side2) &&
				(side2 + side3 > side1);
		}

		float area()
		{
			float p = (side1 + side2 + side3) / 2;
			return sqrt(p * (p - side1) * (p - side2) * (p - side3));
		}
	};
void input(triangle & n, string name)
{
	do
	{
		cout << "Enter the sides of " << name << " triangle: ";
		cin >> n.side1 >> n.side2 >> n.side3;

		if (!n.isValid())
		{
			cout << "Invalid triangle! The sum of any two sides must be greater than the third side. Try again.\n";
		}

	} while (!n.isValid());
}
int main()
{
	
	triangle x;
	triangle y;
	
	input(x, "the first");
	input(y, "the second");


	float areaX = x.area();
	float areaY = y.area();

	cout << "The area of the first triangle is: " << areaX << endl;
	cout << "The area of the second triangle is: " << areaY << endl;

	cout << "Sum of two areas: " << areaX + areaY << endl;

	
	return 0;
}