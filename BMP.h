#ifndef BMP_H
#define BMP_H

#include <string>
#include <vector>
#include <cstdint>

#pragma pack(push,1)

// BMP File Header (14 bytes)
struct BMPFileHeader
{
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
};

// BMP Info Header (40 bytes)
struct BMPInfoHeader
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};

#pragma pack(pop)

class BMP
{
public:

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    std::vector<uint8_t> pixels;

    bool read(const std::string& filename);
    bool write(const std::string& filename);

    size_t getCapacity() const
    {
        if (pixels.size() < 32)
            return 0;

        return (pixels.size() - 32) / 8;
    }
};

#endif