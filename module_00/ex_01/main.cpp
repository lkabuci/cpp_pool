#include <iostream>
#include <string>

class Contact {
public:
    Contact(const std::string& first_name,
            const std::string& last_name,
            const std::string& nickname,
            const std::string& phone_number,
            const std::string& darkest_secret)
            : first_name_(first_name), last_name_(last_name),
              nickname_(nickname), phone_number_(phone_number),
              darkest_secret_(darkest_secret) {}

    std::string get_first_name() const { return first_name_; }
    std::string get_last_name() const { return last_name_; }
    std::string get_nickname() const { return nickname_; }
    std::string get_phone_number() const { return phone_number_; }
    std::string get_darkest_secret() const { return darkest_secret_; }

private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
};

class PhoneBook {
public:
    PhoneBook() : num_contacts_(0), oldest_contact_index_(0) {}

    bool add_contact(const Contact& contact) {
        if (num_contacts_ < 8) {
            contacts_[num_contacts_] = contact;
            num_contacts_++;
            return true;
        } else {
            contacts_[oldest_contact_index_] = contact;
            oldest_contact_index_ = (oldest_contact_index_ + 1) % 8;
            return false;
        }
    }

    void print_contacts() const {
        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        for (int i = 0; i < num_contacts_; i++) {
            std::cout << "|";
            std::cout.width(10);
            std::cout << std::right << i << "|";
            std::cout.width(10);
            std::cout << std::right << trim_string(contacts_[i].get_first_name()) << "|";
            std::cout.width(10);
            std::cout << std::right << trim_string(contacts_[i].get_last_name()) << "|";
            std::cout.width(10);
            std::cout << std::right << trim_string(contacts_[i].get_nickname()) << "|" << std::endl;
        }
    }

    const Contact& get_contact(int index) const {
        return contacts_[index];
    }

private:
    Contact contacts_[8];
    int num_contacts_;
    int oldest_contact_index_;

    std::string trim_string(const std::string& str) const {
        if (str.size() > 10) {
            return str.substr(0, 9) + ".";
        } else {
            return str;
        }
    }
};

int main() {
    PhoneBook phonebook;

    while (true) {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        std::cin >> command;

        if (command == "ADD") {
            std::string first_name, last_name, nickname, phone_number, darkest_secret;
            std::cout << "Enter first name: ";
            std::cin >> first_name;
            std::cout << "Enter last name: ";
            std::cin >> last_name;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            std::cout << "Enter phone number: ";
            std::cin >> phone_number;
		}
	}
}

