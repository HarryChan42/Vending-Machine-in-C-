🛒 Vending Machine Simulation (C++)

A simple, interactive console-based vending machine program written in C++.
Users can insert money, purchase items, return credit, while the owner can restock and collect earnings.

📌 Features
👤 User Functions

View full vending machine inventory (item name, price, quantity).

Insert money (credit is stored until spent or returned).

Purchase items by entering a slot code (e.g., A1, B2).

Returns remaining credit with the return command.

Handles:

Invalid codes

Items out of stock

Insufficient funds

🔐 Owner Functions (Password: admin123)

restock — refill all items to full quantity.

collect — withdraw accumulated machine earnings.

💰 Money Handling

Credit stays in the machine after each purchase.

Machine tracks total earnings separately for the owner.

Change is returned only when the user chooses return.

🧩 Internal Structure
Data Structures

Item — stores name, price, and quantity.

Slot — represents positions like A1, B3, C2.

VendingMachine — manages:

Inventory

Money

Owner controls

User interface printing

Commands Supported
insert <amount>
select <slot code>
return
restock         (owner only)
collect         (owner only)
quit

▶️ How to Run

Compile and run with any C++ compiler:

g++ -std=c++11 vending.cpp -o vending
./vending


The program will display the machine and wait for user commands.

📷 Example Interaction
=== VENDING MACHINE ===
Code  Item             Price   Qty
-----------------------------------
A1    Coca Cola        $1.50    5
A2    Pepsi            $1.50    3
A3    Water            $1.00   10
...
Credit: $0.00

> insert 2
You inserted $2.00

> select A1
Dispensing Coca Cola... Enjoy!
Remaining credit: $0.50

🏁 End Message

The machine runs until the user types:

quit
