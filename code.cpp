#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

// ALL DATA
int level;

const int rows = 25; // max size of rows
const int cols = 25; // max size of columns
char maze[rows][cols];

int coordinatesX, coordinatesY;// user`s coordinates
int finishX, finishY;//coordinates of exit
char letter = 0;
int characterColor = 0;
char direction;

HANDLE color;

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;     // Set cursor size 
    cursorInfo.bVisible = FALSE; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void DidYouChoseYourLetterAndColor()
{
    system("cls");
    while (characterColor == 0 ) //because of declaration, the program can understand, were the letter&color choosed or not 
    {
    	system("cls");
        cout << "Choose the letter or symbol that will represent you in this game: ";
        cin >> letter;
        cout << "Also, you should choose the color of character." << endl;
        cout << "Here some information about colors:\n1 - dark blue\t9 - brighter dark blue\n2 - dark green\t10 - light green\n3 - blue\t11 - bright blue\n4 - dark red\n5 - dark purple\t13 - purple\n6 - yellow\t14 - bright yellow\n7 - white\t15 - white\n8 - grey" << endl;
        cout << "Or you can write a random number to see what will happen." << endl;
        cout << "Your color: ";
        cin >> characterColor;
    }
    if (characterColor != 0 && letter != 0) //only if they BOTH are NOT equal zero
    {
        cout << "Your color and character are chosen.";
        Sleep(800);
        system("cls");
    }
}

// function to print labyrinth + to color Entry, Exit and letter
void printLabyrinth()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == coordinatesX && j == coordinatesY)
            {
                SetConsoleTextAttribute(color, characterColor);
            }
            else if (maze[i][j] == 'E')
            {
                SetConsoleTextAttribute(color, 14); // Yellow color for 'E'
            }
            else if (maze[i][j] == 'X')
            {
                SetConsoleTextAttribute(color, 12); // Red color for 'X'
            }
            else
            {
                SetConsoleTextAttribute(color, 7); // White color for other characters
            }

            cout << maze[i][j] << ' ';
        }
        SetConsoleTextAttribute(color, 7); // Reset to white color
        cout << '\n';
    }
}

// FUNCTIONS FOR 1 CASE
void createLabyrinthONE()
{
    // init only 15*15, and populates everything that left with " "
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i < 15 && j < 15)
            {
                maze[i][j] = '#';
            }
            else
            {
                maze[i][j] = ' ';
            }
        }
    }

    maze[13][0] = 'E'; // Enterence
    maze[1][14] = 'X'; // Exit

    maze[13][1] = '.';
    maze[1][1] = '.';
    maze[13][2] = '.';
    maze[2][1] = '.';
    maze[1][2] = '.';
    maze[1][3] = '.';
    maze[1][4] = '.';
    maze[2][4] = '.';
    maze[3][4] = '.';
    maze[3][5] = '.';
    maze[3][6] = '.';
    maze[3][7] = '.';
    maze[2][7] = '.';
    maze[2][8] = '.';
    maze[2][9] = '.';
    maze[13][3] = '.';
    maze[3][1] = '.';
    maze[13][4] = '.';
    maze[4][1] = '.';
    maze[13][5] = '.';
    maze[5][1] = '.';
    maze[13][6] = '.';
    maze[6][1] = '.';
    maze[6][4] = '.';
    maze[6][5] = '.';
    maze[5][4] = '.';
    maze[4][3] = '.';
    maze[4][4] = '.';
    maze[3][3] = '.';
    maze[3][2] = '.';
    maze[12][6] = '.';
    maze[7][1] = '.';
    maze[7][5] = '.';
    maze[11][6] = '.';
    maze[8][1] = '.';
    maze[8][2] = '.';
    maze[8][3] = '.';
    maze[8][4] = '.';
    maze[8][5] = '.';
    maze[10][6] = '.';
    maze[9][1] = '.';
    maze[10][7] = '.';
    maze[10][1] = '.';
    maze[10][2] = '.';
    maze[10][3] = '.';
    maze[10][8] = '.';
    maze[11][1] = '.';
    maze[11][3] = '.';
    maze[11][8] = '.';
    maze[12][1] = '.';
    maze[12][8] = '.';
    maze[13][8] = '.';
    maze[13][9] = '.';
    maze[13][10] = '.';
    maze[13][11] = '.';
    maze[12][11] = '.';
    maze[11][11] = '.';
    maze[10][11] = '.';
    maze[10][12] = '.';
    maze[10][13] = '.';
    maze[9][13] = '.';
    maze[8][13] = '.';
    maze[8][12] = '.';
    maze[8][11] = '.';
    maze[8][10] = '.';
    maze[8][9] = '.';
    maze[8][8] = '.';
    maze[8][7] = '.';
    maze[7][7] = '.';
    maze[6][7] = '.';
    maze[5][7] = '.';
    maze[5][8] = '.';
    maze[5][9] = '.';
    maze[5][10] = '.';
    maze[5][11] = '.';
    maze[4][11] = '.';
    maze[3][11] = '.';
    maze[2][11] = '.';
    maze[1][11] = '.';
    maze[1][12] = '.';
    maze[1][13] = '.';

    // initial and finish values for letter and finish coordinates
    coordinatesX = 13;
    coordinatesY = 1;
    finishX = 1;
    finishY = 14;

    maze[coordinatesX][coordinatesY] = letter;
}

// FUNCTIONS FOR 2 CASE
void createLabyrinthTWO()
{
    // Initialize the maze with array
    char createLabyrinthTWOarray[rows][cols] = {
        {'#', 'E', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '.', '.', '.', '.', '.', 'X'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '.', '#', '.', '#', '.', '#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    // Copy the initial maze to the current maze
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maze[i][j] = createLabyrinthTWOarray[i][j];
        }
    }

    //  initial and finish values for letter and finish coordinates
    coordinatesX = 1;
    coordinatesY = 1;
    maze[coordinatesX][coordinatesY] = letter;

    finishX = 3;
    finishY = 24;
}

// universe func.
void Movement(char direction)
{
    // Clear previous letter position
    maze[coordinatesX][coordinatesY] = '.';

    // Move user`s character(letter) based on the direction
    switch (direction)
    {
    case 'W':
    case 'w':
        if (coordinatesX > 0 && maze[coordinatesX - 1][coordinatesY] != '#') //checks, if there a way where letter can `make a step` 
        {
            coordinatesX--;
        }
        break;
    case 'S':
    case 's':
        if (coordinatesX < rows - 1 && maze[coordinatesX + 1][coordinatesY] != '#')
        {
            coordinatesX++;
        }
        break;
    case 'A':
    case 'a':
        if (coordinatesY > 0 && maze[coordinatesX][coordinatesY - 1] != '#')
        {
            coordinatesY--;
        }
        break;
    case 'D':
    case 'd':
        if (coordinatesY < cols - 1 && maze[coordinatesX][coordinatesY + 1] != '#')
        {
            coordinatesY++;
        }
        break;
    }

    // place character in the new position
    maze[coordinatesX][coordinatesY] = letter;
}

void readMazeFile()
{
    string nameTxt = "maze_3.txt", nameFirstTxt = "maze.txt", nameFile;
    ifstream file;
    cout << "Files available: maze_3.txt and maze.txt" << endl;
    cout << "Please, tell me the name of file, which you want to open: ";
    cin >> nameFile;

    if (nameFile == nameTxt)
    {
        file.open("maze_3.txt");
    }
    else if (nameFile == nameFirstTxt)
    {
        file.open("maze.txt");
    }

    if (!file.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        
	//	exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> maze[i][j];
            if (maze[i][j] == 'E')
            {
                coordinatesX = i;
                coordinatesY = j;
            }
            else if (maze[i][j] == 'X')
            {
                finishX = i;
                finishY = j;
            }
        }
    }

    file.close();
}

void animation()
{
    hideCursor();
    while (true) // always true until the break hits
    {
        system("cls");
        printLabyrinth();
        cout << "To move use: W, A, S, D"
             << "\nTo quit press: Q" << endl
             << endl;
        cout << "Direction: " << direction << endl;

        direction = _getch();

        if (direction == 'Q' || direction == 'q')
        {
            break;
        }

        Movement(direction);

        if (coordinatesY == finishY && coordinatesX == finishX) // when coordinates of letter matches with the coordinates of exit
        {
            SetConsoleTextAttribute(color, 10);
            cout << "You have found the right path)" << endl<< endl;
            SetConsoleTextAttribute(color, 7);
            Sleep(1350);
            break;
        }
    }
}

int main()
{

    color = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
        system("cls");
        cout << "Choose the level of difficulty for this labyrinth game." << endl
             << "1 - easy, 2 - medium, 3 - load maze from file, 0 - to end the game" << endl
             << "Your choice: ";
        cin >> level;

        if (cin.fail()) //our level has an int data type, that`s mean, that anything besides integer will cause an error, and 'if-statement' checks, is it integer or no and is it in a range from 0 to 3
        {
            system("cls");
            SetConsoleTextAttribute(color, 12);
            cout << endl
                 << "Error: Please enter an integer next time.";
            Sleep(2000);
            SetConsoleTextAttribute(color, 7);
        }
        else if (level < 0 || level > 3)
        {
            system("cls");
            SetConsoleTextAttribute(color, 12);
            cout << endl
                 << "Error: Please choose a value between 0 and 3.";
            Sleep(2000);
            SetConsoleTextAttribute(color, 7);
        }
        else
        {
            switch (level)
            {

            case 1:
                DidYouChoseYourLetterAndColor();
                createLabyrinthONE();
                animation();

                break;

            case 2:
                DidYouChoseYourLetterAndColor();
                createLabyrinthTWO();
                animation();

                break;

            case 3:
                DidYouChoseYourLetterAndColor();
                readMazeFile();
                animation();
								
                break;
            }
        }
    } while (level != 0);
    system("cls");
    cout<<"Thank you for playing!"<<endl;
    cout<<"        ____\n";
    cout<<"      / >    >\n";
    cout<<"      |  _  _|\n";
    cout<<"      \\    x )\n";
    cout<<"      /     |\n";
    cout<<"    /       )\n";
    cout<<"    /   `  |\n";
    cout<<"    |    |||\n";
    cout<<"  __|    |||\n";
    cout<<" //-------\))\n";
    cout<<" \\__";
    
    return 0;
}
