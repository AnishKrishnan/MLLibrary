/** \addtogroup Interfaces
 *  @{
 * interface for file reader class
 */
 
#ifndef IVectorizer_H
#define IVectorizer_H

class IVectorizer
{
public:
	virtual ~IVectorizer() {}
	
	/**
	 * @brief Builds a vocabulary from the corpus of documents, represented as strings.
	 */
	 virtual void Fit (const std::vector<std::string> & corpus) = 0;
};

#endif //IVectorizer_H

 /** @}*/