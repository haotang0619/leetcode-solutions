function calculate(s: string): number {
    let stack = [];
    let postfix = [''];
    let idx = 0;
    
    let len = s.length;
    for(let i = 0; i < len; i++) {
        if(/[0-9]/.test(s[i])) postfix[idx] += s[i];
        else if(/[+-]/.test(s[i])) {
            while(!!stack[0]) postfix[++idx] = stack.pop();
            stack.push(s[i]); postfix[++idx] = '';
        } else if(/[*/]/.test(s[i])) {
            while(/[*/]/.test(stack.slice(-1)[0])) postfix[++idx] = stack.pop();
            stack.push(s[i]); postfix[++idx] = '';
        }
    }
    while(!!stack[0]) postfix[++idx] = stack.pop();
    
    stack = [];
    postfix.forEach((op) => {
        if(/[0-9]/.test(op)) stack.push(op);
        else {
            const b = parseInt(stack.pop());
            const a = parseInt(stack.pop());
            if(op === '+') stack.push(a + b);
            else if(op === '-') stack.push(a - b);
            else if(op === '*') stack.push(a * b);
            else stack.push(Math.floor(a / b));
        }
    })
    return stack[0];
};
