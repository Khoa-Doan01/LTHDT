#include <iostream>
using namespace std;

class Mang1Chieu
{
private:
    int a[200];
    int n;

public:
    Mang1Chieu();

    Mang1Chieu(int n);

    Mang1Chieu(const Mang1Chieu &b);

    ~Mang1Chieu();

    friend void nhap(Mang1Chieu &a);
    friend void xuat(Mang1Chieu a);
    friend int timkiem(Mang1Chieu a, int x);
    friend void sapxep(Mang1Chieu &a);
    friend void chen(Mang1Chieu &a, int x, int k);
    friend void xoa(Mang1Chieu &a, int k);
    friend void tach(Mang1Chieu a, Mang1Chieu &chan, Mang1Chieu &le);
    friend void gop(Mang1Chieu a, Mang1Chieu b, Mang1Chieu &c);
};
Mang1Chieu::Mang1Chieu()
{
    n = 0;
}

Mang1Chieu::Mang1Chieu(int n)
{
    this->n = n;

    for(int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}

Mang1Chieu::Mang1Chieu(const Mang1Chieu &b)
{
    n = b.n;

    for(int i = 0; i < n; i++)
    {
        a[i] = b.a[i];
    }
}

Mang1Chieu::~Mang1Chieu()
{
}

void nhap(Mang1Chieu &a)
{
    cout << "Nhap n = ";
    cin >> a.n;

    for(int i = 0; i < a.n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a.a[i];
    }
}

void xuat(Mang1Chieu a)
{
    for(int i = 0; i < a.n; i++)
    {
        cout << a.a[i] << " ";
    }

    cout << endl;
}

int timkiem(Mang1Chieu a, int x)
{
    for(int i = 0; i < a.n; i++)
    {
        if(a.a[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void sapxep(Mang1Chieu &a)
{
    for(int i = 0; i < a.n - 1; i++)
    {
        for(int j = i + 1; j < a.n; j++)
        {
            if(a.a[i] > a.a[j])
            {
                int temp = a.a[i];
                a.a[i] = a.a[j];
                a.a[j] = temp;
            }
        }
    }
}

void chen(Mang1Chieu &a, int x, int k)
{
    if(k < 0 || k > a.n)
    {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    if(a.n >= 200)
    {
        cout << "Mang da day!" << endl;
        return;
    }

    for(int i = a.n; i > k; i--)
    {
        a.a[i] = a.a[i - 1];
    }

    a.a[k] = x;
    a.n++;
}

void xoa(Mang1Chieu &a, int k)
{
    if(k < 0 || k >= a.n)
    {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    for(int i = k; i < a.n - 1; i++)
    {
        a.a[i] = a.a[i + 1];
    }

    a.n--;
}


void tach(Mang1Chieu a, Mang1Chieu &chan, Mang1Chieu &le)
{
    chan.n = 0;
    le.n = 0;

    for(int i = 0; i < a.n; i++)
    {
        if(a.a[i] % 2 == 0)
        {
            chan.a[chan.n] = a.a[i];
            chan.n++;
        }
        else
        {
            le.a[le.n] = a.a[i];
            le.n++;
        }
    }
}


void gop(Mang1Chieu a, Mang1Chieu b, Mang1Chieu &c)
{
    c.n = 0;

    for(int i = 0; i < a.n; i++)
    {
        c.a[c.n] = a.a[i];
        c.n++;
    }

    for(int i = 0; i < b.n; i++)
    {
        c.a[c.n] = b.a[i];
        c.n++;
    }
}


int main()
{
    Mang1Chieu a;

    cout << "=== NHAP MANG ===" << endl;
    nhap(a);

    cout << "\nMang vua nhap: ";
    xuat(a);


    int x;

    cout << "\nNhap x can tim: ";
    cin >> x;

    int vt = timkiem(a, x);

    if(vt == -1)
    {
        cout << "Khong tim thay!";
    }
    else
    {
        cout << "Tim thay tai vi tri: " << vt;
    }

    sapxep(a);

    cout << "\n\nMang sau khi sap xep: ";
    xuat(a);

    int k, giatri;

    cout << "\nNhap gia tri can chen: ";
    cin >> giatri;

    cout << "Nhap vi tri can chen: ";
    cin >> k;

    chen(a, giatri, k);

    cout << "Mang sau khi chen: ";
    xuat(a);

    cout << "\nNhap vi tri can xoa: ";
    cin >> k;

    xoa(a, k);

    cout << "Mang sau khi xoa: ";
    xuat(a);


    Mang1Chieu chan, le;

    tach(a, chan, le);

    cout << "\nMang chan: ";
    xuat(chan);

    cout << "Mang le: ";
    xuat(le);


    Mang1Chieu b(a);

    cout << "\nMang b sao chep tu mang a: ";
    xuat(b);

    Mang1Chieu c;

    gop(a, b, c);

    cout << "\nMang c sau khi gop a va b: ";
    xuat(c);

    return 0;
}
