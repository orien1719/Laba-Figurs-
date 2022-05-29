#pragma once
#include"TObj.h"
template <class Type>
class TTrinagle : public TObj<Type>
{
protected:
	TVector<Type> FirstPoint, SecondPoint, ThirdPoint;
	int dim;
	TString name;

public:
	Printer<Type> printer;
	TTrinagle();
	TTrinagle(const TTrinagle<Type>& q);
	~TTrinagle();
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TTrinagle<Type>::TTrinagle()
{
	std::cout << "input dim of first point" << std::endl;
	std::cin >> FirstPoint;

	std::cout << std::endl;

	std::cout << "input dim of second point" << std::endl;
	std::cin >> SecondPoint;

	std::cout << std::endl;

	std::cout << "input dim of third point" << std::endl;
	std::cin >> ThirdPoint;

	dim = FirstPoint.GetLength();
	name.SetConstString("triangle");
	if (FirstPoint.GetLength() != SecondPoint.GetLength() && FirstPoint.GetLength() != ThirdPoint.GetLength()) throw "dim of 1-st point != dim of 2-d point !!!";

}

template<class Type>
inline TTrinagle<Type>::TTrinagle(const TTrinagle<Type>& q)
{
	name = q.name;
	FirstPoint = q.FirstPoint;
	SecondPoint = q.SecondPoint;
	ThirdPoint = q.ThirdPoint;
	dim = q.dim;
}

template<class Type>
inline TTrinagle<Type>::~TTrinagle()
{
}

template<class Type>
inline void TTrinagle<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "FirstVector = " << FirstPoint << std::endl;
	std::cout << "SecondVector = " << SecondPoint << std::endl;
	std::cout << "ThirdVector = " << ThirdPoint << std::endl;
}

template<class Type>
inline void TTrinagle<Type>::Plot()
{
	printer.drawLine(FirstPoint[1], FirstPoint[0], SecondPoint[1], SecondPoint[0]);
	printer.drawLine(FirstPoint[1], FirstPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.drawLine(SecondPoint[1], SecondPoint[0], ThirdPoint[1], ThirdPoint[0]);
	printer.ToPrint();

}

template<class Type>
inline int TTrinagle<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TTrinagle<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TTrinagle<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TTrinagle<Type>::operator[](int i)
{
	switch (i)
	{
	case 0:
		return FirstPoint;
	case 1:
		return SecondPoint;
		break;
	case 2:
		return ThirdPoint;
		break;

	default:
		throw "undefined behavior. You trying to get unexist cell of array";
	}
}