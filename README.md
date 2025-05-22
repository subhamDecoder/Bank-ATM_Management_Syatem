# 💰 Bank & ATM Management System (C++)

A simple console-based Bank and ATM Management System built in C++. This project allows users to manage bank accounts, perform transactions, and simulate ATM functionalities using a text-based UI.
---

## 📁 Project Structure

Bank_System/
├── Bank_System.cpp # Main source file
├── Registration_Login.cpp # Handles user registration and login
├── payment_history.txt # Stores transaction/payment logs
├── bank.txt # Stores user data

yaml
---

## 🎯 Features

### 🔒 Bank Management System
- Create New User
- Existing User Login
- Deposit & Withdraw Options
- Money Transfer Between Users
- Make Payments
- Search, Edit, and Delete Users
- View All Users
- Make Bulk Payments

### 🏧 ATM Management System
- User Login & Balance Check
- Withdraw Amount

---

## 📸 Screenshots

| Control Panel | Bank Panel | ATM Panel |
|---------------|------------|-----------|
| ![Control Panel]("https://github.com/subhamDecoder/Bank-ATM_Management_Syatem/blob/c0047245e2a062c1fbe39d98074fd53ea9dfbb8a/Control_panel.png") | ![Bank Panel](/mnt/data/4b25ae9a-8a61-49e4-80c3-ac8aa437389c.png) | ![ATM Panel](/mnt/data/996f0a04-b429-42be-9bed-d24e4b7152f1.png) |

---

## 🛠️ How to Compile and Run

### 🔧 Requirements
- C++ Compiler (e.g., `g++`)
- Windows System (due to `windows.h` and `conio.h` usage)
- Visual Studio Code or any C++-supported IDE

### ▶️ Compile

```bash
g++ Bank_System.cpp Registration_Login.cpp -o BankSystem.exe
▶️ Run
bash
./BankSystem.exe
📝 Notes
User data and transaction logs are stored in text files (bank.txt and payment_history.txt).

This project uses basic file handling and object-oriented programming in C++.

Meant for educational purposes and beginner-level understanding of console applications.

🤝 Contributing
Contributions, issues, and feature requests are welcome. Feel free to fork the repository and make improvements!

📜 License
This project is open source and available under the MIT License.
