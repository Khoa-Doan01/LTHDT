#include<iostream>
using namespace std;
int UCLN(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
class Phanso
{

private:
    int TS, MS;
public:
    void nhap();
    void xuat();
    Phanso cong(Phanso b);
    Phanso tru(Phanso d);
    Phanso nhan(Phanso e);
    Phanso chia(Phanso f); 
    void rutgon();
};

void Phanso::nhap()
{
    cout << "Tu so = ";
    cin >> TS;

    cout << "Mau so = ";
    cin >> MS;
}
void Phanso::xuat()
{
    cout << TS << "/" << MS << endl;
}
void Phanso::rutgon()
{	
    int u = UCLN(TS, MS);
    TS = TS / u;
    MS = MS / u;
}
Phanso Phanso::cong(Phanso b)
{
    Phanso c;
    c.TS = TS * b.MS + MS * b.TS;
    c.MS = MS * b.MS;
    c.rutgon();
    return c;
}
Phanso Phanso::tru(Phanso d)
{
    Phanso c;
    c.TS = TS * d.MS - MS * d.TS;
    c.MS = MS * d.MS;
    c.rutgon();
    return c;
}
Phanso Phanso::nhan(Phanso e)
{
    Phanso c;
    c.TS = TS * e.TS;
    c.MS = MS * e.MS;
    c.rutgon();
    return c;
}
Phanso Phanso::chia(Phanso f)
{
    Phanso c;
    c.TS = TS * f.MS;
    c.MS = MS * f.TS;
    c.rutgon();
    return c;
}
int main()
{
    Phanso x, y, z;
    cout << "Nhap x: " << endl;
    x.nhap();
    cout << "Nhap y: " << endl;
    y.nhap();
    z = x.cong(y);
    cout << "Tong = ";
    z.xuat();
    z =x.tru(y);
    cout << "hieu = ";
    z.xuat();
     z =x.nhan(y);
    cout << "tich = ";
    z.xuat();
     z =x.chia(y);
    cout << "thuong = ";
    z.xuat();
    return 0;
}

