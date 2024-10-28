#include<bits/stdc++.h>
using namespace std;

class User;

class UserUtil{
    static unordered_map<int, User*> userRecords;
    static unordered_map<string, int> userNameToIdMap;
    static int nextUserId;
    static UserUtil* instancePtr;
    UserUtil() {

    }

    public:
        UserUtil(const UserUtil &object) = delete;

        static UserUtil* getInstance();
        static void createUser(string userName);
        static User* getUserFromUserName(string userName);
        static User* getUserFromUserId(int id);
};

class User{
    int id;
    string name;
    unordered_map<int, int> balances;

    public:
        User(string userName, int userId)
        {
            id = userId;
            name = userName;
        }

        string getName()
        {
            return name;
        }

        int getId()
        {
            return id;
        }

        void updateBalance(int userId, int balance)
        {
            balances[userId] += balance;
        }

        void showBalance()
        {
            UserUtil* ptr = UserUtil::getInstance();
            
            for(auto it = balances.begin(); it != balances.end(); it++)
            {
                if(it->second != 0)
                {
                    string userName = ptr->getUserFromUserId(it->first)->getName();

                    if(it->second < 0)
                    {
                        cout<<name<<" owes "<<userName<<": "<<(-1 * it->second)<<endl;
                    }
                    else
                    {
                        cout<<userName<<" owes "<<name<<": "<<it->second<<endl;
                    }
                }
            }
        }
};


UserUtil* UserUtil::getInstance()
    {
        if(instancePtr == NULL)
        {
            instancePtr = new UserUtil();
        }

        return instancePtr;
    }

void UserUtil::createUser(string userName)
    {
        User* newUser = new User(userName, nextUserId);
        userRecords[nextUserId] = newUser;
        userNameToIdMap[userName] = nextUserId;
        nextUserId++;
    }

User* UserUtil::getUserFromUserName(string userName)
    {
        int userId = userNameToIdMap[userName];
        User* user = userRecords[userId];

        return user;
    }

User* UserUtil::getUserFromUserId(int id)
    {
        return userRecords[id];
    }

UserUtil* UserUtil::instancePtr = NULL;
int UserUtil::nextUserId = 1;
unordered_map<int, User*> temp;
unordered_map<int, User*> UserUtil::userRecords = temp;
unordered_map<string, int> tempMap;
unordered_map<string, int> UserUtil::userNameToIdMap = tempMap;

class Ledger{
    public:

        void transact(int payee, vector<int> owee, string transactionType, int amount)
        {
            UserUtil* ptr = UserUtil::getInstance();
            User* userWhoPaid = ptr->getUserFromUserId(payee);

            vector<User*> usersWhoOwe;

            for(auto user : owee)
            {
                usersWhoOwe.push_back(ptr->getUserFromUserId(user));
            }

            int update_val = amount/(usersWhoOwe.size() + 1);

            for(auto user : usersWhoOwe)
            {
                userWhoPaid->updateBalance(user->getId(), update_val);
                user->updateBalance(payee, -1 * update_val);
            }
        }
};

int main() {
    UserUtil* ptr = UserUtil::getInstance();

    ptr->createUser("jigar1");
    ptr->createUser("jigar2");
    ptr->createUser("jigar3");
    ptr->createUser("jigar4");

    Ledger ledger;

    ledger.transact(1, {2, 3, 4}, "EQUAL", 1000);
    ledger.transact(2, {1, 2}, "EQUAL", 100);
    ledger.transact(3, {2, 4}, "EQUAL", 2000);

    ptr->getUserFromUserName("jigar1")->showBalance();
    cout<<endl;
    ptr->getUserFromUserName("jigar2")->showBalance();
    cout<<endl;
    ptr->getUserFromUserName("jigar3")->showBalance();
    cout<<endl;
    ptr->getUserFromUserName("jigar4")->showBalance();

    return 0;
}
