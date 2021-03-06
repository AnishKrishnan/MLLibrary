#include <gtest/gtest.h>
#include "Matrix.h"

class MatrixTests : public::testing::Test
{
public:

	Matrix<int> * mat;

	MatrixTests() 
	{
	}

	void SetUp()
	{
		mat = new Matrix<int>(3, 4);	
	}

	void TearDown()
	{
		delete mat;
		mat = NULL;
	}
};

TEST_F(MatrixTests, ConstructorTest)
{
	for (int i = 0; i < mat->GetRowSize(); i++)
	{
		for (int j = 0; j < mat->GetColumnSize(); j++)
		{
			ASSERT_EQ(0, mat->Get(i, j));
		}
	}
}

TEST_F(MatrixTests, GetandSetTest)
{
	int expectedValue = 42;
	mat->Set(1, 1, expectedValue);

	int actualValue = mat->Get(1, 1);

	ASSERT_EQ(expectedValue, actualValue);
}

TEST_F(MatrixTests, GetRowSizeTest)
{
	int expectedValue = 3;
	int actualValue = mat->GetRowSize();

	ASSERT_EQ(expectedValue, actualValue);
}

TEST_F(MatrixTests, GetColumnSizeTest)
{
	int expectedValue = 4;
	int actualValue = mat->GetColumnSize();

	ASSERT_EQ(expectedValue, actualValue);
}

TEST_F(MatrixTests, ParenthesisGetOperator)
{
	int expectedValue = 4;
	mat->Set(1, 1, expectedValue);

	int actualValue = mat->operator()(1, 1);

	ASSERT_EQ(expectedValue, actualValue);
}

TEST_F(MatrixTests, ParenthesisSetOperator)
{
	int expectedValue = 4;
	mat->operator()(1, 1) = expectedValue;

	int actualValue = mat->operator()(1, 1);

	ASSERT_EQ(expectedValue, actualValue);
}