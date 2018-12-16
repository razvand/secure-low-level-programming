#include <iostream>

class TestClass {
	unsigned int password;

public:
	TestClass(unsigned int p)
	{
		password = p;
	}

	void show_password(void)
	{
		std::cout << "0x" << std::hex << password << std::dec << std::endl;
	}
};

static void use_after_free(void)
{
	TestClass *t = new TestClass(0xabcdef01);

	t->show_password();
	delete t;
	TestClass *u = new TestClass(0x99887766);
	t->show_password();
	delete u;
}

int main()
{
	use_after_free();

	return 0;
}
