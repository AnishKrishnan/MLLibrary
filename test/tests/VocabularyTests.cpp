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

TEST_F(VocabularyTests, AddDuplicateWordTest)
{
	std::string testWord = "test";

	int firstIndex = vocab->Add(testWord);
	int duplicateIndex = vocab->Add(testWord);

	ASSERT_EQ(firstIndex, duplicateIndex);
}

TEST_F(VocabularyTests, GetSizeTest)
{
	std::string testWord = "test";

	vocab->Add(testWord);
	int size = vocab->GetSize();

	ASSERT_EQ(1, size);
}