#ifndef DL_LIST
#define DL_LIST
#include <iostream>
#include "List.h"

using namespace LinkedList; 

    template <typename T>
	List<T>::const_iterator::const_iterator() : current{nullptr} // default zero parameter constructor
	{ }
	template <typename T>
	const T & List<T>::const_iterator::operator*() const // operator*() to return element
	{ return retrieve(); }
	// increment/decrement operators
	
	template <typename T>
	typename List<T>::const_iterator& List<T>::const_iterator::operator++()
	{
	  current = current->next;
	  return *this;
	}
	template <typename T>
	typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
	{
	  const_iterator old = *this;
	  ++(*this);
	  return old;
	}
	template <typename T>
	typename List<T>::const_iterator & List<T>::const_iterator::operator--()
	{
	  current = current->prev;
	  return *this;
	}
	template <typename T>
	typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
	{
	  const_iterator old = *this;
	  --(*this);
	  return old;
	}

	// comparison operators
	template <typename T>
	bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
	  {return current == rhs.current;}
	template <typename T>
	bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
	  {return !(*this==rhs);}

  //  protected:
//	Node *current; // pointer to node in List
	template <typename T>
	T & List<T>::const_iterator::retrieve() const // retrieve the element refers to
	  {return current->data;}
	template <typename T>
	List<T>::const_iterator::const_iterator(Node *p) : current{p} // protected constructor
	  { }

//	friend class List<T>;
//    };

    // nested iterator class
 //   class iterator : public const_iterator {
 //   public:
//	iterator() {}
	template <typename T>
	T & List<T>::iterator::operator*()
	  {return const_iterator::retrieve();}
	template <typename T>
	const T & List<T>::iterator::operator*() const
	  {return const_iterator::operator*();}
	
	// increment/decrement operators
	template <typename T>
	typename List<T>::iterator & List<T>::iterator::operator++()
	{
	  this->current = this->current->next;
	  return *this;
	}
	template <typename T>
	typename List<T>::iterator List<T>::iterator::operator++(int)
	{
	  iterator old = *this;
	  ++(*this);
	  return old;
	}
	template <typename T>
	typename List<T>::iterator & List<T>::iterator::operator--()
	{
	  this->current = this->current->prev;
	  return *this;
	}
	template <typename T>
	typename List<T>::iterator List<T>::iterator::operator--(int)
	{
	  iterator old = *this;
	  --(*this);
	  return old;
	}

 //   protected:
	template <typename T>
	List<T>::iterator::iterator(Node *p) : const_iterator{p}
	  { }
//	friend class List<T>;
//    };

// public:
    // constructor, desctructor, copy constructor
	template <typename T>
    List<T>::List() // default zero parameter constructor
	  { init(); }
	template <typename T>
    List<T>::List(const List &rhs) // copy constructor
	{
	  init();
	  for(auto & x : rhs)
	    push_back(x);
	}
	template <typename T>
    List<T>::List(List && rhs) // move constructor
	  : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
	{
	  rhs.theSize = 0;
	  rhs.head = nullptr;
	  rhs.tail = nullptr;
	}
    // num elements with value of val
	template <typename T>
    List<T>::List(int num, const T& val)
	{
	}
    // constructs with elements [start, end)
	template <typename T>
    List<T>::List(const_iterator start, const_iterator end)
	{
	}
       
	template <typename T>
    List<T>::~List() // destructor
	{
	  clear();
	  delete head;
	  delete tail;
	}

    // copy assignment operator
	template <typename T>
    const typename List<T>::List& List<T>::operator=(const List &rhs)
	{
	  List copy = rhs;
	  std::swap(*this,copy);
	  return *this;
	}
    // move assignment operator
	template <typename T>
    typename List<T>::List & List<T>::operator=(List && rhs)
	{
	  std::swap(theSize, rhs.theSize);
	  std::swap(head, rhs.head);
	  std::swap(tail, rhs.tail);
	  
	  return *this;
	}

    // member functions
	template <typename T>
    int List<T>::size() const // number of elements
	{}
	template <typename T>
    bool List<T>::empty() const // check if list is empty
	{}
	template <typename T>
    void List<T>::clear() // delete all elements
	{}
	template <typename T>
    void List<T>::reverse() // reverse the order of the elements
	{}
	template <typename T>
    T & List<T>::front() // reference to the first element
	{}
	template <typename T>
    const T& List<T>::front() const
	{}
	template <typename T>
    T & List<T>::back() // reference to the last element
	{}
	template <typename T>
    const T & List<T>::back() const
	{}
    template <typename T>
    void List<T>::push_front(const T & val) // insert to the beginning
	{}
	template <typename T>
    void List<T>::push_front(T && val) // move version of insert
	{}
	template <typename T>
    void List<T>::push_back(const T & val) // insert to the end
	{}
	template <typename T>
    void List<T>::push_back(T && val) // move version of insert
	{}
	template <typename T>
    void List<T>::pop_front() // delete first element
	{}
	template <typename T>
    void List<T>::pop_back() // delete last element
	{}
	template <typename T>
    void List<T>::remove(const T &val) // remove all elements with value = val
	{}
    
    // print out all elements. ofc is deliminitor
	template <typename T>
    void List<T>::print(std::ostream& os, char ofc) const
	{}
	template <typename T>
    typename List<T>::iterator List<T>::begin() // iterator to first element
	{}
	template <typename T>
    typename List<T>::const_iterator List<T>::begin() const
	{
	  const_iterator itr{*this, head};
	  return ++itr;
	}
	template <typename T>
    typename List<T>::iterator List<T>::end() // end marker iterator
	{}
	template <typename T>
    typename List<T>::const_iterator List<T>::end() const
	{}
	template <typename T>
    typename List<T>::iterator List<T>::insert(iterator itr, const T& val) // insert val ahead of itr
	{
	  Node *p = itr.current;
	  theSize++;
	  return {p->prev = p->prev->next = new Node{val, p->prev, p } };
	}
	template <typename T>
    typename List<T>::iterator List<T>::insert(iterator itr, T && val) // move version of insert
	{
	  Node *p = itr.current;
	  theSize++;
	  return {p->prev = p->prev->next = new Node{std::move(val), p->prev, p} };
	}
	template <typename T>
    typename List<T>::iterator List<T>::erase(iterator itr) // erase one element
	{
	  Node *p = itr.current;
	  iterator retVal{p->next};
	  p->prev->next = p->next;
	  p->next->prev = p->prev;
	  delete p;
	  theSize--;
	  
	  return retVal;
	}
	template <typename T>
    typename List<T>::iterator List<T>::erase(iterator start, iterator end) // erase [start, end)
	{
	  for(iterator itr = start; itr != end; )
	    itr = erase(itr);
	
	  return end;
	}

    
//private:
 //   int theSize; // number of elements
//    Node *head; // head node
//    Node *tail; // tail node
	template <typename T>
    void List<T>::init() // initialization
	{
	  theSize = 0;
	  head = new Node;
	  tail = new Node;
	  head->next = tail;
	  tail->prev = head;
	}
//};

// overloading comparison operators
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{}

// include the implementation file here
//#include "List.cpp"

//} // end of namespace 4530

#endif
