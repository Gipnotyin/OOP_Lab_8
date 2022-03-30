#pragma once
#include <iostream>
#include <string.h>
#include <process.h>
#include <cstring>
using namespace std;
class sterling
{
protected:
	long pound;
	int shilling, pence;
	char sim;
	sterling perevod(int sum)
	{
		pound = sum / 12 / 20;
		sum -= pound * 12 * 20;
		shilling = sum / 12;
		sum -= shilling * 12;
		pence = sum;
		return sterling(pound, shilling, pence);
	}
public:
	sterling() :pound(0), shilling(0), pence(0)
	{ }

	sterling(double news)
	{
		double sm = news * 100.0F;
		this->pound = sm / 100;
		sm -= pound * 100;
		sm *= 2.4F;
		this->shilling = sm / 12;
		sm -= shilling * 12;
		this->pence = sm;
	}

	sterling(long pound, int shilling, int pence)
	{
		this->pound = pound;
		this->shilling = shilling;
		this->pence = pence;
	}
	void getSterling()
	{
		cin >> sim >> pound >> sim >> shilling >> sim >> pence;
	}

	void shower()
	{
		cout << "&" << pound << "." << shilling << "." << pence;
	}
	sterling add(sterling ster) 
	{
		long sum = pound * 12 * 20 + shilling * 12 + pence;
		long sum1 = ster.pound * 12 * 20 + ster.shilling * 12 + ster.pence;
		return perevod(sum + sum1);
	}
	sterling minus(sterling ster)
	{
		long sum = pound * 12 * 20 + shilling * 12 + pence;
		long sum1 = ster.pound * 12 * 20 + ster.shilling * 12 + ster.pence;
		return perevod(sum - sum1);
	}
	sterling proiz(sterling ster)
	{
		long sum = pound * 12 * 20 + shilling * 12 + pence;
		long sum1 = ster.pound * 12 * 20 + ster.shilling * 12 + ster.pence;
		return perevod(sum * sum1);
	}
	sterling chastnoe(sterling ster)
	{
		long sum = pound * 12 * 20 + shilling * 12 + pence;
		long sum1 = ster.pound * 12 * 20 + ster.shilling * 12 + ster.pence;
		return perevod(sum / sum1);
	}
	sterling getss()
	{
		return sterling(pound, shilling, pence);
	}
	int getpound()
	{
		return pound;
	}
	int getshil()
	{
		return shilling;
	}
	int getpence()
	{
		return pence;
	}
};

