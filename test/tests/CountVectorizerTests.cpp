#include <gtest/gtest.h>
#include "CountVectorizer.h"
#include "StringTokenizer.h"

class CountVectorizerTests : public::testing::Test
{
public:
	CountVectorizer * countVectorizer;
	StringTokenizer tokenizer;

	CountVectorizerTests() : tokenizer(2)
	{
	}

	void SetUp()
	{
		countVectorizer = new CountVectorizer(&tokenizer);
	}

	void TearDown()
	{
		delete countVectorizer;
		countVectorizer = NULL;
	}
};

TEST_F(CountVectorizerTests, BasicFitTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd");

	countVectorizer->Fit(corpus);

	IVocabulary * vocab = countVectorizer->GetVocabulary();

	ASSERT_EQ(4, vocab->GetSize());
}

TEST_F(CountVectorizerTests, MultipleDocumentTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd");
	corpus.push_back("dd ee ff");

	countVectorizer->Fit(corpus);

	IVocabulary * vocab = countVectorizer->GetVocabulary();

	ASSERT_EQ(6, vocab->GetSize());
}

TEST_F(CountVectorizerTests, SingeDocumentTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd");

	countVectorizer->Fit(corpus);
	IMatrix<int> * features = countVectorizer->Transform(corpus);

	ASSERT_EQ(1, features->GetRowSize());
	ASSERT_EQ(4, features->GetColumnSize());

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(1, features->Get(0, i));
	}	
}