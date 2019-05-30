#include "../TextLib/MyString.h"


TMyString::TMyString()
{
	str = 0;
	len = 0;
}

TMyString::TMyString(const TMyString& _str)
{
	len = _str.len;
	if (_str.len == 0)
		str = 0;
	else
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
			str[i] = _str.str[i];
	}
}

TMyString::TMyString(const char* ch)
{
	if (ch == 0)
		throw 1;
	if (ch[0] == '\0')
		return;
	int size=0;
	char k=1;
	while (k != '\0')
	{
		size++;
		k = ch[size];
	}
	len = size+1;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = ch[i];
}

TMyString::~TMyString()
{
	if (len != 0)
		delete str;
	str = 0;
	len = 0;
}

int TMyString::GetLength()
{
	return len;
}

TMyString& TMyString::operator=(const TMyString& _str)
{
	if (this == &_str)
		return *this;
	if (len != _str.len)
	{
		delete[] str;
		len = _str.len;
	}
	if (len != 0)
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
		{
			str[i] = _str.str[i];
		}
	}
	return *this;
}

TMyString TMyString::operator+(TMyString& _str)
{
	TMyString Res;
	Res.len = len + _str.len - 1;
	Res.str = new char[Res.len];
	for (int i = 0; i < len - 1; i++)
		Res.str[i] = str[i];
	for (int i = 0; i < _str.len; i++)
		Res.str[i + len - 1] = _str[i];
	return Res;
}

char& TMyString::operator[] (int i)
{
	if ((i < 0) || (i >= len))
		throw 1;
	return str[i];
}

bool TMyString::operator==(TMyString Other)
{
	if (this->GetLength() != Other.GetLength())
		return false;
	for (int i = 0; i < this->GetLength(); i++)
	{
		if (str[i] != Other[i])
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream &is, TMyString &string)
{
	char s[256];
	is >> s;

	char x = 1;
	int size = 0;
	while (x != '\0')
	{
		size++;
		x = s[size];
	}
	string.len = size + 1;
	string.str = new char[string.len];
	for (int i = 0; i < string.len - 1; i++)
		string.str[i] = s[i];
	string.str[string.len - 1] = 0;
	return is;
}

	std::ostream& operator<<(std::ostream &os, const TMyString &string)
	{
		os << string.str;
		return os;
	}