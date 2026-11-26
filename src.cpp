#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Using: " << argv[0] << " <your_file> <result_file>\n";
        return 1;
    }

    std::ifstream inFile(argv[1], std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: cannot open the file " << argv[1] << "\n";
        return 1;
    }

    std::vector<uint8_t> bytes(
        (std::istreambuf_iterator<char>(inFile)),
        std::istreambuf_iterator<char>()
    );
    inFile.close();

    std::sort(bytes.begin(), bytes.end());

     std::ofstream outFile(argv[2], std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: cannot open the file " << argv[2] << "\n";
        return 1;
    }

    if (!bytes.empty()) {
        outFile.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
    }
    outFile.close();

    std::cout << "Ready! That is the result: " << bytes.size() << "\n";

    return 0;
}
