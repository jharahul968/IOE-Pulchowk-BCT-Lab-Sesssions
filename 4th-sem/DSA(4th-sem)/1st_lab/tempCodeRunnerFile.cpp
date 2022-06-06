    for (int i=0;i<infix.length();i++){
        if (infix[i]=='(')
        infix[i]=')';
        else if (infix[i]==')')
        infix[i]='(';
    }