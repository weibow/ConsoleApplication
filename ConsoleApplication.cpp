// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "iostream"
#include "cstring"

using namespace std;

class CBox
{
private:
	double m_Length;
	double m_Width;
	double m_Height;
	double mm;

public:

	explicit CBox(double lv = 4.0, double wv = 1.0, double hv = 1.0) : m_Length{ lv }, m_Width{ wv }, m_Height{ hv }
	{}

	double see_you_again() const
	{
		return 12;
	}

	double volume() const
	{
		return m_Length * m_Width * m_Height;
	}
	bool operator< (const CBox& aBox) const; //Overloaded 'less than'

	//Overloaded equality operator
	bool operator == (const CBox& aBox) const
	{
		return this->volume() == aBox.volume();
	}
	
	bool operator> (const double value) const
	{
		return this->volume() > value;
	}

	virtual double show_volume() const final
	{
		return m_Length * m_Width * m_Height;
	}

	~CBox()
	{
		cout << "Destructor called." << endl;
	}

};

bool CBox::operator<(const CBox& aBox) const
{
	return this->volume() < aBox.volume();
}


class CCandyBox : public CBox
{
public:
	char * m_Contents;

	explicit CCandyBox(const char *str = "Candy")	//Constructor
	{
		size_t length{ strlen(str) + 1 };
		m_Contents = new char[length];
		strcpy_s(m_Contents, length, str);
	}

	CCandyBox(const CCandyBox& box) = delete;
	CCandyBox & operator = (const CCandyBox& box) = delete;

	~CCandyBox()
	{ delete[] m_Contents; }
};



class CMessage
{
private:
	char* m_pMessage;
public:
	//Function to display a message
	void showTt() const
	{
		cout << m_pMessage << endl;
	}
	//Function to reset a message to *
	void reset()
	{
		char* temp{ m_pMessage };
		while (*temp)
			*(temp++) = '*';
	}
	//Overload assignment operator for CMessage objects
	CMessage & operator= (const CMessage & aMess)
	{
		if (this != &aMess)
		{
			delete[] m_pMessage;
			size_t length{ strlen(aMess.m_pMessage) + 1 };
			m_pMessage = new char[length];

			strcpy_s(this->m_pMessage, length, aMess.m_pMessage);
		}
		return *this;
	}

	//Constructor definition
	CMessage(const char* text = "Default message")
	{
		size_t length {strlen(text) + 1};		
		m_pMessage = new char[length + 1];			//Allocate space for text
		strcpy_s(m_pMessage, length + 1, text);		//copy text to new memory
	}

	//Destructor to free memory allocated by new
	

	~CMessage();
	//{
	//	cout << "Destructor called." << endl;
	//	delete[] m_pMessage;
	//}
	
	//Overload assignement operator for CMessage objects
	
};

CMessage ::~CMessage()
{
	cout << "Destructor called3." << endl;
	delete[] m_pMessage;

}

//Pass-by-Pointer
int incr10(int* num)
{
	cout << endl << "Address received =" << num;

	*num += 2;
	return *num;
}



class CContainer
{
public:
	virtual double volume() const = 0;

	//Function to display a volume
	virtual void showVolume() const
	{
		std::cout << "Volume is" << volume() << std::endl;
	}
};

/* 
 * Main functions
 */
int main()
{
	 CBox me;

	 CBox myBox{ 4.0, 3.0, 2.0 };
	 CCandyBox myCandyBox;
	 CCandyBox myMintBox{ "Wafer Thin Mints" };

	 int x{ 5 };
	 int&& rExpress{ 2 * x + 3 };
	 cout << rExpress << endl;
	 int& rx{ x };
	 cout << rx << endl;

	 std::cout << "myBox occupies " << sizeof myBox
		 << "bytes" << endl
		 << "myCandyBox occupies " << sizeof myCandyBox
		 << "bytes" << endl
		 << "myMintBox occupies " << sizeof myMintBox
		 << "bytes" << endl;
	 std::cout << "myMinitBox volume is " << myMintBox.volume()
		 << endl;

	 const CBox smallBox{ 4.0, 2.0, 1.0};
	 const CBox mediumBox{ 10.0, 4.0, 2.0};
	 CBox bigBox{ 30.0, 20.0, 40.0 }; 
	 CBox thatBox{ 4.0, 2.0, 10.0 };

	 CMessage motto1{ "iF EOE A miss is as good as a mile." };
	 CMessage motto2;

	 int num{ 3 };
	 int* pnum{ &num };

	 int result{ incr10(pnum) };
	 cout << endl << "Address passed = " << result;

	 cout << endl << "num = " << num << endl;

	 //Dynamic object
	 CMessage *pM { new CMessage {"A cat can look at a queen."} };

	 motto1.showTt();
	 pM->showTt();	
	 delete pM;


	 if (mediumBox < smallBox)
		 cout << "mediumBox is smaller than smallBox" << endl;
	 if (mediumBox < bigBox)
		 cout << "mediumBox is smaller than bigBox" << endl;
	 else
		 cout << "mediumBox is not smaller than bigBox" << endl;
	 if (thatBox == mediumBox)
		 cout << "thatBox is equal to mediumBox" << endl;
	 else
		 cout << "thatBox is not equal to mediumBox" << endl;

	cout << "Hello" << std::endl;
	//cout << "Length = " << me.m_Length << "  Height = " << me.m_Height << "  Width = " << me.m_Width << endl;
    return 0;
}

