// COMSC-210 | Lab 19 | Mira Anand
// Module 6, Lesson: Linked Lists, Assignment: Abstract & Automate
// IDE used: Visual Studio Code for Mac

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
        // RETURNS:
        void setTitle(string movieTitle)    { title = movieTitle; }

        // getters, inline since it is 1 line
        // function header
        // DESCRIPTION:
        // ARGUMENTS:
        // RETURNS:
        string getTitle() const             { return title; }

        // creating first member method
        // function header
        // DESCRIPTION:
        // ARGUMENTS:
        // RETURNS:
        void addNodeToHead(double movierating, string movieComment)
        {
            ReviewNode *newNode = new ReviewNode; // create a new node
            newNode->rating = movierating; // set movie rating of new node
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
};

int main()
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for movie rating
    
    return 0;
}