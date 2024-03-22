#include <iostream>
using namespace std;

const int NUM_SPACES = 400;
const int FREE_SPACE = 0; // represents a free space in the game board
const int DOODLEBUG = 1;  // represents a doodlebug in the gameboard
const int ANT = 2;        // represents an ant in the gameboard

class Organism // organism class for ants and doodlebugs
{
public:
    Organism(int x, int y) : x_coordinate(x), y_coordinate(y) {} // constructor for organism
    Organism();
    int getX() { return this->x_coordinate; }
    int getY() { return this->y_coordinate; }
    void move(int positions[20][20]); // function for organism to move; depends on organism

    bool checkForAdjacentSpace(int positions[20][20]); // checks for free space nearby before moving or breeding
    int getID() { return organismID; }
    void updateTimetoBreed() { timeToBreed -= 1; }; // subtracts one time from time to breed

protected:            // in lecture he said don't use protected, you are probably doing it wrong...
    int organismID;   // 1 for doodlebug and 2 for ant
    int x_coordinate; // x coordinate for organism on gameboard
    int y_coordinate; // y coordinate for organism on gameboard
    int timeToBreed;  // how long until organism breeds; depends on organism
};

class Ant : public Organism
{
public:
    Ant(int x_coordinate, int y_coordinate); // ant constructor
};

class Doodlebug : public Organism // doodlebug class extends organism class
{
public:
    Doodlebug(int x_coordinate, int y_coordinate);
    Doodlebug();
    int getTimeToEat() { return timeToEat; }
    int getTimeToBreed() { return timeToBreed; }
    bool checkForAdjacentAnt(int positions[20][20]);
    void eat(vector<Ant> antsVector, int x, int y);
    void die(int positions[20][20], vector<Doodlebug> &doodlebugVector);
    Doodlebug breed(int x, int y);
    void setTimeToEat(int x) { timeToEat = x; }

private:
    int timeToEat; // how long until doodlebug dies
};

vector<Doodlebug> newDoodlebugs; // to keep track of newly bred doodlebugs in one round

class GameBoard
{
public:
    GameBoard();            // constructor initializes a gameboard with 100 ants and 5 doodlebugs
    void printGameBoard();  // function to print the current gameBoard
    void updateGameBoard(); // updates the gameboard after every turn

private:
    int positions[20][20];             // define empty 2D array; will keep track of positions
    vector<Doodlebug> doodlebugVector; // will keep track of all the doodlebugs on the board
    vector<Ant> antsVector;            // will keep track of all the ants on the board
    void updateDoodlebugs();
};

int main()
{
    int time = 0; // time is 0 at start
    GameBoard currentGame;

    while (true)
    {
        string userInput;
        cout << "World at time " << time << ":" << endl;
        currentGame.printGameBoard();
        cout << "Press ENTER to continue";
        currentGame.updateGameBoard();
        getline(cin, userInput);

        time += 1;
    }
}

GameBoard::GameBoard() // gameboard constructor
{
    // initialize all values in the 2D gameboard to 0
    void initializeArray(int positions[20][20]);
    initializeArray(positions);

    // chooses random indexes for all doodlebugs AND creates instances of doodlebugs
    void indexInitialDoodlebugs(int positions[20][20], vector<Doodlebug> &doodlebugVector);
    indexInitialDoodlebugs(positions, doodlebugVector);

    // chooses random indexes for all ants AND creates instances of ants
    void indexInitialAnts(int positions[20][20], vector<Ant> &antsVector);
    indexInitialAnts(positions, antsVector);
}

void GameBoard::printGameBoard()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (positions[i][j] == FREE_SPACE) // print a space
                cout << "- ";
            else if (positions[i][j] == DOODLEBUG) // print a doodlebug
                cout << "x ";
            else if (positions[i][j] == ANT) // print an ant
                cout << "o ";
        }

        cout << endl;
    }
}

// initializes 2D array to all -1s
void initializeArray(int positions[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            positions[i][j] = FREE_SPACE;
        }
    }
}

void indexInitialDoodlebugs(int positions[20][20], vector<Doodlebug> &doodlebugVector)
{
    // assign doodlebugs to a coordinate
    int doodlebugs = 5;
    srand(time(NULL)); // per documentation: https://cplusplus.com/reference/cstdlib/srand/
    while (doodlebugs > 0)
    {
        int x_coordinate, y_coordinate;
        do // generate a unique, random x and y index for each doodlebug
        {
            int randomIdx = rand() % 399;
            cout << randomIdx;
            x_coordinate = randomIdx / 20;

            randomIdx = rand() % 399;
            y_coordinate = randomIdx % 20;
        } while (positions[x_coordinate][y_coordinate] == DOODLEBUG || positions[x_coordinate][y_coordinate] == ANT);

        positions[x_coordinate][y_coordinate] = DOODLEBUG;
        Doodlebug doodlebug(x_coordinate, y_coordinate);
        doodlebugVector.push_back(doodlebug); // add doodlebug to vector of doodlebugs assoc. with gameboard
        doodlebugs--;
    }
}

Ant::Ant(int x_coordinate, int y_coordinate) : Organism(x_coordinate, y_coordinate)
{
    timeToBreed = 3;
    organismID = 2;
}

void indexInitialAnts(int positions[20][20], vector<Ant> &antsVector)
{
    // assign ants
    int ants = 100;
    while (ants > 0)
    {
        int x_coordinate, y_coordinate;
        do // generate a unique, random x and y index for each ant
        {
            int randomIdx = rand() % 399;
            x_coordinate = randomIdx / 20;

            randomIdx = rand() % 399;
            y_coordinate = randomIdx % 20;
        } while (positions[x_coordinate][y_coordinate] == DOODLEBUG || positions[x_coordinate][y_coordinate] == ANT);

        positions[x_coordinate][y_coordinate] = ANT;
        Ant ant(x_coordinate, y_coordinate);
        antsVector.push_back(ant); // add ant to vector of ant assoc. with gameboard
        ants--;
    }
}

void GameBoard::updateGameBoard()
{
    // cycle through list of DOODLEBUGS, which move first
    // for each one, check if there is an ant in adjacent cell
    // if yes, eat it and MOVE TO THAT CELL
    // if no, check if the ant should die or breed. die or breed if required
    // if not dead, then move -- FOLLOW THE SAME STEPS AS ANT -- abstract to organism class, maybe move() function
    updateDoodlebugs(); // cycles through each doodlebug on the board; eats ant if nearby or moves if not
}

void GameBoard::updateDoodlebugs()
{
    for (int i = 0; i < doodlebugVector.size(); i++)
    {
        int x = doodlebugVector[i].getX();
        int y = doodlebugVector[i].getY();
        bool adjacentAnt = doodlebugVector[i].checkForAdjacentAnt(positions); // checks for adjacent ant and moves into that position in the positions array
        // here with the option to either write a separate function or make checkforadjacentant a method on doodlebug, which is better?

        if (adjacentAnt)
        {
            doodlebugVector[i].eat(antsVector, doodlebugVector[i].getX(), doodlebugVector[i].getY()); // removes ant from the ants vector and resets doodlebug's timeToEat
        }
        else
        {
            // check if time to eat or breed
            // if (doodlebugVector[i].getTimeToEat() == 0)
            // {
            //     doodlebugVector[i].die(positions, doodlebugVector);
            // }
            // else
            // {
            // // if (doodlebugVector[i].getTimeToBreed() == 1)
            // // {
            // //     // check if there is space above, below, left, right; if so, breed new thing in that space
            // //     int space = doodlebugVector[i].checkForAdjacentSpace(positions); // find new cell for adjacent doodlebug and breed if there is
            // //     Doodlebug newDoodlebug;
            // //     switch (space)
            // //     {
            // //     case 0:
            // //         newDoodlebug = doodlebugVector[i].breed(doodlebugVector[i].getX() + 1, doodlebugVector[i].getY());
            // //         newDoodlebugs.push_back(newDoodlebug);
            // //         break;
            // //     case 1:
            // //         newDoodlebug = doodlebugVector[i].breed(doodlebugVector[i].getX() - 1, doodlebugVector[i].getY());
            // //         newDoodlebugs.push_back(newDoodlebug);
            // //         break;
            // //     case 2:
            // //         newDoodlebug = doodlebugVector[i].breed(doodlebugVector[i].getX(), doodlebugVector[i].getY() + 1);
            // //         newDoodlebugs.push_back(newDoodlebug);
            // //         break;
            // //     case 3:
            // //         newDoodlebug = doodlebugVector[i].breed(doodlebugVector[i].getX(), doodlebugVector[i].getY() - 1);
            // //         newDoodlebugs.push_back(newDoodlebug);
            // //         break;
            // //     case 4:
            // //         break;
            // //     }
            // }
            // else
            doodlebugVector[i].move(positions); // move if no offspring and no and to eat
        }
        doodlebugVector[i].updateTimetoBreed();
        doodlebugVector[i].setTimeToEat(doodlebugVector[i].getTimeToEat() - 1);
    }
}
// add the new doodlebugs to the list of doodlebugs for next turn's iteration
// for (int i = 0; i < newDoodlebugs.size(); i++)
//     doodlebugVector.push_back(newDoodlebugs[i]);
// }

bool Organism::checkForAdjacentSpace(int positions[20][20])
{
    int id = positions[x_coordinate][y_coordinate]; // figure out what kind of organism this is

    if (positions[x_coordinate + 1][y_coordinate] == FREE_SPACE) // space down
    {
        positions[x_coordinate + 1][y_coordinate] = id;
        return 0;
    }

    if (positions[x_coordinate - 1][y_coordinate] == FREE_SPACE) // space up
    {
        positions[x_coordinate - 1][y_coordinate] = id;
        return 1;
    }

    if (positions[x_coordinate][y_coordinate + 1] == FREE_SPACE) // space right
    {
        positions[x_coordinate][y_coordinate + 1] = id;
        return 2;
    }

    if (positions[x_coordinate][y_coordinate - 1] == FREE_SPACE) // space left
    {
        positions[x_coordinate][y_coordinate - 1] = id;
        return 3;
    }
    return 4; // no space
}

Doodlebug::Doodlebug(int x_coordinate, int y_coordinate) : Organism(x_coordinate, y_coordinate)
{
    timeToEat = 3;
    timeToBreed = 8;
    organismID = 1;
} // creates doodlebug object and assoc. data

Doodlebug::Doodlebug() : Organism()
{
    timeToEat = 3;
    timeToBreed = 8;
    organismID = 1;
}

Organism::Organism()
{
    // blank
}

bool Doodlebug::checkForAdjacentAnt(int positions[20][20]) // checks for adjacent ant and moves into that space if there is one
{
    if (positions[x_coordinate + 1][y_coordinate] == ANT)
    {
        positions[x_coordinate][y_coordinate] = FREE_SPACE; // update doodlebug's old position to be freespace
        positions[x_coordinate + 1][y_coordinate] = DOODLEBUG;

        this->x_coordinate = x_coordinate + 1;
        this->y_coordinate = y_coordinate;
        return true;
    }

    if (positions[x_coordinate - 1][y_coordinate] == ANT)
    {
        positions[x_coordinate][y_coordinate] = FREE_SPACE; // update doodlebug's old position to be freespace
        positions[x_coordinate - 1][y_coordinate] = DOODLEBUG;
        this->x_coordinate = x_coordinate - 1;
        this->y_coordinate = y_coordinate;
        return true;
    }

    if (positions[x_coordinate][y_coordinate + 1] == ANT)
    {
        positions[x_coordinate][y_coordinate] = FREE_SPACE; // update doodlebug's old position to be freespace
        positions[x_coordinate][y_coordinate + 1] = DOODLEBUG;
        this->x_coordinate = x_coordinate;
        this->y_coordinate = y_coordinate + 1;
        return true;
    }

    if (positions[x_coordinate][y_coordinate - 1] == ANT)
    {
        positions[x_coordinate][y_coordinate] = FREE_SPACE; // update doodlebug's old position to be freespace
        positions[x_coordinate][y_coordinate - 1] = DOODLEBUG;
        this->x_coordinate = x_coordinate;
        this->y_coordinate = y_coordinate - 1;
        return true;
    }

    return false;
}

// updates doodlebug's time to eat back to 3, eliminates the ant from the antsVector
void Doodlebug::eat(vector<Ant> antsVector, int x, int y)
{
    this->setTimeToEat(3);
    for (int i = 0; i < antsVector.size(); i++)
    {
        if (antsVector[i].getX() == x && antsVector[i].getY() == y)
        {
            antsVector.erase(antsVector.begin() + i); // remove the ant from the vector
        }
    }
}

void Doodlebug::die(int positions[20][20], vector<Doodlebug> &doodlebugVector)
{
    // update gameboard positions with old doodlebug as freespace
    positions[this->getX()][this->getY()] = FREE_SPACE;

    // remove doodlebug from doodlebug vector
    for (int i = 0; i < doodlebugVector.size(); i++)
    {
        if (doodlebugVector[i].getX() == this->getX() && doodlebugVector[i].getY() == this->getY())
        {
            doodlebugVector.erase(doodlebugVector.begin() + i); // remove the doodlebug from the vector
        }
    }
}

void Organism::move(int positions[20][20])
{
    // Checks random adjacent space for emptiness and moves there if empty
    int x = this->getX();
    int y = this->getY();

    int currOrganism = positions[x][y]; // what is the currOrganism, doodlebug or ant?

    int randNum = rand() % 4;

    switch (randNum)
    {
    case 0: // move up
        if (positions[x - 1][y] == FREE_SPACE)
        {
            positions[x][y] = FREE_SPACE;
            this->x_coordinate = x - 1;
            this->y_coordinate = y;
            positions[x - 1][y] = currOrganism;
        }
        break;

    case 1: // move down
        if (positions[x + 1][y] == FREE_SPACE)
        {
            positions[x][y] = FREE_SPACE;
            this->x_coordinate = x + 1;
            this->y_coordinate = y;
            positions[x + 1][y] = currOrganism;
        }
        break;
    case 2: // move left
        if (positions[x][y - 1] == FREE_SPACE)
        {
            positions[x][y] = FREE_SPACE;
            this->x_coordinate = x;
            this->y_coordinate = y - 1;
            positions[x][y - 1] = currOrganism;
        }
        break;

    case 3: // move right
        if (positions[x][y + 1] == FREE_SPACE)
        {
            positions[x][y] = FREE_SPACE;
            this->x_coordinate = x;
            this->y_coordinate = y + 1;
            positions[x][y + 1] = currOrganism;
        }
        break;
    }
}

Doodlebug Doodlebug::breed(int x, int y)
{
    Doodlebug newDoodlebug(x, y);
    return newDoodlebug;
}