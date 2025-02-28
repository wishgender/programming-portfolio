Algorithm: Evaluated Postfix. Stack is empty, expr is a valid postfix expression. This algorithm needs to be augmented to solve the postfix to assembly problem.

```
While (not done with expr) do
    t = next token in expr // You can use find next blank and substr.
    if t is NOT an operator then
        push(t)
    else
        right = pop stack
        left = pop stack
        push evaluate(left, t, right)
    endif
end while
Top of stack has value
```




//=================================//

when i was using truncID

```
    while (token.length() > 6) {
        token = (token.substr(0,5));
        for (int i = 0; i < tokenID.getVecSize(); i++){
            if (token == tokenID[i]) {
                token = token.substr(0, token.length()-2);
                token += tokenID.getID();
                ++tokenID;
                tokenID.push(token);
            }
        }
        tokenID.push(token);
    }

    while (token.length() > 6) {
            token = (token.substr(0,5));
            for (int i = 0; i < tokenID.getVecSize(); i++){
                if (token == tokenID[i]) {
                    token = token.substr(0, token.length()-2);
                    token += tokenID.getID();
                    ++tokenID;
                    tokenID.push(token);
                }
            }
            tokenID.push(token);
        }
```


//=====================================================//

when i tried to avoid having to open the istream twice

```
    std::vector<String> in2post(String in) {
    String token;
        stack<String> S;
        std::vector<String> result;
        std::vector<String> tokens(in.split(' '));
        int j = 0;

        do {
            if (tokens[j].length() >= 7) tokens[j] = tokens[j].substr(0,5);
            while(tokens[j] != NULL_CHAR) {
                if ( tokens[j] == ")" ) {
                    String rhs = S.pop() + ' ';
                    String op  = S.pop();
                    String lhs = S.pop() + ' ';
                    S.push(lhs + rhs + op);
                }
                else {
                    if(tokens[j] != "(") {
                        S.push(tokens[j]);
                    }
                }

                ++j;
                if (tokens[j].length() >= 7) tokens[j] = tokens[j].substr(0,5);
                if (tokens[j] == ";") result.push_back(" " + (S.top()));
                else if(tokens[j] == NULL_CHAR) {
                    return result;
                }
            }
        } while(tokens[j]!=NULL_CHAR && (tokens[j]!="\r"&&tokens[j]!="\r\n"));
                        //result.push_back(";");
        return result;
    }
```


//=====================================================//

more backed up code

```
    std::ostream& evaluate(String lhs, String rhs, String opr) {
    //    std::cout << "evaluating...\n";
        String instr;
        // switch (opID(opr))
        //     case (0):
        //         return 
        String oprOPCODE = opID(opr);
        instr = lhs + "\n   " + oprOPCODE + "     " + rhs + '\n';
        return instr;
    }

    else { //if the current token is an operator
    
        //right operand
        String rhs = S.pop();
        //left operand
        String lhs = S.pop();

        out << "   LD     " << lhs << std::endl;
        //get the opcode for the operator
        out << "   " << opID(nextToken) << "     " << rhs << std::endl;

        //set TEMPn to the proper identifier and increment the int
        //then push it to the stack
        TEMPn = "TEMP" + String::intToString(nCount++);
        S.push(TEMPn);

        //save temporary variable
        out << "   ST     " << S.top() << std::endl;
    }
```
