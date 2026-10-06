#include <iostream>
#include <string>

#include "BMP.h"
#include "Steganography.h"
#include "FileDialog.h"

int main()
{
    BMP image;
    int choice;

    std::cout << "=========================================\n";
    std::cout << "      BMP IMAGE STEGANOGRAPHY TOOL\n";
    std::cout << "=========================================\n";
    std::cout << "1. Hide Secret Message\n";
    std::cout << "2. Extract Secret Message\n";
    std::cout << "3. Exit\n";
    std::cout << "Choice: ";

    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1)
    {
        // -------------------------------
        // Select input image
        // -------------------------------
        std::string inputFile = FileDialog::openBMP();

        if (inputFile.empty())
        {
            std::cout << "\nNo image selected.\n";
            return 0;
        }

        if (!image.read(inputFile))
        {
            std::cout << "\nUnable to open image.\n";
            return 1;
        }

        // -------------------------------
        // Display image information
        // -------------------------------
        std::cout << "\n========== IMAGE INFORMATION ==========\n";
        std::cout << "Width      : " << image.infoHeader.width << "\n";
        std::cout << "Height     : " << image.infoHeader.height << "\n";
        std::cout << "Format     : 24-bit BMP\n";
        std::cout << "Capacity   : " << image.getCapacity() << " characters\n";
        std::cout << "=======================================\n";

        // -------------------------------
        // Enter secret message
        // -------------------------------
        std::string message;

        std::cout << "\nEnter secret message:\n";
        std::getline(std::cin, message);

        if (!Steganography::encode(image, message))
            return 1;

        // -------------------------------
        // Choose where to save
        // -------------------------------
        std::string outputFile = FileDialog::saveBMP();

        if (outputFile.empty())
        {
            std::cout << "\nSave cancelled.\n";
            return 0;
        }

        if (!image.write(outputFile))
        {
            std::cout << "\nFailed to save image.\n";
            return 1;
        }

        // -------------------------------
        // Statistics
        // -------------------------------
        std::cout << "\n========== ENCODING SUCCESSFUL ==========\n";
        std::cout << "Characters Hidden : " << message.length() << "\n";
        std::cout << "Bits Embedded     : " << message.length() * 8 << "\n";
        std::cout << "Pixels Modified   : " << 32 + message.length() * 8 << "\n";
        std::cout << "Saved As          : " << outputFile << "\n";
    }

    else if (choice == 2)
    {
        // -------------------------------
        // Select encoded image
        // -------------------------------
        std::string inputFile = FileDialog::openBMP();

        if (inputFile.empty())
        {
            std::cout << "\nNo image selected.\n";
            return 0;
        }

        if (!image.read(inputFile))
        {
            std::cout << "\nUnable to open image.\n";
            return 1;
        }

        std::string message = Steganography::decode(image);

        std::cout << "\n========== HIDDEN MESSAGE ==========\n";

        if (message.empty())
            std::cout << "No hidden message found.\n";
        else
            std::cout << message << "\n";
    }

    else if (choice == 3)
    {
        std::cout << "\nGoodbye!\n";
    }

    else
    {
        std::cout << "\nInvalid option.\n";
    }

    return 0;
}