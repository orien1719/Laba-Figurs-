#include"ComplexNumbs.h"
constexpr auto PI = 3.141567;
TComplex::TComplex(double _Re, double _Im)
{
	Re = _Re;
	Im = _Im;
	Angle = 0;
}

TComplex::TComplex(const TComplex& p)
{
	Re = p.Re;
	Im = p.Im;
	Angle = p.Angle;
}

double TComplex::GetRe()
{
	return Re;
}

double TComplex::GetIm()
{
	return Im;
}

double TComplex::GetAngle()
{
	return Angle;
}

double TComplex::GetAbs(const TComplex& num)
{
	return sqrt(num.Re * num.Re + num.Im * num.Im);

}

double TComplex::GetAbs()
{
	return sqrt(Re * Re + Im * Im);

}

TComplex TComplex::PowNZ(int Numb)
{
	TComplex result(*this);

	result.Angle = (atan2(result.Im, result.Re) * 180 / PI) * Numb;
	double abs = sqrt(Re * Re + Im * Im);

	abs = pow(abs, Numb);

	result.Re = cos(result.Angle) * abs;
	result.Im = sin(result.Angle) * abs;
	return result;

}

void TComplex::GetTrigForm(const TComplex& num)
{
	Angle = atan2(num.Im, num.Re) * 180 / PI;
	std::cout << GetAbs(num) << "*(" << " cos(" << Angle << ") + i*sin(" << Angle << ") )" << std::endl;
}

void TComplex::GetTrigForm()
{
	Angle = atan2(Im, Re) * 180 / PI;
	std::cout << GetAbs(*this) << "*(" << " cos(" << Angle << ") + i * sin(" << Angle << "))" << std::endl;
}

void TComplex::SetRe(double _Re)
{
	Re = _Re;
}

void TComplex::SetIm(double _Im)
{
	Im = _Im;
}

void TComplex::SetAngle(double _Angle)
{
	Angle = _Angle;
}


TComplex TComplex::operator * (const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re * num.Re - Im * num.Im;
	result.Im = Re * num.Im + num.Re * Im;
	return result;
}

TComplex TComplex::operator + (const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re + num.Re;
	result.Im = Im + num.Im;
	return result;
}

TComplex TComplex::operator-(const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re - num.Re;
	result.Im = Im - num.Im;
	return result;
}

TComplex TComplex::operator / (const TComplex& num)
{
	TComplex result(*this);
	if (num.Im == 0 && num.Re == 0) throw "This problem was called by operator / Division by zero";
	result.Re = (Re * num.Re + Im * num.Im) / (num.Re * num.Re + num.Im * num.Im);
	result.Im = (num.Re * Im - Re * num.Im) / (num.Re * num.Re + num.Im * num.Im);

	return result;
}
TComplex& TComplex::operator=(const TComplex& num)
{
	this->Re = num.Re;
	this->Im = num.Im;
	return *this;

}

bool TComplex::operator==(const TComplex& num)
{
	if (this->Re == num.Re && this->Im == num.Im) return true;
	else return false;
}



std::ostream& operator<<(std::ostream& stream, const TComplex& num)
{
	stream << num.Re << ' ' << '+' << ' ' << num.Im << " * i";
	return stream;
}

std::istream& operator>>(std::istream& stream, const TComplex& num)
{
	stream >> num.Re;
	stream >> num.Im;
	return stream;
}