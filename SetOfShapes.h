#pragma once
#include"TObj.h"
#include"Point.h"
#include"Vector.h"
#include"Printer.h"
#include"ComplexNumbs.h"
#include "Line.h"
#include"Square.h"
#include"Circle.h"
#include"Triangle.h"

template<class Type>
class TSet
{
public:
	int count;
	TObj<Type>** data;
	TSet();
	~TSet();
	void SetObj(TObj<Type>* _obj);

	void ToPrint();
	void ToPlot();
	void ToPrint(int _numb);
	void ToPlot(int _numb);
	void DeleteLastObj();
	int GetCount();
};

template<class Type>
inline TSet<Type>::TSet()
{
	data = 0;
	count = 0;
}

template<class Type>
inline TSet<Type>::~TSet()
{
	delete[] data;
	data = 0;
}

template<class Type>
inline void TSet<Type>::SetObj(TObj<Type>* _obj)
{
	if (data == 0)
	{
		data = new TObj<Type>*[1];
		count++;
		data[0] = _obj;
	}
	else
	{
		TObj<Type>** temp = new TObj<Type>*[count + 1];

		for (int q = 0; q < count; q++)
			temp[q] = data[q];

		delete[] data;
		data = 0;

		data = new TObj<Type>*[count + 1];

		for (int q = 0; q < count; q++)
			data[q] = temp[q];

		data[count] = _obj;
		count++;

		delete[] temp;
		temp = 0;

	}
}

template<class Type>
inline void TSet<Type>::ToPrint()
{
	if (count > 0)
		for (int q = 0; q < count; q++)
			data[q]->Print();
}

template<class Type>
inline void TSet<Type>::ToPlot()
{
	if (count > 0)
		for (int q = 0; q < count; q++)
			data[q]->Plot();
}

template<class Type>
inline void TSet<Type>::ToPrint(int _numb)
{
	if (_numb < 0 || _numb >(count - 1)) throw "Trying to get access to out of array";
	else
		data[_numb]->Print();
}

template<class Type>
inline void TSet<Type>::ToPlot(int _numb)
{
	if (_numb < 0 || _numb >(count - 1)) throw "Trying to get access to out of array";
	else
		data[_numb]->Plot();
}

template<class Type>
inline void TSet<Type>::DeleteLastObj()
{
	if (data == 0)throw"array is empty";
	else if (data != 0)
	{
		TObj<Type>** temp = new TObj<Type>*[count - 1];
		for (int q = 0; q < count - 1; q++)
			temp[q] = data[q];

		delete[] data;
		data = 0;

		count--;
		data = new TObj<Type>*[count];
		for (int q = 0; q < count; q++)
			data[q] = temp[q];
	}
}

template<class Type>
inline int TSet<Type>::GetCount()
{
	return count;
}