#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int i_MaxSize = 0;
    int i_Size = 0;
    T* i_Elements;
public:
    Stack(int msize)
    {
        i_MaxSize = msize;
        try
        {i_Elements = new T[msize];}
        catch (const std::bad_alloc)
        {cerr << "Constructor ERROR: too big size";}
    }

    int Size()
    {return i_Size;}

    bool Empty()
    {return i_Size != 0;}

    bool push(T NewElement)
    {
        if (i_Size < i_MaxSize)
        {
            i_Elements[i_Size] = NewElement;
            ++i_Size;
        }
        else
        {throw overflow_error("push ERROR: stack is full");}
    }

    T Pop()
    {
        if (i_Size != 0)
        {
            T tmp = i_Elements[0];
            for (int i = 0; i < i_MaxSize - 1; ++i)
            {i_Elements[i] = i_Elements[i + 1];}
            --i_Size;
            return tmp;
        }
        else
        {
            throw out_of_range("Pop ERROR: stack is empty");}
        
    }

    T& Top()
    {
        if (i_Size != 0)
        {return i_Elements[i_Size - 1];}
        else
        {throw logic_error("Top ERROR: stack is empty");}
    }

    ~Stack()
    {delete[] i_Elements;}

};

int main()
{
    Stack<int> stack(25);
    for (int i = 1; i < 25; ++i)
    {stack.push(i);}

    cout << stack.Size() << "\n";
    cout << stack.Pop() << "\n";
    cout << stack.Size() << "\n";
    cout << stack.Top() << "\n";
    cout << stack.Size() << "\n";
    cout << stack.Empty() << "\n";
}
