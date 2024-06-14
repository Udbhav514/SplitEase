#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath> // for ceil function
using namespace std;
class comparator
{
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second < p2.second;
    }
};

int main()
{
    int transactions, friends;
    map<string, int> m; // maintaining net amount for all friends

    cout << "Enter number of friends: ";
    cin >> friends;

    vector<string> friendList(friends);
    cout << "Enter the names of the friends:\n";
    for (int i = 0; i < friends; i++)
    {
        cin >> friendList[i];
        m[friendList[i]] = 0; // initialize their balance
    }

    cout << "Enter total number of transactions: ";
    cin >> transactions;

    string x, y;
    int amount;
    char transactionType;
    cout << "Please enter information for all the transactions according to prompts.\n";

    for (int i = 1; i <= transactions; i++)
    {
        bool validInput = false;
        while (!validInput)
        {
            cout << "Transaction-" << i << endl;
            cout << "Enter 'I' for individual transaction or 'G' for group transaction: ";
            cin >> transactionType;

            if (transactionType == 'I')
            {
                cout << "Name of the person who has to pay: ";
                cin >> x;
                if (m.find(x) == m.end())
                {
                    cout << "Invalid person. Please enter a valid friend name.\n";
                    continue;
                }

                cout << "Name of the person who has to take the money: ";
                cin >> y;
                if (m.find(y) == m.end())
                {
                    cout << "Invalid person. Please enter a valid friend name.\n";
                    continue;
                }

                cout << "Amount: ";
                cin >> amount;

                m[x] -= amount;
                m[y] += amount;
                validInput = true;
            }
            else if (transactionType == 'G')
            {
                cout << "Name of the person who paid for the group: ";
                cin >> x;
                if (m.find(x) == m.end())
                {
                    cout << "Invalid person. Please enter a valid friend name.\n";
                    continue;
                }

                cout << "Total amount paid: ";
                cin >> amount;

                int share = ceil((double)amount / friends); // Round up to ensure each friend gets an equal or more share

                for (const auto &person : friendList)
                {
                    if (person != x)
                    {
                        m[person] -= share;
                        m[x] += share;
                    }
                }
                validInput = true;
            }
            else
            {
                cout << "Invalid transaction type. Please enter 'I' or 'G'.\n";
            }
        }
    }

    multiset<pair<string, int>, comparator> s;
    for (auto p : m)
    {
        string person = p.first;
        int amount = p.second;
        if (amount != 0)
        {
            s.insert(make_pair(person, amount));
        }
    }

    int total_trans = 0;
    cout << "\n------------------------SOLUTION--------------------------\n";

    while (!s.empty())
    {
        auto start = s.begin();
        auto end = s.end();
        end--;
        string debit_person = start->first;
        int debit_amt = start->second;
        string credit_person = end->first;
        int credit_amt = end->second;
        s.erase(start);
        s.erase(end);
        int amount_settled = min(abs(debit_amt), abs(credit_amt));
        debit_amt += amount_settled;
        credit_amt -= amount_settled;
        total_trans++; // one successful transaction has been performed
        cout << "Transaction-" << total_trans << " : \n";
        cout << debit_person << " should pay " << amount_settled << " to " << credit_person << ".\n";
        if (debit_amt != 0)
        {
            s.insert(make_pair(debit_person, debit_amt));
        }
        if (credit_amt != 0)
        {
            s.insert(make_pair(credit_person, credit_amt));
        }
    }
    cout << "\nTotal number of transactions will be: " << total_trans << ".\n";

    return 0;
}
