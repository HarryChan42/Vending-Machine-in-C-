#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

// Represent a single type of item
struct Item {
    string name;
    double price;
    int quantity;

    Item(string n = "", double p = 0.0, int q = 0)
        : name(n), price(p), quantity(q) {}
};

// Possible slots in the machine (e.g., A1, A2, B1, ...)
struct Slot {
    string code;
    Item item;

    Slot(string c = "", Item it = Item()) : code(c), item(it) {}
};

class VendingMachine {
private:
    vector<Slot> slots;
    double insertedMoney = 0.0;
    double totalEarnings = 0.0;

    const string OWNER_PASSWORD = "admin123";

    bool authenticateOwner() const {
        string entered;
        cout << "Enter owner password: ";
        getline(cin, entered);

        if (entered == OWNER_PASSWORD) {
            return true;
        } else {
            cout << "Incorrect password!\n";
            return false;
        }
    }

public:
    VendingMachine() {
        initializeInventory();
    }

    void initializeInventory() {
        slots = {
            {"A1", Item("Coca Cola", 1.50, 5)},
            {"A2", Item("Pepsi",     1.50, 3)},
            {"A3", Item("Water",     1.00, 10)},
            {"B1", Item("Snickers",  1.25, 4)},
            {"B2", Item("Chips",     1.75, 6)},
            {"B3", Item("Oreo",      2.00, 2)},
            {"C1", Item("Gum",       0.75, 8)},
            {"C2", Item("Red Bull",  2.50, 3)}
        };
    }

    void displayInventory() const {
        cout << "\n=== VENDING MACHINE ===\n";
        cout << "Code  Item             Price   Qty\n";
        cout << "-----------------------------------\n";

        for (const auto& slot : slots) {
            cout << left << setw(6) << slot.code
                 << setw(17) << slot.item.name
                 << "$" << fixed << setprecision(2) << setw(6) << slot.item.price
                 << "  " << slot.item.quantity << "\n";
        }
        cout << "-----------------------------------\n";
        cout << "Credit: $" << fixed << setprecision(2) << insertedMoney << endl;
    }

    Slot* findSlot(const string& code) {
        for (auto& slot : slots) {
            if (slot.code == code) {
                return &slot;
            }
        }
        return nullptr;
    }

    void insertMoney(double amount) {
        if (amount > 0) {
            insertedMoney += amount;
            cout << "You inserted $" << fixed << setprecision(2) << amount << "\n";
        }
    }

    //keeps remaining money as credit after purchase
    bool selectItem(const string& code) {
        Slot* slot = findSlot(code);
        if (!slot) {
            cout << "Invalid code!\n";
            return false;
        }
        if (slot->item.quantity <= 0) {
            cout << slot->item.name << " is out of stock!\n";
            return false;
        }
        if (insertedMoney < slot->item.price) {
            cout << "Not enough money! Need $"
                 << fixed << setprecision(2)
                 << (slot->item.price - insertedMoney) << " more.\n";
            return false;
        }

        //Dispense item
        cout << "Dispensing " << slot->item.name << "... Enjoy!\n";
        insertedMoney -= slot->item.price;
        slot->item.quantity--;
        totalEarnings += slot->item.price;

        //do NOT return change, keep as credit
        cout << "Remaining credit: $" << fixed << setprecision(2) << insertedMoney << "\n";

        return true;
    }

    void returnMoney() {
        if (insertedMoney > 0) {
            cout << "Returning $" << fixed << setprecision(2) << insertedMoney << "\n";
            insertedMoney = 0.0;
        } else {
            cout << "No money to return.\n";
        }
    }

    void restock() {
        if (!authenticateOwner()) return;

        for (auto& slot : slots) {
            slot.item.quantity = 10;
        }
        cout << "Machine fully restocked to 10 units each!\n";
    }

    double collectEarnings() {
        if (!authenticateOwner()) return 0.0;

        double earned = totalEarnings;
        totalEarnings = 0.0;
        cout << "Owner collected $" << fixed << setprecision(2) << earned << " in earnings.\n";
        return earned;
    }

    double getInsertedMoney() const { return insertedMoney; }
};

int main() {
    VendingMachine vm;
    string input;
    double money;

    cout << "Vending Machine Started! (Owner password is 'admin123')\n";

    while (true) {
        vm.displayInventory();

        cout << "\nCommands:\n";
        cout << "insert <amount>   - Insert money (e.g., insert 2.50)\n";
        cout << "select <code>     - Buy item (e.g., select A1)\n";
        cout << "return            - Get remaining credit back\n";
        cout << "restock           - (Owner only) refill all items\n";
        cout << "collect           - (Owner only) collect earnings\n";
        cout << "quit              - Exit\n";
        cout << "> ";

        if (!getline(cin, input)) break;

        if (input == "quit") {
            break;
        }
        if (input == "return") {
            vm.returnMoney();
            continue;
        }
        if (input == "restock") {
            vm.restock();
            continue;
        }
        if (input == "collect") {
            vm.collectEarnings();
            continue;
        }

        size_t space = input.find(' ');
        if (space != string::npos) {
            string cmd = input.substr(0, space);
            string arg = input.substr(space + 1);

            if (cmd == "insert") {
                try {
                    money = stod(arg);
                    vm.insertMoney(money);
                } catch (...) {
                    cout << "Invalid amount! Use numbers only.\n";
                }
            }
            else if (cmd == "select") {
                vm.selectItem(arg);
            }
            else {
                cout << "Unknown command!\n";
            }
        }
        else if (!input.empty()) {
            cout << "Unknown command! Type a valid command.\n";
        }
    }

    cout << "Thank you! Come again!\n";
    return 0;
}
