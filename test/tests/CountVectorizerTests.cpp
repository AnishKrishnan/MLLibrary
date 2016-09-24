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

	ASSERT_EQ(true, false);
}