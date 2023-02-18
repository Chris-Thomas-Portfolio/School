template<typename T>
inline int BSTree<T>::Height(BSNode<T>*& current)
{
	if (current == nullptr)
	{
		return 0;
	}
	else
	{
		int left = Height(current->m_left);			//set left to lefts height
		int right = Height(current->m_right);		//set right to rights height
		if (left > right)							//determine which is bigger and set temp to that value +1
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

template<typename T>
inline void BSTree<T>::BreadthFirst(BSNode<T>*& current, void(*visit)(T data))
{
	BSNode<T>* temp = nullptr;
	Queue<BSNode<T>*> queue;					//create a queue
	queue.Enqueue(current);						//enqueue the root node
	while (queue.isEmpty() != true)
	{
		temp = queue.Dequeue();					//traverse and visit nodes in desired order
		visit(temp->m_data);
		if (temp->m_left != nullptr)
		{
			queue.Enqueue(temp->m_left);
		}
		if (temp->m_right != nullptr)
		{
			queue.Enqueue(temp->m_right);
		}
	}
}

template<typename T>
inline void BSTree<T>::Insert(BSNode<T> *& current, T data)
{
	if (current == nullptr)					//if current is nullptr make a new BSNode with the data
		current = new BSNode<T>(data);
	else if (data < current->m_data)		//if data is less than currents data call Insert with currents m_left
		Insert(current->m_left, data);
	else
		Insert(current->m_right, data);		//if data is more than currents data call Insert with currents m_right
}

template<typename T>
inline void BSTree<T>::Copy(BSNode<T>*& new_tree, BSNode<T>* copy)
{
	if (copy == nullptr)							//check to see if copy is nullptr
	{
		new_tree = nullptr;							//if it is set new_tree to nullptr
	}
	else
	{
		new_tree = new BSNode<T>(copy->m_data);		//set new tree to copies data
		Copy(new_tree->m_left, copy->m_left);		//move left down the tree
		Copy(new_tree->m_right, copy->m_right);		//move right downt he tree
	}
}

template<class T>
inline List<T>::List(const List<T>& copy) : m_head(nullptr), m_tail(nullptr)
{
	if (copy.m_head != nullptr)
	{
		Node<T>* travel = copy.m_head;

		while (travel != nullptr)
		{
			Append(travel->m_data);
			travel = travel->m_next;
		}
	}
}

template<class T>
inline void List<T>::Append(T data)
{
	Node<T>* nn = new Node<T>(data);

	if (m_head == nullptr)			//check for empty List
	{
		nn->setPrevious(nullptr);	//set new nodes previous to nullptr
		nn->setNext(nullptr);		//set new nodes next to nullptr
		m_head = nn;				//set m_head and m_tail to new node since its the only node in List.
		m_tail = nn;
	}
	else
	{
		nn->setPrevious(m_tail);	//set new nodes previous to tail of list
		nn->setNext(nullptr);		//set new nodes next to nullptr since it is the end of the list.
		m_tail->setNext(nn);		//set old tails next to new node.
		m_tail = nn;				//set m_tail to new node since it is the new tail.
	}
}

template<class T>
inline void List<T>::Prepend(T data)
{
	Node<T>* nn = new Node<T>(data);			//create new node with data

	nn->setNext(m_head);						//set new nodes next to old head
	nn->setPrevious(nullptr);					//set new nodes previous to nullptr
	if (m_head != nullptr)
	{
		m_head->setPrevious(nn);				//set old heads previous to new node
	}
	if (m_tail == nullptr)
	{
		m_tail = nn;							//if tail is nullptr make new node tail as well
	}

	m_head = nn;								//set new node as head
}

template<class T>
inline void List<T>::Purge()
{
	Node<T>* trail = nullptr;			//create node to traverse list

	while (m_head != nullptr)			//while m_head is not nullptr traverse the list and delete all nodes
	{
		trail = m_head;
		m_head = m_head->m_next;
		m_tail = nullptr;
		delete trail;
	}
}
