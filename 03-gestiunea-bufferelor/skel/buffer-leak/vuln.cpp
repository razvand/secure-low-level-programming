#include <iostream>

static void leak_data(void)
{
	char password[] = "BABYLON5";
	unsigned int buffer[32];
	int n;

	std::cout << "Provide index (negative or EOF to stop)" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> n;
		if (std::cin.eof())
			break;
		if (n < 0)
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
