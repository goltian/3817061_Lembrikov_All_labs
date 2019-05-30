#include <gtest.h>
#include "../TextLib/Text.h"
#include "../TextLib/MyString.h"

TEST(Node, can_create_char)
{
	ASSERT_NO_THROW(TNode A('c'));
}

TEST(Node, can_create_string)
{
	TMyString B;
	B = "This is string";
	ASSERT_NO_THROW(TNode A(B));
}

TEST(Node, can_create_level)
{
	ASSERT_NO_THROW(TNode T1(1));
	ASSERT_NO_THROW(TNode T2(2));
	ASSERT_NO_THROW(TNode T3(3));
	ASSERT_ANY_THROW(TNode T4(4));
}

TEST(Node, can_assign)
{
	TNode A('c');
	TNode B = A;
	ASSERT_EQ(B.GetLevel(), 3);
	ASSERT_EQ(B.GetData(), 'c');
}


TEST(Node, to_string)
{
	TMyString S;
	S = "This is string";
	TNode A(S);
	char* C = A.ToStr();
	TMyString S2(C);
	ASSERT_TRUE(S == S2);
}

TEST(Text, can_create)
{
	ASSERT_NO_THROW(TText Text);
}

TEST(Text, can_copy)
{
	TText Text;
	TMyString S("This is string");
	Text.Ins(Text.GetRoot(), S);
	ASSERT_NO_THROW(TText C(Text));
}

TEST(Text, can_Add_char)
{
	TText Text;
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), "a"));
}

TEST(Text, can_Add_string)
{
	TText Text;
	TMyString S("This is string");
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S));
}

TEST(Text, can_add_many_nodes)
{
	TText Text;
	TMyString S("This is string");
	TMyString S2("string2");
	TMyString S3("string3");
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S));
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S2));
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S3));
}

TEST(Text, can_find)
{
	TText Text;
	TMyString S("This is string");
	Text.Ins(Text.GetRoot(), S);
	TNode* P = Text.Find("This");
	ASSERT_TRUE(P->GetData() == 'T');
	P = P->GetSosed();
	ASSERT_TRUE(P->GetData() == 'h');
}

TEST(Tesxt, can_find_index)
{
	TText Text;
	TMyString S("This is string");
	Text.Ins(Text.GetRoot(), S);
	int p = Text.FindIndex("This");
	ASSERT_TRUE(p == 0);
}

TEST(Text, can_delete)
{
	TText Text;
	TMyString S("This is string");
	Text.Ins(Text.GetRoot(), S);
	TNode* tmp = Text.GetRoot()->GetNextLevel()->GetNextLevel()->GetNextLevel();
	ASSERT_NO_THROW(Text.Del(tmp, 2));
}

TEST(NodeIter, can_create)
{
	TMyString S("This is string");
	TNode P(S);
	ASSERT_NO_THROW(TNodeIter i(&P));
}

TEST(NodeIter, can_go)
{
	TMyString S("This is string");
	TText T;
	T.Ins(T.GetRoot(), S);
	TNodeIter i(T.GetRoot());
	i++;
	i++;
	i++;
	i++;
	ASSERT_TRUE(i()->GetData() == 'T');
}