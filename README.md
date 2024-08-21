
# Project: Pacman - 🍪 CookieMaster 🍪 Game


## General Overview:
This project involves creating the Pacman game, named "CookieMaster."

## Objective and End of the Game:
The player's objective (as Pacman) is to consume all the cookies in each level without being caught by the demons. A level is successfully completed when all cookies on the screen are eaten, leading to the next level. The game continues as long as there are additional levels and the player has not been caught three times. The player has three lives. The game ends either after completing the last level or after the player is caught by a demon three times.

## Strict Adherence to OOP Principles:
This project places a strong emphasis on Object-Oriented Programming (OOP) principles to ensure high-quality, maintainable code. Each class is designed to have a single responsibility, following the principles of encapsulation, inheritance, and polymorphism.

## List of Created Files with Brief Descriptions:

- **Controller:** Encapsulates the entire program, including the `run` function that executes the entire program and all levels.
- **Level:** Manages each level, checks for victory conditions and collisions between the player and demons, and handles the display of the level.
- **Board:** Reads data from the file and prints it on the screen.
- **Object:** Base class for all objects, both moving and static.
  - **MovingObject:** Base class for all moving objects.
    - **Pacman:** Represents the player, Pacman.
    - **Demon:** Represents the demons. Two additional classes inherit from it:
      - **StupidDemon**
      - **SmartDemon**
  - **StaticObject:** Base class for all static objects.
    - **Wall**
    - **Cookie**
    - **Door**
    - **Key**
    - **Gift:** Base class for all types of gifts:
      - **LifeGift:** Adds life to Pacman (up to 3 lives).
      - **TimeGift:** Adds time.
      - **DemonFreezeGift:** Freezes demons for a limited time.
      - **SuperPacGift:** Transforms Pacman into Super Pacman, allowing him to pass through doors and not be eaten by demons for a limited time.
      - **EatDemonPacmanGift:** Allows Pacman to eat demons for a limited time.
- **Menu:** Displays the main menu with buttons.
- **Button:** Manages the menu buttons. There are three types of buttons:
  - **StartNewGame:** Starts a new game.
  - **Help:** Displays help and instructions for the game. Clicking it opens a new window with game instructions.
  - **Exit:** Exits the game.
- **InformationDisplay:** Manages the secondary menu that shows game data.
- **PacmanState:** Manages Pacman's state changes. All types of Pacman states inherit from this class.
  - **RegularState:** Regular Pacman state.
  - **SuperState:** Super Pacman state.
  - **EatDemonState:** State allowing Pacman to eat demons.
- **Subject:** Defines an entity that can be observed, such as Pacman.
- **Observer:** Defines an observer, which in this case is the Information Display.
- **Resources:** Contains all game resources, such as images, sounds, texts, etc.
- **Utilities:** Contains constants.

## Main Data Structures and Their Roles:
- `vector <unique_ptr<StaticObject>> m_statObjects`: For static objects.
- `vector <unique_ptr<Demon>> m_demons`: For demons.
- `unique_ptr<Pacman> m_player`: For Pacman.
- Additional vectors are used in the `Resources` class.

## Noteworthy Algorithms:
- Doors and keys are implemented such that each key has a corresponding door, and they share the same color.

## Design:
After selecting "Start New Game" in the main menu, the `Controller` starts a new game. It constructs a new level each time and manages all game levels. The new level is created in the `Level` class, which is responsible for the player's movements, demon movements, and all collisions (using Double Dispatch).

## Known Bugs:
None at the moment.

## Other Comments:
- Some levels are timed, while others are not.
- Music plays throughout the game, with specific tracks for victory and defeat.
- I used design patterns:
  - **Observer Pattern:** The entity being observed (Subject) and the observer (Observer).
  - **State Pattern:** Different states of Pacman.

I also used Double Dispatch for handling collisions.

I added the **EatDemonPacmanGift** to allow Pacman to eat demons for a limited time, implemented using the State pattern.

Doors and keys are color-matched, ensuring each key opens the corresponding door, and not opening a random door.

## SFML Library:
We used the SFML library for graphics and sound. Follow these instructions to install and use SFML version 2.5.1 to ensure proper compilation:

1. Download the SFML library from the [official website](https://www.sfml-dev.org/download/sfml/2.5.1). The direct link for the 64-bit Visual C++ 2017 file is [here](https://www.sfml-dev.org/files/SFML-2.5.1-windows-vc15-64-bit.zip).
2. Extract the downloaded file into a folder named `SFML` in your `C:` drive. After extraction, you should have a folder structure like `C:\SFML\SFML-2.5.1` with subfolders such as `bin`, `include`, `lib`, etc.
   ![דף הבית](resources/דף הבית.PNG)
   

