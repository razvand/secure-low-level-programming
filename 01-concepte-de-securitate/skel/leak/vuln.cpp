#include <iostream>
#include <cstdlib>

class TestClass {
	unsigned int a;
	unsigned char *p;

public:
	unsigned int do_increment(unsigned int i)
	{
		return a+i;
	}
	unsigned int do_dereference(unsigned int i)
	{
		return *(p+i);
	}
};

static void do_trigger1()
{
	TestClass t;

	unsigned int v = t.do_increment(10);

	std::cout << "v is: " << v << std::endl;
}

static void do_trigger2()
{
	TestClass t;

	unsigned int v = t.do_dereference(10);

	std::cout << "v is: " << v << std::endl;
}

static void do_trigger3()
{
	size_t i;
	unsigned int buffer[32];

	std::cout << "buffer is: ";
	for (i = 0; i < 32; i++)
		std::cout << "0x" << std::hex << buffer[i] << " ";
	std::cout << std::endl;
}

int main()
{
	do_trigger1();
	//do_trigger2(); // this causes segmentation fault
	do_trigger3();

	return 0;
}
