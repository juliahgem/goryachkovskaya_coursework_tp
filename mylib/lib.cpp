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

    }
    return letters;
}

bool alpha_or_space(const char c)
{
    return isalpha(c) || c == ' ';
}

std::string Rle::decompress(std::string& compressed)
{
    size_t i = 0;
    size_t repeat;
    std::string original;
    while (i < compressed.length())
    {
        while (alpha_or_space(compressed[i]))
            original.push_back(compressed[i++]);

        repeat = 0;
        while (isdigit(compressed[i]))
            repeat = 10 * repeat + (compressed[i++] - '0');

        auto char_to_unroll = compressed[i++];
        while (repeat--)
            original.push_back(char_to_unroll);
    }
    return original;
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
