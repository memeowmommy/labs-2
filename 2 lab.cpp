#include <iostream>
using namespace std;
/*
1.	Базовый конструктор																							     
2.	Конструктор копирования (правило 3-х)																		    
3.	Оператор присваивания копированием (правило 3-х)															     
4.	Деструктор (правило 3-х)																						 
5.	Операторы + и +=																							    
6.	Оператор [] – чтение и изменение элемента																		 
7.	Операторы <, >, ==																							     
8.	Операторы ввода и вывода в поток(>>, <<)																		 
9.	Метод find – поиск первого вхождения символа в строку слева														 
10.	Метод length – длина строки																					
11.	Метод c_str – получить массив char																				
12.	Метод at для получения доступа (чтение и изменение) к элементу строки с проверкой на выход за пределы строки    
*/

struct String
{
private:
	size_t m_size = 0;
	char* m_str = nullptr;

public:
	friend ostream& operator << (ostream& out, const String& str);
	friend istream& operator >> (istream& in, String& str);

	String(size_t c, size_t size) = delete;

// 1.	Базовый конструктор
	explicit String(const char* str) : m_size(strlen(str)), m_str(new char[m_size + 1])
	{copy(str, str + m_size + 1, m_str);}

	explicit String(char c, size_t size) : m_size(size), m_str(new char[size + 1])
	{
		fill(m_str, m_str + m_size, c);
		m_str[size] = '\0';
	}

// 2. Конструктор копирования (правило 3-х)

	String(const String& other) : String(other.m_str) {}

// 3. Оператор присваивания копированием (правило 3-х)
	String& operator = (const String& other)
	{
		String tmp = other;
		swap(this->m_size, tmp.m_size);
		swap(this->m_str, tmp.m_str);
		return *this;
	}

// 4. Деструктор (правило 3-х)
	~String()
	{
		if (m_str != nullptr) { delete[] m_str; }
	}

// 5. Операторы + и +=
	String& operator += (const String other)
	{
		size_t size = this->m_size + other.m_size;
		String tmp('q', size);

		for (int i = 0; i < this->m_size; i++)
		{tmp.m_str[i] = this->m_str[i];}
		for (int i = 0; i < other.m_size; i++)
		{tmp.m_str[i + this->m_size] = other.m_str[i];}
		
		swap(this->m_size, tmp.m_size);
		swap(this->m_str, tmp.m_str);

		return *this;
	}

	String operator + (const String& other) const
	{
		String tmp = *this;
		tmp += other;
		return tmp;
	}

	String operator + (const char* other) const
	{
		String tmp1 = *this;
		String tmp2(other);
		tmp1 += tmp2;
		return tmp1;
	}

// 6.	Оператор [] – чтение и изменение элемента
	char& operator [] (size_t el)
	{return this->m_str[el];}

	bool operator > (const String& other)
	{
		if (this->m_size > other.m_size) { return true; }
		else if (this->m_size < other.m_size) { return false; }
		else if (this->m_size == other.m_size)
		{
			for (int i = 0; i < this->m_size; i++)
			{
				if (int(this->m_str[i]) > int(other.m_str[i])) { return true; }
				if (int(this->m_str[i]) < int(other.m_str[i])) { return false; }
				if (int(this->m_str[i]) == int(other.m_str[i])) { continue; }
			}
			return false;
		}
	}

// 7.	Операторы <, >, ==
	bool operator < (const String& other)
	{
		if (this->m_size < other.m_size) { return true; }
		else if (this->m_size > other.m_size) { return false; }
		else if (this->m_size == other.m_size)
		{
			for (int i = 0; i < this->m_size; i++)
			{
				if (int(this->m_str[i]) < int(other.m_str[i])) { return true; }
				if (int(this->m_str[i]) > int(other.m_str[i])) { return false; }
				if (int(this->m_str[i]) == int(other.m_str[i])) { continue; }
			}

			return false;
		}
	}

	bool operator == (const String& other)
	{
		if (this->m_size != this->m_size) { return false; }
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_str[i] != other.m_str[i]) { return false; }
		}
		return true;
	}
// 9.	Метод find – поиск первого вхождения символа в строку слева
	size_t find(char tmp)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_str[i] == tmp) { return i; }
		}
		return -1;
	}

// 10. Метод length – длина строки
	size_t length()		{return m_size;}

// 11. Метод c_str – получить массив char
	char* c_str()	{return m_str;}
	
// 12. Метод at для получения доступа (чтение и изменение) 
//к элементу строки с проверкой на выход за пределы строки
	char& at(unsigned int index)
	{
		if ((this->m_size) > index + 1)
		{
			return (this->m_str[index]);
		}
		else
		{
			cout << "Error! String is out of range!" << endl;
			abort();
		}

	}


	void Print() const
	{
		for (int i = 0; i < this->m_size; i++)
			cout << m_str[i];
		cout << endl;
	}

};

// 8.	Операторы ввода и вывода в поток(>>, <<)
ostream& operator << (ostream& out, const String& str)
{
	for (int i = 0; i < str.m_size; i++)
	{out << str.m_str[i];}
	return out;
}

istream& operator >> (istream& in, String& str)
{
	char* tmp = new char[10000];
	in >> tmp;
	size_t ind = -1;

	for (int i = 0; i < 10000; i++)
	{
		if (tmp[i] == '\0')
		{
			ind = i;
			break;
		}
	}

	str.m_size = ind + 1;
	delete[] str.m_str;

	str.m_str = new char[str.m_size + 1];
	copy(tmp, tmp + ind + 1, str.m_str);
	delete[] tmp;

	return in;
}

int main()
{
	String s1("Hello, world!");
	cout << s1 << endl;
	String s2('g', 3);
	cout << s2 << endl;
	String s3("Hello, world!");
	s3 = s2 + s1 + "!!!";
	cout << s3 << endl;

	cout << s1[2] << endl;
	cout << (s1 > s2) << endl;
	cout << s1.find('o') << endl;

	cin >> s2;
	cout << s2 << endl;
}