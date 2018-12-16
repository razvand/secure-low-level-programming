#include <iostream>

static unsigned long password = 0xDEADBEEFCAFEBABE;

static void leak_data(void)
{
	unsigned long *p = &password;
	unsigned long buffer[32];
	long n;

	std::cout << "address of p: " << std::hex << &p << std::endl;
	std::cout << "address of buffer: " << buffer << std::endl;
	std::cout << std::dec;

	std::cout << "Provide index (789 to stop)" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> n;
		if (std::cin.eof())
			break;
		if (n == 789)
			break;
		std::cout << "buffer[" << n << "] = 0x" << std::hex << buffer[n] << std::endl;
		std::cout << std::dec;
	}
}

int main()
{
	leak_data();

	return 0;
}
