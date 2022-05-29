#pragma once
#include<iostream>
#include"Vector.h"

#include"TObj.h"


template <class Type>
class TPoint : public TObj<Type>
{
protected:
	TString name;
	TVector<Type> Vec;
	int dim;
public:
	Printer<Type> printer;
	TPoint();
	~TPoint();
	TPoint(const TPoint<Type>& _point);
	virtual void Plot();
	virtual void Print();
	virtual TVector<Type>& operator [](int i);
	virtual int GetDim();
	virtual void SetName(const TString& _name);
	virtual TString& GetName();

};

template<class Type>
TPoint<Type>::TPoint()
{

	std::cout << "input dim of first point" << std::endl;
	std::cin >> Vec;
	name.SetConstString("Point");
	dim = Vec.GetLength();
}

template<class Type>
inline TPoint<Type>::~TPoint()
{

}

template<class Type>
inline TPoint<Type>::TPoint(const TPoint<Type>& _point)
{
	name = _point.name;
	Vec = _point.Vec;
	dim = _point.dim;
}

template<class Type>
inline void TPoint<Type>::Plot()
{
	printer.InsertPoint(Vec);
	printer.ToPrint();
}

template<class Type>
void TPoint<Type>::Print()
{
	std::cout << "name = " << name;
	std::cout << "dim =" << dim << std::endl;
	std::cout << "CoordOfPoint = " << Vec << std::endl;
}

template<class Type>
inline TVector<Type>& TPoint<Type>::operator[](int i)
{
	return Vec;
}

template<class Type>
inline int TPoint<Type>::GetDim()
{
	return dim;
}

template<class Type>
inline void TPoint<Type>::SetName(const TString& _name)
{
	name = _name;
}

template<class Type>
inline TString& TPoint<Type>::GetName()
{
	return name;
}