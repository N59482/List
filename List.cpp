#include <iostream>

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
		void show();
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
		head = new element<T>(0,nullptr);
	};

template<typename T>
List<T>::~List() // разобраться как работет, не остаётся ли head
	{
		cout<<"Destructor\n";
		clear();
		// delete head; // ошибка munmap_chunk(): invalid pointer разобраться почему
	};

template<typename T> 
void List<T>::push_back(T data)
	{
		cout<<"push_back\n";
		element<T> *temp = head;//нужно ли писать this->head?
		while(temp->pNext != nullptr)
		    temp = temp->pNext;
		temp->pNext = new element<T>(data);
		Size++;
	};

template<typename T>
void List<T>::push_front(T data)
	{
		cout<<"push_front\n";
	    head->pNext = new element<T> (data, head->pNext);
	    Size++;
	};

template<typename T> 
T& List<T>::operator [] (const int index)
	{
		cout<<"operator []\n";
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
		cout<<"pop_back\n";
	    removeAt(Size-1);
	};

template<typename T> // протестировать
void List<T>::pop_front()
	{
		cout<<"pop_front\n";
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
		cout<<"clear\n";
	    while(Size)
	    {
	      pop_front();  
	    };
	};
	
template<typename T> // протестировать
void List<T>::insert(T value,int index)
	{
		cout<<"insert\n";
	    if (index == getSize()) push_back(value); //уточнить насколько целесообразны дополнительные проверки экстремумов(делает ли это код эфективнее?)
	    else if (index == 0) push_front(value); //уточнить насколько целесообразны дополнительные проверки экстремумов(делает ли это код эфективнее?)
	    else if (index > getSize()) throw OoR();
	    else
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

template<typename T>  // протестировать
void List<T>::removeAt(int index)//5
	{
		cout<<"removeAt\n";
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

template<typename T> 
void List<T>::show()
	{   
	    for(element<T> *temp = head;temp->pNext != nullptr;temp = temp->pNext)
	        cout<<temp->pNext->data<<"->";
	    cout<<endl;
	};

void printline()
	{
	    cout<<"---------------------------------------------------------------------------------------\n";
	};

template<typename T> // протестировать
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
		List<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.show();

		cout<<list[1]<<endl;
		cout<<list[0]<<endl;
		cout<<list[5]<<endl;
		cout<<list[112]<<endl;
		cout<<list[-11]<<endl;
		cout<<list[4]<<endl;
		cout<<list[6]<<endl;
		return 0;
	}