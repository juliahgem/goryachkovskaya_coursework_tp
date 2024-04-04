#include <lib/lib.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stdexcept>
#include <sstream>

std::string Rle::compress(const std::string& input) {
    unsigned int i = input.size();
    std::string letters;

    for (int j = 0; j < i; ++j) {
        int count = 1;
        while (input[j] == input[j + 1]) {
            count++;
            j++;
        }
        letters += std::to_string(count);
        letters.push_back(input[j]);
        letters += " ";

    }
    return letters;
}


std::string Rle::decompress(std::string& compressed)
{
    std::string count = "";
    std::string decompressed_data = "";
    std::string token;
    std::istringstream data(compressed);

    while (std::getline(data, token, ' ')) {
        if (isdigit(token[0])) {
            count += token[0];
        }
        int repeat = std::stoi(count);
        for (int j = 0; j < repeat; j++) {
            decompressed_data += token[1];
        }
        count = "";
    }
    return decompressed_data;
}


std::string Lzw::compress(const std::string& input) {
    int maximum_table_size = 256;
    std::unordered_map<std::string, int> dictionary;
    std::string compressed_data = "";
    std::string string;

    for (int i = 0; i < 256; i++) {
        dictionary[std::string(1, char(i))] = i;
    }

    for (char symbol : input) {
        std::string string_plus_symbol = string + symbol;
        if (dictionary.find(string_plus_symbol) != dictionary.end()) {
            string = string_plus_symbol;
        }
        else {
            compressed_data += std::to_string(dictionary[string]) + " ";
            dictionary[string_plus_symbol] = maximum_table_size;
            maximum_table_size++;
            string = symbol;
        }
    }

    if (!string.empty()) {
        compressed_data += std::to_string(dictionary[string]);
    }

    return compressed_data;
}

std::string Lzw::decompress(const std::string& input) {
    int maximum_table_size = 256;
    std::unordered_map<int, std::string> dictionary;
    std::string decompressed_data = "";

    for (int i = 0; i < 256; i++) {
        dictionary[i] = std::string(1, char(i));
    }

    std::istringstream iss(input);
    std::string token;
    int next_code = 256;
    std::string string;

    while (std::getline(iss, token, ' ')) {
        int code = std::stoi(token);
        std::string entry;
        if (dictionary.find(code) != dictionary.end()) {
            entry = dictionary[code];
        }
        else if (code == next_code) {
            entry = string + string[0];
        }
        else {
            throw std::runtime_error("Invalid compressed data");
        }
        decompressed_data += entry;
        if (!string.empty()) {
            dictionary[next_code] = string + entry[0];
            next_code++;
        }
        string = entry;
    }

    return decompressed_data;
}
