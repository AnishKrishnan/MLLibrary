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

TEST_F(CountVectorizerTests, MultipleDocumentTransformTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd");
	corpus.push_back("aa bb cc dd");

	countVectorizer->Fit(corpus);
	IMatrix<int> * features = countVectorizer->Transform(corpus);

	ASSERT_EQ(2, features->GetRowSize());
	ASSERT_EQ(4, features->GetColumnSize());

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(1, features->Get(0, i));
		ASSERT_EQ(1, features->Get(1, i));
	}	
}

TEST_F(CountVectorizerTests, DuplicateValuesTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd aa bb cc dd");

	countVectorizer->Fit(corpus);
	IMatrix<int> * features = countVectorizer->Transform(corpus);

	ASSERT_EQ(1, features->GetRowSize());
	ASSERT_EQ(4, features->GetColumnSize());

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(2, features->Get(0, i));
	}
}

TEST_F(CountVectorizerTests, NotInVocabTest)
{
	std::vector<std::string> corpus;
	corpus.push_back("aa bb cc dd");

	countVectorizer->Fit(corpus);

	corpus.clear();
	corpus.push_back("ee ff gg hh");

	IMatrix<int> * features = countVectorizer->Transform(corpus);

	ASSERT_EQ(1, features->GetRowSize());
	ASSERT_EQ(4, features->GetColumnSize());

	for (int i = 0; i < 4; i++)
	{
		ASSERT_EQ(0, features->Get(0, i));
	}
}