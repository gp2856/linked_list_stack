#include "stack.h"

Stack::Stack(const Stack & source)
{
	size = source.size;
	// Get a pointer to the head of source
	Node *pSource = source.head;

	if (pSource == nullptr)
	{// if source.head is nullptr, new head is nullptr

		head = nullptr;
	}
	else
	{// Otherwise, allocate memory for the new head and copy the source head

		head = new Node(pSource->value, nullptr);
	}

	// After we copy the head, we need to traverse the linked list
	// Allocate memory for each node and copy the value
	// but we need to make sure our copy is pointing to newly allocated nodes
	// If the head is the only node on the source list, we don't need to do anything else
	pSource = pSource->next;

	if (pSource == nullptr)
	{
		head->next = new Node(pSource->value, nullptr);
	}
	else
	{
		// start at the head
		Node *pDest = head;
		while (pSource)
		{
			// Allocate memory for the new node
			Node *n = new Node(pSource->value, nullptr);
			// Set pointer to next node from current
			pDest->next = n;
			// Move to the next node
			pDest = pDest->next;
			pSource = pSource->next;
		}
	}
}

Stack & Stack::operator=(const Stack & source)
{
	size = source.size;

	// If there is no head or the head is the only node on the stack,
	// Just default to null
	if (source.head == nullptr)
	{
		head = nullptr;
	}
	else if (source.head->next == nullptr)
	{
		head->next = nullptr;
	}
	else
	{
		// Starting from the second node
		Node *pSource = source.head->next;
		Node *pDest = head->next;

		// Until we reach a nullptr
		while (pSource != nullptr)
		{
			// Allocate memory for the new node
			Node *n = new Node(pSource->value, nullptr);
			// Set pointer to next node from current
			pDest->next = n;
			// Move to the next node
			pDest = pDest->next;
			pSource = pSource->next;
		}
	}

	return *this; //mother fucker

}


Stack::~Stack()
{
	for (Node* ptr = head; ptr != nullptr; ptr = head)
	{
		head = head->next;
		delete ptr;
	}
}

void Stack::Push(int val)
{
	Node *n = new Node(val, head);
	head = n;
	size++;
}

int Stack::Pop()
{
	if (head)
	{
		Node *n = head;
		head = head->next;
		int ret = n->value;
		delete n;
		n = nullptr;
		size--;
		return ret;
	}
	return 0;
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return size == 0;
}

Stack::Node::Node(const int val, Node *next)
	:
	value(val),
	next(next)

{

}

// When deep copying a node, most of the work will be done in the parent object Stack,
// but we want to make absolute sure we aren't pointing to the source node's memory
Stack::Node::Node(const Node & source)
{
	value = source.value;
	next = nullptr;
}

