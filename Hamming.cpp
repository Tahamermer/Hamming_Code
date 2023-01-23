#include <iostream>
#include <string>
#include <vector>
#include <map>

std::ostream& operator<<(std::ostream& stream, std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		stream << vector[i];
	}

	return stream;
}

int xor_func(std::vector<int> pos_array) {
	int result = 0;
	for (int k = 0; k < pos_array.size(); k++)
	{
		result ^= pos_array[k];
	}
	return result;
}

int not_op(int a){
    std::map<int, int> negation;
    negation[1] = 0;
    negation[0] = 1;

    return negation.at(a);
}

int main()
{
	// taking input as string and converting it to integer array
	std::string input;
	std::cout << "Enter Data: ";
	std::cin >> input;

	std::map<char, int> bitmap;
	bitmap['1'] = 1;
	bitmap['0'] = 0;

	std::vector<int> bits;
	int res;
	res = input.length();
	bits.reserve(res);

	for (char b : input)
	{
		int tb;
		tb = bitmap.at(b);
		bits.emplace_back(tb);
	}

	std::cout << "[INFO] Entered messege: " << bits << std::endl;
	

	// extracting the positions with bit 1
	std::vector<int> pos;
	pos.reserve(res);
	for (int j = 0; j <= res; j++)
	{
		if (bits[j] == 1)
		{
			pos.emplace_back(j);
		}
	}
	
	// std::cout << pos << std::endl;

	// xor all of the position with bit 
	int result = xor_func(pos);
	if (result == 0)
	{
		std::cout << "[INFO] No errors detected..\n";
	}
	else if (result != 0)
	{
		int error_position = result;
		std::cout << "[INFO] Error Detected at " << result << " position from left\n";
		std::cout << "[INFO] Fixing the error..\n";

        bits[result] = not_op(bits[result]);
		std::cout << "[SUCCESS] Error Fixed..\n";
		std::cout << "[SUCCESS] Final corrected message: " << bits << std::endl;
	}
}
