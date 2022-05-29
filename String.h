#pragma once
#include<iostream>
class TString
{
protected:
	int length;
	char* string;
public:
	TString();
	TString(int _length, char s);
	TString(const TString& p);
	~TString();

	int GetLength();
	void SetLength(int _length);
	void SetString(char* _string);
	void SetConstString(const char* _string);

	bool operator < (const TString& p);
	bool operator > (const TString& p);
	bool operator ==(const TString& p);
	TString& operator = (const TString& p);
	TString operator + (const TString& p);
	char& operator [](int i);
	friend std::istream& operator >> (std::istream& stream, TString& p);
	friend std::ostream& operator << (std::ostream& stream, const TString& p);

	int FindFirstSymb(char symbol);
	int FindFirstWord(char* _string);
	char** Split(char symbol, int& EmptyCount);
	TString& duplicate(int count);

	char* GetString();


};