/* ---------------------------------------------
Program 1: Wumpus with Dynamic sized array *

Course: CS 211, Fall 2022. Tues 4pm lab
System: Mac using Visual Studio Code
Author: Ali Saeed
---------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//The purpose of this function is to print the game layout/maze. It has no parameter because we're not changing anything to any varible. 
//returns void since there is nothing to return.
void printMaze(){
  printf("\n       ______18______             \n");
  printf("      /      |       \\           \n");
  printf("     /      _9__      \\          \n");
  printf("    /      /    \\      \\        \n");
  printf("   /      /      \\      \\       \n");
  printf("  17     8        10     19       \n");
  printf("  | \\   / \\      /  \\   / |    \n");
  printf("  |  \\ /   \\    /    \\ /  |    \n");
  printf("  |   7     1---2     11  |       \n");
  printf("  |   |    /     \\    |   |      \n");
  printf("  |   6----5     3---12   |       \n");
  printf("  |   |     \\   /     |   |      \n");
  printf("  |   \\       4      /    |      \n");
  printf("  |    \\      |     /     |      \n");
  printf("  \\     15---14---13     /       \n");
  printf("   \\   /            \\   /       \n");
  printf("    \\ /              \\ /        \n");
  printf("    16---------------20           \n");
  printf("\n");
}

// Function prints out the dircetions of the game with a picture of the layout. Has No parameters and returns void.
void dircetionsOfGame() {
    printMaze();
    printf("Hunt the Wumpus:                                             \n");
    printf("The Wumpus lives in a completely dark cave of 20 rooms. Each \n");
    printf("room has 3 tunnels leading to other rooms.                   ");
    printf("\n                                                             ");
    printf("\nHazards:                                                     \n");
    printf("1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n");
    printf("2. Two other rooms have super-bats.  If you go there, the bats grab you and     \n");     	
    printf("   fly you to some random room, which could be troublesome.  Then those bats go \n"); 	
    printf("   to a new room different from where they came from and from the other bats.   \n");
    printf("3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and    \n");    	
    printf("   is too heavy for bats to lift.  Usually he is asleep.  Two things wake       \n");       	
    printf("    him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus   \n");   	
    printf("    will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n");	
    printf("    When you move into the Wumpus' room, then he wakes and moves if he is in an \n"); 	
    printf("    odd-numbered room, but stays still otherwise.  After that, if he is in your \n"); 	
    printf("    room, he snaps your neck and you die!                                       \n");
    printf("                                                                                \n");
    printf("Moves:                                                                          \n");
    printf("On each move you can do the following, where input can be upper or lower-case:  \n");
    printf("1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n");
    printf("   then a room number.                                                          \n");
    printf("2. Shoot your guided arrow through a list of up to three adjacent rooms, which  \n");  	
    printf("   you specify.  Your arrow ends up in the final room.                          \n");                          	
    printf("   To shoot enter 'S' followed by the number of rooms (1..3), and then the      \n");      	
    printf("   list of the desired number (up to 3) of adjacent room numbers, separated     \n");     	
    printf("   by spaces. If an arrow can't go a direction because there is no connecting   \n");   	
    printf("   tunnel, it ricochets and moves to the lowest-numbered adjacent room and      \n");      	
    printf("   continues doing this until it has traveled the designated number of rooms.   \n");   	
    printf("   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You  \n");  	
    printf("   automatically pick up the arrow if you go through a room with the arrow in   \n");   	
    printf("   it.                                                                          \n");
    printf("3. Enter 'R' to reset the person and hazard locations, useful for testing.      \n");
    printf("4. Enter 'C' to cheat and display current board positions.                      \n");
    printf("5. Enter 'D' to display this set of instructions.                               \n");
    printf("6. Enter 'P' to print the maze room layout.                                     \n");
    printf("7. Enter 'X' to exit the game.                                                  \n");
    printf("                                                                                \n");
    printf("Good luck!                                                                      \n");
    printf(" \n");
    printf("\n");
}

// this function lets you reset the components of the game and give each components a new values. It takes all the varible that we want to change as reference parameters
//returns void.  because we are not returning a value but just changing the positions of the pieces.
void reseting(int *player ,int *wumpus ,int *pit1 ,int *pit2, int *bat1,int *bat2, int *arrow){
    
    int newPlayerLocation;
    int newWumpusLocation;
    int newPit1Location;
    int newPit2Location;
    int newBat1Location;
    int newBat2Location;
    int newArrowLocation;

    printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow:\n");
    scanf(" %d  %d  %d  %d %d %d %d", &newPlayerLocation, &newWumpusLocation, &newPit1Location, &newPit2Location, &newBat1Location, &newBat2Location, &newArrowLocation);
    
    *arrow = newArrowLocation;
    *player = newPlayerLocation;
    *wumpus = newWumpusLocation;
    *pit1 = newPit1Location;
    *pit2 = newPit2Location;
    *bat1 = newBat1Location;
    *bat2 = newBat2Location;
    printf("\n");
}

// for this function it prints out where all the components of the games are in the maze. It takes in all the game componenets of the game such as player,wumpus,pit1,2 and bat 1,2 and arrow
//returns void since we're not really changing anything
void cheating(int wumpus ,int player ,int pit1 ,int pit2, int bat1, int bat2, int arrow) {
  
  printf("Cheating! Game elements are in the following rooms: \n");
  printf("Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n");
  printf("   %d     %d     %d    %d    %d    %d    %d \n", player, wumpus, pit1, pit2, bat1, bat2, arrow);
  printf("\n");
  
}

// this function lets the player move through the rooms and then checks the rooms that are adjecant to the room player is in and gives you the option of moving through only those rooms. if player doesn't pick one of those adjenct rooms then it prints a message letting player know its an invalid move. This function takes in player, the rooms array to locate the room to move to, and the number of moves made.
//returns void since we're not returning anything.
void moving(int* player, int **rooms, int *numberOfMoves){
  
  int roomNum;
  int room = *player - 1;
  int adjacent1;
  int adjacent2;
  int adjacent3;
  
  adjacent1 = rooms[room][0];
  adjacent2 = rooms[room][1];
  adjacent3 = rooms[room][2];
  
  scanf(" %d", &roomNum);
  
  if(roomNum == adjacent1){
    *player = roomNum;
    *numberOfMoves += 1;
  }
  else if (roomNum == adjacent2){
    *player = roomNum;
    *numberOfMoves += 1;
  }
  else if (roomNum == adjacent3){
    *player = roomNum;
    *numberOfMoves += 1;
  }
  else{
    printf("Invalid move.  Please retry.\n");
  }
}
    
// lets user enter a number and then checks if it matches the room number of the wumpus. if it does then you win, if not then you lose. Takes in wumpus as the parameter since we're checking if the room guess was the wumpus room.
//returns void 
void guessing(int wumpus){
  int guess;

  printf("Enter room (1..20) you think Wumpus is in: ");
  scanf(" %d", &guess);

  if(guess == wumpus){
    printf("You won!\n");
  }
  else{
    printf("You lost.\n");
  }
}

//this function checks to see if there are any hazards in the adjancet room of the player. If there is a hazard it prints a message. This function takes in player and all the hazards that are in the game, That is to check if player is adjacent to the hazards rooms. 
//returns void
void adjacetRooms(int player,int **rooms,int wumpus, int pit1, int pit2, int bat1, int bat2) {

    int adjacent1 = rooms[player - 1][0];
    int adjacent2 = rooms[player - 1][1];
    int adjacent3 = rooms[player - 1][2];
    
    if (wumpus == adjacent1 || wumpus == adjacent2 || wumpus == adjacent3){
      printf("You smell a stench. ");
    }
    if (pit1 == adjacent1 || pit1 == adjacent2 || pit1== adjacent3){
        printf("You feel a draft. ");
    }
    if (pit2 == adjacent1 || pit2 == adjacent2 || pit2 == adjacent3 ){
      printf("You feel a draft. ");
    }
    if (bat1 == adjacent1 || bat1 == adjacent2 || bat1 == adjacent3){
        printf("You hear rustling of bat wings. ");
    }
    if (bat2 == adjacent1 || bat2 == adjacent2 || bat2 == adjacent3){
        printf("You hear rustling of bat wings. ");
    }
      
}

// checks when the player moves and if player lands on the pits it prints out the message and exists the game. Takes in player, wumpus to check if wumpus killed player, the two pits to check if player fell into the pits, rooms of the game, both bat1 and 2 which would make player tranport to different rooms, and lastly arrow which if picked up then the value of arrow is -1.
//returns an int which decides if the game is over or not.
int playerEnteringHazard(int *player,int *wumpus,int *pit1, int *pit2, int **rooms, int *bat1, int *bat2, int *arrow) {
  int oldPlayer,  oldBat1, oldBat2;

  if (*player == *wumpus) {
      //checking to see if player entered an even numbered room with the wumpus in ti and if player did then the message is printed and the player dies
      if(*wumpus == 2 || *wumpus == 4 || *wumpus == 6 || *wumpus == 8 || *wumpus == 10 || *wumpus == 12 || *wumpus == 14 || *wumpus == 16 || *wumpus == 18 || *wumpus == 20) {
          printf("You briefly feel a slimy tentacled arm as your neck is snapped.\nIt is over.\n");
          return 1;
      }
      //this contation statment checks if the player enter an odd number room with a wumpus, if player did, then it prints a message and the wumpus slithers to the lowwer numbered adjancet room
      else if (*wumpus == 1 || *wumpus == 3 || *wumpus == 5 || *wumpus == 7 || *wumpus == 9 || *wumpus == 11 || *wumpus == 13 || *wumpus == 15 || *wumpus == 17 || *wumpus == 19) {
          printf("You hear a slithering sound, as the Wumpus slips away. \nWhew, that was close!\n");
            *wumpus = rooms[*wumpus - 1][0];
      }
  }
  else if (*player == *pit1 || *player == *pit2) {
      printf("Aaaaaaaaahhhhhh....\n    You fall into a pit and die.\n");
      return 1;
  }
  else if (*player == *bat1) {
    oldPlayer = *player;
    oldBat1 = *bat1;
    *player = rand() % 20 + 1;
    while(oldPlayer == *player){
      *player = rand() % 20 + 1;
    }
    *bat1 = rand() % 20 + 1;
    printf ("Woah... you're flying! \nYou've just been transported by bats to room %d.\n", *player);
    while(*bat1 == *player || *bat1 == *bat2 || *bat1 == oldBat1){
      *bat1 = rand() % 20 + 1;
    }
  }
  else if (*player == *bat2){
    oldPlayer = *player;
    oldBat2 = *bat2;
    *player = rand() % 20 + 1;
    while(oldPlayer == *player){
      *player = rand() % 20 + 1;
    }
    *bat2 = rand() % 20 + 1;
    printf ("Woah... you're flying! \nYou've just been transported by bats to room %d.\n", *player);
    while(*bat2 == *player || *bat2 == *bat1 || *bat2 == oldBat2) {
      *bat2 = rand() % 20 + 1;
    }
    
  }
  else if(*player == *arrow){
      printf("Congratulations, you found the arrow and can once again shoot.\n");
      *arrow = -1;
  }

  return 0;
}
// This function makes sure that all the compenents of the game are not equal to eachother. Takes in seven integer variables which are the number of compenents with the firat parament the varible we are trying to compare to the rest. If the component variable is the same to another component then we change the variable of that component.
void allRoomsRandom(int *component, int component2,int component3,int component4,int component5,int component6, int component7) {
  *component = rand() % 20 + 1;
  while(*component == component2 || *component == component3 || *component == component4 || *component == component5 || *component == component6 || *component == component7) { 
    *component = rand() % 20 + 1;
  }
}
// This functions gives all the game components different random rooms. Takes in the player, wumpus, pit 1 and 2, bat 1 and 2, and the arrow. 
//returns void since we're already changing the varible by passing by reference.
void randomizeRooms(int *player, int *wumpus, int *pit1, int *pit2, int *bat1, int *bat2, int *arrow) {
  
  *player = 0;
  *wumpus = 0;
  *pit1 = 0;
  *pit2 = 0;
  *bat1 = 0;
  *bat2 = 0;
  *arrow = 0;

  //making sure none of the componeents are the same
  allRoomsRandom(player, *wumpus, *pit1, *pit2, *bat1, *bat2, *arrow);
  allRoomsRandom(wumpus, *player, *pit1, *pit2, *bat1, *bat2, *arrow);
  allRoomsRandom(pit1, *wumpus, *player, *pit2, *bat1, *bat2, *arrow);
  allRoomsRandom(pit2, *wumpus, *pit1, *player, *bat1, *bat2, *arrow);
  allRoomsRandom(bat1, *wumpus, *pit1, *pit2, *player, *bat2, *arrow);
  allRoomsRandom(bat2, *wumpus, *pit1, *pit2, *bat1, *player, *arrow);
  allRoomsRandom(arrow, *wumpus, *pit1, *pit2, *bat1, *bat2, *player);
}
// this function is a helper function to the function shooting. Its only called when player has an arrow and wants to shoot through only one room. Takes in player, arrow to ajdust to its new location, rooms, and wumpus which is if arrow hits wumpus.
// Returns an int indcatinmg if arrow hit wumpus.
int shootingOnce(int *player, int *arrow, int **rooms, int *wumpus) {
  int roomPicked1;

  scanf(" %d", &roomPicked1);
  if(roomPicked1 == rooms[*player-1][0] || roomPicked1 == rooms[*player-1][1] || roomPicked1 == rooms[*player-1][2] || roomPicked1 == *player) {

    if(roomPicked1 == *wumpus) {
      printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
      return 1;
    }
    else {
      *wumpus = rooms[*wumpus - 1][0];
      *arrow = roomPicked1;
    }
  }
  else {
    printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked1);
    roomPicked1 = rooms[*player-1][0];
    if(roomPicked1 == *wumpus) {
      printf("Your arrow ricochet killed the Wumpus, you lucky dog!\nAccidental victory, but still you win!\n");
      return 1;
    }
    else {
      *wumpus = rooms[*wumpus - 1][0];
      *arrow = roomPicked1;
    }
  }
  
  return 0;
}

// this function is a helper function to the function shooting. Its only called when player has an arrow and wants to shoot through two rooms. Takes in player, arrow to ajdust to its new location, rooms, and wumpus which is if arrow hits wumpus.
// Returns an int indicating if arrow hits wumpus or player.
int shootingTwice(int *player, int *arrow, int **rooms, int *wumpus) {

  int roomPicked1, roomPicked2;

  scanf(" %d %d", &roomPicked1, &roomPicked2);
  // checks if the room to shot at is adjacent to the player. else, arrow ricochets to lowest adjecant room of player.
  if(roomPicked1 == rooms[*player-1][0] || roomPicked1 == rooms[*player-1][1] || roomPicked1 == rooms[*player-1][2] || roomPicked1 == *player) {

    if(roomPicked1 == *wumpus) {
      printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
      return 1;
    }
  }
  else {
    printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked1);
    roomPicked1 = rooms[*player-1][0];
  }
  // checks if the room to shot at is adjacent to the the first room arrow went to. else, arrow ricochets to lowest adjecant room of the fist arrow shot.
  if(roomPicked2 == rooms[roomPicked1 - 1][0] || roomPicked2 == rooms[roomPicked1 - 1][1] || roomPicked2 == rooms[roomPicked1 - 1][2]) {
      if(roomPicked2 == *wumpus){
        printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
        return 1;
      }
      // if player chooses his own room to shoot at.
      if (roomPicked2 == *player) {
        printf("You just shot yourself.\nMaybe Darwin was right. You're dead.\n");
        return 1;
      }
      else {
        *wumpus = rooms[*wumpus - 1][0];
        *arrow = roomPicked2;
      }
  }
  else {
      printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked2);
      roomPicked2 = rooms[roomPicked1 - 1][0];
      if(roomPicked2 == *wumpus) {
          printf("Your arrow ricochet killed the Wumpus, you lucky dog!\nAccidental victory, but still you win!\n");
          return 1;
      }
      else if (roomPicked2 == *player){
          printf("You just shot yourself, and are dying.\nIt didn't take long, you're dead.\n");
          return 1;
      }
      else {
          *wumpus = rooms[*wumpus - 1][0];
          *arrow = roomPicked2;
      }
  }
  return 0;
}

// this function is a helper function to the function shooting. Its only called when player has an arrow and wants to shoot through three rooms. Takes in player, arrow to ajdust to its new location, rooms, and wumpus which is if arrow hits wumpus.
// Returns an int indicating if arrow hits wumpus or player.
int shootingThrice(int *player, int *arrow, int **rooms,int *wumpus) {
  int roomPicked1, roomPicked2, roomPicked3;
  // user enters the rooms to shoot at.
  scanf(" %d %d %d", &roomPicked1 , &roomPicked2, &roomPicked3);
  // this checks the 2nd arrow projectory.
  if(roomPicked1 == rooms[*player-1][0] || roomPicked1 == rooms[*player-1][1] || roomPicked1 == rooms[*player-1][2] || roomPicked1 == *player) {          
    if(roomPicked1 == *wumpus){
      printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
      return 1;
    }
  }
  else {
    printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked1);
    roomPicked1 = rooms[*player-1][0];
  }
  // this checks the 2nd arrow projectory.
  if(roomPicked2 == rooms[roomPicked1 - 1][0] || roomPicked2 == rooms[roomPicked1 - 1][1] || roomPicked2 == rooms[roomPicked1 - 1][2]) {
    if(roomPicked2 == *wumpus){
      printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
      return 1;
    }
    if (roomPicked2 == *player) {
      printf("	You just shot yourself.\nMaybe Darwin was right. You're dead.");
      return 1;
    }
  }
  else {
    printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked2);
    roomPicked2 = rooms[roomPicked1 - 1][0];
    if(roomPicked3 == *wumpus) {
      printf("Your arrow ricochet killed the Wumpus, you lucky dog!\nAccidental victory, but still you win!\n");
      return 1;
    }
  }
  if(roomPicked3 == rooms[roomPicked2 - 1][0] || roomPicked3 == rooms[roomPicked2 - 1][1] || roomPicked3 == rooms[roomPicked2 - 1][2]) {
      if(roomPicked3 == *wumpus){
        printf("Wumpus has just been pierced by your deadly arrow! \nCongratulations on your victory, you awesome hunter you.\n");
        return 1;
      }
      else {
        *wumpus = rooms[*wumpus - 1][0];
        *arrow = roomPicked3;
      }
  }
  else {
    printf("Room %d is not adjacent. Arrow ricochets...\n", roomPicked3);
    roomPicked3 = rooms[roomPicked2 - 1][0];
    if(roomPicked3 == *wumpus) {
      printf("Your arrow ricochet killed the Wumpus, you lucky dog!\nAccidental victory, but still you win!\n");
      return 1;
    }
    else {
      *wumpus = rooms[*wumpus - 1][0];
      *arrow = roomPicked3;
    }
  }
return 0;
}

// This is the shooting function where if arrow is -1 then player has a chance to shoot the arrow and try to kill the wumpus which would end the game. Also player can accidentally hit his own which would cause him to die and end the game. takes in player, arrow, rooms, and wumpus.
// Returns an int indicating if arrow hits wumpus or player.
int shooting(int *player, int *arrow, int **rooms, int *wumpus, int *move) {
  int numOfRooms;
  int shot = 0;

  if(*arrow != -1){
    printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
    *move += 1;
    return 0;
  }
    
  printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
  scanf(" %d", &numOfRooms);

  if(numOfRooms == 1){
    shot = shootingOnce(&*player, &*arrow, &*rooms,&*wumpus);
    *move += 1;
  }
  else if(numOfRooms == 2) {
    shot = shootingTwice(&*player, &*arrow, &*rooms,&*wumpus);
    *move += 1;
  }
  else if(numOfRooms == 3) {
    shot = shootingThrice(&*player, &*arrow, &*rooms,&*wumpus);
    *move += 1;
  }

return shot;
}

// this struct stores the room of all the compopents of the game pieces.
struct GamePieces{

    int player;
    int wumpus;
    int pit1;
    int pit2;
    int bat1;
    int bat2;
    int arrow;

};

int main() {
  srand(1);
  int **rooms = NULL;
  int roomAsArray[20][3] = {{2,5,8}, {1,3,10},{2,4,12}, {3,5,14}, {1,4,6}, {5,7,15}, {6,8,17}, {1,7,9}, {8,10,18}, {2,9,11}, {10,12,19}, {3,11,13}, {12,14,20}, {4,13,15}, {6,14,16}, {15,17,20}, {7,16,18},{9,17,19}, {11,18,20}, {13,16,19}};
  struct GamePieces piece;
  char choice;
  int countOfMoves = 1, gamesOver = 0;
  // this allocates 20 rooms to the pointer and then for wach room we allocate 3 more rooms. Then we assign the Fixed array to the pointer.
  rooms = malloc(sizeof(int *) * 20);
  for(int i = 0; i < 20; i++) {
    rooms[i] = malloc(3 * sizeof(int));
    for (int j = 0; j < 3; j++) 
      rooms[i][j] = roomAsArray[i][j];
  }
  randomizeRooms(&piece.player, &piece.wumpus, &piece.pit1, &piece.pit2, &piece.bat1, &piece.bat2, &piece.arrow);
  do{
      printf("You are in room %d. ", piece.player);
      adjacetRooms(piece.player, rooms, piece.wumpus, piece.pit1, piece.pit2, piece.bat1, piece.bat2);
      printf("\n\n%d. Enter your move (or 'D' for directions): ", countOfMoves);
      scanf(" %c", &choice);
      
        if (toupper(choice) == 'M') {
            moving(&piece.player, rooms, &countOfMoves);
            gamesOver = playerEnteringHazard(&piece.player,&piece.wumpus,&piece.pit1, &piece.pit2, rooms, &piece.bat1, &piece.bat2, &piece.arrow);
            if(gamesOver == 1)
              break;
          }
        else if(toupper(choice) == 'P') {
            printMaze();
        } 
        else if (toupper(choice) == 'D') {
            dircetionsOfGame();
        }
        else if (toupper(choice) == 'R') {
            reseting(&piece.player, &piece.wumpus, &piece.pit1, &piece.pit2,  &piece.bat1, &piece.bat2, &piece.arrow);
        }
        else if (toupper(choice) == 'C') {
            cheating(piece.wumpus , piece.player , piece.pit1 , piece.pit2, piece.bat1, piece.bat2, piece.arrow);
        }
        else if (toupper(choice) == 'G') {
            guessing(piece.wumpus);
            break;
        }
        else if (toupper(choice) == 'S') {
            gamesOver = shooting(&piece.player, &piece.arrow, rooms, &piece.wumpus, &countOfMoves);
            if(gamesOver == 1)
              break;
        }
  } while (toupper(choice) !=  'X');
  printf("\nExiting Program ...\n");
  free(rooms);
  return 0;
}

