#pragma once
#include "LZ78.h"

void ac(string s) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c[255] = { 0 };
	int k = 0, t = 0;
	for (int i = 0; i < s.length(); i++)
	{
		c[(int)s[i]]++;
	}
	for (int i = 0; i < 255; i++)
	{
		if (c[i] != 0) k++;
	}
	char* alp = new char[k];
	char temp;
	int* count = new int[k];
	k = 0;
	for (int i = 0; i < 255; i++)
	{
		if (c[i] != 0)
		{
			alp[k] = (char)i;
			count[k] = c[i];
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = k - 1; j > i; j--)
		{
			if (count[j] > count[j - 1])
			{
				swap(count[j], count[j - 1]);
				swap(alp[j], alp[j - 1]);
			}
		}
	}
	float** inter = new float* [k];
	for (int count = 0; count < k; count++)
		inter[count] = new float[2];
	double down, up;
	inter[0][0] = 0.0;
	inter[0][1] = (double)count[0] / s.length();
	for (int i = 1; i < k; i++)
	{
		inter[i][0] = inter[i - 1][1];
		inter[i][1] = inter[i - 1][1] + (double)count[i] / s.length();
	}
	for (int i = 0; i < s.length() - 1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (s[i] == alp[j])
			{
				down = inter[j][0];
				up = inter[j][1];
				inter[0][0] = down;
				inter[0][1] = down + (up - down) * count[0] / s.length();
				for (int l = 1; l < k; l++)
				{
					inter[l][0] = inter[l - 1][1];
					inter[l][1] = inter[l - 1][1] + (up - down) * count[l] / s.length();
				}
			}
		}
	}
	for (int j = 0; j < k; j++)
	{
		if (alp[j] == s[s.length() - 1])
			cout << "Зашифрованное сообщение, любое число в полуинтервале: [" << inter[j][0] << ", " << inter[j][1] << ")";
	}
}
