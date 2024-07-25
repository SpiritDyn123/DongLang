grammar DongLang;

/*
    function
    if
    for
    base_types: int, float, string,bool,array

    TODO:
    func var_args(不定参数,默认参数)
    struct class?
    closure_function
*/

//grammar
prog:(global_var_expression';'|function_def)*;
//prog:(statement|function_def)*; //old ver


statement: var_expression ';' //定义
    | ret_expression ';' //定义
    | if_expression        //if
    | for_expression        //for
    ;

//def int testfunc(int a, string b, bool c=true){};
function_def: externC ? FUNC type_type_void IDENTIFIER  '(' farg_list ')' (function_body|';');

externC: 'extern' 'C';
function_body: '{' (statement)* '}';

farg:
    type_type IDENTIFIER //
    ;
f_varargs:
    ',''...'
    ;

farg_list:
    | farg (',' farg)* f_varargs? //
    ;

ret_expression:
    RETURN expression?
    ;

/*
    优先级
*/
expression: COND_NOT expression
    | expression opr=(POINT|DIV) expression
    | expression opr=(ADD|SUB) expression
    | NOT expression
    | expression opr=(POINTADDR|OR|XOR) expression
    | expression opr=(CMP_EQ|CMP_NE|CMP_GT|CMP_GE|CMP_LT|CMP_LE) expression
    | expression opr=COND_AND expression
    | expression opr=COND_OR expression
    | expression threeOpr='?' expression ':' expression //三元选择
    | primary
    ;


cond_statement:
    statement
    | (BREAK|CONTINUE)';'
    ;

if_expression:
    IF '(' if_cond ')' '{' cond_statement* '}' (elif_expr)* (else_expr)?
    ;
elif_expr:
    elif '('  if_cond ')' '{' cond_statement* '}'
    ;
else_expr:
     ELSE  '{' cond_statement* '}'
     ;

elif: ELIF
    | ELSE IF
    ;

if_cond:  var_expression? COND_SPE? expression?;
/*
for(int i = 0,j=2;i<10, a;i=j+1) {
for( i = 0,j=2;i<10, j<5;i=i+1, j=j+1) {

}

*/
for_expression:
    FOR '(' for_cond ')' '{' cond_statement* '}'
    ;

/*
 * 如果if_cond不包含var_expression, assigns不能存在
 */
for_cond: expression |
    var_expression? ';' expression? ';' assigns?
    ;

global_var_expression:
    var_declares
    | TYPE IDENTIFIER (type_type|class_def)
    ;
/*
    int a, b=2,c;
    a,b;
    a,b=2,c;
*/

var_expression:
    assigns
    | var_declares
    ;

//=======================结构=========================

paran_expr: '(' expression ')';

call_expr: IDENTIFIER '(' expr_list ')' //function call
    ;

expr_list:
     | expression (',' expression)*
     ;

num_primary:
    ('-')? NUMBER
    | NIL
    ;

str_primary: STRING_LITERAL;

bool_primary:
    TRUE
    | FALSE
    ;

value_primary:
    num_primary
    | bool_primary
    | str_primary
    ;

array_index: '['(expression)']';


id_primary_p_addrs:
    (POINT|POINTADDR)? (POINT POINTADDR?)*
    |POINT? (POINTADDR? POINT)*
    ;
id_primary:
    id_primary_p_addrs (IDENTIFIER|call_expr|paran_expr) array_index*
    ;
primary:
      value_primary //1,"cc",true
     | id_primary //
     ;

primary_type:
      'int'
    | 'string'
    | 'float'
    | 'bool'
    | 'byte'
    ;

array_type: '[' NUMBER? ']';

type_type:
     (primary_type | IDENTIFIER) (POINT|array_type)* //指针,array
    ;

type_type_void:
    type_type
    | VOID
    ;

var_value:
    expression
     | var_arr_value
    ;

var_arr_value:
    '{' var_arr_value (',' var_arr_value)* '}'
    | '{' expr_list '}' //array
    ;

assign:
    id_primary (opr=(ADD|SUB|POINT|DIV|OR|XOR|POINTADDR)? '=' expression)?
    | id_primary (INCREMENT|DECREMENT)
    ;
assigns: assign (',' assign)*
    ;

var:
    IDENTIFIER ('=' var_value)?
    ;
vars:
    var (',' var)*
    ;
var_declares:
   type_type vars
   ;

//=================TODO template,class_def======================
template:
    '['IDENTIFIER*']'
    ;

class_def:
    'class' '{'

    '}'
    ;
//keywords

FUNC: 'func';
RETURN: 'return';
VOID: 'void';
TRUE: 'true';
FALSE: 'false';
FOR:'for';
BREAK: 'break';
CONTINUE: 'continue';
IF:'if';
ELSE: 'else';
ELIF:'elif';
POINTADDR: '&';
COND_AND: '&&';
COND_OR: '||';
COND_NOT: '!';
POINT: FSTAR;
INCREMENT: '++';
DECREMENT : '--';
COND_SPE: ';';
NIL: 'NIL';
TYPE: 'type';

ADD: '+';
SUB: '-';
MUL: POINT;
DIV: '/';
OR: '|';
XOR: '^';
NOT: '~';

CMP_EQ: '==';
CMP_NE: '!=';
CMP_GT: '>';
CMP_LT: '<';
CMP_GE: '>=';
CMP_LE: '<=';

//lexer
SPACE: [ \t\r\n]+ ->skip;
LINE_COMMENT: '//'  ~[\r\n]* -> channel(HIDDEN);
COMMENT: '/*' .*? '*/'-> channel(HIDDEN);

IDENTIFIER: ALPHA ALPHA_DIGIT*;
NUMBER: ( [1-9]DIGIT* | '0' )('.'DIGIT+)?;
INTEGER: [1-9]DIGIT*;
ALPHA_DIGIT: (ALPHA | DIGIT| '_');
ALPHA: [a-zA-Z];
DIGIT: [0-9];
NULL: 'NULL';

STRING_LITERAL:     '"' (~["\\\r\n] | EscapeSequence)* '"' |  '`' (~["\\\r\n] | EscapeSequence)* '`';

fragment
    FSTAR : '*'
    ;

fragment EscapeSequence
    : '\\' [btnfr"'\\]
    | '\\' ([0-3]? [0-7])? [0-7]
    | '\\' 'u'+ HexDigit HexDigit HexDigit HexDigit
    ;

fragment HexDigit
    : [0-9a-fA-F]
    ;
