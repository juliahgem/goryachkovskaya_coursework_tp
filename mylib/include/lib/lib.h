#include <string>

/**
 * @brief ����� Rle ������������� ������ ��� ������ � ������������ ������� ����������� ���� ����� (RLE).
 */
class Rle {
public:
    /**
     * @brief ������� ������� ������ � �������������� ������ ����������� ���� ����� (RLE).
     * @param input ������� ������ ��� ������.
     * @return ������ ������, ���������� ������� RLE.
     */
    static std::string compress(const std::string& input);

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
     * @param compressed ������ ������ ��� ������������.
     * @return ������������������� ������.
     */
    static std::string decompress(const std::string& compressed);
};
