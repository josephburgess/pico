# Raspberry Pi Pico Experiments

A collection of small projects and experiments for the Raspberry Pi Pico using the Pico SDK in C.

## Getting Started

1. Clone the repo:

   ```bash
   git clone https://github.com/yourusername/pico-experiments.git
   cd pico-experiments
   ```

2. Build an example:
   ```bash
   cd blink
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Upload the `.uf2` file:
   - Connect the Pico while holding **BOOTSEL**.
   - Drag and drop the file from `build/` onto the Pico's USB drive.
