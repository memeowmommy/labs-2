#include <iostream>
#include <string>
using namespace std;

class Coder
{
private:

    int m_CurrentKey[30] = {};
    int m_FibKey[30] = { 1, 2 };
    int m_SwapingKey[30] = { 1, 2 };

    string m_Message;
    string m_Words[30];

    int m_isKeyCorrect = 0;
    int WordCount = 1;


    void Fibonacci() // последовательсность Фибоначи 
    {
        for (int i = 2; i < WordCount; i++)
        { m_FibKey[i] = m_FibKey[i - 1] + m_FibKey[i - 2];}
    }

    void WordsCount(const string& Message) // счетчик слов
    {
        for (int i = 0; i < Message.length(); i++)
        {
            if (Message[i] == ' ')
            { WordCount++;}
        }
    }

public:

    Coder(string Message)
    {
        m_Message = Message;
        WordsCount(Message);
        Fibonacci();

        int counter = -1;
        for (int i = 0; i < WordCount; i++)
        {
            counter++;
            while (Message[counter] != ' ')
            {
                m_Words[i] += Message[counter];
                if (counter < Message.length())
                {counter++;}
                else break;
            }
        }
    }

    void Encode()
    {
        for (int i = 0; i < WordCount; i++)
        {m_SwapingKey[i] = m_CurrentKey[i];}

        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < WordCount; j++)
            {
                if (m_SwapingKey[i] == m_FibKey[j])
                {
                    swap(m_Words[i], m_Words[j]);
                    swap(m_SwapingKey[i], m_SwapingKey[j]);
                }
            }
        }
    }

    void Decode()
    {
        for (int i = 0; i < WordCount; i++)
        {m_SwapingKey[i] = m_CurrentKey[i];}

        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < WordCount; j++)
            {
                if (m_CurrentKey[i] == m_FibKey[j])
                {
                    swap(m_Words[i], m_Words[j]);
                    swap(m_CurrentKey[i], m_CurrentKey[j]);
                }
            }
        }

        for (int i = 0; i < WordCount; i++)
        {m_CurrentKey[i] = m_SwapingKey[i];}

    }

    void Output() const
    {
        if (m_isKeyCorrect == 1)
        {
            for (int i = 0; i < WordCount; i++)
            {cout << m_Words[i] << " ";}
        }
    }

    void InputKey()
    {
        cout << "Input key: ";
        for (int i = 0; i < WordCount; i++)
        {cin >> m_CurrentKey[i];}
    }

    void OutputCurrentKey()
    {
        int flag = 0;
        cout << "Current key: ";
        for (int i = 0; i < WordCount; i++)
        {
            for (int j = 0; j < WordCount; j++)
            {if (m_CurrentKey[i] == m_FibKey[j])   {flag++;} }
        }

        if (flag == WordCount) { m_isKeyCorrect = 1;}

        if (m_isKeyCorrect == 1)
        {
            for (int i = 0; i < WordCount; i++)
            {cout << m_CurrentKey[i] << " ";}
        }
        else if (m_isKeyCorrect == 0)   {cout << "Incorrect key!";}
    } 
};

int main()
{
    cout << "Input message: " << endl;
    string Message;
    getline(cin, Message);
    Coder Cd(Message);
    Cd.InputKey();
    cout << endl;

    cout << "Encode: ";
    Cd.Encode();
    Cd.OutputCurrentKey();
    cout << endl;
    cout << "Output: ";
    Cd.Output();
    cout << endl;

    cout << "Decode: ";
    Cd.Decode();
    Cd.OutputCurrentKey();
    cout << endl;
    cout << "Output: ";
    Cd.Output();
}