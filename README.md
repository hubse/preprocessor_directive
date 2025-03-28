# Restart OS Cross-Platform

## Description
This project provides a simple C program that allows users to restart their operating system with confirmation. It supports multiple operating systems, including Windows, macOS, and Linux.

## Features
- Cross-platform support for restarting the OS.
- User confirmation before executing the restart command.
- Logging of actions to a log file.

## Usage
1. Compile the program using a C compiler:
   ```bash
   gcc restart_os_cross_platform.c -o restart_os
   ```
2. Run the compiled program:
   ```bash
   ./restart_os
   ```
3. Follow the prompts to confirm the restart.

## Enhancements
To add new enhancements:
- Modify the `restart_system` function to include additional features, such as scheduling restarts or adding more logging options.
- Update the user interface for better interaction.

## Logging
The program logs messages to `logs/restart_log.txt`. Ensure that the `logs` directory exists before running the program.

## License
This project is licensed under the MIT License.
