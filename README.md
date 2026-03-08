# minitalk

Interprocess communication project using UNIX signals, developed as part of the 42 School curriculum.

## Overview

The goal of this project is to implement a small communication program between a client and a server using UNIX signals.
Messages are transmitted bit by bit, where each signal represents a binary value, allowing the client to send strings to the server.

## Tech Stack

* C
* UNIX Signals (`SIGUSR1`, `SIGUSR2`)
* Makefile

## Features

* Client-server communication via UNIX signals
* Bitwise message encoding and decoding
* Transmission of strings from client to server
* Signal-based synchronization between processes
* Handling of process IDs for message routing

## Learning Outcomes

* Interprocess communication (IPC)
* UNIX signal handling
* Bitwise operations
* Client-server architecture in low-level systems
