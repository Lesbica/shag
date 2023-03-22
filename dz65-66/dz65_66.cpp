#include <iostream>
#include <map>

class User {
private:
        std::map<std::string, std::string> user;
        
        bool IsValidPassword(std::string password) {
                if (password.length() < 5) {
                        return false;
                }
                for (char c : password) {
                        if (!isalnum(c)) {
                                return false;
                        }
                }
                return true;
        }
public:
        User() {}

        void ShowUsers() {
                std::cout << "List of users:" << std::endl;
                for (auto it = user.begin(); it != user.end(); ++it) {
                        std::cout << it->first << " : " << it->second << std::endl;
                }
        }

        void AddUser(std::string login, std::string password) {
                if (user.find(login) != user.end()) {
                        std::cout << "User with login '" << login << "' already exists." << std::endl;
                }
                else if (!IsValidPassword(password)) {
                        std::cout << "Invalid password. Password must contain at least 5 characters, and can only contain alphanumeric characters." << std::endl;
                }
                else {
                        user[login] = password;
                        std::cout << "User with login '" << login << "' and password '" << password << "' has been added." << std::endl;
                }
        }

        void DeleteUserByLogin(std::string login) {
                auto it = user.find(login);
                if (it != user.end()) {
                        user.erase(it);
                        std::cout << "User with login '" << login << "' has been deleted." << std::endl;
                }
                else {
                        std::cout << "User with login '" << login << "' does not exist." << std::endl;
                }
        }

        void ChangePassword(std::string login, std::string oldPassword, std::string newPassword) {
                auto it = user.find(login);
                if (it == user.end()) {
                        std::cout << "User with login '" << login << "' does not exist." << std::endl;
                        return;
                }
                if (it->second != oldPassword) {
                        std::cout << "Incorrect login or old password." << std::endl;
                        return;
                }
                if (!IsValidPassword(newPassword)) {
                        std::cout << "Invalid password. Password must contain at least 5 characters, and can only contain alphanumeric characters." << std::endl;
                        return;
                }
                it->second = newPassword;
                std::cout << "Password for user with login '" << login << "' has been changed to '" << newPassword << "'." << std::endl;
        }

        std::string GetPassword(std::string login) {
                auto it = user.find(login);
                if (it == user.end()) {
                        return "";
                }
                return it->second;
        }
};

int main()
{
        User users;
        users.AddUser("user1", "password1");
        users.AddUser("user2", "password2");
        users.AddUser("user1", "password3");
        users.AddUser("user3", "password1");
        users.DeleteUserByLogin("user3");
        users.ShowUsers();
        std::cout << users.GetPassword("user1") << std::endl;
        users.ChangePassword("user2", "password2", "password4");
        users.ShowUsers();
        
        return 0;
}