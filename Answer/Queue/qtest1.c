/*
 * File: qtest.c
 * -------------
 * This program tests the queue.h interface by simulating a
 * simple waiting line.  Entering a name adds that person to
 * the waiting line.  Entering a blank line removes the name
 * at the head of the line and displays it on the screen.
 * Typing "quit" exits from the program.
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "queue.h"

/* Main program */

main()
{
    queueADT waitingLine;
    string line;
    double *prn;

    printf("Waiting line manager.\n");
    printf("Type a real number to enter it into the line.\n");
    printf("Type a blank line to serve the first real number in line.\n");
    printf("Type \"quit\" to exit from the program.\n");
    waitingLine = NewQueue();
    while (TRUE) {
        printf(":");
        line = GetLine();
        if (StringEqual(line, "quit")) break;
        if (StringEqual(line, "")) {
            if (QueueLength(waitingLine) == 0) {
                printf("No one is waiting\n");
            } else {
                prn = Dequeue(waitingLine);
                printf("%g\n", *prn);
            }
        } else {
        	prn = New(double *);
        	*prn = StringToReal(line);
            Enqueue(waitingLine, prn);
        }
    }
}
