#include "StringTokenizer.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class StringTokenizerTests : public::testing::Test
{
public:

	StringTokenizer tokenizer;
	
	StringTokenizerTests()
	{
	}

	void SetUp()
	{
	}

	void TearDown()
	{
	}

	~StringTokenizerTests()
	{
	}
};

TEST_F(StringTokenizerTests, BasicTokenizeTest)
{
	ASSERT_EQ(true, false);
}