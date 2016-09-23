#include "StringTokenizer.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class StringTokenizerTests : public::testing::Test
{
public:

	StringTokenizer tokenizer;
	
	StringTokenizerTests() : tokenizer(2)
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

	void ValidateTokenization(const std::string testData, const std::vector<std::string> & expectedFeatures)
	{
		std::vector<std::string> tokenizedFeatures;
		tokenizer.Tokenize(testData, tokenizedFeatures);

		ASSERT_EQ(expectedFeatures.size(), tokenizedFeatures.size());

		for (int i = 0; i < expectedFeatures.size(); i++)
		{
			ASSERT_EQ(expectedFeatures.at(i), tokenizedFeatures.at(i));
		}
	}
};

TEST_F(StringTokenizerTests, BasicTokenizeTest)
{
	std::string testData = "aa aa aa aa";
	std::vector<std::string> expectedFeatures(4, "aa");

	this->ValidateTokenization(testData, expectedFeatures);
}

TEST_F(StringTokenizerTests, MinWordLengthTest)
{
	std::string testData = "aa aa a aa aa";
	std::vector<std::string> expectedFeatures(4, "aa");

	this->ValidateTokenization(testData, expectedFeatures);
}

TEST_F(StringTokenizerTests, RemoveNonAlphabetCharacterTests)
{
	std::string testData = "aa, aa. aa! aa: aa;";
	std::vector<std::string> expectedFeatures(5, "aa");

	this->ValidateTokenization(testData, expectedFeatures);
}