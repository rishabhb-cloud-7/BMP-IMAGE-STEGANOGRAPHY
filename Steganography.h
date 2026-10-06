#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include "BMP.h"
#include <string>

class Steganography
{
public:
    // Encodes a text message into a BMP image.
    // Hide a secret message inside a BMP image
    static bool encode(BMP& image, const std::string& message);

    // Extract a secret message from a BMP image
    static std::string decode(const BMP& image);
};

#endif