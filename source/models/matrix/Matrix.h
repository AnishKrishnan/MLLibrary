/** \addtogroup FeatureExtractor
 *  @{
 * Class for the storage of a matrix.
 */

#ifndef Matrix_H
#define Matrix_H

#include <boost/numeric/ublas/matrix.hpp>
#include "IMatrix.h"

template<typename T> class Matrix : public IMatrix<T>
{
public:

	/**
	 * @brief Constructor for Matrix
	 */
	Matrix (int rowSize, int columnSize);

	/**
	* @brief accessor to a specific element in the matrix
	*/
	virtual T Get (int row, int column);

	/**
	* @brief accessor to a reference to a specific element in the matrix. Used for setting.
	*/
	virtual void Set (int row, int column, T & value);

	/**
	* @brief get row size.
	*/
	virtual int GetRowSize ();


private:

	boost::numeric::ublas::matrix<T> _matrix;
};

template <typename T> Matrix<T>::Matrix(int rowSize, int columnSize) : _matrix(rowSize, columnSize)
{

}

template <typename T> T Matrix<T>::Get(int row, int column)
{
	return _matrix(row, column);
}

template <typename T> void Matrix<T>::Set(int row, int column, T & value)
{
	_matrix(row, column) = value;
}

template <typename T> int Matrix<T>::GetRowSize()
{
	return _matrix.size1();
}

#endif //Matrix_H
/** @}*/