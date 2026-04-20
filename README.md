# 📚 Library Management System in C
### Mini Project | B.Tech CSE Core – Semester 2 | MIT World Peace University, Pune

---

## 🎯 Project Overview

A fully functional **console-based Library Management System** built in **C Programming Language** as a Semester 2 mini project at MIT-WPU, Pune. The system digitises core library operations through a menu-driven interface using fundamental C concepts.

---

## ✨ Features

| # | Operation | Description |
|---|-----------|-------------|
| 1 | ➕ Add Book | Add a new book with ISBN, title, author & price |
| 2 | 📋 Display All | View all books with availability status |
| 3 | 🔍 Search Book | Find any book instantly by ISBN |
| 4 | 📤 Issue Book | Mark a book as issued to a student |
| 5 | 📥 Return Book | Mark an issued book as returned |
| 6 | 🗑️ Delete Book | Remove a book record from the system |

---

## 🛠️ Tech Stack

- **Language:** C (C99 standard)
- **Compiler:** GCC / Code::Blocks / Turbo C
- **Concepts Used:** Structures, Arrays, Functions, Loops, String Handling, Switch-Case

---

## 📁 Repository Structure

```
📦 Library-Management-System-C/
 ┣ 📄 library_management.c          ← Main source code
 ┣ 📊 Library_Management_System.pptx ← Project presentation (8 slides)
 ┣ 📝 Library_Management_System_Report.docx ← Full project report (10 sections)
 ┗ 📖 README.md
```

---

## 🚀 How to Run

**Step 1 — Clone the repository:**
```bash
git clone https://github.com/YOUR_USERNAME/Library-Management-System-C.git
cd Library-Management-System-C
```

**Step 2 — Compile using GCC:**
```bash
gcc library_management.c -o library_management
```

**Step 3 — Run the program:**
```bash
./library_management
```

> On Windows: `library_management.exe`

---

## 💻 Sample Output

```
==========================================
   MIT World Peace University, Pune
   B.Tech CSE | Semester 2 Mini Project
   LIBRARY MANAGEMENT SYSTEM IN C
==========================================
  [1] Add New Book
  [2] Display All Books
  [3] Search Book
  [4] Issue Book
  [5] Return Book
  [6] Delete Book
  [7] Exit
==========================================
  Enter your choice: 1

--- Add New Book ---
  Enter ISBN Number  : 1001
  Enter Book Title   : Let Us C
  Enter Author Name  : Yashavant Kanetkar
  Enter Price (INR)  : 299
  [OK] Book added successfully! Total books: 1
```

---

## 🧠 C Concepts Demonstrated

- `struct` — custom data type to model a Book record
- Arrays — `library[100]` array of Book structures
- Functions — modular code (addBook, searchBook, etc.)
- Loops — `for` loop for search and display, `do-while` for menu
- String functions — `fgets()`, `strcspn()` for string input
- Switch-case — menu-driven control flow
- Input validation — duplicate ISBN check, issued book protection

---

## ✅ Validations Built-in

- 🚫 Duplicate ISBN check on add
- 🚫 Cannot issue an already-issued book
- 🚫 Cannot return a book that wasn't issued
- 🚫 Cannot delete a currently issued book
- 🚫 Array bounds check (max 100 books)

---

## 👨‍💻 About

**Student:** Suyash Mane  
**PRN:** 1262251987  
**Program:** B.Tech Computer Science Engineering (CSE Core)  
**Semester:** 2nd Semester  
**University:** MIT World Peace University (MIT-WPU), Pune  
**Academic Year:** 2024–25

---

## 📚 References

- Yashavant Kanetkar — *Let Us C* (17th Edition)
- Brian W. Kernighan & Dennis M. Ritchie — *The C Programming Language*
- MIT-WPU Semester 2 Course Notes
- Udemy: *Most Comprehensive Course in C Programming* by Yashavant Kanetkar

---

⭐ *If this project helped you, consider giving it a star!*
