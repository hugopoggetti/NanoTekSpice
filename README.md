## 🔌 NanoTekSpice - Digital Circuit Simulator ⚡

NanoTekSpice is a **C++** logic circuit simulator that models digital electronic components using a configuration file. It constructs a graph of components, simulates their behavior, and processes user commands interactively. 🧠💡

## 📜 Features  

✅ Supports various logic gates (AND, OR, XOR, NOT, NAND, NOR) 🔲  
✅ Handles complex chipsets like **4008**, **4013**, **4040**, and more  
✅ Interactive shell for modifying circuit states in real time 🖥️  
✅ Error handling for invalid configurations ❌  
✅ Expandable with additional components & graphical output (Bonus) 🎨  

## 🛠️ Installation & Usage  

### 📦 Compilation  

```bash
make
```

### 🚀 Running a Circuit Simulation  

```bash
./nanotekspice path/to/circuit.nts
```

Example:

```bash
./nanotekspice nts_single/4017_johnson.nts
```

### 🕹️ Interactive Commands  

Once inside the simulator, you can enter:

- `simulate` → Runs a single simulation step
- `display` → Shows the current state of all inputs/outputs
- `input=value` → Sets the value of an input (0, 1, or U for undefined)
- `loop` → Continuously simulates until interrupted (CTRL+C)
- `exit` → Exits the program

## 📁 Project Structure  

```
📦 NanoTekSpice
├── 📜 Makefile       # Compilation rules
├── 📜 README.md      # This file 😉
├── 📂 build/         # Compiled binaries
├── 📂 src/           # Source code
├── 📂 tests/         # Unit tests
├── 📂 nts_single/    # Example circuits
├── 📂 nts_advanced/  # More complex circuits
└── nanotekspice      # Compiled simulator
```

## 🎯 Example Execution  

```
> ./nanotekspice nts_single/4017_johnson.nts
> display
tick: 0
input(s):
  in_0: U
  in_1: U
  in_r: U
output(s):
  out_0: U
  out_1: U
  out_2: U
  out_3: U
  out_4: U
  out_5: U
  out_6: U
  out_7: U
  out_8: U
  out_9: U
  out_s: U
>
...
``` NanoTekSpice
