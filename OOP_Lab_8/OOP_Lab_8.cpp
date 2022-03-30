#include <iostream>
#include <string.h>
#include <process.h>
#include <cstring>
#include "sterling.h"
#include "fraction.h"

using namespace std;

class publication
{
private:
    string name;
    float price;
public:
    publication() : name(""), price(0.0)
    { }
    void getdata()
    {
        cout << "Введите название книги: ";
        cin >> name;
        cout << "Введите цену книги: ";
        cin >> price;
    }
    void putdata()
    {
        cout << "Название книги: " << name << endl
            << "Цена книги: " << price << endl;
        
    }
};

class sales
{
private:
    float sale[3];
public:
    sales()
    {
        for (int i = 0; i < 3; i++)
        {
            sale[i] = 0.0;
        }
    }
    void getdata()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Введите общую стоимость за " << i + 1 << " месяц: ";
            cin >> sale[i];
        }
    }
    void putdata()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Общая стоимость за " << i + 1 << " месяц: " << sale[i] << endl;
        }
    }
};
class book : public publication, public sales
{
private:
    int count;
public:
    book() : publication(), count(0), sales()
    { }
    void getdata()
    {
        publication::getdata();
        cout << "Введите количество страниц в книге: ";
        cin >> count;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout << "Количество страниц в книге: " << count << endl;
        sales::putdata();
    }
};
class type : public publication, public sales
{
private:
    float minutes;
public:
    type() : publication(), minutes(0.0), sales()
    { }
    void getdata()
    {
        publication::getdata();
        cout << "Введите время записи в книге: ";
        cin >> minutes;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout << "Время записи: " << minutes << endl;
        sales::putdata();
    }
};

class disk : public publication
{
private:
    enum disks{ CD, DVD };
    disks dis;
    char sim;
public:
    disk() : publication(), dis(CD)
    { }
    void getdata()
    {
        publication::getdata();
        cout << "На чём вы хотите хранить данные CD/DVD?(c,d)\n";
        cin >> sim;
        switch (sim)
        {
        case 'c': dis = CD; break;
        case 'd': dis = DVD; break;
        default:
            cout << "Ошибка ввода!\n";
            break;
        }
    }
    void putdata()
    {
        publication::putdata();
        switch (dis)
        {
        case disk::CD: 
            cout << "Данные хранятся на CD-диске\n";
            break;
        case disk::DVD:
            cout << "Данные хранятся на DVD-диске\n";
            break;
        }
    }
};

class employee
{
private:
    static const int LEN = 80;
    char name[LEN];
    unsigned long number;
public:
    void getdata()
    {
        cout << "Введите имя сотрудника: "; cin >> name;
        cout << "Введите номер: "; cin >> number;
    }
    void putdata() const
    {
        cout << "Имя сотрудника: " << name << endl
            << "Номер сотрудника: " << number << endl;
    }
};
class compensation : public employee
{
private:
    double compensations;
    enum period { hour, week, month };
    period per;
    char sim;
public:
    void getdata()
    {
        employee::getdata();
        cout << "Введите сумму компенсации: "; cin >> compensations;
        cout << "Какую оплату получаете?(h, w, m)\n"; cin >> sim;
        switch (sim)
        {
        case 'h': per = hour; break;
        case 'w': per = week; break;
        case 'm': per = month; break;
        default:
            cout << "Вы ввели не корректные данные!\n";
            break;
        }
    }
    void putdata() const
    {
        employee::putdata();
        cout << "Сумма компенсации: " << compensations << endl;
        switch (per)
        {
        case compensation::hour: cout << "По часовая оплата\n";
            break;
        case compensation::week: cout << "По недельная оплата\n";
            break;
        case compensation::month: cout << "По месячная оплата\n";
            break;
        default:
            break;
        }
    }
};

class manager : public compensation
{
private:
    static const int LEN = 80;
    char title[LEN]; //должность
    double dues; //сумма взносов в гольф-клуб
public:
    void getdata()
    {
        compensation::getdata();
        cout << "Введите должность: "; cin >> title;
        cout << "Введите сумму взносов в гоьф-клуб: "; cin >> dues;
    }
    void putdata() const
    {
        compensation::putdata();
        cout << "Должность: " << title << endl
            << "Сумма взносов в гольф-клуб: " << dues << endl;
    }
};

class scientist : public compensation
{
private:
    int pubs; //количество публикаций
public:
    void getdata()
    {
        compensation::getdata();
        cout << "Введите количество публикация: "; cin >> pubs;
    }
    void putdata() const
    {
        compensation::putdata();
        cout << "Количество публикаций: " << pubs << endl;
    }
};

class laborer : public compensation
{
};

class safearray
{
protected:
    static const int LIMIT = 100;
    int arr[LIMIT];
public:
    int& operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "Ошибочный индекс!\n"; exit(1);
        }
        return arr[n];
    }
    int limit()
    {
        return LIMIT;
    }
};

class safehilo : public safearray
{
private:
    int top, bottom;
public:
    safehilo() : bottom(0), top(99)
    { }
    safehilo(int b, int t) : top(t), bottom(b)
    { }
    int& operator[](int n)
    {
        if ((n < bottom || n > top) || ((top - bottom + 1) >= LIMIT))
        {
            cout << "Ошибочный индекс!\n"; exit(1);
        }
        return arr[n % (top - bottom + 1)];
    }
    void setGran()
    {
        cout << "Введите нижнюю границу: ";
        cin >> bottom;
        cout << "Введите верхнюю границу: ";
        cin >> top;
    }
    int getindexbt()
    {
        return bottom;
    }
    int getindextp()
    {
        return top;
    }
};

class Counter
{
protected:
    unsigned int count;
public:
    Counter() : count()
    { }
    Counter(int c) : count(c)
    { }
    unsigned int get_count() const
    {
        return count;
    }
    Counter operator++()
    {
        return Counter(++count);
    }
    Counter operator--()
    {
        return Counter(--count);
    }
};

class counter : public Counter
{
public:
    counter() : Counter()
    { }
    counter(int c) : Counter(c)
    { }
    counter operator++(int)
    {
        return counter(++count);
    }
    counter operator--(int)
    {
        return counter(--count);
    }
    Counter::operator++;
    Counter::operator--;
};

class String
{
protected:
    static const int SIZE = 80;
    string s;
public:
    String()
    {
        s = '\0';
    }
    String(char s[])
    {
        this->s = s;
    }
    void display() const
    {
        cout << s;
    }
};

class Pstring : public String
{
public:
    Pstring(char s[]);
    string left(string s, int n)
    {
        if (n <= this->s.length())
        {
            for (int i = 0; i < n; i++)
            {
                this->s += s[i];
            }
        }
        else
        {
            cout << "вы ввели длину больше, чем она есть!\n";
        }
        return string(this->s);
    }
    string mid(string s1, int s, int n)
    {
        if (s >= 0 && s < n && n <= this->s.length())
        {
            for (int i = 0; i < this->s.length(); i++)
            {
                if (i >= s && i <= n)
                {
                    this->s += s1[i];
                }
            }
        }
        else
        {
            cout << "Вы ввели не корректные данные!\n";
        }
        return string(this->s);
    }
    string right(string s1, int n)
    {
        if (n <= s.length())
        {
            for (int i = s.length() - n; i < s.length(); i++)
            {
                s += s1[i];
            }
        }
        else
        {
            cout << "Вы ввели не кореектные данные!\n";
        }
        return string(s);
    }
};
Pstring::Pstring(char s[])
{
    if (strlen(s) > SIZE - 1)
    {
        int h;
        for(h = 0; h < SIZE - 1; h++)
        {
            s[h] = s[h];
        }
        s[h] = '\0';
    }
    else
    {
        this->s = s;
    }
}

class date {
private:
    int months, days, years;
public:
    void getdate() {
        cout << "Введите день: ";
        cin >> days;
        cout << "Введите месяц: ";
        cin >> months; 
        cout << "Введите год: ";
        cin >> years;
    }
    void showdate() const
    {
        cout << "Дата: " << days << "/" << months << "/" << years << endl;
    }
};
class publication2 : public publication
{
private:
    date data;
public:
    publication2() : publication()
    { }
    void getdata()
    {
        data.getdate();
    }
};
class book2 : public publication2
{
private:
    int count;
public:
    book2() : publication2(), count(0)
    { }
    void getdata()
    {
        publication::getdata();
        cout << "Введите количество страниц в книге: ";
        cin >> count;
        publication2::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout << "Количество страниц в книге: " << count << endl;
        publication2::putdata();
    }
};
class type2 : public publication2
{
private:
    float minutes;
public:
    type2() : publication2(), minutes(0.0)
    { }
    void getdata()
    {
        publication::getdata();
        cout << "Введите время записи в книге: ";
        cin >> minutes;
        publication2::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout << "Время записи: " << minutes << endl;
        publication2::putdata();
    }
};

class executive : public manager
{
private:
    double money;
    int stock;
public:
    void getdata()
    {
        manager::getdata();
        cout << "Размер годовой премии: ";
        cin >> money;
        cout << "Количество акций: ";
        cin >> stock;
    }
    void putdata()
    {
        manager::putdata();
        cout << "Размер годовой премии " << money << endl;
        cout << "Количество акций " << stock << endl;
    }
};

struct paiR
{
    int x, y;
};
class stack
{
protected:
    static const int MAX = 6;
    int st[MAX];
    int top;
public:
    stack()
    {
        top = -1;
    }
    void push(int var)
    {
        st[++top] = var;
    }
    int pop()
    {
        return st[top--];
    }
};
class stack2 : public stack
{
public:
    void push(int var)
    {
        if (top >= MAX - 1)
        {
            cout << "Ошибка: стек переполнен\n"; exit(1);
        }
        stack::push(var);
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Ошибка: стек пуст\n"; exit(1);
        }
        return stack::pop();
    }
};
class pairstack : public stack2
{
private:
    paiR Pair;
public:
    void push(paiR p)
    {
        stack2::push(p.x);
        stack2::push(p.y);
    }
    paiR pop()
    {
        Pair.y = stack2::pop();
        Pair.x = stack2::pop();
        return Pair;
    }
};

class sterfrac : public sterling, public fraction
{
private:
    void lowtermssterl()
    {
        int t = num / den;
        num -= t * den;
        long sum = pound * 12 * 20 + shilling * 12 + pence + t;
        pound = sum / 12 / 20;
        sum -= pound * 12 * 20;
        shilling = sum / 12;
        sum -= shilling * 12;
        pence = sum;
    }
public:
    sterfrac() : sterling(), fraction()
    { }
    sterfrac(double news, int a, int b) : sterling(news), fraction(a, b)
    { }
    sterfrac(long pound, int shilling, int pence, int a, int b) : sterling(pound, shilling, pence), fraction(a, b)
    { }
    sterfrac(sterling ster, fraction frac)
    {
        pound = ster.getpound();
        shilling = ster.getshil();
        pence = ster.getpence();
        num = frac.getnum();
        den = frac.getden();
    }
    void getsterfrac()
    {
        cout << "Введите сумму денег вида &*.*.*-*/*: ";
        sterling::getSterling();
        cin >> sim;
        fraction::get();
    }
    void show()
    {
        lowtermssterl();
        cout << "Сумма денег: ";
        sterling::shower();
        cout << "-";
        fraction::shower();
        cout << endl;
    }
    sterfrac operator+(sterfrac sfrac)
    {
        return sterfrac(sterling::add(sfrac.getss()), fraction::add(sfrac.gets()));
    }
    sterfrac operator-(sterfrac sfrac)
    {
        return sterfrac(sterling::minus(sfrac.getss()), fraction::minus(sfrac.gets()));
    }
    sterfrac operator*(sterfrac sfrac)
    {
        return sterfrac(sterling::proiz(sfrac.getss()), fraction::proiz(sfrac.gets()));
    }
    sterfrac operator/(sterfrac sfrac)
    {
        return sterfrac(sterling::chastnoe(sfrac.getss()), fraction::chastnoe(sfrac.gets()));
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    book Book;
    type Type;
    disk Disk;
    manager emp_m;
    scientist emp_s;
    laborer emp_l;
    safehilo safearr;
    counter counts, counts1(100);
    Pstring s1();
    bool end = true, find;
    int number, indt, indb;
    char ch;
    sterfrac sfrac, sfrac2, sfrac1;
    do
    {
        cout << "Введите номер задания, которого хотите проверить: ";
        cin >> number;
        switch (number)
        {
        case 1:
            Book.getdata();
            Type.getdata();
            Book.putdata();
            Type.putdata();
            break;
        case 3:
            Book.getdata();
            Type.getdata();
            Book.putdata();
            Type.putdata();
            break;
        case 4:
            Disk.getdata();
            Disk.putdata();
            break;
        case 5:
            emp_m.getdata();
            emp_s.getdata();
            emp_l.getdata();
            cout << "Данные о менеджере:\n";
            emp_m.putdata();
            cout << "Данные об учёном:\n";
            emp_s.putdata();
            cout << "Данные о рабочем:\n";
            emp_l.putdata();
            break;
        case 6:
            safearr.setGran();
            for (int i = safearr.getindexbt() ; i <= safearr.getindextp(); i++)
            {
                cin >> safearr[i];
            }
            for (int i = safearr.getindexbt(); i <= safearr.getindextp(); i++)
            {
                cout << "Значение " << i << " элемента: " << safearr[i] << endl;
            }
            break;
        case 7:
            counts1--;
            cout << (counts1--).get_count() << endl;
            --counts1;
            cout << counts1.get_count() << endl;
            ++counts; 
            cout << (counts++).get_count() << endl;
            cout << (++counts).get_count() << endl;
            break;
        case 12:
            sfrac1.getsterfrac();
            cout << "Какое арифметическое действие выполнить?(+,-,*,/)\n";
            cin >> ch;
            switch (ch)
            {
            case '+':
                sfrac2.getsterfrac();
                sfrac = sfrac1 + sfrac2;
                break;
            case '-':
                sfrac2.getsterfrac();
                sfrac = sfrac1 - sfrac2;
                break;
            case '*':
                sfrac2.getsterfrac();
                sfrac = sfrac1 * sfrac2;
                break;
            case '/':
                sfrac2.getsterfrac();
                sfrac = sfrac1 / sfrac2;
                break;
            default:
                cout << "Такого арифметичсекого действия нет!\n";
                break;
            }
            sfrac.show();
            break;
        default:
            cout << "Спасибо за проверку лабы!\n";
            end = false;
            break;
        }
    } while (end);
}
