#include <gtest.h>
#include "../ScanTableLib/ScanTable.h"
#include "../ScanTableLib/ScanElem.h"
#include "../PolishLib/Stroka.h"

TEST(ScanElem, can_create)
{
	TString key("key");
	ASSERT_NO_THROW(TScanElem<int> A(key, 12));
}

TEST(ScanElem, can_compare)
{
	TString key("key");
	TString abc("abc");
	TString abcd("abcd");
	TString key2("key");
	TScanElem<int> A(key, 12);
	TScanElem<int> B(abc, 13);
	TScanElem<int> C(abcd, 13);
	TScanElem<int> D(key2, 15);
	ASSERT_TRUE(A > B);
	ASSERT_TRUE(C < B);
	ASSERT_TRUE(A == D);
}

TEST(ScanTable, can_create_with_int_parametr)
{
	ASSERT_NO_THROW(TScanTable<int> ST(20));
}

TEST(ScanTable, can_not_create_with_negative_size)
{
	ASSERT_ANY_THROW(TScanTable<int> ST(-20));
}

TEST(ScanTable, can_put_and_get)
{
	TScanTable<int> ST(10);
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");
	ST.Put(i, 1);
	ST.Put(like, 2);
	ST.Put(write, 3);
	ST.Put(code, 4);
	ASSERT_TRUE(ST[code] == 4);
	ASSERT_TRUE(ST[i] == 1);
	ASSERT_TRUE(ST[like] == 2);
	ASSERT_TRUE(ST[write] == 3);
}

TEST(ScanTable, can_not_put_exist_elem)
{
	TScanTable<int> ST(10);
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");
	ST.Put(i, 1);
	ST.Put(like, 2);
	ST.Put(write, 3);
	ST.Put(code, 4);
	ASSERT_ANY_THROW(ST.Put(like, 20));
}

TEST(ScanTable, can_delete)
{
	TScanTable<int> ST(10);
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");
	ST.Put(i, 1);
	ST.Put(like, 2);
	ST.Put(write, 3);
	ST.Put(code, 4);
	ASSERT_NO_THROW(ST.Del(i));
	ASSERT_NO_THROW(ST.Del(write));
	ASSERT_TRUE(ST[code] == 4);
	ASSERT_TRUE(ST[like] == 2);
	ASSERT_EQ(ST.GetCount(), 2);
}

TEST(ScanTable, can_not_delete_not_exist_elem)
{
	TScanTable<int> ST(10);
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");
	ST.Put(i, 1);
	ST.Put(like, 2);
	ST.Put(write, 3);
	ST.Put(code, 4);
	TString me("me");
	ASSERT_ANY_THROW(ST.Del(me));
}

TEST(ScanTable, can_find)
{
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");

	TScanTable<int> ST(10);
	ST.Put(i, 1);
	ST.Put(like, 2);
	ST.Put(write, 3);
	ST.Put(code, 4);

	TScanElem<int> A = ST.Search(i);
	ASSERT_TRUE(A.GetData() == 1);
	ASSERT_TRUE(A.GetKey() == i);

	TScanElem<int> B = ST.Search(code);
	ASSERT_TRUE(B.GetData() == 4);
	ASSERT_TRUE(B.GetKey() == code);
}

TEST(ScanTable, can_add_if_do_not_exist)
{
	TScanTable<int> ST(10);
	TString i("i");
	TString like("like");
	TString write("write");
	TString code("code");
	ST[i] = 1;
	ST[like] = 2;
	ST[write] = 3;
	ST[code] = 4;
	ASSERT_TRUE(ST.Search(code).GetData() == 4);
	ASSERT_TRUE(ST.Search(i).GetData() == 1);
	ASSERT_TRUE(ST.Search(like).GetData() == 2);
	ASSERT_TRUE(ST.Search(write).GetData() == 3);
}

