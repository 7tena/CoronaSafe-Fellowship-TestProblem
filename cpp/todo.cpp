#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <vector>

std::string line;
std::vector<std::string> todovector;

void add(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::cout << "Error: Missing todo string. Nothing added!" << std::endl;
    }
    else
    {
        std ::fstream todo("todo.txt");
        if (todo.peek() == std::ifstream::traits_type::eof())
        { 
            todo << argv[2];
            todo.close();
        }
        else
        {
            std ::fstream todo("todo.txt", std ::ios::out | std ::ios::in | std ::ios::app);
            todo << std ::endl << argv[2];
            todo.close();
            std::cout << "2" << std::endl;
        }
        std::cout << "Added todo: \"" << argv[2] << "\"" << std::endl;
    }
}

void ls()
{
    std::ifstream todo("todo.txt");
    if (todo.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "There are no pending todos!";
        todo.close();
    }
    else
    {

        std::ifstream todo("todo.txt", std ::ios::in);
        while (getline(todo, line))
        {
            todovector.push_back(line);
        }
        for (int i = todovector.size() - 1; i >= 0; i--)
        {
            std::cout << "[" << i + 1 << "] " << todovector[i] << std::endl;
        }
        todo.close();
    }
}

void del(int argc, char *argv[])
{

    std::ifstream todo("todo.txt", std ::ios::in);
    while (getline(todo, line))
    {
        todovector.push_back(line);
    }
    todo.close();
    if (argc == 2)
    {
        std::cout << "Error: Missing NUMBER for deleting todo." << std::endl;
    }
    else if ((atoi(argv[2])) > todovector.size() - 1)
    {
        std::cout << "Error: todo #" << argv[2] << " does not exist. Nothing deleted." << std::endl;
    }

    else
    {
        int i = 0;
        std::ofstream todo;
        todo.open("todo.txt", std::ofstream::out | std::ofstream::trunc);
        while (i < todovector.size())
        {
            if (i == (atoi(argv[2])))
            {
                i++;
                continue;
            }
            else
            {
                if (i == todovector.size() - 1)
                {
                    todo << todovector[i];
                }
                else
                {
                    todo << todovector[i] << std::endl;
                }
                i++;
            }
        }
        std::cout << "Deleted todo #" << argv[2];
    }
}

void done(int argc, char *argv[])
{
    int number_of_lines = 0;
    std::string line;
    std::ifstream todo("todo.txt", std ::ios::in);
    while (std::getline(todo, line))
        ++number_of_lines;
    todo.close();
    if (argc == 2)
    {
        std::cout << "Error: Missing NUMBER for marking todo as done." << std::endl;
    }
    else if ((atoi(argv[2])) >= number_of_lines)
    {
        std::cout << "Error: todo #" << argv[2] << " does not exist.";
    }
    // else
    // {
    //     std ::string lines;
    //     std::ifstream todo("todo.txt", std ::ios::in);
    //     std::fstream done("done.txt", std::ios::out);
    //     while (getline(todo, lines))
    //     {
    //         todovector.push_back(lines);
    //     }
    // }
}

int main(int argc, char *argv[])
{
    if ((argc == 1) || (strcmp(argv[1], "help") == 0))
    {
        std ::cout << "Usage :-\n$ ./todo add \"todo item\"  # Add a new todo\n$ ./todo ls               # Show remaining todos\n$ ./todo del NUMBER       # Delete a todo\n$ ./todo done NUMBER      # Complete a todo\n$ ./todo help             # Show usage\n$ ./todo report           # Statistics\n";
    }
    else if (strcmp(argv[1], "ls") == 0)
    {
        ls();
    }
    else if (strcmp(argv[1], "add") == 0)
    {
        add(argc, argv);
    }
    else if (strcmp(argv[1], "del") == 0)
    {
        del(argc, argv);
    }
    else if (strcmp(argv[1], "done") == 0)
    {
        done(argc, argv);
    }
    else if (strcmp(argv[1], "report") == 0)
    {
    }
    else
    {
    }
}
