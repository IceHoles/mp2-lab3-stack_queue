#include <gtest.h>
#include "Queue.h"

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_create_queue_2) {
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, size_and_memory_size) {
	
	Queue<int> q;
	for (int i = 0; i < 31; i++) {
		q.push(314159265 + i);
	}
	EXPECT_EQ(31, q.size());
	EXPECT_EQ(40, q.msize());
}
 
TEST(Queue, queue_is_empty) {
	Queue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(Queue, queue_is_full) {
	Queue<int> q;
	for (int i = 0; i < 20; i++) {
		q.push(314159265 + i);
	}
	EXPECT_EQ(true, q.full());
}

TEST(Queue, top) {
	Queue<int> q(314159265);
	EXPECT_EQ(314159265, q.top());
}

TEST(Queue, try_to_top_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.top());
}

TEST(Queue, can_push_correctly) {
	Queue<int> q(314159265);
	EXPECT_EQ(314159265, q.top());
}

TEST(Queue, can_pop) {
	Queue<int> q(314159265);
	q.pop();
	EXPECT_EQ(0, q.size());
	ASSERT_ANY_THROW(q.top());
}

TEST(Queue, top_after_pop) {
	Queue<int> q(314159265);
	q.push(314159266);
	q.pop();
	EXPECT_EQ(314159266, q.top());
}

TEST(Queue, try_to_pop_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, can_resize_correctly) {
	Queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(314159265 + i);
	}
	q.pop();
	q.push(314159275);
	EXPECT_EQ(314159266, q.top());
	EXPECT_EQ(10, q.size());
	EXPECT_EQ(10, q.msize());
}