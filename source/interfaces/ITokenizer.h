/** \addtogroup Interfaces
 *  @{
 * interface for a string tokenizer
 */
 
#ifndef ITokenizer_H
#define ITokenizer_H

class ITokenizer
{
public:
	virtual ~ITokenizer() {}
	
	/**
	 * @brief Populates a vector of strings, tokenized from the input text.
	 */
	 virtual void Tokenize(std::string text, std::vector<std::string> & tokenizedString) = 0;
};
#endif //ITokenizer_H

 /** @}*/