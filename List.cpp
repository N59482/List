#include <iostream>

using namespace std;

template<typename T>
class List
	{
		public:
		List();
		~List();
		T& operator [] (const int index);
		void push_back(const T& data);
		void push_front(const T& data);
		void pop_back();
		void pop_front();
		void insert(const T & value,const int index);
		void removeAt(const int & index);
		void clear();
		void show();
		void index_show(List<T> & p_list);// пример использования перегруженного оператора методами класса.
		int getSize(){return Size;}
		struct OoR : exception
			{
			   const char* what() const noexcept {return "Out of range!\n";}
			};
		struct missing : exception
			{
			   const char* what() const noexcept {return "the value is missing\n";}
			};

		private:

		template<typename T1>
		class element
		{
			public:
			element *pNext;
			T1 data;
			element(T1 data=T1(), element *pNext=NULL)
			{
				this->data=data;
				this->pNext=pNext;
			};
		};
		
		element<T> *head;
		int Size;	
	};

template<typename T>
List<T>::List()
	{
		cout<<"Constructor\n";
		Size = 0;
		head = new element<T>();
	};

template<typename T>
List<T>::~List() // разобраться как работет, не остаётся ли head
	{
		cout<<"Destructor\n";
		clear();
		// delete head; // ошибка munmap_chunk(): invalid pointer разобраться почему
	};

template<typename T> 
void List<T>::push_back(const T & data)
	{
		// cout<<"push_back\n";
		element<T> *temp = head;//нужно ли писать this->head?
		while(temp->pNext != nullptr)
		    temp = temp->pNext;
		temp->pNext = new element<T>(data);
		Size++;
	};

template<typename T>
void List<T>::push_front(const T& data)
	{
		// cout<<"push_front\n";
	    head->pNext = new element<T> (data, head->pNext);
	    Size++;
	};

template<typename T> 
T& List<T>::operator [] (const int index)
	{
		// cout<<"operator []\n";
		if(index >= Size) throw OoR(); 
		element<T> *temp = head->pNext;
		for(int i = 0; i < Size; i++)
			{
				if (i==index) return temp->data; 
				temp = temp->pNext;
			};
		throw OoR(); 
	};

template<typename T> // протестировать
void List<T>::pop_back()
	{
		// cout<<"pop_back\n";
	    removeAt(Size-1);
	};

template<typename T> // протестировать
void List<T>::pop_front()
	{
		// cout<<"pop_front\n";
		if(head->pNext != nullptr)
			{
				element<T> *temp = head->pNext; 
				head->pNext = temp->pNext;
				delete temp;
				Size--;
			};
	};
	
template<typename T>
void List<T>::clear()
	{
		// cout<<"clear\n";
	    while(Size)
	    {
	      pop_front();  
	    };
	};
	
template<typename T> 
void List<T>::insert(const T & value,const int index)
	{
		// cout<<"insert\n";
	    if((index > getSize()) || (index < 0)) throw OoR();
	    element<T> *prev = head;
	    for(int i = 0; i < index; i++)
	    	prev = prev->pNext;
	    prev->pNext = new element<T>(value,prev->pNext);
	    Size++;
	};

template<typename T> 
void List<T>::removeAt(const int & index)
	{
		// cout<<"removeAt\n";
	    if((index < 0) || (index >= getSize())) throw OoR();
	    element<T> *temp = head;
	    for(int i = 0; i < index; i++)
	    	temp = temp->pNext;
	    element<T> *delete_me = temp->pNext;
	    temp->pNext = delete_me->pNext;
	    delete delete_me;
	    Size--;
	};

template<typename T> 
void List<T>::show()
	{   
	    for(element<T> *temp = head;temp->pNext != nullptr;temp = temp->pNext)
	        cout<<temp->pNext->data<<"->";
	    cout<<endl;
	};
	
template<typename T> 
void List<T>::index_show(List<T> & p_list)
	{   
	    for(int i = 0; i < p_list.getSize(); i++)
	        cout<<p_list[i]<<"->";
	    cout<<endl;
	};	

template<typename T> 
void Status(List<T> & tos)
	{
	    cout<<"Теперь в списке "<<tos.getSize() <<(((tos.getSize()%10)<5)?" элемента.":" элементов.")<< endl;
		for(int i=0;i<tos.getSize();i++)
		{
		    cout<<tos[i]<<((i==(tos.getSize()-1))?".\n":"->");
		};
	};

int main()
	{
		// List<int> l;
		// Status(l);
		
		// l.push_back(3);
		// Status(l);
        
  		// l.push_back(4);
		// Status(l);
		
		// int x = 2;
		// l.push_front(x);
		// Status(l);

		// l.push_front(l[1] - l[0]);
		// Status(l);

		// l.pop_back();
		// Status(l);

		// l.pop_front();
		// Status(l);

		// l.insert(4,1);
		// Status(l);

		// l.removeAt(0);
		// Status(l);

		return 0;
	}