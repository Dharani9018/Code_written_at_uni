/*
* Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true
  */

bool isValid(char* s) 
{
    char stack[strlen(s)];
    int top = -1;
    if(strlen(s)%2!=0)
    {
        return false;
    }
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if(top==-1)
            {
                return false;
            }
            else
            {
                if((s[i]=='}' && stack[top]=='{') || s[i]==']' && stack[top]=='[' || (s[i]==')' && stack[top]=='(') ) 
                {
                    top--;
                    continue;
                }
                else if(s[i]=='{' || s[i]=='(' || s[i]=='[')
                {
                    stack[++top]=s[i];
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(top==-1)
        {return true;}
        
    return false;
}

