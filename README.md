# 🖼️ PPM Graphics Engine — C++

A lightweight, terminal-based graphics engine built from scratch in **pure C++** — no external libraries. Draw shapes on a virtual pixel canvas and export the result as a `.ppm` image file.

---

## 📸 Preview

> Draw rectangles and circles, choose colors, fill or outline — all from the terminal. Output is saved as a standard PPM (P3) image.

```
chose a option:
1> for a rectangle
2> for a circle
3> for exit
Enter: 1

Enter rectangle height and width: 40 60
Enter position(x,y) of rectangle on screen: 10 10
Color(red,yellow,blue,white): red
Filled shape(y/n): y
```

---

## 💡 How It Works

The core idea is simple — a 2D array represents the screen where every cell stores an RGB pixel value.

```
Screen (130 rows × 200 columns)
┌─────────────────────────────┐
│  "0 0 0"  "0 0 0"  ...     │  ← each cell = one pixel (R G B)
│  "0 0 0"  "255 0 0" ...    │
│   ...                       │
└─────────────────────────────┘
         ↓
     Write to .ppm file
```

**Step-by-step flow:**
1. Initialize all pixels as black `(0 0 0)`
2. User selects a shape, size, position, color, and fill option
3. Program updates only the relevant pixel cells with the chosen RGB value
4. After all shapes are placed, the full pixel grid is written to `game.ppm` in PPM P3 format

The coordinate origin `(0, 0)` is at the **bottom-left** of the image.

---

## ✨ Features

| Feature | Details |
|---|---|
| 🔲 Rectangle | Filled or outline, any position and size |
| ⭕ Circle | Filled or outline, defined by radius and position |
| 🎨 Colors | Red, Yellow, Blue, White |
| 📐 Positioning | X/Y coordinate input, origin at bottom-left |
| ✅ Validation | Detects out-of-bounds placement and prompts retry |
| 💾 Output | Exports as standard PPM (P3) image — `game.ppm` |

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (g++ recommended)
- Any PPM-compatible image viewer:
  - **Windows** — website>> (https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html)

### Build & Run
```
copy main.cpp code and paste into your .cpp file and run it and get game.ppm image in the same folder in which .cpp is open
image using  website https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html

```

After running, open the generated `game.ppm` file in any compatible viewer.

---

## 🗂️ Project Structure

```
ppm-graphics-engine/
│
├── main.cpp        # All source code (single file)
├── game.ppm        # Output image (generated on run)
└── README.md
```

---


## 🙋‍♂️ Author

ADARSH SINGH
- GitHub: [@your-username](https://github.com/your-username)
- LinkedIn: [your-linkedin](https://linkedin.com/in/your-linkedin)

---

## 📄 License

This project is open source project.

---

> *Built from scratch — no libraries, no shortcuts. Just C++, math, and pixels.*
