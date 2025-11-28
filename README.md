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
 
  Update(Vending Machine with UI)
  Progress Summary
✔ Refactored Console Logic

The original single-file vending machine program was separated into:

VendingMachine.h / .cpp (model)

mainwindow.h / .cpp (controller)

mainwindow.ui (interface)

A new method getSlots() was added to expose inventory to the GUI.

Built the GUI Layout

Designed the interface using Qt Designer with:

Inventory table

Buttons for actions

Inputs for amount and item code

Live credit display

Implemented GUI Logic

Connected UI elements to vending-machine methods:

Insert money

Buy item

Return money

Restock & collect earnings

Table and label refresh functions

Compilation Issues Encountered

Despite correct C++ code, the project failed to compile with errors such as:

use of undeclared identifier 'Ui'

expected expression

declaration does not declare anything

return-statement with no value

These errors appeared inside valid functions and unrelated lines.

**Author:** Hoi Bong Chan
**Language:** C++  
**Frameworks:** VScode, C++, Qt creator  
**Keywords:** vending-machine-simulator, structs, classes, vectors, encapsulation, state-management, command-line, password-protection, inventory-management
