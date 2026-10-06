# BMP Image Steganography Tool

## Description
The BMP Image Steganography Tool is a C++ application that hides and extracts secret text messages inside **24-bit BMP images** using the **Least Significant Bit (LSB)** steganography technique. The project demonstrates binary file handling, bitwise operations, object-oriented programming, and image processing concepts.

---

## 🚀 Features
* **Message Embedding:** Hide secret messages inside 24-bit BMP images.
* **Message Extraction:** Extract hidden messages from encoded images.
* **Windows File Picker:** Native dialogs for seamless image selection.
* **Capacity Validation:** Automatic checks before encoding to ensure the message fits.
* **Image Diagnostics:** Displays image information (width, height, capacity).
* **Encoding Statistics:** Shows detailed embedding metrics after a successful run.

---

## 🛠️ Technologies Used
* **Language:** C++
* **Paradigms:** Object-Oriented Programming (OOP)
* **Core Concepts:** Binary File Handling, Bitwise Operations, LSB Steganography
* **APIs:** Windows API (for file dialogs)

---

## 📦 Installation
1. Open the project solution file (`.sln`) in **Microsoft Visual Studio**.
2. Build the solution (**Build > Build Solution** or `Ctrl + Shift + B`).
3. Run the project (`F5` or `Ctrl + F5`).
4. Ensure you have a **24-bit BMP image** available for testing.

---

## 💻 Usage

### Hiding a Message
1. Run the application.
2. Enter choice `1` (**Hide Secret Message**).
3. Select your source BMP image using the file picker.
4. Type in your secret message.
5. Choose the destination folder and name to save the encoded image.

### Extracting a Message
1. Run the application.
2. Enter choice `2` (**Extract a Message**).
3. Select the encoded BMP image using the file picker.
4. The application will decode and display the hidden message.

---

## 📁 Project Structure
```text
├── Source Code/
│   ├── BMP.cpp
│   ├── BMP.h
│   ├── FileDialog.cpp
│   ├── FileDialog.h
│   ├── Steganography.cpp
│   ├── Steganography.h
│   └── main.cpp
├── Images/
│   ├── input.bmp
│   └── encoded.bmp
├── Screenshots/
└── README.md
```

---

## 🧠 Learning Outcomes
This project helped strengthen my understanding of:
* Binary file processing and parsing custom headers.
* BMP image structure (Headers, Pixel Arrays, and Padding).
* Bitwise operations (`&`, `|`, `<<`, `>>`) for data manipulation.
* Object-Oriented Programming (OOP) design patterns in C++.
* Interfacing with the Windows API.
* Core data security and steganography concepts.

---

## 🔮 Future Improvements
* Add support for compressed formats like **PNG images**.
* Implement **AES password-protected** message encryption before embedding.
* Upgrade from a Console Application to a full **Graphical User Interface (GUI)**.
* Add support for hiding **entire text files** (`.txt`) rather than just raw text input.

---

## 🧑‍💻 Author
* **Rishabh Bhaskar**
* Bachelor of Computer Science (BCS)
* University of Wollongong in Dubai
