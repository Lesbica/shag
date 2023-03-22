#include <iostream>
#include <fstream>
using namespace std;

class Circle
{
private:
    double x;
    double y;
    double r;
public:
    friend ofstream& operator<<(ofstream& out, Circle& cr);
    friend ifstream& operator>>(ifstream& in, Circle& cr);
    Circle(double x, double y, double r)
    {
        this->r = r;
        this->x = x;
        this->y = y;
    }

    double GetX()
    {
       return x; 
    }

    void SetX(double x)
    {
        this->x = x;
    }
    
    double GetY()
    {
        return y; 
    }

    void SetY(double y)
    {
        this->y = y;
    }
    
    double GetR()
    {
        return r; 
    }

    void SetR(double r)
    {
        this->r = r;
    }

    void Print()
    {
        cout << "x=" << x << endl;
        cout << "y=" << y << endl;
        cout << "r=" << r << endl;
    }

    void SaveToFile()
    {
        ofstream out;
        out.open("D:\\hello.txt");
        if (out.is_open())
        {
            out << "x=" << x << endl;
            out << "y=" << y << endl;
            out << "r=" << r << endl;
        }
    }

    bool SaveToFileBinary(const char* filename)
    {
        ofstream out(filename,ios::binary|ios::out);
        if(out.is_open())
        {
            out.write((char*)&x, sizeof x);
            out.write((char*)&y, sizeof y);
            out.write((char*)&r, sizeof r);
            out.close();
            return true;
        }
        return false;
    }

    bool LoadFromFileBinary(const char* filename)
    {
        ifstream in(filename,ios::binary|ios::in);
        if(in.is_open())
        {
            in.read((char*)&x, sizeof x);
            in.read((char*)&y, sizeof y);
            in.read((char*)&r, sizeof r);
            in.close();
            return true;
        }
        return false;
    }

    static bool SaveArrayCircle(Circle* AC, int count, const char* filename)
    {
        ofstream out;
        out.open(filename);
        if (out.is_open())
        {
            out << "count=" << count << endl;
            for (int i = 0; i < count; i++)
            {
                out << "circle " << i << ": "<<"x=" << AC[i].x << " " <<"y=" << AC[i].y << " " << "r=" << AC[i].r << " "<< endl;
            }
            return true;
        }
        return false;
    }
};

ofstream& operator<<(ofstream& out, Circle& cr)
{
    if (out.is_open())
    {
        out << cr.x << endl;
        out << cr.y << endl;
        out << cr.r << endl;
    }
    return out;
}

ifstream& operator>>(ifstream& in, Circle& cr)
{
    if (in.is_open())
    {
        in >> cr.x;
        in >> cr.y;
        in >> cr.r;
    }
    return in;
}

void main()
{
    Circle AС[3] = {Circle(1, 2, 3), Circle(4, 5, 6), Circle(7, 8, 9)};
    Circle test(0,0,0);
    test.SaveArrayCircle(AС, 3, "D:\\arraycircle.txt");
}

