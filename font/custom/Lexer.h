#pragma once

enum emCustomTokenType {
	TT_EOF,	// eof
	TT_NUM, // number
	TT_IDENTIFER, // identifier
	TT_DEF, // def
	TT_PAREN, // '('
};

class CustomLexer {
private:
	static char curChar;
	CustomLexer() {

	}

public:
	static CustomLexer* Instance() {
		return new CustomLexer();
	}

	static emCustomTokenType readToken() {
		return TT_EOF;
	}
};
