#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #define RESTART_CMD "shutdown /r /t 0"
#elif __APPLE__
    #define RESTART_CMD "sudo shutdown -r now"
#else // Assume Linux
    #define RESTART_CMD "sudo shutdown -r now"
#endif

// Function to log messages to a log file
void log_message(const char *message) {
    FILE *log_file = fopen("./logs/restart_log.txt", "a");
        if (log_file == NULL) {
            fprintf(stderr, "Error: Could not open log file for writing.\n");
            return; // Exit the function if the log file cannot be opened
        if (log_file != NULL) {
            time_t now = time(NULL);
            fprintf(log_file, "[%s] %s\n", ctime(&now), message);
            fclose(log_file);
        }
    }
}

// Function to restart the operating system
void restart_system() {
    printf("Restarting the operating system using command: %s\n", RESTART_CMD);
    // Log the restart command
    log_message("User initiated a system restart.");
    if (system(RESTART_CMD) == -1) {
        fprintf(stderr, "Error: Failed to execute restart command.\n");
        log_message("Failed to execute restart command.");
    } else {
        log_message("System restart initiated.");
    }
}

int main() {
    char choice[10]; // Buffer to hold user input
    // Clear the input buffer
    memset(choice, 0, sizeof(choice));

    // Prompt the user for confirmation
    while (1) {
        printf("Are you sure you want to restart the operating system? (y/n): ");
        if (fgets(choice, sizeof(choice), stdin) != NULL) {
            // Check if the user input is 'y' or 'Y'
            // Trim whitespace from input
            char *newline = strchr(choice, '\n');
            if (newline) *newline = '\0'; // Remove newline character

            if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0) {
                restart_system(); // Call the restart function
                break;
            } else if (strcmp(choice, "n\n") == 0 || strcmp(choice, "N\n") == 0) {
                printf("Restart canceled.\n");
                log_message("Restart canceled by user.");
                break;
            } else {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        } else {
            fprintf(stderr, "Error reading input.\n");
            return 1; // Return an error status
        }
    }

    return 0; // Return success status
    // Cleanup resources if needed
}
