#include <gtest.h>
#include "TStack.h"

TEST(TStack, default_constructor) {
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, constructor_with_parameter) {
	ASSERT_NO_THROW(TStack<int> s(0));
}

TEST(TStack, size) {
	TStack<int> s(13);
	EXPECT_EQ(1, s.stack_size());
}

TEST(TStack, empty) {
	TStack<int> s;
	EXPECT_EQ(1, s.empty());
}

TEST(TStack, push_and_top) {
	TStack<int> s;
	s.push(314159265);
	EXPECT_EQ(314159265, s.top());
	EXPECT_EQ(1, s.stack_size());
}

TEST(TStack, push_push) {
	TStack<int> s;
	s.push(314159265);
	s.push(314159266);
	s.push(314159267);
	s.push(314159268);
	s.push(314159269);
	EXPECT_EQ(314159269, s.top());
	EXPECT_EQ(5, s.stack_size());
}

TEST(TStack, pop) {
	TStack<int> s;
	s.push(314159265);
	s.push(314159266);
	s.pop();
	EXPECT_EQ(314159265, s.top());
	EXPECT_EQ(1, s.stack_size());
}

TEST(TStack, throw_pop) {
	TStack<int> s;
	ASSERT_ANY_THROW(s.pop());
}		  