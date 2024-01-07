#include <stdio.h>
// #include <stdlib.h>

// void displayNotification(const char *message) {
//     printf("Notification: %s\n", message);
// }

// // void receiveNotifications(int empID) {
// //     switch (empID) {
// //         case 101:
// //             displayNotification("Meeting scheduled for tomorrow.");
// //             break;
// //         case 102:
// //             displayNotification("Task deadline approaching.");
// //             break;
// //         default:
// //             displayNotification("No new notifications.");
// //             break;
// //     }
// // }

// void openFileWithOptions() {
//     int option;
//     char Notificationtxt;
//     FILE *filePointer;

//     printf("\nChoose an option:");
//     printf("\n1. Open in read mode");
//     printf("\n2. Open in write mode (overwrite if exists)");

//     printf("\nEnter your choice: ");
//     scanf("%d", &option);

//     switch (option) {
//         case 1:
//             filePointer = fopen("Notification.txt", "r");
//             if (filePointer == NULL) {
//                 printf("File not found or unable to open in read mode.\n");
//                 exit(1);
//             }
//             printf("File opened in read mode.\n");
//             // Perform operations in read mode here (if required)
//             fclose(filePointer);
//             break;
//         case 2:
//             filePointer = fopen("Notification.txt", "w");
//             if (filePointer == NULL) {
//                 printf("Unable to open in write mode.\n");
//                 exit(1);
//             }
//             printf("File opened in write mode.\n");
//             // Perform operations in write mode here (if required)
//             fclose(filePointer);
//             break;
//         default:
//             printf("Invalid option. Please choose 1 or 2.\n");
//             break;
//     }
// }

// int main() {
//     int employeeID;
//     printf("Enter your employee ID: ");
//     scanf("%d", &employeeID);

//     receiveNotifications(employeeID);

//     openFileWithOptions();

//     return 0;
// }