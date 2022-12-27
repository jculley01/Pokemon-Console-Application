# Pokemon-Console-Application

## How to Run
To run this console application pull all of the header files along with their corresponding cpp files and then use the main file to run the game

## Project Details
This project was constructed using C++ and MVC structure and most of the functionality for the game was done using object oriented programming concepts. The game objects were constructed using inheritance by creating parent classes of Building and GameObject which then allowed for a seamless integration of of different buildings such as the PokemonCenter and the PokemonGym. To make the development of the project more efficient, polymorphism was used to overload operators for the Point2D and Vector2D which needed to be added, multiplied, and outputted in later steps of development. To handle errors for inputs, exceptions were used to ensure that the game would not crash. The MVC structure for the game was essential because as the user continues to make commands, the game objects and the game board need to be dynamically updated as well.

## Game Commands
m (trainernum) x y : move command - enter m followed by the trainer number you want moved and then the x and y coordinates of where you want to move

c (trainernum) (centernum) : move to center - enter c followed by the trainer number and then the center number to set destination of a center

g (trainernum) (gymnum) : move to gym - enter g followed by the trainer number and then the gym number to set destination of a gym

p (trainernum) (numofpotions) : heal command - enter p followed by the trainer number and then the number of potions you want to buy

b (trainernum) (numofbattles) : battle command - enter b followed by the trainer number and then the number of battles you want to do

s : stop command - enter s to stop the current action

a : advance command - this command moves forward one time unit

r : run command - this command moves forward five time units

q : quit command - this command ends the game

n (type) (id) x y : new object command - enter n followed by and of the objects and then specify an id number and a location to add a new object onto the board (ex. n c 3 5 5 will build a new PokemonCenter with the id of 3 and place it at (5,5) on the grid)



