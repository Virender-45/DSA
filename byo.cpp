#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextEditor
{
public:
    void createFile()
    {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;

        ofstream file(filename);
        if (file.is_open())
        {
            cout << "File created successfully." << endl;
            file.close();
        }
        else
        {
            cout << "Unable to create file." << endl;
        }
    }

    void openFile()
    {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;

        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }

    void saveFile()
    {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;

        ofstream file(filename);
        if (file.is_open())
        {
            string text;
            cout << "Enter text to save: ";
            cin.ignore(); // ignore newline character left in input buffer
            getline(cin, text);
            file << text;
            file.close();
            cout << "File saved successfully." << endl;
        }
        else
        {
            cout << "Unable to save file." << endl;
        }
    }

    void run()
    {
        int choice;
        while (true)
        {
            cout << "Text Editor Menu:" << endl;
            cout << "1. Create File" << endl;
            cout << "2. Open File" << endl;
            cout << "3. Save File" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                saveFile();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main()
{
    TextEditor editor;
    editor.run();
    return 0;
}