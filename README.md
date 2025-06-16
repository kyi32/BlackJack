# Blackjack Game Project

## Overview
This repository contains the source code, documentation, and related files for a Blackjack game developed by Ivan Rybalko and KyiMin Thant from the Faculty of Mechanical Engineering and Robotics at AGH. The project implements a console-based Blackjack game in C++ using object-oriented programming (OOP) principles, supporting two human players against a dealer.

## Files
### Source Code
- `BlackJack.cpp`: Main entry point of the game.
- `Cards.cpp` / `Cards.h`: Represents a single playing card with rank and suit.
- `Deck.cpp` / `Deck.h`: Manages a deck of 52 cards, including initialization and shuffling.
- `Hand.cpp` / `Hand.h`: Handles the cards held by a player or dealer and calculates scores.
- `Player.cpp` / `Player.h`: Base class for all player types with shared functionality.
- `PlayerHuman.cpp` / `PlayerHuman.h`: Derived class for human-controlled players with user input.
- `Dealer.cpp` / `Dealer.h`: Derived class for automated dealer behavior.
- `System.cpp` / `System.h`: Coordinates the game loop and manages gameplay flow.

### Documentation
- `BlackJack_game_project (report).pdf`: Detailed project report including architecture, use case diagram, program flow, suggestions for improvement, conclusion, and working code.

### Other Files
- `BlackJack.vcproj`, `BlackJack.vcproj.filters`, `BlackJack.vcproj.user`: Visual Studio project files.

## Project Details
- **Objective**: Create a functional Blackjack game to practice OOP concepts and provide an engaging console-based experience.
- **Features**: Two human players, automated dealer, betting system, hit/stand/double options, and score calculation with Ace flexibility (1 or 11).
- **Technology**: C++ with standard library features (e.g., `vector`, `random`).
- **Rules**: Players aim for a score closest to 21 without exceeding it; dealer stands on 17 (hard or soft depending on setting).

## Architecture
- **Cards**: Stores rank and suit, provides value and display methods.
- **Deck**: Initializes and shuffles 52 cards, handles card drawing.
- **Hand**: Manages a collection of cards and computes the total score.
- **Player**: Abstract base class with shared attributes (name, balance, bet, hand).
- **PlayerHuman**: Handles user input for moves (hit, stand, double).
- **Dealer**: Automates dealer actions based on Blackjack rules.
- **System**: Controls game flow, including round management and result display.

## Installation and Usage
1. Clone the repository.
2. Open `BlackJack.vcproj` in Visual Studio.
3. Build and run the project.
4. Follow console prompts to play: enter bets, choose actions, and decide to play again.

## Demonstration
- Refer to `BlackJack_game_project (report).pdf` for an example game round output.

## Contributors
- Ivan Rybalko
- KyiMin Thant
