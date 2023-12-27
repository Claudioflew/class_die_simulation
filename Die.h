// Comment 1: although this is not a big project, we should include "include guard".
#ifndef DIE_H
#define DIE_H

class Die {
public:
  Die(int); // Comment 2: this is a constructor.

  // Comment 3: these are member function prototypes.
  void setSides(int);
  void roll();
  unsigned int getSides() const;
  unsigned int getValue() const;

// Comment 4: class object's attributes should be private, which means can only be accessed or modified through the class object member functions.
private:
  unsigned int numSides;
  unsigned int value;
};

#endif
