#include <gtest.h>
#include "../PolynomLib/Polynom.h"

TEST(Monom, can_create)
{
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	ASSERT_NO_THROW(TMonom(5, p, 6));
}

TEST(Monom, can_not_create_with_negative_number_of_variables)
{
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	ASSERT_ANY_THROW(TMonom(-5, p, 6));
}

TEST(Monom, can_add)
{
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	TMonom M1(5, p, 6);
	TMonom M2(5, p, 2);
	TMonom Rez = M1 + M2;
	ASSERT_EQ(Rez.GetC(), 8);
	ASSERT_EQ(Rez.GetN(), 5);
}

TEST(Monom, can_subtract)
{
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	TMonom M1(5, p, 6);
	TMonom M2(5, p, 2);
	TMonom Rez = M1 - M2;
	ASSERT_EQ(Rez.GetC(), 4);
	ASSERT_EQ(Rez.GetN(), 5);
}

TEST(Monom, can_not_add_and_subtract_with_different_power)
{
	unsigned* p1 = new unsigned[5];
	p1[0] = 1;
	p1[1] = 2;
	p1[2] = 3;
	p1[3] = 4;
	p1[4] = 5;
	unsigned* p2 = new unsigned[5];
	p2[0] = 3;
	p2[1] = 2;
	p2[2] = 3;
	p2[3] = 4;
	p2[4] = 5;
	TMonom M1(5, p1, 6);
	TMonom M2(5, p2, 2);
	ASSERT_ANY_THROW(TMonom Rez = M1 - M2);
}

TEST(Monom, can_multiplicate)
{
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	TMonom M1(5, p, 6);
	TMonom M2(5, p, 2);
	TMonom Rez = M1 * M2;
	ASSERT_EQ(Rez.GetC(), 12);
	ASSERT_EQ(Rez.GetN(), 5);
	ASSERT_EQ(Rez.GetPower()[0], 2);
	ASSERT_EQ(Rez.GetPower()[1], 4);
	ASSERT_EQ(Rez.GetPower()[2], 6);
	ASSERT_EQ(Rez.GetPower()[3], 8);
	ASSERT_EQ(Rez.GetPower()[4], 10);
}

TEST(Monom, can_compare)
{
	unsigned* p1 = new unsigned[5];
	p1[0] = 1;
	p1[1] = 2;
	p1[2] = 3;
	p1[3] = 4;
	p1[4] = 5;
	unsigned* p2 = new unsigned[5];
	p2[0] = 3;
	p2[1] = 2;
	p2[2] = 3;
	p2[3] = 4;
	p2[4] = 5;
	TMonom M1(5, p1, 6);
	TMonom M2(5, p2, 2);
	TMonom M3(4, p1, 1);
	ASSERT_ANY_THROW(M1 > M3);
	ASSERT_TRUE(M2 > M1);
	ASSERT_FALSE(M2 < M1);
}

TEST(Polynom, can_create)
{
	ASSERT_NO_THROW(TPolynom P(5));
}

TEST(Polynom, can_not_create_with_negative_number_of_variables)
{
	ASSERT_ANY_THROW(TPolynom P(-5));
}

TEST(Polynom, can_add_monom)
{
	TPolynom P(5);
	unsigned* p = new unsigned[5];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	TMonom M(5, p, 6);
	ASSERT_NO_THROW(P += M);
	ASSERT_TRUE(*P.GetStart() == M);
}

TEST(Polynom, can_add_many_monoms)
{
	TPolynom P(5);
	unsigned* p1 = new unsigned[5];
	unsigned* p2 = new unsigned[5];
	unsigned* p3 = new unsigned[5];
	unsigned* p4 = new unsigned[5];
	for (int i = 0; i < 5; i++) 
	{
		p1[i] = i;
		p2[i] = 5 - i;
		p3[i] = i + 1;
		p4[i] = 10 - i;
	}

	TMonom M1(5, p1, 3);
	TMonom M2(5, p2, 6);
	TMonom M3(5, p3, 1);
	TMonom M4(5, p4, 7);
	ASSERT_NO_THROW(P += M1);
	ASSERT_NO_THROW(P += M2);
	ASSERT_NO_THROW(P += M3);
	ASSERT_NO_THROW(P += M4);
	TMonom* a = P.GetStart();
	ASSERT_TRUE(*a == M4);
	a = a->GetNext();
	ASSERT_TRUE(*a == M2);
	a = a->GetNext();
	ASSERT_TRUE(*a == M3);
	a = a->GetNext();
	ASSERT_TRUE(*a == M1);
}

TEST(Polynom, can_copy)
{
	TPolynom P(5);
	unsigned* p1 = new unsigned[5];
	unsigned* p2 = new unsigned[5];
	unsigned* p3 = new unsigned[5];
	unsigned* p4 = new unsigned[5];
	for (int i = 0; i < 5; i++)
	{
		p1[i] = i;
		p2[i] = 5 - i;
		p3[i] = i + 1;
		p4[i] = 10 - i;
	}

	TMonom M1(5, p1, 3);
	TMonom M2(5, p2, 6);
	TMonom M3(5, p3, 1);
	TMonom M4(5, p4, 7);
	ASSERT_NO_THROW(P += M1);
	ASSERT_NO_THROW(P += M2);
	ASSERT_NO_THROW(P += M3);
	ASSERT_NO_THROW(P += M4);
	TPolynom Pcopy(P);
	TMonom* a = Pcopy.GetStart();
	ASSERT_TRUE(*a == M4);
	a = a->GetNext();
	ASSERT_TRUE(*a == M2);
	a = a->GetNext();
	ASSERT_TRUE(*a == M3);
	a = a->GetNext();
	ASSERT_TRUE(*a == M1);
}

TEST(Polynom, can_add_polynom)
{
	TPolynom P1(5);
	TPolynom P2(5);
	unsigned* p1 = new unsigned[5];
	unsigned* p2 = new unsigned[5];
	unsigned* p3 = new unsigned[5];
	unsigned* p4 = new unsigned[5];
	for (int i = 0; i < 5; i++)
	{
		p1[i] = i;
		p2[i] = 5 - i;
		p3[i] = i + 1;
		p4[i] = 10 - i;
	}

	TMonom M1(5, p1, 3);
	TMonom M2(5, p2, 6);
	TMonom M3(5, p3, 1);
	TMonom M4(5, p4, 7);
	TMonom M5(5, p2, 5);
	TMonom M6(5, p3, -12);
	P1 += M1;
	P1 += M2;
	P1 += M3;
	P2 += M4;
	P2 += M5;
	P2 += M6;
	TPolynom P3(5);
	ASSERT_NO_THROW(P3 = P1 + P2);
	TMonom* a = P3.GetStart();
	ASSERT_TRUE(a->GetC() == 7);
	ASSERT_TRUE(*a == M4);
	a = a->GetNext();

	ASSERT_TRUE(a->GetC() == 11);
	ASSERT_TRUE(*a == M2);
	a = a->GetNext();

	ASSERT_EQ(a->GetC(), -11);
	ASSERT_TRUE(*a == M3);
	a = a->GetNext();

	ASSERT_TRUE(a->GetC() == 3);
	ASSERT_TRUE(*a == M1);
	a = a->GetNext();

	ASSERT_TRUE(a == 0);
}

