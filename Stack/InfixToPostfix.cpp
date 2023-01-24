#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int size;
    int Stacktop;

public:
    Stack()
    {
        size = 1000;
        arr = new T[size];
        Stacktop = -1;
    }

    void push(T data)
    {
        if (isFull())
            return;

        Stacktop++;
        arr[Stacktop] = data;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Stacktop--;
    }

    T top()
    {
        return arr[Stacktop];
    }

    bool isEmpty()
    {
        if (Stacktop == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (Stacktop == size - 1)
            return true;
        return false;
    }
};

int precedence(char c)
{
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int solve(int x, int y, char c)
{
    switch (c)
    {
    case '+':
        return x + y;

    case '-':
        return x - y;

    case '*':
        return x * y;

    case '/':
        return x / y;

    default:
        break;
    }
}

int evaluation(string str)
{
    Stack<int> s;
    int i = 0;
    while (str[i] != ')')
    {
        char c = str[i];
        if (!isOperator(c))
            s.push(c - '0');
        else
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(solve(b, a, c));
        }
        i++;
    }
    return s.top();
}

string infixToPostfix(string str)
{
    str=str+")";
    string p = "";
    Stack<char> s;
    s.push('(');

    int i = 0;
    while (!s.isEmpty())
    {
        char c = str[i];
        if (!isOperator(c))
            p = p + c;
        if (c == '(')
            s.push(c);
        if (isOperator(c))
        {
            while (precedence(c) <= precedence(s.top()))
            {
                p = p + s.top();
                s.pop();
            }
            s.push(c);
        }
        if (c == ')')
        {
            while (s.top() != '(')
            {
                p = p + s.top();
                s.pop();
            }
            s.pop();
        }
        i++;
    }
    return p;
}

int main()
{
    string s;
    cin >> s;

    s = infixToPostfix(s);
    cout << s << endl;

    cout << "Evaluated value is: " << evaluation(s);

    return 0;
}