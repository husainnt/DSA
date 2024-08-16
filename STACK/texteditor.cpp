#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

class Instruction
{
public:
    string action;
    string text;

    Instruction(const string &a, const string &t)
        : action(a), text(t) {}
};

class TextEditor
{
private:
    string content;
    stack<Instruction> undoStack;
    stack<Instruction> redoStack;

public:
    TextEditor();

    void insertText(const string &text);
    void deleteText(int length);
    void undo();
    void redo();
    void saveToFile(const string &filename);
    void openFromFile(const string &filename);
    void displayContent() const;
};

TextEditor::TextEditor()
{
    content = "";
}

void TextEditor::insertText(const string &text)
{
    content += text;
    undoStack.push(Instruction("INSERT", text));
    while (!redoStack.empty())
        redoStack.pop();
}

void TextEditor::deleteText(int length)
{
    if (length < 0 || length > content.length())
    {
        cout << RED << "Invalid length!" << RESET << endl;
        return;
    }

    string deletedText = content.substr(content.length() - length, length);
    content.erase(content.length() - length, length);
    undoStack.push(Instruction("DELETE", deletedText));
    while (!redoStack.empty())
        redoStack.pop();
}

void TextEditor::undo()
{
    if (undoStack.empty())
    {
        cout << RED << "Nothing to undo!" << RESET << endl;
        return;
    }

    Instruction lastInstruction = undoStack.top();
    undoStack.pop();

    if (lastInstruction.action == "INSERT")
    {
        content.erase(content.length() - lastInstruction.text.length(), lastInstruction.text.length());
        redoStack.push(Instruction("DELETE", lastInstruction.text));
    }
    else if (lastInstruction.action == "DELETE")
    {
        content += lastInstruction.text;
        redoStack.push(Instruction("INSERT", lastInstruction.text));
    }
}

void TextEditor::redo()
{
    if (redoStack.empty())
    {
        cout << RED << "Nothing to redo!" << RESET << endl;
        return;
    }

    Instruction lastInstruction = redoStack.top();
    redoStack.pop();

    if (lastInstruction.action == "INSERT")
    {
        content += lastInstruction.text;
        undoStack.push(Instruction("INSERT", lastInstruction.text));
    }
    else if (lastInstruction.action == "DELETE")
    {
        content.erase(content.length() - lastInstruction.text.length(), lastInstruction.text.length());
        undoStack.push(Instruction("DELETE", lastInstruction.text));
    }
}

void TextEditor::saveToFile(const string &filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << content;
        outFile.close();
        cout << GREEN << "File saved successfully!" << RESET << endl;
    }
    else
    {
        cout << RED << "Error opening file!" << RESET << endl;
    }
}

void TextEditor::openFromFile(const string &filename)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        content = "";
        inFile.seekg(0, ios::end);
        size_t size = inFile.tellg();
        inFile.seekg(0);
        content.resize(size);
        inFile.read(&content[0], size);
        inFile.close();
        cout << GREEN << "File opened successfully!" << RESET << endl;
    }
    else
    {
        cout << RED << "Error opening file!" << RESET << endl;
    }
}

void TextEditor::displayContent() const
{
    cout << CYAN << "Current Content:\n"
         << RESET
         << content << endl;
}

void displayLoadingScreen()
{
    cout << BLUE << "Loading" << RESET;
    for (int i = 0; i < 3; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

int main()
{
    displayLoadingScreen();
    TextEditor editor;
    string command;

    while (true)
    {
        cout << MAGENTA << "Enter a command (insert, delete, undo, redo, save, open, exit): " << RESET;
        cin >> command;

        if (command == "insert")
        {
            string text;
            cout << YELLOW << "Enter text to insert: " << RESET;
            cin.ignore();
            getline(cin, text);
            editor.insertText(text);
        }
        else if (command == "delete")
        {
            int length;
            cout << YELLOW << "Enter length to delete (including spaces): " << RESET;
            cin >> length;
            editor.deleteText(length);
        }
        else if (command == "undo")
        {
            editor.undo();
        }
        else if (command == "redo")
        {
            editor.redo();
        }
        else if (command == "save")
        {
            string filename;
            cout << YELLOW << "Enter filename: " << RESET;
            cin >> filename;
            editor.saveToFile(filename);
        }
        else if (command == "open")
        {
            string filename;
            cout << YELLOW << "Enter filename: " << RESET;
            cin >> filename;
            editor.openFromFile(filename);
        }
        else if (command == "exit")
        {
            break;
        }

        editor.displayContent();
    }

    return 0;
}
