// COMSC-210 | Lab 19 | Mira Anand
// Module 6, Lesson: Linked Lists, Assignment: Abstract & Automate
// IDE used: Visual Studio Code for Mac

// The program trusts that the user has the external input file is structured exactly the way I have created it
// Please open input file to see specific format to follow

#include <cstdlib> // needed to generate random number
#include <ctime> // needed to generate random number
#include <fstream> // to be able to read data from an external .txt file
#include <iomanip> // to use setprecision()
#include <iostream>
#include <string>
#include <vector> // to use STD::vector, my container of choice for this assignment
using namespace std;

// creation of Movie Class
class Movie
{
    // private member variables
    private:
        struct ReviewNode // creation of a struct named "Review", for linked list development
        {
            double rating; // to store a movie rating
            string comment; // to store a movie review comment
            ReviewNode *next; // points to next node
        };
        string title; // to store a movie title
        ReviewNode *head; // pointer to head of the linked list
    
    // public member functions
    public:
        // creation of a partial constructor, Movie(string movieTitle)
        // inline, since it is 1 line
        // DESCRIPTION: this partial constructor initializes "title" by parameter and initializes "head" to nullptr
        // ARGUMENTS: string movieTitle, represents the title of the movie
        // RETURNS: no return type
        Movie(string movieTitle)            { title = movieTitle; head = nullptr; }

        // setters, inline since it is 1 line
        // void setTitle(string movieTitle) function header
        // DESCRIPTION: this function will "set" the movie titles for each Movie object
        // ARGUMENTS: string movieTitle, represents the title of the movie
        // RETURNS: nothing, void function
        void setTitle(string movieTitle)    { title = movieTitle; }

        // getters, inline since it is 1 line
        // string getTitle() const function header
        // DESCRIPTION: this function will "get" the movie titles for each Movie object after they are "set"
        // ARGUMENTS: no arguments/parameters
        // RETURNS: the string movie title for each movie
        // adding a trailing const, since getters do not change an object's data
        string getTitle() const             { return title; }

        // creating first member method
        // void addNodeToHead(double movieRating, string movieComment) function header
        // DESCRIPTION: this function will create a new node, set the value of the new node, and add this new node to the front (head) of the list
        // ARGUMENTS: double movieRating, which represents the movie rating being added
        // - string movieComment, which represents the movie comment being added
        // RETURNS: nothing, void function
        void addNodeToHead(double movieRating, string movieComment)
        {
            ReviewNode *newNode = new ReviewNode; // create a new node
            newNode->rating = movieRating; // set movie rating of new node
            newNode->comment = movieComment; // set movie comment of new node

            if (!head) // if linked list is empty
            {
                head = newNode; // make newNode the head
                newNode->next = nullptr; // next node after newNode should be set to nullptr
            }
            else // if linked list is NOT empty
            {
                newNode->next = head; // next will now point to list's 1st node
                head = newNode; // head points to newNode
            }
        }

        // creating second member method
        // void print() function header
        // DESCRIPTION: this function will check if the linked list is empty or not. The contents of the linked list will be neatly outputted to the console
        // - if there are no contents, the user will be notified with a console message and the program will exit
        // ARGUMENTS: no arguments/parameters
        // RETURNS: nothing, void function
        void print()
        {
            if (!head) // if linked list is empty
            {
                cout << "The linked list is empty." << endl;
                cout << "Now exiting program..." << endl;
                return; // exit the function
            }

            int reviewer = 1; // to keep a count/track of the number of human reviewers for each movie
            ReviewNode *current = head; // used to start at the beginning of the list and traverse

            // traverse the list and display its contents 
            cout << "Outputting reviews for all movies..." << endl << endl;
            cout << "Here are the reviews (movie ratings and comments) for " << title << ":" << endl;
            while (current)
            {
                cout << "Reviewer #" << reviewer++ << " rating: "; 
                cout << fixed << setprecision(1) << current->rating << ", "; // rating should be 1 decimal place
                cout << "Reviewer comment: " << current->comment << endl;

                current = current->next; // move to next node
            }
        }

        // creating third member method
        // void deleteList() function header
        // DESCRIPTION: this function will traverse the list (visit each node) and delete each node
        // - clean up linked list to avoid memory leaks, for good housekeeping
        // ARGUMENTS: no arguments/parameters
        // RETURNS: nothing, void function
        void deleteList()
        {
            ReviewNode *current = head; // set current to head of list
            while (current) // traverse the list, visit each node
            {
                head = current->next; // head is set to next node
                delete current; // delete node
                current = head; // current is set to head again
            }

            head = nullptr; // indicates an empty list
        }
};

int main()
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for movie rating

    vector<Movie> reviews; // creation of an STD::vector container to hold multiple Movie objects
    string singleInputFileLine; // declaring a string variable to hold each line encountered in the input file
    double rating; // to hold a random movie rating (1.0 - 5.0)

    // declaration and initialization of a string variable that holds the name of the input file to read data from
    string inputFile = "movieReviewInfo.txt";
    // creation of an ifsteam (input file) object
    ifstream fin;
    // open the input file
    fin.open(inputFile);

    // the if condition checks if the input file opened correctly
    if (fin.good())
    {
        while (getline(fin, singleInputFileLine)) // while loop used to read the movie title, which is the 1st line in the input file
        {
            Movie newNode(singleInputFileLine); // creation of a Movie object

            while (getline(fin, singleInputFileLine)) // another while loop used to read the movie review comments
            {
                if (singleInputFileLine.empty()) // if a blank line is encountered, we have reached the end of the review comments for this movie
                {
                    break;
                }

                // rating will be a double, within the range of 1.0 - 5.0
                rating = (rand() % 41 + 10) / 10.0; // rand() % 41 = 0 - 40, + 10 = 10 - 50, / 10.0 = 1.0 - 5.0 
                newNode.addNodeToHead(rating, singleInputFileLine);
            }

            reviews.push_back(newNode);
        }

        fin.close(); // Close the input file
    }
    // if the input file did not open correctly, execute "else"
    else
    {
        cout << "ERROR: Could not open input file. Please make sure the file exists in the correct location and try running the program again." << endl;
        cout << "Program will now exit..." << endl;
        return 1; // return an error state
    }
    
    return 0;
}