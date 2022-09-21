#include "Token.h"


using namespace std;

unsigned int Token::GetLineNum() const
{
	return lineNum;
}
void Token::SetLineNum(unsigned int line)
{
	this->lineNum = line;
}
TokenType Token::GetType() const
{
	return e_type;
}
void Token::SetType(TokenType type)
{
	this->e_type = type;
}
string Token::GetValue() const
{
	return value;
}
void Token::SetValue(string description)
{
	this->value = description;
}
string Token::MyToString() const
{
	//maybe change this is cout to make it work with the vector of pointers
	stringstream out;
	out << "(" << MyTokenString(e_type) << "," << "\"" << value << "\"" << "," << lineNum << ")";
	return out.str();
}


