# Raspberry Pi Pico experiments

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

3. Plug in a raspberry pi pico, in BOOTSEL mode
4. Drag the .uf2 binary onto the pico (which should be in external storage mode if connected in BOOTSEL)
5. The pico should reboot and run the binary
