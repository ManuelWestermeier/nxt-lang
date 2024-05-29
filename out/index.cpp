
#define DO {
#define DOES ) {
#define END }

#define IF if (
#define DOIF ) {

#define ELSEIF else if (
#define DOELSEIF ) {

#define ELSE else {

#define FN auto 
#define ARGS = [&](
#define RUNS ) {
#define ENDFN };

#define CALL (
#define CALLEND )

#define EXIT return
#define STOP ;

#define FOR for (
#define FORRUN ) {

#define WHILE while (
#define WHILERUN ) {

#define ADD +
#define SUB -
#define MUL *
#define DIV /
#define MOD %

#define _ADD +=
#define _SUB -=
#define _MUL *=
#define _DIV /=

#define INC ++
#define DEC --

#define become =
#define EQUALS ==
#define NOT !

#define LESS <
#define MORE >
#define LESSOREQUALS =<
#define MOREOREQUALS >=

#include <string>
#include <vector>
#include <stdio.h>

using std::vector, std::string;

//your code
int main (int argc, char** argv) {
    //From Other FILE
printf CALL "FROM OTHER FILE\n" CALLEND STOP

string title = "TestTitle";

string templateString = "<!DOCTYPE html>\r\n<html lang=\"en\">\r\n<head>\r\n    <meta charset=\"UTF-8\">\r\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n    <title>" + title + "</title>\r\n</head>\r\n<body>\r\n    \r\n</body>\r\n</html>";

printf CALL templateString.c_str CALL CALLEND CALLEND STOP

printf CALL "Hello World\n" CALLEND STOP

bool x become true STOP

FN test ARGS int count, int times RUNS

    count _MUL times STOP

    FOR int i STOP i < count STOP i INC FORRUN

        IF x DOIF
            printf CALL "x is true %d\n", i ADD 1 CALLEND STOP    
        END

    END

    EXIT 10 STOP

ENDFN

test CALL 5, 2 CALLEND STOP

WHILE false WHILERUN
    IF x DOIF
        //if
    END
    ELSEIF !x DOELSEIF
        //else if
    END
    ELSE 
        //else
    END
END

EXIT 0 STOP
}