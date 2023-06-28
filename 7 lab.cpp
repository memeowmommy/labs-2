/*
Используя наследование и полиморфизм, напишите программу, которая работает с геометрическими фигурами:
1.	Треугольник
2.	Прямоугольник
3.	Круг

Программа должна хранить координаты и размеры фигуры, цвет, уметь вычислять площадь фигуры.
Продемонстрируйте, как ваша программа будет выводить на экран площади всех фигур.
*/

#include <iostream>
using namespace std;

enum class Color
{
	BLUE,
	GREEN,
	YELLOW
};

class Figure
{
private:

	Color m_color;
	double m_area = 0;
	double m_x_coord, m_y_coord;
	double m_angles;

public:

	Figure(Color color, double x_coord, double y_coord, double angles) : m_color(color), m_x_coord(x_coord), m_y_coord(y_coord), m_angles(angles) { }

	virtual double Area() {return m_area;}
};

class Triangle : public Figure
{
protected:

	double m_side_A = 0;
	double m_side_B = 0;
	double m_side_C = 0;

public:

	Triangle(Color color, double x_coord, double y_coord, double side_A, double side_B, double side_C) : Figure(color, x_coord, y_coord, 3)
	{m_side_A = side_A, m_side_B = side_B, m_side_C = side_C;}

	double Area() override
	{
		double p = (m_side_A + m_side_B + m_side_C) / 2;
		return sqrt(p * (p - m_side_A) * (p - m_side_B) * (p - m_side_C));
	}
};

class Rectangle : public Figure
{
protected:

	double m_height = 0;
	double m_width = 0;

public:

	Rectangle(Color color, double x_coord, double y_coord, double height, double width) : Figure(color, x_coord, y_coord, 4) { m_height = height, m_width = width; }

	double Area() override
	{return m_height * m_width;}
};

class Circle : public Figure
{
protected:
	double m_radius = 0;

public:

	Circle(Color color, double x_coord, double y_coord, double radius) : Figure(color, x_coord, y_coord, 0) { m_radius = radius; }

	double Area() override
	{return acos(-1) * m_radius * m_radius;}
};

int main()
{
	Triangle t(Color::BLUE, 4, 5, 4, 3, 5);
	Rectangle r(Color::GREEN, 3, 5, 1, 9);
	Circle c(Color::YELLOW, 1, 2, 5);
	cout << "Triangle: " << t.Area() << endl;
	cout << "Rectangle: " << r.Area() << endl;
	cout << "Circle: " << c.Area() << endl;
}