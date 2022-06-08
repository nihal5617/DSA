def prec(operator):
    if operator == '+' or operator == '-':
        return 1
    elif operator == '*' or operator == '/':
        return 2
    else:
        return -1

def infix_to_postfix(exp:str):
    stack = []
    answer = ''
    for i in range(len(exp)):
        if exp[i].isalpha():
             answer += exp[i]
        elif exp[i] == '(':
            stack.append(exp[i])
        elif exp[i] == ')':
            while stack and stack[-1] != '(':
                answer += stack.pop()
            if stack and stack[-1] != '(':
                return -1
            else:
                stack.pop()
        else:
            while stack and prec(exp[i]) <= prec(stack[-1]):
                answer += stack.pop() 
            stack.append(exp[i])
    for i in stack:
        answer += i
    print(answer)

if __name__ == '__main__':
    print("Enter the infix expression:")
    exp = input()
    infix_to_postfix(exp)