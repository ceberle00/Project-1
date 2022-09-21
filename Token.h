#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>

using namespace std;

enum class TokenType {
	COLON,
	COLON_DASH,
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	STRING,
	ID,
	COMMENT,
	UNDEFINED,
	EOFTOKEN
};

//other string to output just the word
inline string MyTokenString(TokenType t)
{
	switch (t) {
	case TokenType::COMMA:
		return "COMMA";
	case TokenType::PERIOD:
		return "PERIOD";
	case TokenType::Q_MARK:
		return "Q_MARK";
	case TokenType::LEFT_PAREN:
		return "LEFT_PAREN";
	case TokenType::RIGHT_PAREN:
		return "RIGHT_PAREN";
	case TokenType::COLON:
		return "COLON";
	case TokenType::COLON_DASH:
		return "COLON_DASH";
	case TokenType::MULTIPLY:
		return "MULTIPLY";
	case TokenType::ADD:
		return "ADD";
	case TokenType::SCHEMES:
		return "SCHEMES";
	case TokenType::FACTS:
		return "FACTS";
	case TokenType::RULES:
		return "RULES";
	case TokenType::QUERIES:
		return "QUERIES";
	case TokenType::ID:
		return "ID";
	case TokenType::STRING:
		return "STRING";
	case TokenType::COMMENT:
		return "COMMENT";
	case TokenType::UNDEFINED:
		return "UNDEFINED";
	case TokenType::EOFTOKEN:
		return "EOF";
	default:
		return "UNDEFINED";
	}
}

class Token
{
private:
	TokenType e_type;
	string value;
	unsigned int lineNum;

public:

	//both named type, check back for errors, also string may need &
	Token(TokenType type, string description, unsigned int line) : e_type(type), value(description), lineNum(line) {};
	//just mystring and get and set values
	string GetValue() const;
	void SetValue(string description);

	TokenType GetType() const;
	void SetType(TokenType type);

	unsigned int GetLineNum() const;
	void SetLineNum(unsigned int line);

	string MyToString() const;

};

#endif // TOKEN_H

