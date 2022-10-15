
/*
15.10.22
R. Pleyiuk

*/
#include <iostream>

using namespace std;
template <class T>
struct Element
{
	T data; 
	Element* next; 
};

template <class T>
class List
{
private:
	Element<T>* begin; 
	Element<T>* end; 
	int count; 

	Element<T>* Move(int index)
	{
		if (count > 0) // 
		{

			Element<T>* t = begin;
			for (int i = 0; i < index; i++)
				t = t->next;
			return t;
		}
		return nullptr;
	}

public:
	List()
	{
		
		begin = end = nullptr;
		count = 0;
	}
	
	
	~List()
	{
		
		//Clear();
	}

	


	void Add(T _data)
	{
		try {
			
			Element<T>* elem = new Element<T>;
			elem->data = _data;
			elem->next = nullptr; 
			
			if (begin == nullptr)
			{
				
				begin = end = elem;
			}
			else
			{
				
				end->next = elem;
				end = elem;
			}

			
			count++;
		}
		catch (bad_alloc e)
		{
			
			cout << e.what() << endl;
		}
	}

	T& operator[](int index)
	{
		
		if ((index < 0) || (index > count - 1))
		{
			
			throw out_of_range("Incorrect index.");
		}

		
		Element<T>* t = Move(index);

		return t->data;
	}
	
	
	void Print(string msg)
	{
		cout << msg << endl;

		if (count == 0) 
		{
			cout << "List is empty." << endl;
			return;
		}

		
		Element<T>* t = begin;

		while (t != nullptr)
		{
			cout << t->data << " ";
			t = t->next;
		}
		cout << endl;
	}

	void Merge(const List& obj)
	{
		

		 
		Element<T>* t = obj.begin;

		for (int i = 0; i < obj.count; i++)
		{
			//
			Add(t->data);
			t = t->next;
		}

		count = obj.count;
	
	}
	 
	List<T>& operator + ( const List& obj)
	{
		
		Merge(obj);
		return *this;
	}



};

int main()
{
	List<double> L, P; 
	L.Print("L: ");
	P.Print("P: ");

	

	
	L.Add(2.5);
	L.Add(3.8);
	L.Add(4.1);
	L.Add(3.3);
	L.Print("L: ");

	P.Add(2);
	P.Add(10);
	P.Add(6);
	P.Add(4);
	P.Print("P: ");

	

	
	L[0] = 22.1;
	L.Print("L[0] = 22.1: ");

	
	cout << "L[1] = " << L[1] << endl;
	double z = L[2];
	cout << "z = " << z << endl;

	List<double> LP = P + L;
	LP.Print("LP: ");

	
}
