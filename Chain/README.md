# 👶 Baby Care Chain — Chain of Responsibility Pattern

### Overview
This example demonstrates the **Chain of Responsibility** design pattern.
A baby's need is passed along a chain of caregivers — each handles what they can, or passes it on.

### Participants
- **Handler:** `Caregiver`
- **ConcreteHandlers:** `Granny`, `Dad`, `Mom`
- **Client:** `main.cpp`

### Flow
1. The client creates a chain: `Granny → Dad → Mom`.
2. The user enters a need (`love`, `feed`, or `change`).
3. Each caregiver decides if they can handle it; if not, they pass it to the next.

### Example Run
