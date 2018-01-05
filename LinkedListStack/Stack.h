#pragma once
class Stack
{
private:
	class Node
	{
	public:
		Node(int val, Node *next);
		Node(const Node& source);
		Node& operator=(Node& source) = delete;
		~Node() = default;
	public:
		int value;
		Node *next = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& source);
	Stack& operator=(const Stack& source);
	~Stack();
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Node * head = nullptr;
	int size = 0;
};