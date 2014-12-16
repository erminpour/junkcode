
/*
 * Victor Hugo Erminpour
 * Deck.java
 */

import java.util.*;

public class Deck {

  private Card deck[] = new Card[52];
  private int deckPointer = 0;

  Deck() {
    /* init deck */
    int i = 0;
    for (Card.Suit suit : Card.Suit.values()) {
      for (Card.Number number : Card.Number.values()) {
        deck[i] = new Card(suit, number);
        i++;
      }
    }
  }
  public void sort() {
    Arrays.sort(deck);
  }
  public void shuffle() {
    Collections.shuffle(Arrays.asList(deck));
  }

  public Card[] deal(int n) {
    Card cards[] = new Card[n];
    if((this.deckPointer + n) >= 51){
      this.shuffle();
      this.deckPointer = 0;
    }
    for(int i=0; i< n; i++)
      cards[i] = deck[deckPointer++];
    return cards;
  }

  public String toString() {
    String result = "";
    for (int i=0; i<this.deck.length; i++)
      result = result + this.deck[i] + "\n";
  return result;
  }

  public static void main(String[] args) {
    Deck myDeck = new Deck();

    System.out.println(myDeck);
    myDeck.shuffle();
    System.out.println(myDeck);
  }
}

