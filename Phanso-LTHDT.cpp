#include <iostream>
using namespace std;

class PhanSo
{
private:
    int TS;
    int MS;

public:
    PhanSo();
    PhanSo(int ts, int ms);
    PhanSo(const PhanSo &b);
    ~PhanSo();
    
    void nhap();
    void xuat();
    void rutgon();

    PhanSo cong(PhanSo b);
    PhanSo tru(PhanSo b);
    PhanSo nhan(PhanSo b);
    PhanSo chia(PhanSo b);
    friend bool sosanh(PhanSo a, PhanSo b);
};

int UCLN(int a, int b)
{
    if(a < 0)
        a = -a;

    if(b < 0)
        b = -b;

    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

PhanSo::PhanSo()
{
    TS = 0;
    MS = 1;
}

PhanSo::PhanSo(int ts, int ms)
{
    TS = ts;

    if(ms == 0)
        MS = 1;
    else
        MS = ms;
}

PhanSo::PhanSo(const PhanSo &b)
{
    TS = b.TS;
    MS = b.MS;
}

PhanSo::~PhanSo()
{
}

void PhanSo::nhap()
{
    cout << "Tu so = ";
    cin >> TS;

    do
    {
        cout << "Mau so = ";
        cin >> MS;

        if(MS == 0)
            cout << "Mau so phai khac 0!" << endl;

    } while(MS == 0);
}

void PhanSo::rutgon()
{
    int u = UCLN(TS, MS);

    TS = TS / u;
    MS = MS / u;

    if(MS < 0)
    {
        TS = -TS;
        MS = -MS;
    }
}

void PhanSo::xuat()
{
    if(MS == 1)
        cout << TS;
    else
        cout << TS << "/" << MS;
}

PhanSo PhanSo::cong(PhanSo b)
{
    PhanSo c;

    c.TS = TS * b.MS + MS * b.TS;
    c.MS = MS * b.MS;

    c.rutgon();

    return c;
}

PhanSo PhanSo::tru(PhanSo b)
{
    PhanSo c;

    c.TS = TS * b.MS - MS * b.TS;
    c.MS = MS * b.MS;

    c.rutgon();

    return c;
}

PhanSo PhanSo::nhan(PhanSo b)
{
    PhanSo c;

    c.TS = TS * b.TS;
    c.MS = MS * b.MS;

    c.rutgon();

    return c;
}

PhanSo PhanSo::chia(PhanSo b)
{
    PhanSo c;

    c.TS = TS * b.MS;
    c.MS = MS * b.TS;

    c.rutgon();

    return c;
}
bool sosanh(PhanSo a, PhanSo b)
{
    return a.TS * b.MS == b.TS * a.MS;
}
int main()
{
    PhanSo a, b;

    cout << "Nhan phan so a" << endl;
    a.nhap();

    cout << "\nNhap phan so b" << endl;
    b.nhap();

    cout << "\nA = ";
    a.xuat();

    cout << "\nB = ";
    b.xuat();

    PhanSo c = a.cong(b);

    cout << "\n\nA + B = ";
    c.xuat();

    c = a.tru(b);

    cout << "\nA - B = ";
    c.xuat();

    c = a.nhan(b);

    cout << "\nA * B = ";
    c.xuat();

    c = a.chia(b);

    cout << "\nA / B = ";
    c.xuat();

    PhanSo d(a);

    cout << "\n\nPhan so D sao chep tu A = ";
    d.xuat();
    cout << "\n\nSo sanh A va B: ";

    if(sosanh(a, b))
        cout << "A = B";
    else
        cout << "A != B";

    cout << endl;

    return 0;
}
