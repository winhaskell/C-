#include <iostream>

using namespace std;

class Stack
{
public:
  Stack() : first(0), last(0)
  {
  }

  Stack(const Stack& other) : first(0), last(0)
  {
    copy(other);
  }

  ~Stack()
  {
    clear();
  }

  Stack& operator=(const Stack& other)
  {
    if (this != &other)
    {
      clear();
      copy(other);
    }

    return *this;
  }

  void clear()
  {
    while (!empty())
      pop();
  }

  bool empty() const
  {
    return last == 0;
  }

  void push(int v)
  {
    Node* n = createNode(v, last);

    if (empty())
      first = n;
    else
      last->next = n;

    last = n;
  }

  void pop()
  {
    Node* p = last->prev;

    if (p)
      p->next = 0;

    delete last;
    last = p;

    if (last == 0)
      first = 0;
  }

  int top() const
  {
    return last->value;
  }

private:
  struct Node
  {
    int value;
    Node* prev;
    Node* next;
  };

  Node* createNode(int value, Node* prev = 0, Node* next = 0)
  {
    Node* n = new Node;

    n->value = value;
    n->prev = prev;
    n->next = next;

    return n;
  }

  void copy(const Stack& other)
  {
    Node* n = other.first;

    while (n) // while (n != 0)
    {
      push(n->value);
      n = n->next;
    }
  }

  Node* first;
  Node* last;
};

int main()
{
  Stack s;

  for (int i = 0; i < 10; ++i)
    s.push(i);

  Stack s2 = s; // copy constructor

  Stack s3;
  s3 = s;       // assignment operator

  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  while (!s2.empty())
  {
    cout << s2.top() << endl;
    s2.pop();
  }

  while (!s3.empty())
  {
    cout << s3.top() << endl;
    s3.pop();
  }

  return 0;
}
