#include "BMP.h"

#include <fstream>
#include <iostream>
#include <vector>

bool BMP::read(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cout << "Cannot open image.\n";
        return false;
    }

    // Read headers
    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    // Check if it's really a BMP
    if (fileHeader.fileType != 0x4D42)
    {
        std::cout << "Not a BMP image.\n";
        return false;
    }

    // Only support 24-bit BMP
    if (infoHeader.bitCount != 24)
    {
        std::cout << "Only 24-bit BMP files are supported.\n";
        return false;
    }

    int width = infoHeader.width;
    int height = abs(infoHeader.height);

    int rowSize = width * 3;
    int padding = (4 - (rowSize % 4)) % 4;

    pixels.clear();

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            char byte;
            file.read(&byte, 1);
            pixels.push_back(static_cast<uint8_t>(byte));
        }

        file.ignore(padding);
    }

    file.close();
    return true;
}

bool BMP::write(const std::string& filename)
{
    std::ofstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cout << "Cannot create output image.\n";
        return false;
    }

    int width = infoHeader.width;
    int height = abs(infoHeader.height);

    int rowSize = width * 3;
    int padding = (4 - (rowSize % 4)) % 4;

    infoHeader.imageSize = (rowSize + padding) * height;
    fileHeader.fileSize =
        sizeof(BMPFileHeader) +
        sizeof(BMPInfoHeader) +
        infoHeader.imageSize;

    file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    size_t index = 0;

    char zero = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < rowSize; x++)
        {
            file.write(reinterpret_cast<char*>(&pixels[index]), 1);
            index++;
        }

        for (int i = 0; i < padding; i++)
            file.write(&zero, 1);
    }

    file.close();
    return true;
}