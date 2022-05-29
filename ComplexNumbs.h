#pragma once
#include<iostream>
class TComplex
{
private:
	double Im;
	double Re;
	double Angle;

public:

	TComplex(double _Re = 0, double _Im = 0);
	TComplex(const TComplex& p);

	double GetRe();
	double GetIm();
	double GetAngle();
	double GetAbs(const TComplex& num);
	double GetAbs();

	TComplex PowNZ(int Numb);

	void GetTrigForm(const TComplex& num);
	void GetTrigForm();

	void SetRe(double _Re);
	void SetIm(double _Im);
	void SetAngle(double _Angle);


	TComplex operator * (const TComplex& num);
	TComplex operator + (const TComplex& num);
	TComplex operator - (const TComplex& num);
	TComplex operator / (const TComplex& num);
	TComplex& operator = (const TComplex& num);
	bool operator == (const TComplex& num);
	friend std::ostream& operator << (std::ostream& stream, const TComplex& num);
	friend std::istream& operator >> (std::istream& stream, const TComplex& num);
};