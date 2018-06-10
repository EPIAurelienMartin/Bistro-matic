#!/bin/bash

cd ..
make re > /dev/null
echo -en "\ec"

echo -e "Basic tests\n"

echo "   01 - syntax errors - 09 tests"

echo "3+6" | ./calc "0123456789" "()+-*%" 3 > got
echo -n "syntax error" > except
echo -ne "\tA - missing operator : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3+6" | ./calc "0123456789" "()+-*/%{}" 3 > got
echo -n "syntax error" > except
echo -ne "\tB - too many operator : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3+6" | ./calc "012345+789" "()+-*/%" 3 > got
echo -n "syntax error" > except
echo -ne "\tC - operator in the base : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3+6" | ./calc "0113456789" "()+-*/%" 3 > got
echo -n "syntax error" > except
echo -ne "\tD - two identical digits : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3+6" | ./calc "0123456789" "()+-//%" 3 > got
echo -n "syntax error" > except
echo -ne "\tE - two identical operators : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "(3+6" | ./calc "0123456789" "()+-*/%" 4 > got
echo -n "syntax error" > except
echo -ne "\tF - unmatched parenthesis #1 : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "((3+6)+2" | ./calc "0123456789" "()+-*/%" 8 > got
echo -n "syntax error" > except
echo -ne "\tG - unmatched parenthesis #2 : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3+6(+2)" | ./calc "0123456789" "()+-*/%" 7 > got
echo -n "syntax error" > except
echo -ne "\tH - invalid expression : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "" | ./calc "0123456789" "()+-*/%" 0 > got
echo -n "syntax error" > except
echo -ne "\tI - empty expression : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi



echo "   02 - calcul - 8 tests"


echo "3+6" | ./calc "0123456789" "()+-*/%" 3 > got
echo -n "9" > except
echo -ne "\tA - simple addition : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "3v6" | ./calc "0123456789" "{}vwxyz" 3 > got
echo -n "9" > except
echo -ne "\tB - addition change operand: "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "--++-6(12)" | ./calc "0123456789" "()+-*/%" 10 > got
echo -n "syntax error" > except
echo -ne "\tC - unary expression error : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "--++-6*12" | ./calc "0123456789" "()+-*/%" 9 > got
echo -n "-72" > except
echo -ne "\tD - unary expression : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "-(12-(4*32))" | ./calc "0123456789" "()+-*/%" 12 > got
echo -n "116" > except
echo -ne "\tE - priority parenthis but one missing : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "-(12-(4*32)" | ./calc "0123456789" "()+-*/%" 11 > got
echo -n "syntax error" > except
echo -ne "\tF - simple addition : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "-(e@-(;*!@))" | ./calc "0A@!;ie& ]" "()+-*/%" 12 > got
echo -n "ee" > except
echo -ne "\tG - base change : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

echo "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))" | ./calc "0123456789" "()+-*/%" 84 > got
echo -n "-744629760" > except
echo -ne "\tH - Big : "
diff got except > /dev/null
if [ $? -ne 0 ]
then
    echo -ne "KO\n"
    echo -ne "\t  Test failure: The output must match the regular expression '^"
    cat except
    echo -n "', but it was '"
    cat got
    echo "'"
else
    echo -ne "OK\n"
    echo -e "\t  PASSED"
fi

make fclean > /dev/null
rm except got
