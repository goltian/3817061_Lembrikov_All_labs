#include <gtest.h>
#include "../Plexlib/Plex.h"
#include "../PlexLib/Circle.h"

TEST(Point, can_create)
{
	ASSERT_NO_THROW(TPoint T);
	ASSERT_NO_THROW(TPoint P(3, 5));
}

TEST(Point, can_get)
{
	TPoint T(3, 5);
	ASSERT_EQ(T.GetX(), 3);
	ASSERT_EQ(T.GetY(), 5);
}

TEST(Point, can_set)
{
	TPoint T;
	ASSERT_NO_THROW(T.SetX(3));
	ASSERT_NO_THROW(T.SetY(5));
	ASSERT_EQ(T.GetX(), 3);
	ASSERT_EQ(T.GetY(), 5);
}

TEST(Point, can_compare)
{
	TPoint T(3, 5);
	TPoint P(3, 5);
	TPoint K(2, 4);
	ASSERT_TRUE(T == P);
	ASSERT_FALSE(P == K);
}

TEST(Line, can_create)
{
	ASSERT_NO_THROW(TLine L1);
	ASSERT_NO_THROW(TLine L2(3, 5, 2, 4));
	TPoint T(3, 5);
	TPoint P(2, 4);
	ASSERT_NO_THROW(TLine L3(T, P));
}

TEST(Line, can_get)
{
	TLine L(3, 5, 2, 4);
	TPoint T(3, 5);
	TPoint P(2, 4);
	ASSERT_TRUE(L.GetA() == T);
	ASSERT_TRUE(L.GetB() == P);
}

TEST(Plex, can_create)
{
	ASSERT_NO_THROW(TPlex P);
	TPoint L(3, 5);
	TPoint R(4, 2);
	ASSERT_NO_THROW(TPlex P(&L, &R));
}

TEST(Plex, can_get)
{
	TPoint L(3, 5);
	TPoint R(4, 2);
	TPlex P(&L, &R);
	ASSERT_TRUE(P.GetLeft() == &L);
	ASSERT_TRUE(P.GetRight() == &R);
}

TEST(Plex, can_set)
{
	TPoint L(3, 5);
	TPoint R(4, 2);
	TPlex P;
	P.SetLeft(&L);
	P.SetRight(&R);
	ASSERT_TRUE(P.GetLeft() == &L);
	ASSERT_TRUE(P.GetRight() == &R);
}

TEST(Plex, can_add_line)
{
	TPoint L(3, 5);
	TPoint R(4, 2);
	TPoint T1(7, 8);
	TPoint T2(4, 2);
	TPlex P(&T1, &T2);
	ASSERT_NO_THROW(P.Add(&L, &R));
}

TEST(Plex, can_not_add_error_line)
{
	TPoint L(3, 5);
	TPoint R(4, 2);
	TPoint T1(7, 8);
	TPoint T2(4, 5);
	TPlex P(&T1, &T2);
	ASSERT_ANY_THROW(P.Add(&L, &R));
}

TEST(Circle, can_create)
{
	TPoint P(3, 2);
	ASSERT_NO_THROW(TCircle C);
	ASSERT_NO_THROW(TCircle A(&P, 3));
}

TEST(Circle, can_not_create_with_negative_radius)
{
	TPoint P(3, 2);
	ASSERT_ANY_THROW(TCircle A(&P, -3));
}

TEST(Circle, can_copy)
{
	TPoint P(3, 2);
	TCircle A(&P, 3);
	TCircle AC(A);
	ASSERT_TRUE(AC.GetCenter()->GetX() == 3);
	ASSERT_TRUE(AC.GetCenter()->GetY() == 2);
	ASSERT_TRUE(AC.GetR() == 3);
}

TEST(Circle, can_Set_and_Get)
{
	TPoint P(3, 2);
	TCircle A(&P, 3);
	TPoint P2(4, 10);
	A.SetCenter(&P2);
	A.SetR(20);
	ASSERT_TRUE(A.GetCenter()->GetX() == 4);
	ASSERT_TRUE(A.GetCenter()->GetY() == 10);
	ASSERT_TRUE(A.GetR() == 20);
}