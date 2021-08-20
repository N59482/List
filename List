#include <iostream>

using namespace std;

template<typename T>
class OS
{
	public:
	OS();
	~OS();
	T& operator [] (const int index);
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void insert(T value, int index);
	void removeAt(int index);
	void clear();
	//void randOS(int ossize); нет мне лень
	int getSize(){return Size;}
	
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
OS<T>::OS()
{
	Size=0;
	head = nullptr;
};

template<typename T>
OS<T>::~OS()
{
	clear();
};

template<typename T>
void OS<T>::push_back(T data)
{
	if (head==nullptr)// Если список пуст
	{
		head = new element<T>(data);
		Size=1;
	}
	else 
	{
		element<T> *temp = this->head;
		while(temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}; 
		
		temp->pNext = new element<T>(data);
		Size++;
	};
};

template<typename T>
void OS<T>::push_front(T data)
{
    head = new element<T> (data, head);
    Size++;
};

template<typename T>
T& OS<T>::operator [] (const int index)
{
  element<T> *temp = this->head;
  if(index<=Size)
  {
      for(int i=0; temp!=nullptr; i++)
   {
      if (i == index)
      {
          return temp->data;
      }
      else temp = temp->pNext;
   }; 
  } else cout<<"Индекс за границами массва\n";
};

template<typename T>
void OS<T>::pop_back()
{
    removeAt(Size-1);
};

template<typename T>
void OS<T>::pop_front()
{
	    element<T> *temp = head; 
	    head = temp->pNext;
	    delete temp;
	    Size--;
};
	
template<typename T>
void OS<T>::clear()
{
	    while(Size)
	    {
	      pop_front();  
	    };
	};
	
template<typename T>
void OS<T>::insert(T value,int index)
{
    if (index == getSize()) push_back(value); //если индекс на 1 больше списка то вставить в конец; 
    else if (index == 0) push_front(value);
    else if (index > getSize()) cout<<"Индекс выходит далеко за рамки массива\n";
    else   //вариант с правильной логикой; 
    {
        element<T> *temp = head;
        for(int i=0; i<(index-1); i++)//идем предшествующий элемент;
        {
            temp = temp->pNext;
        };
        temp->pNext = new element<T>(value,temp->pNext);
        Size++;
    };
};

template<typename T> 
void OS<T>::removeAt(int index)//5
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

void poloska()
{
    cout<<"---------------------------------------------------------------------------------------\n";
};


template<typename T>
void Status(OS<T> & tos)
{
    cout<<"Теперь в списке "<<tos.getSize() <<(((tos.getSize()%10)<5)?" элемента.":" элементов.")<< endl; //выводим количество элементов

	for(int i=0;i<tos.getSize();i++) // выводим список
	{
	    cout<<tos[i]<<((i==(tos.getSize()-1))?".\n":"->");
	};
};

int main()////////////////////////???????????????????????cv
{
    int vote_index;
    
	OS<int> os; //Создаем список
	
	os.push_back(0); // заполняем;
	os.push_back(11);
	os.push_back(22);
	os.push_back(33);
	
	poloska();

    cout<<"В списке "<<os.getSize() <<(((os.getSize()%10)<5)?" элемента.":" элементов.")<< endl; //выводим количество элементов

	for(int i=0;i<os.getSize();i++) // выводим список
	{
	    cout<<os[i]<<((i==(os.getSize()-1))?".\n":"->");
	};
	
	poloska();
	
	cout<<"Вставим в конец число " << 44 << endl;
	os.push_back(44);
	
	Status(os);
	poloska();
	
	cout<<"Вставим в начало число "<< -11 <<endl;
	os.push_front(-11);
	
	Status(os);
	poloska();
	
	cout<<"Удалим последний элемент"<<endl;
	os.pop_back();
	
	Status(os);
	poloska();
	
	cout<<"Теперь удалим первый элемент"<<endl;
	os.pop_front();
	
	Status(os);
	poloska();
	
	cout<<"Вставим число 20 на 2-е место списка"<<endl;
	os.insert(20,2);
	
	Status(os);
	poloska();
	
	cout<<"Удалим из списка 1-й элемент\n";
	os.removeAt(1);
	
	Status(os);
	poloska();
	
	cout<<"THE END SYKA\n";
	
	return 0;
}
