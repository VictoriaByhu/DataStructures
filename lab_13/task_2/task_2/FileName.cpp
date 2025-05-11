#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Student
{
	string name;
	double mark;

public:
	Student(string n = "Oleg", double m = 5) : name(n), mark(m) {}

	void print() const {
		cout << "Name: " << name << ", Mark: " << mark << endl;
	}
};

void reverseQueue(queue<Student>& s)
{
	stack<Student> st;

	while (!s.empty())
	{
		st.push(s.front());
		s.pop();
	}

	while (!st.empty())
	{
		s.push(st.top());
		st.pop();
	}
}


int main()
{
	queue<Student> s;

	s.push(Student("Kateryna", 8));
	s.push(Student("Ivan", 5));
	s.push(Student("Anya", 6));
	s.push(Student("Mykola", 4));

	cout << "Original queue:" << endl;
	queue<Student> temp = s; 
	while (!temp.empty()) {
		temp.front().print();
		temp.pop();
	}

	reverseQueue(s);

	cout << "\nReversed queue:" << endl;
	while (!s.empty()) {
		s.front().print();
		s.pop();
	}

	return 0;
}