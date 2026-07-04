# PIG - Portable Image Gear

PIG is an .AppImage manager designed to make better use of the format through a concise interface. The project arose from specific needs of mine that various other managers fail to meet.

## Default Storage Path

Applications and their metadata are managed within:

```plaintext
~/Programs/AppImages/
```

## Building From Source

### Prerequisites

* GCC or Clang supporting C++23
* Premake5
* Ninja Build System

### Compilation Steps

1. Generate the Ninja build files using Premake:

    ```bash
    premake5 ninja
    ```

2. Compile the project:

    ```bash
    ninja
    ```

> Or simply run the provided `scripts/setup.sh` script to perform both steps automatically.

The compiled binary will be located at `build/Debug/x86_64/pig` (or `Release` depending on your build configuration).

## Usage

To import an AppImage file into the manager:

```bash
./pig copy /path/to/application.AppImage
```

### File Structure

```plaintext
.
├── include
│   ├── fileManagement.hpp
│   └── main.hpp
├── LICENSE
├── premake5.lua
├── README.md
├── scripts
│   ├── build.sh
│   ├── clean.sh
│   ├── run.sh
│   └── setup.sh
└── src
    ├── fileManagement.cpp
    └── main.cpp
```

### Initial Requirements

#### Phase 1: Core & Ingestion (CLI)

* [x] **Path Resolution:** Accept a custom storage path or fallback to a default directory (e.g., `~/Programs/AppImages/`).
* [x] **Directory Isolation:** Create a dedicated subdirectory for each application to prevent data fragmentation.
* [x] **Ingestion:** Move or copy the target `.AppImage` into its specific subdirectory.
* [ ] **Permissions:** Apply executable permissions (`chmod +x`) programmatically to the binary.
* [ ] **Initialization & Launch:** Generate empty `.home` and `.config` directories adjacent to the binary *before* the initial execution to isolate application data. Launch the process within this sandbox context.

#### Phase 2: Desktop Integration

* [ ] **Asset Extraction:** Extract the embedded application icon from the `.AppImage` payload and write it to `~/.local/share/icons/PIG/`.
* [ ] **Desktop Entry:** Generate a compliant `.desktop` file in `~/.local/share/applications/` referencing the absolute paths of the binary and the extracted icon.
* [ ] **Purge System:** Implement a removal routine to delete the binary, its subdirectories, and the desktop shortcut, with an explicit prompt allowing the user to preserve configuration and save-game data.

#### Future Backlog

* [ ] **Configuration Management:** Centralize global manager states in `~/.config/pig/` with schema migration support.
* [ ] **Update Engine:** Automate the download and replacement of existing `.AppImage` binaries.
* [ ] **Synchronization Watchdog:** Detect upstream file name changes and automatically rename active `.home` and `.config` directories to preserve data links.
* [ ] **Desktop Environment Bridging:** Inject host cursor, font, and GTK/Qt configuration trees directly into the sandboxed `.home` directories.
* [ ] **Third-Party Launchers:** Expose integration scripts to register managed binaries inside Steam (as a non-Steam game) and Lutris.
* [ ] **Monolithic Backup:** Compile all isolated data directories into a compressed archive (`.tar.gz`) for single-file disaster recovery.
