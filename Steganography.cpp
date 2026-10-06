/*
------------------------------------------------------------
BMP Image Steganography Tool

Technique:
Least Significant Bit (LSB) Steganography

Description:
This program hides secret text messages inside 24-bit BMP
images by modifying the least significant bit of each colour
byte. The first 32 bits store the message length, followed
by the message itself.

Author: Rishabh Bhaskar
------------------------------------------------------------
*/


#include "Steganography.h"

#include <iostream>

bool Steganography::encode(BMP& image, const std::string& message)
{
    // Store message length first (4 bytes)
    uint32_t messageLength = static_cast<uint32_t>(message.length());

    size_t capacity = image.getCapacity();

    if (messageLength > capacity)
    {
        std::cout << "\n=====================================\n";
        std::cout << "Image Capacity Check\n";
        std::cout << "=====================================\n";

        std::cout << "Image Capacity : "
            << capacity
            << " characters\n";

        std::cout << "Your Message   : "
            << messageLength
            << " characters\n\n";

        std::cout << "Result : Message cannot fit inside this image.\n";

        return false;
    }

    size_t index = 0;

    // ----------------------------
    // Store message length (32 bits)
    // ----------------------------
    for (int i = 0; i < 32; i++)
    {
        uint8_t bit = (messageLength >> i) & 1;

        image.pixels[index] &= 0xFE;
        image.pixels[index] |= bit;

        index++;
    }

    // ----------------------------
    // Store message characters
    // ----------------------------
    for (char c : message)
    {
        for (int i = 0; i < 8; i++)
        {
            uint8_t bit = (c >> i) & 1;

            image.pixels[index] &= 0xFE;
            image.pixels[index] |= bit;

            index++;
        }
    }

    return true;
}

std::string Steganography::decode(const BMP& image)
{
    uint32_t messageLength = 0;

    size_t index = 0;

    // ----------------------------
    // Read message length
    // ----------------------------
    for (int i = 0; i < 32; i++)
    {
        uint8_t bit = image.pixels[index] & 1;

        messageLength |= (bit << i);

        index++;
    }

    if (32 + messageLength * 8 > image.pixels.size())
    {
        std::cout << "No hidden message found.\n";
        return "";
    }

    std::string message;

    // ----------------------------
    // Read message
    // ----------------------------
    for (uint32_t c = 0; c < messageLength; c++)
    {
        char letter = 0;

        for (int i = 0; i < 8; i++)
        {
            uint8_t bit = image.pixels[index] & 1;

            letter |= (bit << i);

            index++;
        }

        message += letter;
    }

    return message;
}