/** \addtogroup Interfaces
 *  @{
 * interface for the matrix class
 */
 
#ifndef IMatrix_H
#define IMatrix_H

template<typename T> class IMatrix
{
public:
	virtual ~IMatrix() {}
	
	/**
	* @brief accessor to a specific element in the matrix
	*/
	virtual T operator () (int row, int column) = 0;

	/**
	* @brief accessor to a reference to a specific element in the matrix. Used for setting.
	*/
	virtual T & operator() (int row, int column) = 0;

};

#endif //IMatrix_H

 /** @}*/