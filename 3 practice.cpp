#include <iostream>
using namespace std;

class KinematicSolver
{
private:
    float m_L1, m_L2, m_L3 = 1; //стороны АВС
    float m_alpha, m_beta, m_gamma = 0; //углы АВС
    float m_angle_A, m_angle_B = 0; //искомые углы А и В
    int m_x, m_y = 0; //координаты точки А
    int errormark = 0;

public:

    KinematicSolver(int x, int y, float L1, float L2)
    {   
        m_x = x;
        m_y = y;
        m_L1 = L1; //CB
        m_L2 = L2; //BA
        m_L3 = sqrt(x * x + y * y); // CA
        this->Solve(m_x, m_y);
    }

    void Link1(size_t L1)
    {
        if (L1 == 0)
        {
            cout << "Cannot be solved. Incorrect data." << endl;
            errormark = 0;
        }
        else
        {
            m_L1 = L1;
            Solve(m_x, m_y);
            errormark++;
        }
    }

    void Link2(size_t L2)
    {
        if (L2 == 0)
        {
            cout << "Cannot be solved. Incorrect data." << endl;
            errormark = 0;
        }
        else
        {
            m_L2 = L2;
            Solve(m_x, m_y);
            errormark++;
        }
    }

    void Print()
    {
        if (errormark >= 3)
        {
            cout << "L1 (CB): " << m_L1 << "    L2 (BA): " << m_L2 << "    CA: " << m_L3 << " " << endl;
            cout << "Alpha: " << m_alpha << "    Beta: " << m_beta << "    Gamma: " << m_gamma << endl;
            cout << "A: " << m_angle_A << "    B: " << m_angle_B << endl;
        }
    }

    void Solve(int x, int y)
    {
        if (abs((m_L2 * m_L2 + m_L3 * m_L3 - m_L1 * m_L1) / (2 * m_L2 * m_L3)) > 1)
        {
            cout << "Cannot be solved." << endl;
            m_alpha = -1;
            m_beta = -1;
            m_gamma = -1;
            errormark = 0;
        }
        else
        {
            m_alpha = acos((m_L2 * m_L2 + m_L3 * m_L3 - m_L1 * m_L1) / (2 * m_L2 * m_L3)) * (180 / acos(-1));
            m_beta = acos((m_L1 * m_L1 + m_L3 * m_L3 - m_L2 * m_L2) / (2 * m_L1 * m_L3)) * (180 / acos(-1));
            m_gamma = 180 - m_alpha - m_beta;
            errormark += 3;
            Angles();
        }
    }

    void Angles()
    {
        m_angle_A = m_alpha - atan((-m_y) / (-m_x)); //A=Alpha-A' 
        m_angle_B = 180 - m_beta; //B=180-Beta
    }

};

int main()
{
    KinematicSolver s1(1, 2, 1, 2);
    s1.Print();
    float a = 1;
    //s1.Link1(0);
    //s1.Link2(a);
}