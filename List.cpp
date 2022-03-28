#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class List
	{
		public:
		List();
		~List();
		T& operator [] (const int index);
		void push_back(T data);
		void push_front(T data);
		void pop_back();
		void pop_front();
		void insert(T value, int index);
		void removeAt(int index);
		void clear();
		int getSize(){return Size;} 
		struct OoR : exception
		{
		   const char* what() const noexcept {return "Out of range!\n";}
		};
		struct missing : exception //протестить
		{
		   const char* what() const noexcept {return "the value is missing!\n";}
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
		Size=0;
		head = nullptr;
	};

template<typename T>
List<T>::~List()
	{
		clear();
	};

template<typename T>
void List<T>::push_back(T data)
	{
		element<T> *temp = head;//element<T> *temp = this->head;
		while(temp->pNext) //while(temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}; 
		temp->pNext = new element<T>(data);
		Size++;
	};

template<typename T>
void List<T>::push_front(T data)
	{
	    head = new element<T> (data, head);
	    Size++;
	};

template<typename T> // протестировать!
T& List<T>::operator [] (const int index)
	{
		if(index > Size) throw OoR(); 
		element<T> *temp = head->pNext;
		for(int i = 0; !(temp); ++i)
			{
				if (i==index) return temp->data;
				temp = temp->pNext;
			};
		throw missing();
	};

template<typename T>
void List<T>::pop_back()
	{
	    removeAt(Size-1);
	};

template<typename T>
void List<T>::pop_front()
	{
		    element<T> *temp = head; 
		    head = temp->pNext;
		    delete temp;
		    Size--;
	};
	
template<typename T>
void List<T>::clear()
	{
	    while(Size)
	    {
	      pop_front();  
	    };
	};
	
template<typename T>
void List<T>::insert(T value,int index)
	{
	    if (index == getSize()) push_back(value); //если индекс на 1 больше списка то вставить в конец; 
	    else if (index == 0) push_front(value);
	    else if (index > getSize()) cout<<"Индекс выходит далеко за рамки массива\n";
	    else   //вариант с правильной логикой; 
	    {
	        element<T> *temp = head;
	        for(int i=0; i<(index-1); i++)//ищем предшествующий элемент;
	        {
	            temp = temp->pNext;
	        };
	        temp->pNext = new element<T>(value,temp->pNext);
	        Size++;
	    };
	};

template<typename T> 
void List<T>::removeAt(int index)//5
	{
	    if (index == 0) pop_front();
	    else if (index >= getSize()) cout<<"Выход за границы массива\n";
	    else 
	    {
	        element<T> *temp = head;
	        for(int i=0; i<index-1; i++)//идем предшествующий элемент;
	        {
	           // cout<<i<<" "<<temp->data<<"|";
	            temp = temp->pNext;
	        };
	        //cout<<endl;
	        element<T> *btd = temp->pNext; //удаляемый элементт;
	        temp->pNext = btd->pNext;
	        delete btd;
	        
	        Size--;
	    };
	};

void printline()
	{
	    cout<<"---------------------------------------------------------------------------------------\n";
	};

template<typename T>
void Status(List<T> & tos)
	{
	    cout<<"Теперь в списке "<<tos.getSize() <<(((tos.getSize()%10)<5)?" элемента.":" элементов.")<< endl; //выводим количество элементов

		for(int i=0;i<tos.getSize();i++) // выводим список
		{
		    cout<<tos[i]<<((i==(tos.getSize()-1))?".\n":"->");
		};
	};

int main()
	{
	    int vote_index;
	    
		List<int> list; //Создаем список
		list.push_back(0); // заполняем;
		list.push_back(11);
		list.push_back(22);
		list.push_back(33);
		Status(list);
	    cout<<"В списке "<<list.getSize() <<(((list.getSize()%10)<5)?" элемента.":" элементов.")<< endl; //выводим количество элементов

		for(int i=0;i<list.getSize();i++) // выводим список
		{
		    cout<<list[i]<<((i==(list.getSize()-1))?".\n":"->");
		};
		
		cout<<"Вставим в конец число " << 44 << endl;
		list.push_back(44);

		try // это работает
		{
			cout<<list[40]<<endl;
		}
		catch(const std::exception & ex)
		{
			cout<<ex.what();
		};
		
		Status(list);
		printline();
		
		cout<<"Вставим в начало число "<< -11 <<endl;
		list.push_front(-11);
		
		Status(list);
		printline();
		
		cout<<"Удалим последний элемент"<<endl;
		list.pop_back();
		
		Status(list);
		printline();
		
		cout<<"Теперь удалим первый элемент"<<endl;
		list.pop_front();
		
		Status(list);
		printline();
		
		cout<<"Вставим число 20 на 2-е место списка"<<endl;
		list.insert(20,2);
		
		Status(list);
		printline();
		
		cout<<"Удалим из списка 1-й элемент\n";
		list.removeAt(1);
		
		Status(list);
		printline();
		
		return 0;
	}
