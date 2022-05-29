#pragma once
#include"Vector.h"

template <class Type>
class Printer
{
	
protected:
	Type qwerty = 0;

	char board[61][121];
public:
	Printer();
	void InsertPoint(const TVector<Type>& _vec1);
	void InsertPoint(float x, float y);
	void drawLine(Type x1, Type y1, Type x2, Type y2);
	void InsertLine(float x1, float y1, float x2, float y2);
	void InsertCircle(Type x0, Type y0, Type radius);
	void ToPrint();
	void clear();
};

template<class Type>
inline Printer<Type>::Printer()
{
	clear();
}

template<class Type>
inline void Printer<Type>::InsertPoint(const TVector<Type>& _vec1)
{
	TVector<Type> temporary = _vec1;
	board[(int)temporary[0]][(int)temporary[1]] = '.';
}

template<class Type>
inline void Printer<Type>::InsertPoint(float x, float y)
{
	board[(int)x][(int)y] = '.';
}

template<class Type>
inline void Printer<Type>::InsertCircle(Type x, Type y, Type _radius)
{
	for (float m = (float)(x - _radius); m < (float)(x + _radius); m += 0.01)
	{
		for (float p = (float)(y - _radius); p < (float)(y + _radius); p += 0.01)
		{
			if (round((m - x) * (m - x) + (p - y) * (p - y)) == round(_radius * _radius))
				InsertPoint(round(m), round(p));

		}
	}
}


template<class Type>
inline void Printer<Type>::ToPrint()
{
	int i = 0;
	std::cout << "  ";
	for (int q = 0; q < 121; q++)
	{
		std::cout << i;
		i++;
		if (i > 9) i = 0;
	}
	i = 0;
	std::cout << std::endl;

	for (int q = 0; q < 121; q++)
		std::cout << '_';

	for (int q = 0; q < 61; q++)
	{
		std::cout << i << '|';
		i++;
		if (i > 9) i = 0;

		for (int w = 0; w < 121; w++)
			std::cout << board[q][w];
		std::cout << std::endl;
	}
}

template<class Type>
inline void Printer<Type>::clear()
{
	for (int q = 0; q < 61; q++)
	{
		for (int w = 0; w < 121; w++)
			board[q][w] = ' ';
	}
}

template<class Type>
inline void Printer<Type>::drawLine(Type x1, Type y1, Type x2, Type y2)
{
	const int deltaX = (int)abs(x2 - x1);
	const int deltaY = (int)abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	InsertPoint(x2, y2);
	while (x1 != x2 || y1 != y2)
	{
		InsertPoint(x1, y1);
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}
template<class Type>
inline void Printer<Type>::InsertLine(float x1, float y1, float x2, float y2) 
{
	double xx1 = x1;
	double xx2 = x2;
	double yy1 = y1;
	double yy2 = y2;

	if (xx1 > xx2) {
		float t = xx1; xx1 = xx2; xx2 = t;
		t = yy1; yy1 = yy2; yy2 = t;
	}
	for (float t = xx1; t <= xx2; t += 0.1)
	{
		if (yy2 > yy1)
			for (float m = yy1; m <= yy2; m += 0.1)
			{
				if (round((t - xx1) * (yy2 - yy1)) == round((m - yy1) * (xx2 - xx1)))
				{
					InsertPoint(round(t), round(m));
				}
			}
		else
			for (float m = yy2; m <= yy1; m += 0.1)
			{
				if (round((t - xx1) * (yy2 - yy1)) == round((m - yy1) * (xx2 - xx1)))
				{
					InsertPoint(round(t), round(m));
				}
			}
	}

}