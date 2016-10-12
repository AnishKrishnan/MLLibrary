#include "BayesHelper.h"
#include "Matrix.h"
#include <stdio.h> 
#include <stdint.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class BayesHelperTests : public::testing::Test
{
public:
	BayesHelperTests() : mat(4 ,2)
	{
		for (int i = 0; i < mat.GetRowSize() - 1; i++)
		{
			mat(i, 1) = i + 1;
			labels[i] = 1;
		}

		mat(3, 0) = 4;
		labels[3] = 0;
	}

	Matrix<int> mat;
	uint8_t labels[3];
};	

TEST_F(BayesHelperTests, CalculateMeanTest)
{
	double expectedValue = 2.0;

	double actual = BayesHelper<int>::CalculateMean(&mat, labels, 1, 1);	

	ASSERT_EQ(expectedValue, actual);
}

TEST_F(BayesHelperTests, CalculateMeanWithNoLabels)
{
	double expectedValue = 0.0;
	double actual = BayesHelper<int>::CalculateMean(&mat, labels, 1, 0);

	ASSERT_EQ(expectedValue, actual);
}

TEST_F(BayesHelperTests, CalculateMeanWithSpecificLabel)
{
	double expectedValue = 4.0;
	double actual = BayesHelper<int>::CalculateMean(&mat, labels, 0, 0);

	ASSERT_EQ(expectedValue, actual);
}

TEST_F(BayesHelperTests, CalculateVariance)
{
	double expectedValue = 1.0;
	double mean = BayesHelper<int>::CalculateMean(&mat, labels, 1, 1);
	double actual = BayesHelper<int>::CalculateVariance(&mat, labels, mean, 1, 1);

	ASSERT_EQ(expectedValue, actual);
}

TEST_F(BayesHelperTests, CalculateVarianceWithNoLables)
{
	double expectedValue = 0.0;
	double mean = BayesHelper<int>::CalculateMean(&mat, labels, 0, 0);
	double actual = BayesHelper<int>::CalculateVariance(&mat, labels, mean, 0, 0);

	ASSERT_EQ(expectedValue, actual);	
}