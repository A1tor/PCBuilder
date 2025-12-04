#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ref class PcbUser
{
private:
    static const Char delimiter = Char('^');
    static String^ dataFilePath= ".\\resources\\users.txt";
	String^ name;
	String^ password;
    String^ status;
public:

    PcbUser() {}

	PcbUser(String^ name, String^ password, String^ status)
		: name(name), password(password), status(status)
	{	}

    PcbUser(String^ codeString) {
        auto parameters = codeString->Split(delimiter);
        this->name = parameters[0];
        this->password = parameters[1]->GetHashCode().ToString();
        this->status = parameters[2];
    }

    void copyUser(PcbUser^ user) {
        this->name = user->name;
        this->password = user->password;
        this->status = user->status;
    }

    String^ getName() {
        return name;
    }

    String^ getStatus() {
        return status;
    }

	String^ getCredentials() {
		return String::Concat(name, delimiter, password, delimiter, status);
	}

	static List<PcbUser^>^ getUserArray() {
        List<PcbUser^>^ userList = gcnew List<PcbUser^>();
        try
        {
            StreamReader^ reader = File::OpenText(dataFilePath);
            String^ line;
            while ((line = reader->ReadLine()) != nullptr)
            {
                auto parameters = line->Split(delimiter);
                userList->Add(gcnew PcbUser(parameters[0], parameters[1], parameters[2]));
            }
            reader->Close();
        } catch (Exception^ e) {
            throw e;
        }
        return userList;
	}

    static void updateUserListFile(List<PcbUser^>^ userList) {
        try
        {
            StreamWriter^ writer = gcnew StreamWriter(dataFilePath);
            for each (auto user in userList)
                writer->WriteLine(user->getCredentials());
            writer->Close();
        } catch (Exception^ e) {
            throw e;
        }
    }

    static void addToList(List<PcbUser^>^ userList, PcbUser^ user) {
        //Реализация линейного поиска. Ищет любое вхождение, которое меньше данного. \
        //При равенстве выкидывает ошибку
        int index = 0, comparison;
        for each (auto userInList in userList) {
            comparison = user->name->CompareTo(userInList->name);
            if (comparison == 0)
                throw gcnew Exception("Trying to insert existing user");
            if (comparison < 0)
                break;
            index++;
        }
        userList->Insert(index, user);
    }

    static int getUserWithCredentials(List<PcbUser^>^ userList, String^ username, String^ password) {
        //Реализация бинарного поиска. Ищет конкретное вхождение
        int low = 0;
        int high = userList->Count - 1; 
        int mid, comparison;

        while (low <= high) {
            mid = (low + high) / 2;
            comparison = username->CompareTo(userList[mid]->name);
            if (comparison == 0) {
                if (!userList[mid]->password->Equals(password) && password != nullptr)
                    break;
                return mid;
            } else if (comparison < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    String^ ToString() override
    {
        return String::Concat(status, " ", name);
    }
};

