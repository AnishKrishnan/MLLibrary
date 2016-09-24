#include <gtest/gtest.h>
#include "Vocabulary.h"

class VocabularyTests : public::testing::Test
{
public:

	Vocabulary * vocab;

	VocabularyTests() 
	{
	}

	void SetUp()
	{
		vocab = new Vocabulary();
	}

	void TearDown()
	{
		delete vocab;
		vocab = NULL;
	}
};

TEST_F(VocabularyTests, AddOneWord)
{
	std::string testWord = "test";
	int expectedIndex = 0;

	int actualIndex = vocab->Add(testWord);
	ASSERT_EQ(expectedIndex, actualIndex);
}

TEST_F(VocabularyTests, GetOneWord)
{
	std::string testWord = "test";

	int expectedIndex = vocab->Add(testWord);
	int actualIndex = vocab->Get(testWord);

	ASSERT_EQ(expectedIndex, actualIndex);
}