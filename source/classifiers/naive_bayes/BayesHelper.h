/** \addtogroup Classifiers
 *  @{
 * Class for helper functions for calculating the Naive Bayes algorithm
 */

#ifndef BayesHelper_H
#define BayesHelper_H

#include "IMatrix.h"
#include <stdint.h>

template<typename T> class BayesHelper 
{
public:

	/**
	* @brief Calculates the mean value for a given feature and label value.
	*/
	static double CalculateMean (IMatrix<T> * mat, uint8_t labels[], int featureIndex, uint8_t desiredLabel); 

};

template<typename T> double BayesHelper<T>::CalculateMean(IMatrix<T> * mat, uint8_t labels[], int featureIndex, uint8_t desiredLabel)
{
	double sum = 0.0;
	int count = 0;

	for (int i = 0; i < mat->GetRowSize(); i++)
	{
		if (labels[i] == desiredLabel)
		{
			sum += mat->Get(i, featureIndex);
			count++;
		}
	}

	return sum / count;
}

#endif //BayesHelper_H
/** @}*/