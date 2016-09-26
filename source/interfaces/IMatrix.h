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
	virtual T Get (int row, int column) = 0;

	/**
	* @brief setter for the matrix value.
	*/
	virtual void Set (int row, int column, T & value) = 0;

	/**
	* @brief get row size.
	*/
	virtual int GetRowSize () = 0;

	/**
	* @brief get column size
	*/
	virtual int GetColumnSize() = 0;

};

#endif //IMatrix_H

 /** @}*/