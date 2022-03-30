#pragma once
#include <iostream>
#include <string.h>
#include <process.h>
#include <cstring>
using namespace std;
class fraction {
protected:
	int num, den;
	char ch;
	void lowterms() // сокращение дроби
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num); // используем неотрицательные
		tden = labs(den); // значения (нужен cmath)
		if (tden == 0) // проверка знаменателя на 0
		{
			cout << "Недопустимый знаменатель!"; exit(1);
		}
		else if (tnum == 0) // проверка числителя на 0
		{
			num = 0; den = 1; return;
		}
		// нахождение наибольшего общего делителя
		while (tnum != 0)
		{
			if (tnum < tden) // если числитель больше знаменателя,
			{
				temp = tnum; tnum = tden; tden = temp;
			} // меняем их местами
			tnum = tnum - tden; // вычитание
		}
		gcd = tden; // делим числитель и знаменатель на
		num = num / gcd; // полученный наибольший общий делитель
		den = den / gcd;
	}
public:
	fraction()
	{
		num = 0, den = 1;
	}
	fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
		lowterms();
	}
	void get()
	{
		cin >> num >> ch >> den;
		lowterms();
	}
	void shower()
	{
		lowterms();
		cout << num << '/' << den;
	}
	fraction add(fraction frac2)
	{
		num = num * frac2.den + den * frac2.num;
		den = den * frac2.den;
		return fraction(num, den);
	}
	fraction minus(fraction frac2)
	{
		num = num * frac2.den - den * frac2.num;
		den = den * frac2.den;
		return fraction(num, den);
	}
	fraction proiz(fraction frac2)
	{
		num = num * frac2.num;
		den = den * frac2.den;
		return fraction(num, den);
	}
	fraction chastnoe(fraction frac2)
	{
		num = num * frac2.den;
		den = den * frac2.num;
		return fraction(num, den);
	}
	fraction gets()
	{
		return fraction(num, den);
	}
	int getnum()
	{
		return num;
	}
	int getden()
	{
		return den;
	}
};