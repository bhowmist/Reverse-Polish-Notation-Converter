# Reverse-Polish-Notation-Converter
This program allows the conversion of a mathematical expression in infix notation to reverse Polish notation (RPN).

Infix Notation Rules:
---------------------
● The placement of operators is between operands. For example: a+b
● Parentheses, (), can be used to surround groups of operands and operators to indicate
the intended order in which operations are to be performed.
● The order of operation, when not overridden by parentheses, is described in the table
below by descending order. For example, because division has higher precedence than
multiplication, a*b/c is equivalent to a*(b/c).

Precedence        Name        Operator

1                Exponent          ^

2                Division          /

3               Multiplication     *

4                Subtraction       -

5                Addition          +

Operators with equal precedence associate from left to right. For example, a^b^c is
equivalent to (a^b)^c.

It is not necessary to include the unary negation operator as part of this exercise.
Example: -b.

Valid operands are only lowercase letters: a, b, ..., z

RPN Notation Rules:
-------------------
● The operators follow their operands. For example: ab+
● Valid operators are ^, /, *, -, +
● Valid operands are only lowercase letters: a, b, ..., z
-----------------------------------------------------------------------------------------------------------------------------
Examples:
1. Infix to RPN: a+b-c becomes abc-+

2. Infix to RPN: (a+b)-c becomes ab+c-

3. Infix to RPN: l/m^n*o-p and ((l/(m^n))*o)-p are equivalent expressions that become
lmn^/o*p-

4. Infix to RPN: ((v/w)^x)*(y-z) becomes vw/x^yz-*


