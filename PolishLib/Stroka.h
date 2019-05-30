#pragma once
#include <iostream>
#include "../ExceptionLib/ExceptionLib.h"

class TString
{
protected:
  char* s;
  int length;

public:
  TString();
  TString(TString &A);
  TString(char* s);
  ~TString();

  int GetLength();
  void DeleteS();

  TString operator+(TString &A);
  TString& operator=(TString &A);
  char& operator[](int i);

	bool operator==(TString& _str);
	bool operator>(TString& _str);
	bool operator<(TString& _str);

  friend std::istream& operator>>(std::istream &A, TString &B);
  friend std::ostream& operator<<(std::ostream &A, const TString &B);
};

