# 🌿 So_Long

<div align="center">

Embark on **So_Long** - A thrilling 2D maze game where you gather items and seek the exit. Enhanced with bonus features but without global variables for a cleaner codebase.

![Project Status](https://img.shields.io/badge/Project-So_Long-blue?style=for-the-badge&logo=42)
![Programming Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge&logo=c)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

</div>

---

## 📚 Table of Contents

<details>
<summary>View Contents</summary>

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Bonus Features](#bonus-features)
- [Contributing](#contributing)
- [License](#license)

</details>

---

## 🔍 Overview

**So_Long** challenges you to navigate through mazes, collect items, and escape using MiniLibX for graphical rendering. This project combines game logic, graphics programming, and map parsing into an educational yet fun experience.

---

## ✨ Features

- **Map Loading**: Dynamically loads and validates game maps from `.ber` files.
- **Player Interaction**: Move your character with intuitive keyboard controls.
- **Collectibles**: Collect all items to unlock the level's exit.
- **Obstacle Avoidance**: Collision detection prevents unwanted movements.
- **Exit Condition**: The game ends once all collectibles are gathered and you reach the exit.

---

## 🚀 Installation

### 📦 Prerequisites

- **C Compiler** (e.g., GCC)
- **MiniLibX** library
- **Make** tool

### 🔧 Setup

```bash
git clone https://github.com/melaniereis/42_so_long.git
cd so_long
make
```
## 🖥️ Usage
Start the game with:

```bash
./so_long maps/map_example.ber
````
## 🧠 Implementation Details

- **Map Parser**: Ensures map integrity for a correct gameplay experience.
- **Graphics Engine**: Utilizes MiniLibX for rendering game elements.
- **Game Mechanics**:
  - **Movement**: Player actions are managed through event-driven programming.
  - **Collectibles**: Tracked internally, without a visual counter.
  - **Win Condition**: Automatically checks if all items are collected before allowing exit.

## 🎁 Bonus Features

- **Enemy AI**: Adds patrolling enemies to ramp up the challenge.
- **Visuals**: Simple animations for player and environmental objects enhance gameplay.

**Note:** This version omits a move counter and sound effects for simplicity.

## 🧬 Design Philosophy

### MiniLibX:
- **Graphics Simplicity**: MiniLibX's straightforward API keeps the focus on game logic rather than complex graphics.
- **Compatibility**: Designed for ease of use across different systems, fitting the 42 School's educational goals.

## 🤝 Contributing

We welcome contributions! Fork the repository, make your enhancements, and send a pull request.

## 📜 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for further details.

<div align="center">

**Adventure Awaits! 🎉**

[⬆ Back to Top](#-so_long)

</div>
