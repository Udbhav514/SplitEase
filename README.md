# Splitwise-like Application

This C++ application simulates a simplified version of Splitwise, a tool for managing shared expenses among friends or groups. It allows users to input individual and group transactions, calculates how debts should be settled, and outputs a series of transactions to balance the debts among participants.

## How It Works

### Initialization
- **Number of Friends**: Users start by entering the number of friends involved in the group.
- **Friend Names**: Names of all friends are entered, initializing each with a balance of zero in a map (`map<string, int> m`).

### Transaction Input
- **Individual Transactions (`'I'`)**: Users specify who pays (`x`) and who receives (`y`) a certain amount (`amount`). The program updates each person's balance accordingly.
- **Group Transactions (`'G'`)**: Users specify who paid for the group (`x`) and the total amount (`amount`). The program divides this amount evenly among all friends, ensuring each gets at least their share using the ceiling function (`ceil()`).

### Debt Calculation
- **Multiset Sorting**: After all transactions are inputted, the program sorts friends based on their net balances using a custom comparator (`comparator` class and `multiset<pair<string, int>, comparator> s`). This allows for efficient debt settlement calculations.

### Debt Settlement
- **Transaction Execution**: The program iterates through the sorted multiset to settle debts. It identifies pairs of friends (`debit_person` and `credit_person`) with imbalances and executes transactions (`amount_settled`) until balances are zeroed out or minimized.

### Output
- **Transaction Details**: Each transaction is outputted, detailing who pays whom and how much, until all debts are settled.
- **Total Transactions**: The program concludes by displaying the total number of transactions executed to settle all debts.

## Example Usage
To run the program, compile and execute the provided C++ code in a suitable development environment. Follow the prompts to input friend details and transactions. Ensure correct input format (`'I'` for individual, `'G'` for group transactions) and valid friend names throughout.

## Modifications
Feel free to modify the code to suit specific scenarios or add additional features, such as handling different currencies, incorporating interest calculations, or exporting transaction logs.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.
