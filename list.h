#ifndef HUGO_LIST_H__
#define HUGO_LIST_H__

namespace ds
{
	namespace detail
	{
		template <class T>
		struct list_node
		{
		public:
			list_node(const T& v, list_node<T>* p = 0, list_node<T>* n = 0);
			list_node(list_node<T>* node);
			list_node<T>* prev;
			list_node<T>* next;
			T val;
		};

		template <class T>
		list_node<T>::list_node( const T& v, list_node<T>* p, list_node<T>* n)
			: prev(p), next(n), val(v)
		{}

		template <class T>
		list_node<T>::list_node(list_node<T>* node)
			: prev(node->prev), next(node->next), val(node->val)
		{}

		template <class T>
		class list_iterator
		{
		public:
			list_iterator();
			list_iterator(list_node<T>* node);
			list_iterator(const list_iterator& iter);

			list_iterator& operator=(const list_iterator& iter);
			list_iterator operator++(int);
			list_iterator& operator++();
			list_iterator operator--(int);
			list_iterator& operator--();
			bool operator==(const list_iterator& iter);
			bool operator!=(const list_iterator& iter);
			T& operator*();
		//private:
			list_node<T>* node_ptr;

			template <class S>
			friend class list;
		};

		template <class T>
		list_iterator<T>::list_iterator()
			: node_ptr(0)
		{}

		template <class T>
		list_iterator<T>::list_iterator(list_node<T>* node)
			: node_ptr(node)
		{}
		
		template <class T>
		list_iterator<T>::list_iterator(const list_iterator<T>& iter)
			: node_ptr(iter.node_ptr)
		{}

		template <class T>
		list_iterator<T>& list_iterator<T>::operator=(const list_iterator<T>& iter)
		{
			node_ptr = iter.node_ptr;
			return *this;
		}

		template <class T>
		list_iterator<T> list_iterator<T>::operator++(int)
		{
			list_iterator<T> iter = *this;
			if(node_ptr != 0)
				node_ptr = node_ptr->next;
			return iter;
		}

		template <class T>
		list_iterator<T>& list_iterator<T>::operator++()
		{
			if(node_ptr != 0)
				node_ptr = node_ptr->next;
			return *this;
		}

		template <class T>
		list_iterator<T> list_iterator<T>::operator--(int)
		{
			list_iterator<T> iter = *this;
			if(node_ptr != 0)
				node_ptr = node_ptr->prev;
			return iter;
		}

		template <class T>
		list_iterator<T>& list_iterator<T>::operator--()
		{
			if(node_ptr != 0)
				node_ptr = node_ptr->prev;
			return *this;
		}

		template <class T>
		bool list_iterator<T>::operator==(const list_iterator<T>& iter)
		{
			return iter.node_ptr == node_ptr;
		}

		template <class T>
		bool list_iterator<T>::operator!=(const list_iterator<T>& iter)
		{
			return !(*this == iter); 
		}

		template <class T>
		T& list_iterator<T>::operator*()
		{
			return node_ptr->val;
		}
	}

	template <class T>
	class list
	{
	public:
		typedef typename detail::list_iterator<T>			iterator;
		typedef typename T									value_type;
		typedef typename T&									reference;
		typedef typename const T&							const_reference;

		list();
		list(const list<T>& lst);
		~list();

		void push_back(const_reference val);
		void push_front(const_reference val);
		iterator insert(iterator iter, const_reference val);
		void pop_front();
		void pop_back();
		iterator erase(iterator iter);
		iterator erase(iterator i, iterator f);
		void clear();
		bool empty();
		unsigned int size();

		iterator begin();
		iterator end();
	protected:
		void init_nodes();
	private:
		detail::list_node<T>* first, *last;
		unsigned int sz;
	};


	template <class T>
	void list<T>::init_nodes()
	{
		last = new detail::list_node<T>(T(), 0, 0);
		first = new detail::list_node<T>(T(),  0, last);
		last->prev = first;
	}
	template <class T>
	list<T>::list()
		: first(0), last(0), sz(0)
	{
		init_nodes();
	}

	template <class T>
	list<T>::~list()
	{
		clear();
		delete first;
		delete last;
		sz = 0;
	}

	template <class T>
	typename list<T>::iterator list<T>::begin()
	{
		return iterator(first->next);
	}

	template <class T>
	typename list<T>::iterator list<T>::end()
	{
		return iterator(last);
	}

	template <class T>
	list<T>::list(const list<T>& lst)
		: first(0), last(0), sz(0)
	{
		init_nodes();
		for(iterator it = lst.begin(); it != lst.end(); i++)
			push_back(*it);
	}

	template <class T>
	void list<T>::push_back(typename list<T>::const_reference val)
	{
		insert(end(), val);
	}

	template <class T>
	void list<T>::push_front(typename list<T>::const_reference val)
	{
		insert(begin(), val);
	}

	template <class T>
	typename list<T>::iterator list<T>::insert(iterator iter, const_reference val)
	{
		if(iter.node_ptr != 0)
		{
			detail::list_node<T>* node = new detail::list_node<T>(val, iter.node_ptr->prev, iter.node_ptr);
			if(iter.node_ptr->prev != 0)
				iter.node_ptr->prev->next = node;
			iter.node_ptr->prev = node;
			return iterator(node);
		}
		return iterator(0);
	}

	template <class T>
	void list<T>::pop_front()
	{
		erase(begin());
	}

	template <class T>
	void list<T>::pop_back()
	{
		erase(end()--);
	}

	template <class T>
	typename list<T>::iterator list<T>::erase(iterator iter)
	{
		if(iter.node_ptr != 0)
		{
			iterator it(iter.node_ptr->next);
			if(iter.node_ptr->prev != 0)
				iter.node_ptr->prev->next = iter.node_ptr->next;
			if(iter.node_ptr->next != 0)
				iter.node_ptr->next->prev = iter.node_ptr->prev;
			delete iter.node_ptr;
			return it;
		}
		return iterator(0);
	}

	template <class T>
	typename list<T>::iterator list<T>::erase(iterator i, iterator f)
	{
		iterator it;
		while(i != f)
			it = erase(i++);
		return it;
	}

	template <class T>
	void list<T>::clear()
	{
		erase(begin(), end());
	}

	template <class T>
	bool list<T>::empty()
	{
		return sz == 0;
	}

	template <class T>
	unsigned int list<T>::size()
	{
		return sz;
	}

}

#endif