
/*
 * Victor Hugo Erminpour
 * Poker.java
 */

import java.util.*;
import java.io.*;

class Player {
  Card[] hand = new Card[5];

  Player(Card[] hand) {
    this.hand = (Card[]) hand.clone(); 
  }

  public void showHand() {
    for(Card c : this.hand)
      System.out.println(c);
  }

  public String getHandValue() {
    if(this.isPair() == true)
      return "Pair";
    return "Nothing";
  }

  public boolean isPair() {
    int counter = 0;
    Card[] tmpHand = (Card[]) this.hand.clone();

    //Loop through the values. Compare each value to all values
    //If exactly two matches are made - return true
    for(int x = 0; x < tmpHand.length; x++) {
        for(int y = 0; y < this.hand.length; y++) {
          if(tmpHand[x].equals(this.hand[y]))
            counter++;
          if(counter == 2)
            return true;
        }
      counter = 0;
    }
  return false;
  }
}

public class Poker {

  public static void main(String[] args) throws IOException {
    int numberOfPlayers;
    Deck myDeck = new Deck();

    System.out.print("Input number of players: ");
    BufferedReader consoleIn = 
                   new BufferedReader(new InputStreamReader(System.in));  
    String stringInt = consoleIn.readLine();  
    numberOfPlayers = Integer.parseInt(stringInt);  
    System.out.println("Number of players == " + numberOfPlayers);

    /* shuffle deck */
    System.out.print("Shuffling Deck...");
    myDeck.shuffle();
    System.out.println("OK");

    /* deal cards */
    System.out.print("Dealing cards...");
    Player[] players = new Player[numberOfPlayers];
    for(int i=0; i < players.length; i++)
      players[i] = new Player(myDeck.deal(5));
    System.out.println("OK");

    /* show player's hand and hand value */
    for(int i=0; i < players.length; i++) {
    System.out.println("");
    System.out.println("Player " + (i+1) + "'s hand: ");
    System.out.println("========================");
      players[i].showHand();
      System.out.println(players[i].getHandValue());
    }
  }
}

// NR: You don't get a chance to delegate much functionality between classes.
// That was kind of the point of the assignment.  But this isn't a bad start.

// Score: 7/10
