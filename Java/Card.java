
/*
 * Victor Hugo Erminpour
 * Card.java
 */

import java.util.*;

public class Card implements java.lang.Comparable, Cloneable {

  public enum Suit { DIAMONDS, HEARTS, SPADES, CLUBS }
  public enum Number { Two, Three, Four, Five, Six,
                       Seven, Eight, Nine, Ten, Jack, 
                       Queen, King, Ace }

  public Suit suit;
  public Number number;

  // Constructor()
  public Card(Suit suit, Number number) {
        this.suit = suit;
        this.number = number;
  }

  // getNumber()
  public Number getNumber() {
    return number;
  }

  // getSuit()
  public Suit getSuit() {
    return suit;
  }

  // toString()
  public String toString() {
    return (number + " of " + suit);
  }

  // equals()
  public boolean equals(Object o) {
	  Card card = (Card) o;
	  if (card.suit.ordinal() == this.suit.ordinal() &&
        card.number.ordinal() == this.number.ordinal()) {
	    return (true);
    }
    else {
      return (false);
    }
  }

  // clone()
  public Object clone() {
    try {
      return(super.clone());
    }
    catch(CloneNotSupportedException cnse){
      return null;
    }
  }

  // compareTo()
  public int compareTo(Object object) {
    Card card = (Card) object;
    if(card.suit.ordinal() < this.suit.ordinal())
      return 1;
    else
      return 0;
 
  }
}

