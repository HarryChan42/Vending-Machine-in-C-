# Vending Machine Simulator (C++)

A clean, console-based **vending machine simulator** written in modern C++ that demonstrates object-oriented design, basic state management, and a simple text-based user interface.

Perfect for beginners learning classes, structs, vectors, input parsing, and encapsulation in C++.

## Features

- **Customer Mode**
  - View current inventory with item codes, names, prices, and stock quantities
  - Insert any amount of money (credit is preserved)
  - Purchase items by code (e.g., `select A1`)
  - Remaining credit stays in the machine for multiple purchases (no automatic change)
  - Return all remaining credit with the `return` command

- **Owner Mode** (password-protected: `admin123`)
  - Fully restock all slots to 10 units each (`restock`)
  - Collect total earnings from sales (`collect`)

- **Realistic Behavior**
  - Out-of-stock detection
  - Insufficient funds handling
  - Formatted, easy-to-read display using `<iomanip>`
  - Total sales tracking

## Default Inventory

| Code | Item         | Price  | Initial Stock |
|------|--------------|--------|---------------|
| A1   | Coca Cola    | $1.50  | 5             |
| A2   | Pepsi        | $1.50  | 3             |
| A3   | Water        | $1.00  | 10            |
| B1   | Snickers     | $1.25  | 4             |
| B2   | Chips        | $1.75  | 6             |
| B3   | Oreo         | $2.00  | 2             |
| C1   | Gum          | $0.75  | 8             |
| C2   | Red Bull     | $2.50  | 3             |


## Future Improvements (Work in Progress)

The project is actively being extended with new features. Here's what's currently in development:

### Version 2.0 – Graphical User Interface (Qt)
- **desktop GUI** using **Qt Creator**
  - Grid of item buttons with images, prices, and stock indicators
  - Digital credit display
  - money insert
- Enhanced owner panel:
  - Login password protection
  - Collection/Restock Control
 
## Current Progress
28th November, 2025

What I did so far:
- Core Logic Refactored

- Extracted console logic into VendingMachine.h/.cpp

- Added getSlots() for GUI table access

- Preserved all original functionality: insert, purchase, return money, restock, collect earnings

GUI Designed in Qt Creator

mainwindow.ui built with:

- Inventory table (QTableWidget)

- Insert / Select controls (QLineEdit, buttons)

- Credit display label

- Owner actions (Restock, Collect)

Controller Implemented

- Full mainwindow.cpp written with Qt signals/slots

- Table and credit update helpers

- Error handling via QMessageBox

- Integrated model ↔ UI interaction

Issues Encountered
❌ Build & Autogen Errors

Compilation produced errors such as:

expected expression

declaration does not declare anything[

These stem from Qt failing to generate ui_mainwindow.h, often due to a corrupted build directory or misconfigured project regeneration.

Root Cause

Qt autogen files (ui_*.h, moc files) were not recreated, causing valid C++ code to fail to compile.

Next Steps

Recreate project with a clean CMake/qmake setup

Delete and regenerate the entire build directory

Re-import logic files into a fresh Qt project

Continue GUI enhancement (item grid, product images, owner panel)

**Author:** Hoi Bong Chan
**Language:** C++  
**Frameworks:** VScode, C++, Qt creator  
**Keywords:** vending-machine-simulator, structs, classes, vectors, encapsulation, state-management, command-line, password-protection, inventory-management
