#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <lib/lib.h>

// функция получения имени файла
std::string path_input() {
    std::string filename;
    std::cout << "Enter file name with extension: ";
    std::cin >> filename;
    return filename;
}

// функция считывания содержимого файла
// в качестве типа данных используется картеж из int и string
// будем передавать код состояния 0 - успех, 1 - произошла ошибка и строку
std::tuple<int, std::string> read_file(const std::string& path) {
    std::string line;
    std::ifstream fin(path);
    if (fin.is_open()) {
        while (std::getline(fin, line))
        fin.close();
    }
    else {
        std::tuple<int, std::string> ret = { 1, "None" };
        return ret;
    }
    std::tuple<int, std::string> ret = { 0, line };
    return ret;
}

// функция записи результата программы в файл
void writer(std::string compressed_data) {
    std::cout << "Write the result into file? (y/n): ";
    std::string x = "n";
    std::cin >> x;
    if (x == "y") {
        std::cout << "Enter the file path:";
        std::string relative_file_path = "";
        std::cin >> relative_file_path;
        std::ofstream result_file (relative_file_path);
        if (result_file.is_open()){
            result_file << compressed_data;
            result_file.flush();
            result_file.close();
        }
        else {
            std::cout << "Error!" << std::endl;
        }
        std::cout << "File has been written" << std::endl;
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file_path>\n";
        return 1;
    }

    std::string file_path = argv[1];
    int choice;
    std::cout << "Choose action:\n";
    std::cout << "(enter the number):\n";
    std::cout << "1: Rle compression\n";
    std::cout << "2: Rle decompression\n";
    std::cout << "3: Lzw compression\n";
    std::cout << "4: Lzw decompression\n";
    std::cin >> choice;

    std::string content;
    int error;
    std::tie(error, content) = read_file(file_path);
    if (error != 0) {
        std::cout << "Can't open file / Invalid file name!\n";
        return 1;
    }

    switch (choice) {
    case 1: {
        std::string after_compress = Rle::compress(content);
        std::cout << "Before compression: " << content << "\n"
            << "After compression: " << after_compress << "\n";
        writer(after_compress);
        break;
    }
    case 2: {
        std::string after_decompress = Rle::decompress(content);
        std::cout << "Before decompression: " << content << "\n"
            << "After decompression: " << after_decompress << "\n";
        break;
    }
    case 3: {
        std::string after_compress = Lzw::compress(content);
        std::cout << "Before compression: " << content << "\n"
            << "After compression: " << after_compress << "\n";
        writer(after_compress);
        break;
    }
    case 4: {
         std::string after_decompress = Lzw::decompress(content);
        std::cout << "Before decompression: " << content << "\n"
            << "After decompression: " << after_decompress << "\n";
        break;
    }
    default: {
        std::cout << "Invalid option!\n";
        return 1;
    }
    }

    return 0;
}
                                                                                                                                               