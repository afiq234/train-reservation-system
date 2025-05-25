# 🚆 Train Reservation System (C Language)

A console-based train reservation system developed in C that allows users to:
- View available trains
- Book and cancel tickets
- Search reservations
- Manage train and passenger records (admin access)

> **Note:** This is a file-based system using binary I/O and basic terminal UI with `conio.h`, `stdio.h`, and `windows.h`.

---

## 📌 Features

- 🧾 View all available trains and details
- 🧍 User-friendly interface to book and cancel tickets
- 🔍 Search passenger reservation by name
- 👨‍💼 Admin panel to:
  - View passenger records
  - Add new trains
  - Delete existing trains
- 🧠 Basic insertion sort for seat ordering
- 🗂 Data stored in `.txt` files using `fread()` and `fwrite()`

---

## 💡 How It Works

### 👥 Users
- Use options [1] to [5] in the main menu.
- Can view trains, book or cancel tickets, and search reservations.

### 🔐 Admin
- Access via option [4] → password prompt (`user/pass`)
- Can view passengers, add new trains, or delete existing ones.

---

## 🗃 File Storage

| File Name             | Purpose                             |
|----------------------|-------------------------------------|
| `train_details.txt`  | Stores train data (`struct adddata`)|
| `train_report.txt`   | Stores number of trains (`int k`)   |
| `booklist.txt`       | Stores booked tickets (`struct bookticket`)|
| `booklistreport.txt` | Stores total ticket bookings (`int u`)|

All files use binary file operations for efficiency.

---

## 🧾 Requirements

- Windows (uses `<windows.h>`, `<conio.h>`)
- C Compiler (like GCC or Code::Blocks)
- Terminal or Command Prompt

---

## 🚀 How to Run

1. Save the file as `trainReservation2.c`
2. Compile:
```bash
gcc trainReservation2.c -o trainReservation.exe
```

## 🛠️ Functions Breakdown

| File Name             | Purpose                             |
|----------------------|-------------------------------------|
| `viewinfo()`  | Displays train list|
| `bookticket()`   | Book a train ticket   |
| `cancelticket()`       | Cancel a ticket|
| `admin()` | Admin portal menu|
| `addtrain()`  | Admin: Add new trains|
| `dlttrain()`   | Admin: Delete trains   |
| `viewpassenger()`       | Admin: View all passengers|
| `searchPassenger()` | Search booking by name|
| `aread()/awrite()` | File I/O for train records|
| `viewpassengers_read()`  | File I/O for passenger records|

## 🧑‍💻 Author
Fiq
