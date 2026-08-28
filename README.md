# Mk Kernel

![License](https://img.shields.io/badge/license-BSD%203--Clause-blue) ![Platform](https://img.shields.io/badge/platform-STM32F746G--Eval2%20%7C%20DISCO-orange) ![Architecture](https://img.shields.io/badge/arch-Cortex--M7-green) ![Toolchain](https://img.shields.io/badge/toolchain-arm--none--eabi--gcc%2010.3-lightgrey) ![Language](https://img.shields.io/badge/language-C%20%2B%20ARM%20ASM-yellow)

The **Mk Kernel** is a bare-metal, zero-dependency Real-Time Operating System (RTOS) core written from scratch in C and ARM Thumb-2 assembly. Designed specifically for the **ARM Cortex-M7** processor (targeting the STM32F74xxx and STM32F75xxx MCU families), it sits at the **Foundation layer** of the Mk OS software ecosystem.

It provides a deterministic execution environment with memory protection, hardware-accelerated $O(1)$ scheduling, zero dynamic memory allocation, and zero-latency interrupt handling.

---

## Key Features

- **Preemptive $O(1)$ Scheduler**: Fixed-priority scheduling with Round-Robin time-slicing for tasks of equal priority. Uses the ARM `CLZ` (*Count Leading Zeros*) instruction for instantaneous selection of the highest-priority ready task.
- **Hardware-Enforced Security & Isolation (TEE)**: Software Trusted Execution Environment leveraging the Cortex-M7 Memory Protection Unit (MPU) and privilege levels.
- **Zero Dynamic Allocation**: Built entirely on fixed-size memory pools (`T_mkPool`), completely eliminating heap fragmentation and non-deterministic allocation delays.
- **FPU Context Management**: Full support for floating-point (`K_MK_TYPE_FLOATING`) and non-floating-point tasks.
- **Synchronization Primitives**: Semaphores, Mutexes (with priority inheritance), Event Fields, and Mailboxes.
- **Zero-Latency Interrupts**: High-priority hardware interrupts are never masked by the kernel (`BASEPRI` masking).
- **Asynchronous Callback Manager**: Deferred execution engine handling up to 30 concurrent function callbacks via dedicated background tasks.
- **Structured Fault Handling**: Built-in trap handlers for `HardFault`, `MemManage`, `BusFault`, `UsageFault`, and stack overflow detection.
- **Zero External Dependencies**: Pure standalone implementation written in C and Assembly.

---


## Documentation

ℹ️ For detailed technical articles and API documentation, visit [La Fabrique du MCU](https://lafabriquedumcu.com/articles/rtos/api.html).

---

## Build

### Hardware targets

Both boards are supported from the `main` branch. The target is selected at build time via the
CMake preset:

| Preset | Board | MCU |
|--------|-------|-----|
| `release-eval2` / `debug-eval2` | STM32F746G-Eval2 | STM32F746NG |
| `release-disco` / `debug-disco` | STM32F746G-DISCO REV.C | STM32F746NG |

### Requirements

- [GNU Arm Embedded Toolchain 10.3-2021.10](https://developer.arm.com/downloads/-/gnu-rm)
- CMake ≥ 3.25
- Ninja

### Build system

The project uses **CMake** with **presets** defined in `CMakePresets.json`. Four presets are
available:

| Preset | Board | Type |
|--------|-------|------|
| `release-eval2` | STM32F746G-Eval2 | Release (`-Ofast`) |
| `debug-eval2` | STM32F746G-Eval2 | Debug (`-O0 -g3`) |
| `release-disco` | STM32F746G-DISCO REV.C | Release (`-Ofast`) |
| `debug-disco` | STM32F746G-DISCO REV.C | Debug (`-O0 -g3`) |

### Steps

1. Configure the project using the desired preset:
   ```
   cmake --preset debug-eval2
   ```

2. Build the firmware:
   ```
   cmake --build --preset debug-eval2
   ```

   This produces in `build/<preset>/`:
   - `Mk.elf` — full debug symbols
   - `Mk-Strip.elf` — stripped binary
   - `Mk.srec` — S-Record with embedded symbol table
   - `Mk.map` — linker map file

### Compiler versions used

| Tool | Version |
|------|---------|
| `arm-none-eabi-gcc` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `arm-none-eabi-g++` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| CMake | ≥ 3.25 |
| Ninja | latest |

### Flashing and debugging

Debug configurations for **VS Code** are included in the repository in `.vscode/launch.json`,
using the [Cortex-Debug](https://github.com/Marus/cortex-debug) extension with J-Link:

| Configuration | Board | Type | Binary flashed |
|---|---|---|---|
| `Debug Mk — EVAL2 (J-Link)` | STM32F746G-Eval2 | Debug | `build/debug-eval2/Mk.elf` |
| `Debug Mk — DISCO (J-Link)` | STM32F746G-DISCO REV.C | Debug | `build/debug-disco/Mk.elf` |
| `Release Mk — EVAL2 (J-Link)` | STM32F746G-Eval2 | Release | `build/release-eval2/Mk.elf` |
| `Release Mk — DISCO (J-Link)` | STM32F746G-DISCO REV.C | Release | `build/release-disco/Mk.elf` |

All configurations require a J-Link probe (or a ST-Link flashed with the J-Link firmware) and
the [J-Link Software](https://www.segger.com/downloads/jlink/) installed.

## License

Copyright © 2019-2026 **Mathieu Renard**. All rights reserved.

This project is licensed under the **BSD 3-Clause License** — see the [LICENSE](LICENSE) file for
details.