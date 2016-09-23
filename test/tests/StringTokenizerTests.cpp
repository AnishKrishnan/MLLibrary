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
	std::string testData = "aa aa aa aa";
	std::vector<std::string> tokenizedFeatures;
	std::vector<std::string> expectedFeatures(4, "aa");

	tokenizer.Tokenize(testData, tokenizedFeatures);

	ASSERT_EQ(expectedFeatures.size(), tokenizedFeatures.size());
}