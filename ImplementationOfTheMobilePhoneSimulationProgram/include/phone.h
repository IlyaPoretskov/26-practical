#pragma once
#include <iostream>
#include <string>
#include <map>

#define DEBUG 0

class Phone
{

private:

    std::string phone;

public:

    bool isValid()
    {
        if (phone.length() != 12)
        {
            return false;
        }

        if (phone[0] != '+' || phone[1] != '7')
        {
            return false;
        }

        std::string leftSide;

        for (int i = 2; i < 12; i++)
        {
            leftSide += phone[i];
        }

#if DEBUG
        std::cout  << leftSide << std::endl;
#endif

        for (char i : leftSide)
        {
            if ( !(  i >= '0' && i <= '9'  ) )
            {
                return false;
            }
        }
#if DEBUG
        std::cout << "true" << std::endl;
#endif
        return true;
    }
    friend class PhoneBook;
};


class PhoneBook
{

private:

    std::map<Phone *, std::string> phoneBook;
    std::map<std::string, Phone *> inversedPhoneBook;

public:

    ~PhoneBook()
    {
        phoneBook.clear();
        inversedPhoneBook.clear();
    }

    void add()
    {
        std::cout << "Input the name of new phone contact:" << std::endl;

        std::string contactName;
        std::cin >> contactName;

        std::cout << "Input number of new phone contact:" << std::endl;
        auto *contactNumber = new Phone();
        std::cin >> contactNumber->phone;

#if DEBUG
        std::cout << contactNumber->phone << std::endl;
#endif

        while (!contactNumber->isValid())
        {
            std::cout << "Wrong input, try again" << std::endl;
            std::cin >> contactNumber->phone;
        }

        std::pair<Phone *, std::string> firstPair (contactNumber, contactName);
        std::pair<std::string, Phone *> secondPair(contactName, contactNumber);

        phoneBook.insert(firstPair);
        inversedPhoneBook.insert(secondPair);
    }

    void call()
    {
        std::cout << "The call will be made by phone number(0) / by name(1): " << std::endl;
        int n;
        std::cin >> n;

        while (n != 0 && n != 1)
        {
            std::cout << "Wrong input, try again" << std::endl;
            std::cin >> n;
        }

        if (n == 0)
        {
            std::cout << "Input telephone number: " << std::endl;
            auto *contactNumber = new Phone();

            std::cin >> contactNumber->phone;

#if DEBUG
            std::cout << contactNumber->phone << std::endl;
            if (phoneBook.find(contactNumber) == phoneBook.end())
            {
                std::cout << "Didn't find!" << std::endl;
                std::cout << phoneBook.find(contactNumber)->first->phone << std::endl;
            }
            else
            {
                std::cout << "The object found!" << std::endl;
            }
#endif

            while (!contactNumber->isValid())
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >>  contactNumber->phone;
            }

#if DEBUG
            int c = phoneBook.count(contactNumber);
#endif

            std::pair<Phone *, std::string> oPair;

            bool tmpIsFind = false;

            for (auto & it : phoneBook)
            {
                if (it.first->phone == contactNumber->phone)
                {
                    tmpIsFind = true;
                    oPair.first = contactNumber;
                    oPair.second = it.second;
                }
            }

            while (!tmpIsFind)
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >> contactNumber->phone;

                while (!contactNumber->isValid())
                {
                    std::cout << "Wrong input, try again" << std::endl;
                    std::cin >> contactNumber->phone;
                }

                for (auto & it : phoneBook)
                {
                    if (it.first->phone == contactNumber->phone)
                    {
                        tmpIsFind = true;
                        oPair.first->phone = contactNumber->phone;
                        oPair.second = it.second;
                    }
                }
            }



            std::cout << "CALL:  " << std::endl <<
                         "NAME:  " << oPair.second << std::endl <<
                         "PHONE: " << oPair.first->phone << std::endl;
            delete contactNumber;
        }
        else
        {
            std::cout << "Input contact name: " << std::endl;
            std::string contactName;

            std::cin >> contactName;

            while (inversedPhoneBook.count(contactName) <= 0)
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >> contactName;
            }

            auto it = inversedPhoneBook.find(contactName);

            std::cout << "CALL:  " << std::endl <<
                         "NAME:  " << it->first << std::endl <<
                         "PHONE: " << it->second->phone << std::endl;
        }
    }

    void sms()
    {
        std::cout << "The sms will be made by phone number(0) / by name(1): " << std::endl;
        int n;
        std::cin >> n;

        while (n != 0 && n != 1)
        {
            std::cout << "Wrong input, try again" << std::endl;
            std::cin >> n;
        }

        if (n == 0)
        {
            std::cout << "Input telephone number: " << std::endl;
            auto *contactNumber = new Phone();

            std::cin >> contactNumber->phone;

            while (!contactNumber->isValid())
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >> contactNumber->phone;
            }

            std::pair<Phone *, std::string> oPair;

            bool tmpIsFind = false;

            for (auto & it : phoneBook)
            {
                if (it.first->phone == contactNumber->phone)
                {
                    tmpIsFind = true;
                    oPair.first = contactNumber;
                    oPair.second = it.second;
                }
            }

            while (!tmpIsFind)
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >> contactNumber->phone;

                while (!contactNumber->isValid())
                {
                    std::cout << "Wrong input, try again" << std::endl;
                    std::cin >> contactNumber->phone;
                }

                for (auto & it : phoneBook)
                {
                    if (it.first->phone == contactNumber->phone)
                    {
                        tmpIsFind = true;
                        oPair.first->phone = contactNumber->phone;
                        oPair.second = it.second;
                    }
                }
            }

            auto it = phoneBook.find(contactNumber);

            std::cout << "Input sms: " << std::endl;
            std:: string sms;
            std::cin >> sms;

            std::cout << "SMS:   " << sms << std::endl <<
                         "NAME:  " << oPair.second << std::endl <<
                         "PHONE: " << oPair.first->phone << std::endl;
            delete contactNumber;
        }
        else
        {
            std::cout << "Input contact name: " << std::endl;
            std::string contactName;

            std::cin >> contactName;

            while (inversedPhoneBook.count(contactName) <= 0)
            {
                std::cout << "Wrong input, try again" << std::endl;
                std::cin >> contactName;
            }

            auto it = inversedPhoneBook.find(contactName);

            std::cout << "Input sms: " << std::endl;
            std:: string sms;
            std::cin >> sms;

            std::cout << "SMS:   " << sms << std::endl <<
                         "NAME:  " << it->first << std::endl <<
                         "PHONE: " << it->second->phone << std::endl;
        }
    }
};