# Minesweeper Game 🎮

## Overview 📝
This project implements the classic Minesweeper game in C++. The game is console-based and allows players to reveal cells, flag mines, and navigate the grid while trying to avoid detonating a mine. Players can choose between three difficulty levels: Easy, Medium, and Hard.

---

## Features 🌟
- **Multiple Difficulty Levels**: Choose from Easy, Medium, or Hard, with varying grid sizes and mine counts.
- **Real-time Timer**: Tracks the time taken for the game. ⏱️
- **Flagging System**: Players can flag cells to mark potential mines. 🚩
- **Recursive Cell Reveal**: Empty cells reveal surrounding cells automatically. 🔄
- **Dynamic Board Display**: Updates the grid after each action. 📊

---

## Gameplay Instructions 🎯
1. **Run the Game**:
   Compile the code using a C++ compiler (e.g., g++). Run the resulting executable.

2. **Select Difficulty**:
   - Easy: 8x8 grid with 10 mines 🟩
   - Medium: 16x16 grid with 40 mines 🟨
   - Hard: 16x30 grid with 99 mines 🟥

3. **Game Actions**:
   - Enter `r <row> <col>` to reveal a cell. 🔍
   - Enter `f <row> <col>` to flag/unflag a cell. 🚩

4. **Winning Condition**:
   - Reveal all non-mine cells. 🏆

5. **Losing Condition**:
   - Revealing a mine ends the game. 💣

---

## Code Structure 🛠️
- **`Game` Class**:
  - Handles the game board, mine placement, cell revealing, and flagging.
  - Provides methods for calculating mine hints and managing game state.

- **`main` Function**:
  - Manages user interactions and game loop.

---

## Controls and Input 🎮
- Input Format: `action row column`
  - `action`: `r` for reveal, `f` for flag.
  - `row`, `column`: Coordinates of the cell.
- Example:
  ```
  Enter action (r for reveal, f for flag) and coordinates (row col): r 3 4
  ```

---

## Requirements 🖥️
- **C++ Compiler**: Ensure you have a C++11 or later compiler.
- **Operating System**: Compatible with Linux, macOS, and Windows.

---

## Notes 📝
- Ensure input coordinates are within bounds to avoid errors. ❗

---

## Future Enhancements 🚀
- Add a graphical user interface (GUI) using SFML libraries. 🖼️
- Implement advanced game mechanics like score tracking. 📈
- Add functionality to save and load games. 💾

---
🚀 Getting Started
Prerequisites
A C++ compiler (e.g., GCC, MSVC).
A Windows or Linux environment.
---

📧 Contact For feedback, suggestions, or collaboration, feel free to reach out:

Email: jshamita075@gmail.com
