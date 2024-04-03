#include <string>

/**
 * @brief ����� Rle ������������� ������ ��� ������ � ������������ ������� ����������� ���� ����� (RLE).
 */
class Rle {
public:
    /**
     * @brief ������� ������� ������ � �������������� ������ ����������� ���� ����� (RLE).
     * @param input_str ������� ������ ��� ������.
     * @return ������ ������, ���������� ������� RLE.
     */
    static std::string compress(const std::string& input_str);

    /**
     * @brief ��������������� ������, ������ ������� RLE.
     * @param compressed ������ ������ ��� ������������.
     * @return ������������������� ������.
     */
    static std::string decompress(std::string& compressed);
};

/**
 * @brief ����� Lzw ������������� ������ ��� ������ � ������������ ������� Lempel-Ziv-Welch (LZW).
 */
class Lzw {
public:
    /**
     * @brief ������� ������� ������ � �������������� ��������� ������ Lempel-Ziv-Welch (LZW).
     * @param input ������� ������ ��� ������.
     * @return ������ ������, ���������� ������� LZW.
     */
    static std::string compress(const std::string& input);

    /**
     * @brief ��������������� ������, ������ ������� LZW.
     * @param input ������ ������ ��� ������������.
     * @return ������������������� ������.
     */
    static std::string decompress(const std::string& input);
};
