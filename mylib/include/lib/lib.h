#include <string>

/**
 * @brief Класс Rle предоставляет методы для сжатия и декомпрессии методом кодирования длин серий (RLE).
 */
class Rle {
public:
    /**
     * @brief Сжимает входную строку с использованием метода кодирования длин серий (RLE).
     * @param input Входная строка для сжатия.
     * @return Сжатая строка, полученная методом RLE.
     */
    static std::string compress(const std::string& input);

    /**
     * @brief Декомпрессирует строку, сжатую методом RLE.
     * @param compressed Сжатая строка для декомпрессии.
     * @return Декомпрессированная строка.
     */
    static std::string decompress(std::string& compressed);
};

/**
 * @brief Класс Lzw предоставляет методы для сжатия и декомпрессии методом Lempel-Ziv-Welch (LZW).
 */
class Lzw {
public:
    /**
     * @brief Сжимает входную строку с использованием алгоритма сжатия Lempel-Ziv-Welch (LZW).
     * @param input Входная строка для сжатия.
     * @return Сжатая строка, полученная методом LZW.
     */
    static std::string compress(const std::string& input);

    /**
     * @brief Декомпрессирует строку, сжатую методом LZW.
     * @param compressed Сжатая строка для декомпрессии.
     * @return Декомпрессированная строка.
     */
    static std::string decompress(const std::string& compressed);
};
