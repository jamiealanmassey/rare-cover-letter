#ifndef _EXPR_TOKEN_H
#define _EXPR_TOKEN_H

/** Descriptive tokens giving meaning to each word in the input **/
enum class ExprToken : int32_t
{
	EXAMINE  = 1,
	MOVE     = 2,
	DESCRIBE = 4,
	EXIT     = 8,
	HELP     = 16,
	WORD     = 32,
};

#endif // _EXPR_TOKEN_H
