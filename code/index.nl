@add test.nl

string title = "TestTitle";

@template templateString from template.html

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