#pragma once
#include "TObj.h"

template <class Type>
class TCircle : public TObj<Type>
{
protected:
	TVector<Type> point;
	Type radius;
	int dim;
	TString name;

public:
	Printer<Type> printer;
	Type x, y, r;
	TCircle(Type _radius);
	TCircle(const TCircle<Type>& _circle);
	~TCircle();
	virtual void Print();
	virtual void Plot();
	virtual int GetDim();
	void SetRadius(Type _radius);
	Type GetRadius();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();
	virtual TVector<Type>& operator [] (int i);
};

template<class Type>
inline TCircle<Type>::TCircle(Type _radius)
{
	std::cout << "input dim of circle" << std::endl;
	std::cin >> point;
	dim = point.GetLength();
	name.SetConstString("circle");
	radius = _radius;
	x = 0; y = 0; r = 0;
}

template<class Type>
inline TCircle<Type>::TCircle(const TCircle<Type>& _circle)
{

	point = _circle.point;
	dim = _circle.dim;
	name = _circle.name;
	radius = _circle.radius;
}

template<class Type>
inline TCircle<Type>::~TCircle()
{

}

template<class Type>
inline void TCircle<Type>::Print()
{
	std::cout << std::endl;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "Coordinates: " << point << std::endl;
	std::cout << "name = " << name;
	std::cout << "radius = " << radius << std::endl;
}

template<class Type>
inline void TCircle<Type>::Plot()
{
	x = point[0];
	y = point[1];
	r = radius;
	printer.InsertCircle(x, y, r);
	printer.ToPrint();
}

template<class Type>
inline int TCircle<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TCircle<Type>::SetRadius(Type _radius)
{
	radius = _radius;
}

template<class Type>
inline Type TCircle<Type>::GetRadius()
{
	return radius;
}

template<class Type>
inline void TCircle<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TCircle<Type>::GetName()
{
	return name;
}

template<class Type>
inline TVector<Type>& TCircle<Type>::operator[](int i)
{
	return point;
}